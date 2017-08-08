#include "cents.h"
#include <iostream>

template<typename T>
const T& max(const T& x, const T& y){
	return(x<y)?y:x;
}

template<typename T>
const T& min(const T& x, const T& y){
	return(x<y)?x:y;
}

int main(){
	Cents dudu(12);
	Cents vivi(6);
	Cents bigger = max(dudu, vivi);
	std::cout<<"max is : " << bigger.getCents();
	bigger.setCents(100);
	std::cout<< "bigger after setting is : "<< bigger.getCents()<< std::endl;
	return 0;
}
