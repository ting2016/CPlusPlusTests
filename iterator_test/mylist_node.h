#ifndef MYLIST_NODE
#define MYLIST_NODE

template <class T>
class Mylist_node{
private:
	T value;
	Mylist_node<T>* next;
public:
	Mylist_node(const T& t, Mylist_node<T>* next):value(t),next(next){}
	~Mylist_node();
};

#endif
