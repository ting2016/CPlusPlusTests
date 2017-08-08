#include <iostream>
#include <cmath>
int getNumDiv(const unsigned long& value){
	int count =1;
	for(unsigned long i =2; i<=value/2;i++){
		if(value%i==0)
			count++;
	}
	if(value>1)
		count++;
	std::cout<<"num of divisors for: "<< value <<" is: "<< count <<std::endl;
	return count;

}
int main(){
	int numDiv;
	unsigned long i =1;
	unsigned long triangleNumber=0;
	std::cout<<"please enter the number of divisors:";
	std::cin>>numDiv;
	while(true){
		triangleNumber+=i;	
		std::cout<<"current triangleNumber: "<<triangleNumber<<std::endl;
		if(getNumDiv(triangleNumber)>numDiv){
			std::cout<<"find the value of first triangle number that has over "<<numDiv<<" divisors.: "<< triangleNumber;
			return 1; 

		}
		i++;
	}
	return  -1;
}
