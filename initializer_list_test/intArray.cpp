#include "intArray.h"
#include <cassert>
#include <iostream>

IntArray::IntArray(int length){
	m_length = length;
	m_data = new int[m_length];
}

IntArray::IntArray(const std::initializer_list<int>& list):IntArray(list.size()){
	int count = 0;
	for(auto& element: list){
		m_data[count]=element;
		count++;
	}
}

int& IntArray::operator[](int index){
	assert(index>=0&&index<m_length);
	return m_data[index];
}

int IntArray::getLength(){
	return m_length;
}

void IntArray::display(){
	for(int i = 0; i<m_length;i++){
		std::cout<<""<<m_data[i];
	}
	std::cout<<std::endl;
}

IntArray& IntArray::operator=(const IntArray& other){
	if(this == &other)
		return *this;
	delete[] m_data;
	m_length = other.m_length;
	m_data = new int[m_length];
	for(int i =0;i<m_length;i++){
		m_data[i] = other.m_data[i];	
	}
	return *this;
}
IntArray::~IntArray(){
	delete[] m_data;
}
