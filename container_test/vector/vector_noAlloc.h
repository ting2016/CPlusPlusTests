#ifndef TING_VECTOR_H
#define TING_VECTOR_H
#include <memory>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
namespace ting{
template<class T>
class Vector{
using value_type = T;
using reference = value_type&;
using const_reference = const value_type&;
using pointer = T*;
using const_pointer = const pointer;
using size_type = std::size_t;
using iterator = T*;
using const_iterator = const iterator;
using difference_type = std::ptrdiff_t;

private:
	pointer data;
	size_type size;
	size_type capacity;
public:
	explicit Vector(){size = 0; capacity = 0;}
	Vector(size_type n, const value_type& val):capacity(n),size(n){
		data = new T[size];
		for(size_type i =0; i<size;i++){
			 data[i] = val;
		}
	}

	template< class InputIt>
	Vector(InputIt first, InputIt last){
		size = capacity = difference_type(last - first);
		data = new value_type[size];
		InputIt temp;
		for(temp = first;temp!=last; temp++){
			*data = *temp;
		}
	}

	~Vector(){ delete []data;}
	
	void print() const{
		for(size_type i = 0; i<size; i++){
			std::cout<<data[i]<<" ";
	}
	std::cout<<std::endl;
	}
	
};
};
#endif
