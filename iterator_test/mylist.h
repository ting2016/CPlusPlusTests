#ifndef MYLIST_H
#define MYLIST_H
#include "mylist_node.h"
#include "mylist_iterator.h"
template <class T>
class Mylist{
private:
	Mylist_node<T>* head;
	Mylist_node<T>* tail;
public:
	Mylist():head(nullptr), tail(nullptr){}
	~Mylist(){};
	bool empty() const{return head==nullptr;}
	void push_back(const T& t){
		Mylist_node<T> newNode(t, nullptr);
		if(head ==nullptr)
			head =  	
	}
	iterator begin();
	iterator end();
	
};

#endif
