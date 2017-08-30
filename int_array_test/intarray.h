#ifndef INTARRAY_H
#define INTARRAY_H
class IntArray{
private:
    int m_length;
    int *m_data;
public:
    IntArray(): m_length(0), m_data(nullptr){}
    IntArray(int length): m_length(length){
        m_data = new int[length];
    }
    ~IntArray(){
        delete[] m_data;
    }
    void erase();
    int& operator[](int index);
    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength);
    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength();
};


#endif // INTARRAY_H
