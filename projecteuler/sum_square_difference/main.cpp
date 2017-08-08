#include <iostream>
#include <assert.h>
int sum_square(int num){
	assert(num>=1);
	int sum =0;
	for(int i = 1; i<=num;i++){
		sum+=(i*i);
	}
	return sum;
}

int square_sum(int num){
	assert(num >= 1);
	int sum =0;
	for(int i = 1; i<=num;i++){
		sum+=i;
	}
	sum*=sum;
	return sum;
}
int main(){
	int num;
	int diff;
	std::cout<<"please enter the number of natural nubmers: ";
	std::cin >> num;
	diff = square_sum(num)-sum_square(num);
	std::cout<<"the diff is: "<< diff<<std::endl;
	return 1;
}
