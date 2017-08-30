#ifndef LINKEDLIST_ITERATOR_H
#define LINKEDLIST_ITERATOR_H
#include "node.h"
template<class T>
class Linkedlist_iterator{
private:
	Node<T>* currentPosition;
public:
	Linkedlist_iterator(Node<T>* p):currentPosition(p){}
	Linkedlist_iterator(const Linkedlist_iterator& other):currentPosition(other.currentPosition){}
	Linkedlist_iterator& operator++();
	Linkedlist_iterator operator++(int);
	Node<T>& operator*();
	bool operator==(const Linkedlist_iterator&);
	bool operator!=(const Linkedlist_iterator&);
};

template<class T>
Linkedlist_iterator<T>& Linkedlist_iterator<T>::operator++(){
	currentPosition++;
	return *this;
}

template<class T>
Linkedlist_iterator<T> Linkedlist_iterator<T>::operator++(int){
	Linkedlist_iterator<T> temp(*this);
	currentPosition++;
	return temp;
}

template<class T>
bool Linkedlist_iterator<T>::operator==(const Linkedlist_iterator<T>& other){
	return(currentPosition==other.currentPosition);
}	

template<class T>
bool Linkedlist_iterator<T>::operator!=(const Linkedlist_iterator<T>& other){
	return(currentPosition!=other.currentPosition);
}

template<class T>
Node<T>& Linkedlist_iterator<T>::operator*(){
	return *currentPosition;
}
#endif
