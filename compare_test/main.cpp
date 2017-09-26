#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Person{
private:
	int age;
	std::string name;
public:
	Person(int age, std::string name):age(age),name(name){}
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	friend bool operator<(const Person& p1, const Person& p2);
};

bool operator<(const Person& p1, const Person& p2){
	if(p1.age==p2.age)
		return p1.name<p2.name;
	else
		return p1.age<p1.age;
}

std::ostream& operator<<(std::ostream& os, const Person& p){
	os<<" age: "<<p.age<<" name: "<<p.name<<std::endl;
	return os;
}


template<class T>
class Compare_class{
public:
	bool operator()(const T& t1, const T& t2){
		return t1<t2;
	}
};

template<class T>
bool compare_func(const T& t1, const T& t2){
	return t1<t2;
}	

template<class It>
void display(const It begin, const It end){
	for(auto it = begin; it!=end;it++){
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}


int main(){
	std::vector<Person> personVec;
	personVec.push_back(Person(22,"lifang"));
	personVec.push_back(Person(37,"zhangting"));
	personVec.push_back(Person(25,"linlin"));
	std::sort(personVec.begin(), personVec.end());
	display(personVec.cbegin(), personVec.cend());
}
