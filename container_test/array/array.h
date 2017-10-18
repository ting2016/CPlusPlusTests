#ifndef TING_ARRAY_H 
#define TING_ARRAY_H

#include <cstddef>
#include <iostream>
namespace ting{
template<class T, size_t N>
class Array{
//new typedef for c++11
using value_type = T;
using reference = value_type&;
using const_reference = const value_type&;
using size_type = size_t;
using pointer = value_type*;
using const_pointer = const value_type*;

private:
	value_type array[N];
public:
	size_type size(){return N;}
	bool empty(){return (N==0);}
	reference operator[](size_type index){return array[index];}
	const_reference operator[](size_type index) const { return array[index];}
	reference at(size_type index){return array[index];}
	const_reference at(size_type index) const { return array[index];}
	reference front(){return array[0];}
	const_reference front() const { return array[0];}
	reference back(){ return array[N-1];}
	const_reference back() const { return array[N-1];}
	pointer data(){ return &array[0];}
	const_pointer data() const { return &array[0];}
	//can we use this loop for fixed size array?
	void fill(const value_type& v) {for(auto& e: array){e = v;}}
	void print() const { 
		for(auto& e: array){ 
			std::cout<<e<< " ";
		}
		std::cout<<std::endl;
	}
		
};//end of class Array
};//end of namespace ting

#endif
