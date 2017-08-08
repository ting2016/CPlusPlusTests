#include <iostream>
#include <vector>
#include <cmath>
bool isPrime(long int value){
	int i =2;
	for(;i<=std::sqrt(value);i++){
		if(value%i==0)
			return false;
	}
	return true;
}
long int getPrimesSum(const long int maxValue){
	long int sum =0;
	for(int v =2; v<maxValue;v++){
		if(isPrime(v)){
			sum+=v;
			
		}	
	}
	return sum;
}
int main(){
	long int value;
	long int sum = 0;
	std::vector<long int> primeList;
	std::cout<< "please enter a max value:";
	std::cin>>value;
       	sum = getPrimesSum(value);
	std::cout<<"the sum of prime factors below: "<<value<<" is: "<< sum<<std::endl;
	return 1;
}
