#include "auto_ptr.h"
#include "resource.h"
Auto_ptr<Resource> generateResource()
{
	Auto_ptr<Resource> res(new Resource);
	
	return res; // this return value will invoke the move constructor
}
 
int main()
{
	Auto_ptr<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment
 
	return 0;
}

