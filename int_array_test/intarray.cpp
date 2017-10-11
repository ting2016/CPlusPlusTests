#include "intarray.h"
#include <assert.h>

int IntArray::getLength(){
    return m_length;
}

int IntArray::erase(){
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator [](int index){
    assert(index>=0&&index<m_length);
    return m_data[index];
}

// reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
void IntArray::reallocate(int newLength){
    erase();
    if(newLength<=0){
        return;
    }
    m_data = new int[newLength];
    m_length = newLength;
}

// resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
void IntArray::resize(int newLength){
    if(newLength == m_length){
        return;
    }
    if(newLength<=0){
        erase();
        return;
    }
    int *data = new int[newLength];
    if(m_length>0){
        int elemToCopy = newLength > m_length ? m_length : newLength;
        for(int i = 0; i< elemToCopy; i++){
            data[i] = m_data[i];
        }
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

void IntArray::insertAtBeginning(int value){

}
