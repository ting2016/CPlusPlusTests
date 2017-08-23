#include <initializer_list>

class IntArray{
private:
	int m_length;
	int* m_data;
public:
	IntArray():m_length(0),m_data(nullptr){
	}
	IntArray(int length);
	IntArray(const std::initializer_list<int>& list);
	~IntArray();
	int& operator[](int index);
	int getLength();
	void display();
	IntArray& operator=(const IntArray& other);
};
