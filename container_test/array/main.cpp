#include "array.h"
#include "../person.h"

int main(){
  using namespace ting;
  const size_t size = 10;
  Array<Person, size> array_ting;
  const Array<Person,size> const_array_ting;
  array_ting.print();
  const_array_ting.print();
  Person newP1("zhangting", 30);
  Person newP2("wangmingn", 32);
  //const_array_ting[0] = newP1;//this won't compile, as const object has to be initialized at defination, which means for this case, we have to initialize name and age for class person 				 //in Person's constructor to create a const Array<Person, size> 
  array_ting[0] = newP1;
  array_ting.at(2) = newP2;
  array_ting.print();
	 
}
