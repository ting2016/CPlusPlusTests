#include <assert.h>
#include <iostream>
#include <vector>

bool isPrime(int value){
	assert(value>=2);
	if(value==2)
		return true;
	for(int i=2; i<value;i++){
		if(value%i==0)
			return false;
	}	
	return true;
}

int main(){
	std::size_t num;
	std::vector<int> primeList;
	int init = 2;
	std::cout<<"what is the num of prime: ";
	std::cin>>num;
	while(true){
		if(isPrime(init)){
			primeList.push_back(init);
		}
		if(primeList.size()==num)
			break;
		init++;
	}
	std::cout<<" the "<<num<<"th prime number is: "<< primeList.at(primeList.size()-1);
}
