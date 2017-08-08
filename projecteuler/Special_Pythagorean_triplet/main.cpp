#include <iostream>

int main(){
	int sum;
	std::cout<<"please enter the sum of these tree numbers: ";
	std::cin>>sum;
	for(int i = 0; i<sum/3;i++){
		for(int j=i+1;j<sum/2;j++){
			int k = sum-i-j;
			if (i*i + j*j==k*k){
				std::cout<<"special pythagorean triplet is found: a="<<i<<" b="<<j<<" c="<<k<<std::endl;
				std::cout<<"product is: "<<i*j*k<<std::endl;
			}
		}
	}
}
