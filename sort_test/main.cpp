#include "sorts.h"
#include <vector>

int main(){
	using namespace ting::sorts;
	std::vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(10);
	v.push_back(1);
	v.push_back(8);
	v.push_back(5);
	v.push_back(3);
	v.push_back(0);
	v.push_back(6);
	v.push_back(7);
	v.push_back(9);
	//display(v);
	//bubbleSort(v);
	//insertSort(v);
	//selectSort(v);
	//mergeSort(v,0, v.size()-1);
	//shellSort(v);
	//quickSort(v,0, v.size()-1);
	//std::cout<<"after bubble sort:\n";
	//display(v);
	heapSortTest();
}
