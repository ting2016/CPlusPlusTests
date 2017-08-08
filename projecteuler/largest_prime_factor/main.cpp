#include <iostream>
#include <vector>
void getLargestPrimeFactor(const long int value, long int& largestPrimeFactor){
	std::vector<long int> primeCollect;
	long int left = value;
	long int i =2;
	std::cout<<"primeCollect:";
	while(i<=left/2){
		if(left%i==0){
			primeCollect.push_back(i);
			std::cout<<i<<" ";
			left = left/i;
			i=2;
		}
		i++;
	}
	if((left>=2)&&(left<value)){
		std::cout<<left<<" "<<std::endl;
		primeCollect.push_back(left);
	}
	if(primeCollect.size()!=0)
		largestPrimeFactor = primeCollect.at(primeCollect.size()-1);
	else
		std::cout<<"no prime factor collected!"<<std::endl;
}
int main(){
	long int value;
	std::cout<< "please enter a value:";
	std::cin>>value;
	long int largestPrimeFactor;
       	getLargestPrimeFactor(value,largestPrimeFactor);
	std::cout<<"the largest prime factor is: "<< largestPrimeFactor<<std::endl;
	return 1;
}
