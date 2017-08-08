#include "classA.h"
#include <iostream>

std::string ClassA::to_string() const{
    std::string  s = std::to_string(a) + " " + std::to_string(b);
    return s;
}

ClassA::ClassA(int a, int b){
    this->a = a;
    this->b = b;
}

ClassA::ClassA(int a){
    this->a = a;
}
