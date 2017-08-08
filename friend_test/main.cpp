#include "classA.h"
#include "classB.h"
#include "display.h"
#include <iostream>
int main(){
    ClassA A(1, 2);
    ClassB B(3, 4);
    ClassA C = A + B;
    ClassB D = B + A;
    std::cout << A;
    std::cout << B;
    std::cout << C;
    std::cout << D;
}
