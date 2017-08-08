#include <spdlog/spdlog.h> //spdlog::*
#include <spdlog/fmt/ostr.h> // custom formats

#include <QString> // QString
#include <iostream> // std::cout
#include <memory> // unique pointer stuff

enum LogType{
    DW_OFF = 6,
    DW_CRITICAL = 5,
    DW_ERROR = 4,
    DW_WARN = 3,
    DW_INFO = 2,
    DW_DEBUG = 1,
    DW_TRACE = 0
};

std::shared_ptr<spdlog::logger> mainLog;
std::ostream& operator<<(std::ostream& os, const QString& c) // make fmt recognize QStrings
{
    return os << c.toStdString();
}

void init_dwlog(std::string logpath, const std::string logName) {
    static bool initialized = false;

    if(initialized) {
        spdlog::get(logName)->error("Logging is already initialized! Aborting.");
        return;
    }

    using spdlog::spdlog_ex;
    try {
        using spdlog::logger;
        using spdlog::register_logger;
        using spdlog::sink_ptr;
        using std::begin;
        using std::end;
        using std::make_shared;
        using std::vector;

        // TODO: determine if we should use *_st or *_mt loggers
        using file_sink   = spdlog::sinks::simple_file_sink_st;
        using stdout_sink = spdlog::sinks::stdout_sink_st;

        vector<sink_ptr> sinks;
        sinks.push_back(make_shared<stdout_sink>());
        sinks.push_back(make_shared<file_sink>(logpath));
        auto mainlog = make_shared<logger>(logName, begin(sinks), end(sinks));
        register_logger(mainlog);
        // TODO: determine what categories we will have in logging:
        // an example of creating a new category:
        // auto categorylog = make_shared<logger>("category_name", begin(sinks), end(sinks));
        // spdlog::register_logger(categorylog)
        // the first arg is the category name, so we can do spdlog::get("category_name")
        // we could also possibly iterate over a list of string categories to register
        initialized = true;
    }
    catch (const spdlog_ex& ex) {
        using std::cout;
        using std::endl;
        // we can probably continue running, but do we want to?
        cout << "Failed to initialize logging: " << ex.what() << endl;
    }
}

void clean_dwlog() {
    spdlog::drop_all();
}
void expand(std::string & message)  //Terminate recursive call
{
    message.append("\n");
}

template<typename FIRST_PARA, typename... PARAS>
void expand(std::string & message, FIRST_PARA firstPara, PARAS... paras) // recursive variadic function
{
    message.append(firstPara);
    expand(message, paras...);
}

template<typename... PARAS>
void output(LogType type, PARAS... paras)
{
    std::string message;
    expand(message, paras...);
    std::cout<<message<<std::endl;
    std::cout<<"type is "<<type<<std::endl;
    switch(type){
    case DW_CRITICAL:
        mainLog->critical(message);
        break;
    case DW_DEBUG:
        mainLog->debug(message);
        break;
    case DW_ERROR:
        mainLog->error(message);
        break;
    case DW_INFO:
        mainLog->info(message);
        break;
    case DW_TRACE:
        mainLog->trace(message);
        break;
    case DW_WARN:
        mainLog->warn(message);
        break;
    case DW_OFF:
        break;
    default:
        break;
    }
}


int main(int, char*[]) {
    try {
        auto console = spdlog::stdout_color_mt("console");
    }
    catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Failed to initialize logging! " << ex.what() << std::endl;
        return 1;
    }

    /* we can use something along these lines to select the log level
     * e.g if NDEBUG is not set (aka we are in Debug mode, not Release), trace!
    #ifndef NDEBUG
    spdlog::set_level(spdlog::level::trace);
    #endif
     */
    spdlog::set_level(spdlog::level::trace); // let's just show everything off for now though

    auto log = spdlog::get("console");

    log->trace("this is a trace message");
    SPDLOG_TRACE(log, "this is too!");
    log->debug("this is a debug message");
    log->info("this is an info message");
    log->warn("this is a stern warning");
    log->error("something went wrong!");
    log->critical("aaand we crash!");

    QString qs = "<I am a QString>";
    log->info("We can format QStrings, and any type we want! Like so: {}.", qs);
    log->info("Note that after we use critical, there is no guarantee formatting (in particular, *color* formatting) will remain the same, as it should only be used prior to crashing.");

    init_dwlog("./mainLog/main.log","mainLog");
    mainLog =spdlog::get("mainLog");
    LogType type = DW_TRACE;
    output(type,"\t", "::", "another string", "\n");
//    mainLog->info("1","2","3");
//    mainLog->log(spdlog::level::critical,"***%v*%v*%v***","1","2","3");
//    mainLog->log(spdlog::level::critical,">>>>>>>>> %H:%M:%S %z %v <<<<<<<<<","1");

    spdlog::drop_all();
}
