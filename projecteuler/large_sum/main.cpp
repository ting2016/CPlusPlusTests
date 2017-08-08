#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
	std::ifstream ifs;
	std::vector<std::string> numberList;
	std::vector<int> sum;
	ifs.open("input.txt");
	while(ifs){
		std::string line;
		std::getline(ifs,line);
		if(line.size()==50)
			numberList.push_back(line);
	}
	std::cout<<"thare are altogether "<<numberList.size()<<" lines"<<std::endl;
	unsigned int left = 0;
	for(int i=49;i>=0;i--){
		unsigned int digitSum =left;
		for(std::size_t j =0;j<numberList.size();j++){
			std::cout<<" "<<numberList[j][i];
			digitSum+=(numberList[j][i]-'0');
		}
		std::cout<<"sum for digit "<<i<<" is "<<digitSum<<std::endl;
		sum.push_back(digitSum%10);
		left=(digitSum/10);
	}
	while(left>0){
		sum.push_back(left%10);
		left= left/10;
	}
	std::cout<<"the first ten digits of the sum is: ";
	for(int i=0;i<10;i++)
		std::cout<<sum.at(sum.size()-1-i)<<" ";	
	return 1;
}
