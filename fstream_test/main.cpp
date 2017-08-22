#include <fstream>
#include <iostream>

int main(){
	using namespace std;
	ifstream ifs("test.txt");
	if(!ifs){
		cerr<<" can not open test.txt "<<endl;
	}
	while(ifs){
		std::string sinput;
		//ifs>>sinput; //this read word by word;
		getline(ifs, sinput);//this read line by line
		cout<< sinput;
		cout<<endl;
	}
	ofstream ofs("test.txt", ios::app);
	ofs<<"add a new line\n";
	ofs<<"add another new line\n";
	return 1;

}
