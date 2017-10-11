#ifndef LINKDELIST_H
#define LINKDELIST_H
#include "node.h"
#include <iostream>

template<class T>
class Linkedlist{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	typedef Linkedlist_iterator<T> Iterator;
	typedef Linkedlist_const_iterator<T> Const_Iterator;
	Linkedlist(const Linkedlist& l);
	Linkedlist(const Node<T>* newNode);
	Linkedlist();
	Linkedlist& operator=(Linkedlist& otherl);
	~Linkedlist();
	void empty();
	void print() const;
	void insertToHead(const T& newElem);
	void insertToTail(const T& newElem);
	Iterator begin(){return Iterator(head);}
	Iterator end(){ return Iterator();}
	Const_Iterator cbegin() const{return Const_Iterator(head);}
	Const_Iterator cend() const{return Const_Iterator();}
};

template<class T>
Linkedlist<T>::Linkedlist():head(nullptr), tail(nullptr){}
//copy constructor
template<class T>
Linkedlist<T>::Linkedlist(const Linkedlist& l):head(nullptr), tail(nullptr){
	Node<T>* tempP = l.head;
	if(tempP){
		tail = head = new Node<T>(tempP->elem);
		tempP = tempP->next;
	}
	while(tempP){
		tail->next = new Node<T>(tempP->elem);
		tempP = tempP->next;
		tail = tail->next;
	}
}

template<class T>
Linkedlist<T>::Linkedlist(const Node<T>* newNode):head(nullptr), tail(nullptr){
	if(newNode)
		head = tail = new Node<T>(newNode->elem);
}

//copy assignment
template<class T>
Linkedlist<T>& Linkedlist<T>::operator=(Linkedlist& otherl){
	if(this == &otherl)
		return *this;
	empty();
	Node<T>* tempP = otherl.head;
	if(tempP){
		tail = head = new Node<T>(tempP->elem);
		tempP = tempP->next;
	}
	while(tempP){
		tail->next = new Node<T>(tempP->elem);
		tempP = tempP->next;
		tail = tail->next;
	}
	
}

template<class T>
Linkedlist<T>::~Linkedlist(){
	empty();
}

template<class T>
void Linkedlist<T>::print() const{
	Node<T>* tempP = head;
	while(tempP){
		std::cout<<" "<<tempP->elem;
		tempP=tempP->next;
	}
	std::cout<<std::endl;
}

template<class T>
void Linkedlist<T>::empty(){
	Node<T>* tempP = head;
	while(head){
		head=head->next;
		delete tempP;
		tempP = head;
	} 
}

template<class T>
void Linkedlist<T>::insertToHead(const T& newElem){
	Node<T>* pn = new Node<T>(newElem);
	pn->next = head;
	head = pn;
	//tail was nullptr before insert to head
	if(head->next == nullptr){
		tail = head;
	}
}

template<class T>
void Linkedlist<T>::insertToTail(const T& newElem){
	Node<T>* pn = new Node<T>(newElem);
	if(tail==nullptr){
		pn->next = tail;
		tail = head = pn;
	}
	tail->next = pn;
	tail = tail->next;
}

#endif 
