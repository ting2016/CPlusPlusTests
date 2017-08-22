#ifndef SORTS_H
#define SORTS_H
#include <vector>
#include <iostream>

namespace ting{
	namespace sorts{
		template <class T>
		void bubbleSort(std::vector<T>&);
		template <class T>
		void insertSort(std::vector<T>&);
		template <class T>
		void selectSort(std::vector<T>&);
		template <class T>
		void mergeSort(std::vector<T>&);
		template <class T>
		void shellSort(std::vector<T>&);
		template <class T>
		void quickSort(std::vector<T>&);
		void sortTest();
		template <class T>
		void display(const std::vector<T>&);
		template<class T>
		void  merge(std::vector<T>& v, int low, int mid, int high);
		template<class T>
		void mergeSort(std::vector<T>& v, int low, int high);
	}
}

template <class T>
void ting::sorts::display(const std::vector<T>& v){
	std::cout<<"[ ";
	for(auto it = v.cbegin(); it!=v.cend();it++){
		std::cout<<*it<<" ";
	}
	std::cout<<"]\n";
}

template <class T>             
void ting::sorts::bubbleSort(std::vector<T>& v){
	for(int i = 0; i<v.size()-1;i++){
		for(int j=0; j<v.size()-i-1;j++){
			if(v[j]>v[j+1])
				std::swap(v[j],v[j+1]);	
		}
	}
}

template <class T>
void ting::sorts::insertSort(std::vector<T>& v){
	for(int i=0;i<v.size();i++){
		for(int j=i;j>0;j--){
			if(v[j]>v[j-1]){
				std::swap(v[j],v[j-1]);
				
			}
		
		}
	}
}

template <class T>
void ting::sorts::selectSort(std::vector<T>& v){
	for(int i =0; i<v.size();i++){
		for(int j =i+1;j<v.size();j++){
			if(v[j]<v[i]){
				std::swap(v[i],v[j]);
			}
		}
	}
}
template <class T>
//low is the index  the first element, high is the index of last element
void  ting::sorts::merge(std::vector<T>& v,int low, int mid, int high){
	if(low == high)
		return ;
	std::vector<T> sortedV;
	 auto p1 = v.begin()+low;
	 auto  p2 = v.begin()+mid+1;
	while(p1!=v.begin()+mid+1&&p2!=v.begin()+high +1){
		if(*p1<=*p2){
			sortedV.push_back(*p1);
			p1++;
		}
		else{
			sortedV.push_back(*p2);
			p2++;
		}
	}
	if(p1!=v.begin()+mid +1){
		while(p1!=v.begin()+mid+1){
			sortedV.push_back(*p1);
			p1++;
		}
	}
	else if(p2!=v.begin()+high +1){
		while(p2!=v.begin()+high+1){
			sortedV.push_back(*p2);
			p2++;
		}
	}
	for(int i = 0,index = low ;i<sortedV.size();i++, index++){
	
		v[index ]= sortedV[i];
	}
}

template <class T>
void ting::sorts::mergeSort(std::vector<T>& v,int low, int high){
	if(low==high)
		return;
	int mid = low + (high-low)/2; 
	mergeSort(v, low, mid);
	mergeSort(v, mid+1, high);
	merge(v,low, mid, high);
	
}

template <class T>
void ting::sorts::shellSort(std::vector<T>&){
}

template <class T>
void ting::sorts::quickSort(std::vector<T>&){
}

void ting::sorts::sortTest(){
	
}












#endif
