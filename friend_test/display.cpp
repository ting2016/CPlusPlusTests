#include "classB.h"
#include "classA.h"
#include <iostream>

std::ostream& operator<<(std::ostream& o, const ClassA& ca){
  return o << ca.to_string() << std::endl;
}
/*
std::ostream& operator <<(std::ostream& o, const ClassB& cb){
    return o<< cb.to_string() << std::endl;
}
*/

//if call the private member in ClassB directly, will set this function as a friend function in ClassB
std::ostream& operator <<(std::ostream& o, const ClassB& cb){
    return o<< cb.a <<" " << cb.b << std::endl;
}

ClassA operator+(const ClassA& ca, const ClassB& cb){
    return ClassA(ca.a+cb.a, ca.b+cb.b);

}

ClassB operator+(const ClassB& cb, const ClassA& ca){
    return ClassB(ca.a+cb.a, ca.b+cb.b);

}
