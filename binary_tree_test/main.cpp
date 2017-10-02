#include "binary_tree.h"

int main(){
    Binary_tree<int> mybst;
    mybst.insert(1);
    //std::cout<<mybst.getRootElem()<<std::endl;
    mybst.insert(5);
    mybst.insert(2);
    mybst.insert(10);
    mybst.insert(6);
    mybst.insert(3);
    mybst.print();
    //test for erase a node with both lchid and rchild
    //mybst.erase(5);
    //test for erase a node with only rchild
    //mybst.erase(2);
    int e = 9;
    Node<int>* node =mybst.find(e);
    if(node)
        std::cout<<"find elem :" << node->getElem() << std::endl;
    else
        std::cout<<"elem: "<<e << " not found." << std::endl;
    mybst.print();

}
