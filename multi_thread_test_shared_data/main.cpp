#include <vector>
#include <thread>
#include <iostream>
#include <mutex>
struct Counter {
    int value;
    std::mutex m;
    Counter() : value(0){}

    void increment(){
	m.lock();
        ++value;
	m.unlock();
    }
    //method2: use lock_guard in case mutex m gets no chance to do unlock because of unexpected exceptions
    /*
    void increment(){
	std::lock_guard<std::mutex> lockGuard(m);
	++value;
    }
    */
};

int main(){
	Counter count;
	std::vector<std::thread> threads;
	for(int i = 0; i<5; i++){
		threads.push_back(std::thread([&count](){
			for (int j = 0; j<100; j++){
				count.increment();
			} 
		}));
	}
	for(auto& t: threads){
		t.join();
	}
	std::cout<<count.value<<std::endl;
	return 0;
}
