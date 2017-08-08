#ifndef CLASSA_H
#define CLASSA_H
#include <string>
class ClassB;
class ClassA{
private:
        int a;
        int b; // if initialize, will assign some random value
public:
        ClassA(int a, int b);
        ClassA(int a);
        std::string to_string() const;
        friend ClassA operator+(const ClassA& ca, const ClassB& cb);
        friend ClassB operator+(const ClassB& cb, const ClassA& ca);
};
#endif // CLASSA_H
