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
		return (p1.name<p2.name);
	return (p1.age<p2.age);
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

template<class It, class Compare>
void my_sort(It begin, It end, Compare comp){


}

template <class It>
void my_sort(It begin, It end){

}


int main(){
	int a[5]{2,5,1,8,6};
	std::vector<int> intV(a, a+5);
	std::sort(intV.begin(), intV.end());
	std::cout<<"after sort intv:\n";
	display(intV.cbegin(), intV.cend());
	
	std::vector<Person> personVec;
	personVec.push_back(Person(22,"lifang"));
	personVec.push_back(Person(37,"zhangting"));
	personVec.push_back(Person(25,"linlin"));
	personVec.push_back(Person(25, "liangliang"));
	std::cout<<"before sort personVec:\n";
	display(personVec.cbegin(), personVec.cend());
	//method1: using an object of compare class to do the comparision
	Compare_class<Person> compare_class;
	std::sort(personVec.begin(), personVec.end(), compare_class);
	//method2: using compare class to do the comparision
	//std::sort(personVec.begin(), personVec.end(),Compare_class<Person>());
	//method3: using compare function to do the comparison
	//std::sort(personVec.begin(), personVec.end(), compare_func<Person>);
	//mdthod4: using operator '<' as the comparator, you need to reload operator'<' for the objects to be sorted
	//std::sort(personVec.begin(), personVec.end());
	std::cout<<"after sort personVec:\n";
	display(personVec.cbegin(), personVec.cend());
}
