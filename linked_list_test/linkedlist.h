#ifndef LINKDELIST_H
#define LINKDELIST_H
#include "node.h"

template<class T>
class Linkedlist{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	Linkedlist(const Linkedlist& l);
	Linkedlist(const Node<T>* newNode);
	Linkedlist();
	Linkedlist& operator=(Linkedlist& otherl);
	~Linkedlist();
	void push_back(const Node<T>& newNode);
};

template<class T>
Linkedlist<T>::Linkedlist(const Linkedlist& l){

}

#endif 
