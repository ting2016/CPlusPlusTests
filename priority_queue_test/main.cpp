#include "priority_queue.h"

int main(){
	ting::Priority_queue<int> pq;
	pq.push(8);
	pq.display();
	pq.push(6);
	pq.display();
	pq.push(2);
	pq.display();
	pq.push(1);
	pq.display();
	pq.push(10);
	pq.display();
	pq.push(5);
	pq.display();
	std::cout<<"start pop"<<std::endl;
	pq.pop();
	pq.display();
	pq.pop();
	pq.display();
	pq.pop();
	pq.display();
	pq.pop();
	pq.display();
	pq.pop();
	pq.display();
}
