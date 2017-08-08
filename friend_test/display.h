#ifndef DISPLAY_H
#define DISPLAY_H
#include <ostream>
class ClassA;
class ClassB;
std::ostream& operator<<(std::ostream& o, const ClassA& ca);
std::ostream& operator<<(std::ostream& o, const ClassB& cb);
ClassA operator+(const ClassA& ca, const ClassB& cb);
ClassB operator+(const ClassB& cb, const ClassA& ca);
#endif // DISPLAY_H
