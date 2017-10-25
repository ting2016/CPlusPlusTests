#include "auto_ptr.h"
#include "resource.h"
#include <utility>
Auto_ptr<Resource> generateResource()
{
	Auto_ptr<Resource> res(new Resource);//this will invoke default constructor
	
	return res; // this return value will invoke the move constructor, why?
	//explain:  it is moved instead of copied, even though res is an l-value. The C++ specification has a special rule that says automatic objects returned from a function by value         //can be moved even if they are l-values
	//note: compiler may elide the return value from function generateResource(), so the move constructor will not be called for this case 
}
 
int main()
{
	Auto_ptr<Resource> mainres;//this will invoke default constructor
	mainres = generateResource(); // this assignment will invoke the move assignment, as the return value of generateResource() is an r-value
 	/************************************************/
	Auto_ptr<Resource> mainres2(mainres);//this will invoke copy constructor 
	/*****************************************************/
	Auto_ptr<Resource> mainres3;//this will invode default constructor
	mainres3 = mainres;//this will invoke copy assignment
	/****************************************************/
	Auto_ptr<Resource> mainres4(std::move(mainres));//this will invoke move constructor
	return 0;
}

