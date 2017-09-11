#include <thread>
#include <iostream>

void threadFunc(){
	std::cout<<"welcome to multiThreading"<<std::endl;
}
//a functor is an object of a class that overloads operator()
class myFunctor{
	void operator()(){
		std::cout<<"This is my function object"<<std::endl;
	}
};

class myFunctorWithPara{
	void operator()(int*arr, int length){
		std::cout<<"an arry with length "<<length<<" is passed to thread"<<std::endl;
		for(int i = 0; i<length;i++){
			std::cout<<arr[i]<<" ";
		}
		std::cout<<std::endl;
	}
};

class myClass{
public:
	void publicFunc(){
		std::cout<<"public function of myClass is called."<<std::endl;
	}

};

void funcWithPara(int val, char* str, double dval){
	std::cout<<val<<" "<<str<<" "<<dval<<" "<<std::endl;
}

int main(){
	//initialize a thread with a function
	std::thread thradTest1(threadFunc);
	thradTest1.detach();
	if(thradTest1.joinable()){
		thradTest1.join();
	}
	else{
		std::cout<<"thradTest1 is detached"<<std::endl;
	}
	//initialize a thread by passing with an object of a class(must overload operator())
	myFunctor myf;
	std::thread thradTest2(myf);
	if(thradTest2.joinable()){	
		thradTest2.join();
	}

	//initialize a thread with a public member function of a class
	myClass myc;
	std::thread thradTest3(&myClass::publicFunc, myc);
	if(thradTest3.joinable()){
		thradTest3.join();
	}
	
	//initialize a thread with a function with parameters
	char str[] = "Hello";
	std::thread threadTest4(funcWithPara, 5, str, 3.2);
	if(threadTest4.joinable()){
		threadTest4.join();
	}
	
	//initialize a thread with an object with parameters(must add the parameters list to the loverloaded operator())
}
