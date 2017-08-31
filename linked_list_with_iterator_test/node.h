#ifndef NODE_H
#define NODE_H
#include <iostream>

template<class T> class Linkedlist;//forward declare Linkedlist class as a template class
template<class T> class Node;
template<class T>
bool operator==(const Node<T>& n1, const Node<T>& n2);
template<class T> class Linkedlist_iterator;
template<class T> class Linkedlist_const_iterator;
template <class T>
class Node{
	friend class Linkedlist<T>;
	friend  bool operator==<T>(const Node<T>& n1, const Node<T>& n2);
	friend class Linkedlist_iterator<T>;
	friend class Linkedlist_const_iterator<T>;

private:
	Node<T>* next;
	T elem;
public:
	Node(const Node<T>& other){
		elem = other.elem;
		next = other.next;
	}
	Node(const T& other){
		elem = other;
		next = nullptr;
	}
	void print(){std::cout<<" "<< elem;}
	T getElem(){return elem;}
};

template<class T>
bool operator==(const Node<T>& n1, const Node<T>& n2){
	return(n1.elem == n2.elem);
}

#endif 
