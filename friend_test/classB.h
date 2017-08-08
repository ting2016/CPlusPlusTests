#ifndef CLASSB_H
#define CLASSB_H
#include <string>
class ClassA;
class ClassB{
private:
        int a;
        int b;
 public:
        ClassB(int a, int b);
        std::string to_string() const;
        friend std::ostream& operator<<(std::ostream& o, const ClassB& cb);
        friend ClassA operator+(const ClassA& ca, const ClassB& cb);
        friend ClassB operator+(const ClassB& cb, const ClassA& ca);
};

#endif // CLASSB_H
