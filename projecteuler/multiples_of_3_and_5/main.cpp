#include <vector>
#include <iostream>
int main(){
	int maxV;
	int sum = 0;
	std::cout<<"please enter the max value: ";
	std::cin>>maxV;
	for(int tempV = maxV-1; tempV>=3;tempV--){
		if((tempV%3==0)||(tempV%5==0)){
			sum+=tempV;	
		}	
	}	
	std::cout<<"the sum of all the multiples of 3 or 5 below " << maxV << " is: " << sum << std::endl;
	return 0;
} 
