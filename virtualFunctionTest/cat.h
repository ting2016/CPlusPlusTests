#ifndef CAT_H
#define CAT_H
class Cat: public Animal{
public:
    Cat(std::string name):Animal(name){}
    virtual const char* speak(){ return "meow";}
};

#endif // CAT_H
