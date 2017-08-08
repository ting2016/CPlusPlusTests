#ifndef DOG_H
#define DOG_H
#include <string>
class Dog: public Animal{
public:
    Dog(std::string name):Animal(name){}
    const char* speak(){return "woof";}
};

#endif // DOG_H
