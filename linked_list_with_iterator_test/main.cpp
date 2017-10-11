#include "linkedlist.h"
#include "linkedlist_iterator.h"
#include "linkedlist_const_iterator.h"
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
	std::cout<<"list1: ";
	for(auto iterator=list1.begin();iterator!=list1.end();iterator++){
		(*iterator).print();
	}
	std::cout<<std::endl;
	
	auto it1 = list1.begin();
	auto it4 = list4.begin();
	for(;it1!=list1.end()&&it4!=list4.end();){
		if((*it1)==(*it4)){
			std::cout<<"same\n";
			it1++;
			it4++;
		}
	}
	if(it1==list1.end()){
		std::cout<<"it1 reach the end of list1"<<std::endl;
	}
	if((it1==list1.end())&&(it4==list4.end()))
		std::cout<<"list1 and list4 is the same!"<<std::endl;
	auto it3 = list3.begin();
	//return 1, then move to second element
	std::cout<<"\nit3 now points to : ";
	(*(it3++)).print();
	std::cout<<std::endl;
	//move to third element, then return the third element
	std::cout<<"after move forward two steps, it3 now points to : ";
	(*(++it3)).print();
	std::cout<<std::endl;

	//test for const iterator
	const Linkedlist<int> const_list(list1);
	std::cout<<"const_list:";
	const_list.print();
	std::cout<<std::endl;
	auto const_it = const_list.cbegin();
	std::cout<<"const_list points to: ";
	//auto it = const_list.begin(); //this won't compile, a const object can not call a non-const member function
	(*const_it).print();
	(*(++const_it)).print();
	const_list.print();
	//*const_it=10;//this won't compile as, the pointer in linkedlist_const_iterator is set to const
	//const_list.print();
}
