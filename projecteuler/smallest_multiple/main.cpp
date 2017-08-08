#include <iostream>
int main(){
	int init = 1;
	while(true){
		int i;
		for(i = 1; i<=20; i++){
			if(init%i!=0){
				init++;
				i = 1;
				break;
			}
		}	
		if(i>20){
			std::cout<< "find the smalleset positive number evenly divisible by number from 1 to 20: "<< init <<std::endl;
			break;
		}
	}
}
