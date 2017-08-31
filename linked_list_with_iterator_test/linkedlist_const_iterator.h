#ifndef LINKEDLIST_CONST_ITERATOR_H 
#define LINKEDLIST_CONST_ITERATOR_H
#include "node.h"
template<class T>
bool operator!=(const Linkedlist_const_iterator<T>& li1, const Linkedlist_const_iterator<T>& li2);
template<class T>
bool operator==(const Linkedlist_const_iterator<T>& li1, const Linkedlist_const_iterator<T>& li2);
template<class T>
class Linkedlist_const_iterator{

friend bool operator!=<T>(const Linkedlist_const_iterator<T>& li1, const Linkedlist_const_iterator<T>& li2);
friend bool operator==<T>(const Linkedlist_const_iterator<T>& li1, const Linkedlist_const_iterator<T>& li2);

private:
	const Node<T>* currentPosition;
public:
	Linkedlist_const_iterator(Node<T>* pn):currentPosition(pn){};
	Linkedlist_const_iterator():currentPosition(nullptr){};
	Linkedlist_const_iterator& operator++();
	Linkedlist_const_iterator operator++(int);
	Node<T>& operator*();
};

template<class T>
bool operator!=(const Linkedlist_const_iterator<T>& li1, const Linkedlist_const_iterator<T>& li2){
	return li1.currentPosition!=li2.currentPosition;
}

template<class T>
bool operator==(const Linkedlist_const_iterator<T>& li1, const Linkedlist_const_iterator<T>& li2){
	return li1.currentPosition==li2.currentPosition;
}

template<class T>
Linkedlist_const_iterator<T>& Linkedlist_const_iterator<T>::operator++(){
	if(currentPosition!=nullptr){
		currentPosition = currentPosition->next;
	}
	return *this;
}

template<class T>
Linkedlist_const_iterator<T> Linkedlist_const_iterator<T>::operator++(int){
	Linkedlist_const_iterator<T> temp(*this);
	if(currentPosition!=nullptr)
		currentPosition=currentPosition->next;
	return temp;
}

template<class T>
Node<T>& Linkedlist_const_iterator<T>::operator*(){
	if(currentPosition!=nullptr)
		return *currentPosition;
	else
		std::cout<<"can not deference a NULL object!";
}
#endif
