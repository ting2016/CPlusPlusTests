#include <iostream>
using namespace std;

int f1(int i) {
    return i;
}

int f2(int i) {
    return i*2;
}

typedef int (*fptr)(int);


fptr f( char c ) {
    if ( c == '1' ) {
        return f1;
    }
    else {
        return f2;
    }
}

int main() {
    char c = '1';
    fptr fp = f( c );
    fptr fp2 =f2;
    cout << fp(1) << endl;
    cout << fp2(2) << endl;
}

