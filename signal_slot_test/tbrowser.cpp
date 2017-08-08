#include "tbrowser.h"
#include <iostream>
TBrowser::TBrowser(){

    connect(this,SIGNAL(sendSomething(String)), this, SLOT(printsomething(String)));
    sendSomething(s);


}

TBrowser::printSomething(string s){
    cout<<"the string sent from sendSomething is : "<<s<<endl;

}
