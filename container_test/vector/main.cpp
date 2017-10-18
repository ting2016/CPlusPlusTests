//#include "vector.h"
#include "vector_noAlloc.h"
#include "../person.h"

int main(){
	using namespace ting;
	Vector<int> v1;
	v1.print();
	Vector<int> v2(4, 0);
	v2.print();
}
