#include <iostream>
int even_fibonacci_numbers(int max){
	int sum=0;
        if(max>=2){
                int a = 1;
                int b = 2;
                std::cout << "\"" << a<< " ";
                while(b<=max){
                        std::cout << b << " ";
                        if(b%2==0){
                       		sum+=b; 
			}
                        int t = a + b;
                        a = b;
                        b = t;
                }
                std::cout << "\"";
                return sum;
        }
        else{
                return -1;
        }

}

int main(){
        int max;
        std::cout<<" please enter the max value: ";
        std::cin >> max;
        std::cout << "he sum of the even-valued terms(not exceed the max value) of the Fibonacci sequence is: "<< even_fibonacci_numbers(max) << std::endl;
        return 1;
}
