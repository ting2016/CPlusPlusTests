#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main(){
	std::string maxS;
	std::string minS;
	int digitNum;
	std::cout<< "please enter digit numbrer: ";
	std::cin >>digitNum;
	for(int i = 0;i<digitNum;i++){
		maxS.push_back('9');
	}
	if(digitNum<=1){
		minS.push_back('0');
	}
	else{
		minS.push_back('1');
	}
	for(int i = 0;i<digitNum-1;i++){
		minS.push_back('0');
	}
	int maxV = std::atoi(maxS.c_str());
	int minV = std::atoi(minS.c_str());
	std::vector<int> pllist;
	std::cout<<"max value is: " << maxV;
	std::cout<<"min value is: " <<minV;
	int tempV1, tempV2;
	tempV1 = tempV2 = maxV;
	while(tempV1>=minV){
		while(tempV2>=minV){
			int mult = tempV1*tempV2;
			std::string multS = std::to_string(mult);
			//std::cout<<"product of: "<<tempV1<<" with "<<tempV2<<" is: "<<multS<<std::endl;
			std::string multSR = multS;
			std::reverse(multSR.begin(), multSR.end());
			//std::cout<<" reverse of product is: "<<multSR<<std::endl;
			if(multS==multSR){
				std::cout<<"find a palindrome: "<<multS<<std::endl;
				pllist.push_back(mult);
			}
			tempV2--;
		}
		tempV2 = maxV;
		tempV1--;
	}
	std::sort(pllist.begin(), pllist.end());
	int largestPl = pllist.at(pllist.size()-1);
	std::cout<< "the largest palindrome is: " << largestPl;

	return 1; 
}

