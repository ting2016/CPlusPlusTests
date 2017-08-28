#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
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
	
};

#endif 
