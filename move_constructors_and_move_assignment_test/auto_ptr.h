#ifndef AUTO_PTR_H
#define AUTO_PTR_H
#include <iostream>
template<class T>
class Auto_ptr{
	private:
		T* m_ptr;
	public:
		Auto_ptr(T* ptr = nullptr):m_ptr(ptr){
			std::cout<<"Auto_ptr: default constructor is called"<<std::endl;
		}
		~Auto_ptr(){
			std::cout<<"Auto_ptr: destructor is called"<<std::endl;
			delete m_ptr;
		}
		//copy constructor
		Auto_ptr(const Auto_ptr& a);
		//copy assignment
		Auto_ptr& operator=(const Auto_ptr& a);
		//move constructor
		Auto_ptr(Auto_ptr&& a);
		//move assignmet
		Auto_ptr& operator=(Auto_ptr&& a);
		T& operator*() const;
		T* operator->() const;
		bool isNull() const;
};

#include "auto_ptr.h"
template<class T>
//copy constructor
Auto_ptr<T>::Auto_ptr(const Auto_ptr& a){
	std::cout<<"Auto_ptr: copy constructor is called"<<std::endl;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
}
//copy assignment
template<class T>
Auto_ptr<T>& Auto_ptr<T>::operator=(const Auto_ptr& a){
	std::cout<<"Auto_ptr: copy assignment is called"<<std::endl;
        if(&a == this)
                return *this;
        delete m_ptr;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
        return *this;
}

template<class T>
bool Auto_ptr<T>::isNull() const {
        return (m_ptr==nullptr);
}

template<class T>
T& Auto_ptr<T>::operator*() const {
        return *m_ptr;
}

template<class T>
T* Auto_ptr<T>::operator->() const {
        return m_ptr;
}
//move constructor
template<class T>
Auto_ptr<T>::Auto_ptr(Auto_ptr&& a):m_ptr(a.m_ptr){
	std::cout<<"Auto_ptr: move constructor is called"<<std::endl;
        a.m_ptr = nullptr;
}
//move assignement
template<class T>
Auto_ptr<T>& Auto_ptr<T>::operator=(Auto_ptr&& a){
	std:: cout<<"Auto_ptr: move assignment is called"<<std::endl;
        if(this==&a)
                return *this;
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
}

#endif
