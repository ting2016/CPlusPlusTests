/*this is a test of different ways to initialize a thread.*/
#include <thread>
#include <iostream>

void threadFunc(){
    std::cout<<"Hello from threadFunc"<<std::endl;
}
//a functor is an object of a class that overloads operator()
class MyClass1{
public:
    void operator()(){
        std::cout<<"Hello from MyClass1 which overloads ()"<<std::endl;
    }
};

class MyClass2{
    void operator()(int para){
        std::cout<<"Hello from MyClass1 which overloads () with para, para =" << para << std::endl;
    }
};

class MyClassWithMemberFunc{
public:
    void publicFunc(){
        std::cout<<"Hello from MyClassWithMemberFunc"<<std::endl;
    }

};

void funcWithPara(int para){
    std::cout<<"Hello from funcWithPara, para =" << para <<std::endl;
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

    //initialize a thread by passing with an object of a class or passing the class(must overload operator())
    MyClass1 myf;
    std::thread threadTest2(myf); //passing object of a class
    //std::thread threadTest2((MyClass1())); //passing class
    if(threadTest2.joinable()){
        threadTest2.join();
    }

    //initialize a thread with a public member function of a class
    MyClassWithMemberFunc myc;
    std::thread thradTest3(&MyClassWithMemberFunc::publicFunc, myc);
    if(thradTest3.joinable()){
        thradTest3.join();
    }

    //initialize a thread with a function with parameters
    int para = 5;
    std::thread threadTest4(funcWithPara,para);
    if(threadTest4.joinable()){
        threadTest4.join();
    }
    
    //start a thread with a lambda
    std::thread threadTest5([](){
	std::cout<<"thread from a lambda" << std::endl;
    });
    if (threadTest5.joinable()){
	threadTest5.join();
    }

}

