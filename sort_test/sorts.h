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
		int partitionForQuick(std::vector<T>&,const int& left, const int& right);
		template <class T>
		void quickSort(std::vector<T>&, int left, int right);
		void sortTest();
		template <class T>
		void display(const std::vector<T>&);
		template<class T>
		void  merge(std::vector<T>& v, int low, int mid, int high);
		template<class T>
		void mergeSort(std::vector<T>& v, int low, int high);
		template<class T>
		void heapSort(std::vector<T>& v);
		template<class T>
		void buildMaxHeap(std::vector<T>& v);
		template<class T>
		void heapify(std::vector<T>& v,int n, int i);
		void heapSortTest();
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
void ting::sorts::shellSort(std::vector<T>& v){
	for(int interval = v.size()/2; interval > 0;interval/=2){
		for(int i = interval; i<v.size();i++){
			for(int j=i-interval;j>=0;j-=interval){
				if(v[i]<v[j]){
					std::swap(v[i],v[j]);
				}	
			}
		}	
}
}

//left point the the left first element to be sorted, right points to the right element to be sorted
template <class T>
void ting::sorts::quickSort(std::vector<T>& v,int left, int right){
	if(left>=right)
		return;
	int pivotPosition = partitionForQuick(v, left, right);
	quickSort(v, left, pivotPosition-1);
	quickSort(v, pivotPosition+1, right);
}

template <class T>
int ting::sorts::partitionForQuick(std::vector<T>& v, const int& left, const int& right){
	int leftPoint = left;
	int rightPoint = right -1;
	int pivot = v[right];
	while(true){
		while((v[leftPoint]<pivot)&&(left<right))
			leftPoint++;
		while((v[rightPoint]>=pivot)&&(rightPoint>left))
			rightPoint--;
		if(leftPoint>=rightPoint)
			break;
		else{
			std::swap(v[leftPoint],v[rightPoint]);
			leftPoint++;
			rightPoint++;
		}
	}
	if(v[leftPoint]>=v[right]){
		std::swap(v[leftPoint],v[right]);
		return leftPoint;
	}
	else{
		std::swap(v[leftPoint+1], v[right]);
		return leftPoint +1;
	}
}
// heapify sub_tree of v the subtrees of which are alreay maxheaps:  n is the max index, i is the index for the root
template<class T>
void ting::sorts::heapify(std::vector<T>& v, int n, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if((l<=n)&&(v[l]>v[largest])){
		largest = l;
	}
	if(r<=n&&(v[r]>v[largest])){
		largest =r;
	}
	if(largest!=i){
		std::swap(v[i],v[largest]);
		heapify(v,n, largest);
	}
	
	
}

template<class T>
void ting::sorts::buildMaxHeap(std::vector<T>& v){
	//heapify only non_leaf nodes from below to top
	for(int i = v.size()/2 -1; i>=0; i--){
		heapify(v,v.size()-1, i);
	}
}
//do heapsort upon built heap
template<class T>
void ting::sorts::heapSort(std::vector<T>& v){
	buildMaxHeap(v);
	display(v);
	//i start as the max index of v
	int i = v.size()-1;
	while(i>0){
		//make v[i] as the max of elems from index 0 to i
		std::swap(v[0], v[i]);
		//heapify elems before index i
		heapify(v,i-1, 0);
		i--;
	}
}


void ting::sorts::heapSortTest(){
	std::vector<int> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(1);
	v.push_back(10);
	v.push_back(18);
	v.push_back(12);
	v.push_back(5);
	heapSort(v);
	display(v);
	
}













#endif
