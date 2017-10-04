#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
class Application{
	std::mutex m_mutex;
	bool m_dataLoaded;
public:
	Application(){m_dataLoaded = false;}
	void subTask();
	void mainTask();

};


int main(){
	Application app;
	std::thread t1(&Application::subTask, &app);
	std::thread t2(&Application::mainTask, &app);
	t1.join();
	t2.join();
	return 0;

}
//task of this func is to load data
void Application::subTask(){
	std::cout<<"from subTask: start loading data" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout<<"from subTask:finish loading data......."<<std::endl;
	std::lock_guard<std::mutex> guard(m_mutex);
	m_dataLoaded = true;
}

void Application::mainTask(){
	std::cout<<"form mainTask: do handshaking....."<<std::endl;
	m_mutex.lock();
	while(!m_dataLoaded){
		m_mutex.unlock();
		std::cout<<"from mainTask: still waiting for subTask to finish loading data"<<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		//lock m_mutex here as mainTask will read m_dataLoaded again
		m_mutex.lock();
	}
	//unlock m_mutex, m_dataLoaded is true, while stops
	m_mutex.unlock();
	std::cout<<" from mainTask: processing loaded data....."<<std::endl;
}
