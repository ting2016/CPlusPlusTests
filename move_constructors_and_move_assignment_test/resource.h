#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
class Resource
{
public:
	Resource(){
		std::cout<<"Resource acquired\n";
	}
	~Resource(){
		std::cout<<"Resource destroyed\n";
	}

};
#endif
