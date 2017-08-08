#include "classB.h"
#include <iostream>

std::string ClassB::to_string() const{
    std::string  s = std::to_string(a) + " " + std::to_string(b);
    return s;
}

ClassB::ClassB(int a, int b){
    this->a = a;
    this->b = b;
}
