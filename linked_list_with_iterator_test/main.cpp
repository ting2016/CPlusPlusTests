#include "linkedlist.h"
#include "node.h"
int main(){
	Linkedlist<int> list1;
	Node<int> newNode(5);
	Linkedlist<int> list2(&newNode);
	Linkedlist<int> list3;
	list3.insertToHead(3);
	list3.insertToHead(1);
	list3.insertToTail(5);
	list1 = list3;
	Linkedlist<int> list4(list1);
	list1.print();
	list2.print();
	list3.print();
	list4.print();
}
