#ifndef TING_VECTOR_H
#define TING_VECTOR_H
#include <memory>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
namespace ting{
template<class T, class Alloc = std::allocator <T>>
class Vector{
using value_type = T;
using allocator_type = Alloc;
using reference = value_type&;
using const_reference = const value_type&;
using pointer = std::allocator_traits<Alloc>::pointer;
using const_pointer = std::allocator_traits<Alloc>::const_pointer;
using size_type = std::size_t;
using iterator = std::iterator<random_access_iterator_tag, value_type>;
using const_iterator = const iterator;
using reverse_iterator = std::reverse_iterator<iterator>;
using const_reverse_iterator = std::reverse_iterator<const_iterator>;
using difference_type = std::ptrdiff_t;

private:
	pointer data;
	size_type size;
	size_type capacity;
	allocator_type alloc;
public:
	explicit Vector(const allocator_type& alloc = allocator_type()):alloc(alloc){size = 0; capacity = 0;}
	Vector(size_type n, const value_type& val, const allocator_type& alloc = allocator_type()):size(n),capacity(n),alloc(alloc){
		data = new T[size];
		for(size_type i =0; i<size;i++){
			 data[i] = val;
		}
	}

	template< class InputIt>
	Vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()){
		size = capacity = difference_type(last - first);
		data = new value_type[size];
		InputIt temp;
		size_type  i;
		for(temp = first, i = 0;temp!=last; temp++,i++){
			data[i] = static_cast<value_type>(*temp);
		}
	}

	~Vector(){ delete []data;}

	allocator_type get_allocator() const{
		return alloc;
	}

	void print() const{
	for(size_type i = 0; i<size; i++){
		std::cout<<data[i]<<" ";
	}
	std::cout<<std::endl;
	}
	
	
};
};
#endif
