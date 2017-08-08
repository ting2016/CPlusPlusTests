#include<iostream>

int main(){
	unsigned int maxvalue;
	std::cout<<"please enter the max value:";
	std::cin>>maxvalue;
	int longestChainLength = 1;
	unsigned int result=0;
	for(unsigned int i = 1;i<=maxvalue;i++){
		unsigned int temp =i;
		int count = 1;
//		std::cout<<" temp = "<<temp<<std::endl;
		while(true){
			if(temp%2==0){
				temp =temp/2;
//				std::cout<<"temp/2: "<<temp;
				count++;
			}
			else{
				temp=temp*3+1;
//				std::cout<<"temp*3 +1"<<temp;
				count++;
			}
			if(temp==1){
				if(count>longestChainLength){
					result =i;
					longestChainLength = count;
					std::cout<<result<<" produces the longest Chain, length: "<<longestChainLength<<std::endl;
				}
				break;
			}
		}
	}
	std::cout<<"result : "<<result<<std::endl;
}
