#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
class Animal{
protected:
    std::string m_name;
    Animal(std::string name):m_name(name){}
public:
    std::string getName(){ return m_name;}
    virtual const char* speak(){return "???";} //need to be virtual to support polymorphism
};

#endif // ANIMAL_H
