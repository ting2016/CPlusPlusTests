#include <iostream>
int main(){
	int scale;
	std::cout<<"please enter the scale of the grid: ";
	std::cin>>scale;
	unsigned long routeNum =1;
	for(int i = 0;i<scale;i++){
		routeNum*=(scale*2-i);
		routeNum/=(i+1);
	}
	std::cout<<"there are : "<<routeNum<<" routes."<<std::endl;
}
