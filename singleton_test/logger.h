#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger{
private:
	Logger& operator==(const Logger&)=delete;
	Logger(const Logger&) = delete;
	Logger(){};
	static Logger* m_pInstance;
public:
	static Logger* Instance();
	bool openLogFile(std::string logFile);
	void writeToLogFile();
	bool closeLogFile();
};
#endif
