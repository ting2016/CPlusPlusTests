#include <iostream>
#include<cassert>
unsigned long long getPowerFor2(int power){
	assert(power>=1);
	if(power==1)
		return 2;
	return 2*getPowerFor2(power-1);
}
int main(){
	int power;
	std::cout<<"pleast enter the power: ";
	std::cin>>power;
	unsigned long long result = getPowerFor2(power);
	std::cout<<"result is: "<<result<<std::endl;
	int sum =0;
	unsigned long long temp = result;
	while(temp>0){
		sum+=temp%10;	
		temp/=10;
	}
	std::cout<<"sum is: "<<sum;
	return 1;
}
