#include "intArray.h"

int main(){
	IntArray a1;
	IntArray a2(5);
	IntArray a3{1,2,3,4,5};
	a2 = a3;
	a1.display();
	a2.display();
	a3.display();

}
