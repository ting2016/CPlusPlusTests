#include "counter.h"
#include <iostream>
using namespace std;
int main()
{
    Counter a, b;
        QObject::connect(&a, SIGNAL(valueChanged(int)),
                         &b, SLOT(setValue(int)));

        a.setValue(12);     // a.value() == 12, b.value() == 12
        cout<<"b value : "<<b.value()<<endl;
        b.setValue(48);     // a.value() == 12, b.value() == 48
        cout<<"b value second time: "<<b.value()<<endl;


}
