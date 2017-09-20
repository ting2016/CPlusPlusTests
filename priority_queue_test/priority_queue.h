#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include <exception>
#include <vector>
#include <iostream>
namespace ting{
		template<class T>
		class Priority_queue{
		private:
			std::vector<T> m_vec;
			void heapify(int index);
			int getLChild(int index);
			int getRChild(int index);
			int getParent(int index);
		public:
			int size() const;		
			void pop();
			const T& top() const;
			void push(const T& t);
			bool empty() const;
			void buildHeap();
			void display();
		};
}

template<class T>
void ting::Priority_queue<T>::display(){
	for(auto it = m_vec.cbegin();it!=m_vec.cend();it++)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
}

//return left child index, if no left child, return -1
template<class T>
int ting::Priority_queue<T>::getLChild(int index){
	if(index<0||index>m_vec.size()-1)
		throw std::exception();
	int l = 2*index +1;
	if(l<m_vec.size())
		return l;
	else
		return -1;
}

//return right child's index, if no right child, return -1
template<class T>
int ting::Priority_queue<T>::getRChild(int index){
	if(index<0||index>m_vec.size()-1)
		throw std::exception();
	int r = 2*index +2;
	if(r<m_vec.size())
		return r;
	else
		return -1;

}
//return the parent's index, if no parent, return -1
template<class T>
int ting::Priority_queue<T>::getParent(int index){
	if(index<0||index>m_vec.size()-1)
		throw std::exception();
	if(index!=0){
		int p =  (index -1)/2;
		return p;
	}
	else{
		return -1;
	}
}
template<class T>
int ting::Priority_queue<T>::size() const{
	return m_vec.size();
}

template<class T>
const T& ting::Priority_queue<T>::top() const {
	if(m_vec.size()>0){
		return m_vec[0];
	}
	else{
		throw std::exception();
	}
}

template<class T>
bool ting::Priority_queue<T>::empty() const{
	return m_vec.empty();
}

template<class T>
void ting::Priority_queue<T>::push(const T& t){
	m_vec.push_back(t);
	buildHeap();
}

template<class T>
void ting::Priority_queue<T>::pop(){
	if(!m_vec.empty()){
		m_vec.erase(m_vec.begin());
		buildHeap();
	}
	else{
		throw std::exception();
	}
}

//assume the children of given index are heapify, heapify the sub tree which has index as to//ot
template<class T>
void ting::Priority_queue<T>::heapify(int index){
	if(index<0||index>m_vec.size()-1)
		throw std::exception();
	int l = getLChild(index);
	int r = getRChild(index);
	//index is a leave
	if((l==-1)&&(r==-1))
		return;
	int max = index;
	if(l!=-1){
		if(m_vec[l]>m_vec[max])
			max = l;
	}
	if(r!=-1){
		if(m_vec[r]>m_vec[max])
			max = r;
	}
	if(max!=index){
		std::swap(m_vec[index], m_vec[max]);
		heapify(max);
	}	
}

template<class T>
void ting::Priority_queue<T>::buildHeap(){
	if(m_vec.size()==1)
		return;
	//heapify every non-leave node
	for(int i = m_vec.size()/2 -1;i>=0;i--){
		heapify(i);
	}

}

#endif
