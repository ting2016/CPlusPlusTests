#ifndef LINKEDLIST_ITERATOR_H
#define LINKEDLIST_ITERATOR_H
#include "node.h"
template<class T>
bool operator!=(const Linkedlist_iterator<T>& li1, const Linkedlist_iterator<T>& li2);
template<class T>
bool operator==(const Linkedlist_iterator<T>& li1, const Linkedlist_iterator<T>& li2);
template<class T>
class Linkedlist_iterator{

friend bool operator!=<T>(const Linkedlist_iterator<T>& li1, const Linkedlist_iterator<T>& li2);
friend bool operator==<T>(const Linkedlist_iterator<T>& li1, const Linkedlist_iterator<T>& li2);

private:
	Node<T>* currentPosition;
public:
	Linkedlist_iterator(Node<T>* pn):currentPosition(pn){};
	Linkedlist_iterator():currentPosition(nullptr){};
	Linkedlist_iterator& operator++();
	Linkedlist_iterator operator++(int);
	Node<T>& operator*();
};
template<class T>
bool operator!=(const Linkedlist_iterator<T>& li1, const Linkedlist_iterator<T>& li2){
	return li1.currentPosition!=li2.currentPosition;
}

template<class T>
bool operator==(const Linkedlist_iterator<T>& li1, const Linkedlist_iterator<T>& li2){
	return li1.currentPosition==li2.currentPosition;
}

template<class T>
Linkedlist_iterator<T>& Linkedlist_iterator<T>::operator++(){
	if(currentPosition!=nullptr){
		currentPosition = currentPosition->next;
	}
	return *this;
}

template<class T>
Linkedlist_iterator<T> Linkedlist_iterator<T>::operator++(int){
	Linkedlist_iterator<T> temp(*this);
	if(currentPosition!=nullptr)
		currentPosition=currentPosition->next;
	return temp;
}

template<class T>
Node<T>& Linkedlist_iterator<T>::operator*(){
	if(currentPosition!=nullptr)
		return *currentPosition;
	else
		std::cout<<"can not deference a NULL object!";
}
#endif
