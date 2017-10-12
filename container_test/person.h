#include <iostream>
#include <string>
class Person{
private:
        std::string name;
        int age;
public:
        
        Person(std::string name = "", int age = 0): name(name),age(age){};
        Person& operator=(const Person& p){ 
                name = p.name; 
                age = p.age; 
                return *this;
        }
        friend std::ostream& operator<<(std::ostream&, const Person& p);


};

std::ostream& operator<<(std::ostream& o, const Person& p){
        o<<"name: "<<p.name<<" age: "<<p.age<<std::endl;
        return o;
}

