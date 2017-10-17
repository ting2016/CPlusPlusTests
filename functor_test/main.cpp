#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//absValus is an functor,this class reload operator'()', we can use the object of it as a function
struct absValue{
	float operator()(float f){
		return (f>0)? f:-f;
	}

};

class Print {
public:
	void operator()(int elem) const {
		cout << elem << " ";
	}
};

template <int val>
void setValue(int& elem)
{
	elem = val;
}

template <typename T>
class PrintElements
{
public:
	void operator()(T& elm) const {cout << elm << ' ';}
};

int main () {
	//test1
	vector<int> vect;
	for (int i=1; i<10; ++i) {
		vect.push_back(i);
	}

	Print print_it;
	//the 3rd argument could be a functor, not just a regular function
	for_each (vect.begin(), vect.end(), print_it);
	cout << endl;
	//test2
	float f = -123.45;
	absValue aObject;
	std::cout<<"abs value for: "<< f <<" is " << aObject(f) <<std::endl;
	//test3
	int size = 5;
	vector<int> v(size);
        PrintElements<int> print;
	for_each(v.begin(), v.end(), print);
	for_each(v.begin(), v.end(), setValue<10>);
	for_each(v.begin(), v.end(), print);
}


