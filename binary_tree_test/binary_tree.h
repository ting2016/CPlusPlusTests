#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
//assume there are no two nodes have the same elem value
template<class T> class Binary_tree;
template<class T>
class Node{
friend class Binary_tree<T>;
private:
    T elem;
    Node* lchild;
    Node* rchild;
public:
    Node(const T& e):elem(e), lchild(nullptr), rchild(nullptr){}
    const T& getElem() const {return elem;}
};

template <class T>
class Binary_tree{
private:
    Node<T>* root;
    int size;
public:
    Binary_tree(){root = nullptr;size = 0;}
    ~Binary_tree();
    void insert(const T& e);
    void print() const;
    Node<T>* find(const T& e) const;
    void erase(const T& e);
    bool empty() const;
    const T& getRootElem() const;
private:
    void insert(const T& e, Node<T>*& r);
    void erase(const T& e, Node<T>* r, Node<T>* p=nullptr);
    void print(const Node<T>* r) const;
    Node<T>* find(const T&e, Node<T>* r) const;
    //assume r has rchild, which means r is not nullptr
    void getMinOfRchild(Node<T>* r, Node<T>*& minRchild, Node<T>*& pOfMinRchild=nullptr) const;
    Node<T>* getParent(const Node<T>* r) const;
    //interchange the contents of n1 and n2
    void swap(Node<T>* n1, Node<T>* n2);
    void eraseTree(const Node<T>* r);

};

template<class T>
void Binary_tree<T>::insert(const T&e){
    insert(e, root);
}

template<class T>
void Binary_tree<T>::print() const{
    print(root);
    std::cout<<std::endl;
}

template<class T>
void Binary_tree<T>::erase(const T& e){
    erase(e, root);
}

template<class T>
Node<T>* Binary_tree<T>::find(const T&e) const{
    return find(e, root);
}

//reference must be used for r to made sure every new node is created as a part of the bst
template<class T>
void Binary_tree<T>::insert(const T& e, Node<T>*& r){
    std::cout<<"e: "<< e <<std::endl;
    if(r!=nullptr){
        //do insert at lchid
        if(e<r->elem){
            std::cout<<"do insert on lchild"<<std::endl;
            insert(e, r->lchild);
        }
        //do insert at rchild
        else{
            std::cout<<"do insert on lchild"<<std::endl;
            insert(e, r->rchild);
        }
    }
    else{
        std::cout<<"creat new node"<<std::endl;
        r = new Node<T>(e);
        size++;
        return;
    }

}

//print bst from min to max,first lchild, then root, last rchild
template<class T>
void Binary_tree<T>::print(const Node<T>* r) const {
    if(r!=nullptr){
        print(r->lchild);
        std::cout<<r->elem<<" ";
        print(r->rchild);
    }
    //empty tree
    else{
        return;
    }
}

template<class T>
Node<T>* Binary_tree<T>::find(const T&e, Node<T>* r) const {
    if(r){
        // find
        if(r->elem==e){
            return r;
        }
        if(e<r->elem){
            find(e, r->lchild);
        }
        else{
            find(e, r->rchild);
        }

    }
    else{
        // not find
        return nullptr;
    }

}

template<class T>
bool Binary_tree<T>::empty() const{
    return size==0;
}

template<class T>
const T& Binary_tree<T>::getRootElem() const {
    if(root!=nullptr)
        return root->elem;
    else
        throw std::exception();
}

template<class T>
void Binary_tree<T>::erase(const T& e, Node<T>* r,Node<T>* p){
    if(r){
        //r points to the node to be deleted
        if(r->elem==e){
            //r is the root
            if(p==nullptr){
                delete r;
                size--;
                r = nullptr;
                return;
            }
            //r is a leave
            if((r->lchild==nullptr)&&(r->rchild==nullptr)){
                if(r->elem<p->elem)
                    p->lchild = nullptr;
                else
                    p->rchild = nullptr;
                delete r;
                size--;
                //do we need to set r to nullptr here?
                return;
            }
            //r has only lchild
            else if((r->lchild!=nullptr)&&(r->rchild==nullptr)){
                if(r->elem<p->elem)
                    p->lchild = r->lchild;
                else
                    p->rchild = r->lchild;
                delete r;
                size--;
                return;
            }
            //r has only rchild
            else if((r->lchild==nullptr)&&(r->rchild!=nullptr)){
                if(r->elem<p->elem)
                    p->lchild = r->rchild;
                else
                    p->rchild = r->rchild;
                delete r;
                size--;
                return;
            }
            //r have both rchild and lchild
            else{
                Node<T>* minRchild;
                Node<T>* pOfMinRchild;
                getMinOfRchild(r, minRchild, pOfMinRchild);
                swap(r, minRchild);
                erase(e, minRchild,pOfMinRchild);
            }

        }
        else{
            p = r;
            if(e<r->elem)
                erase(e, r->lchild, p);
            else
                erase(e, r->rchild, p);
        }
    }
    //node to be deleted not found or empty tree
    else{
        std::cout<<"empty tree or node to be deleted not found"<<std::endl;
        return;
    }


}
//assume rchild of r is not empty
template<class T>
void Binary_tree<T>::getMinOfRchild(Node<T>* r, Node<T>*& minRchild, Node<T>*& pOfMinRchild) const{
    Node<T>* temp = r->rchild;
    pOfMinRchild = r;
    while(temp->lchild){
        pOfMinRchild = temp;
        temp = temp->lchild;
    }
    std::cout<<"min Rchild for root: "<<r->elem<<" is "<< temp->elem << std::endl;
    std::cout<<"parent of minRchild is: "<<pOfMinRchild->elem<< std::endl;
    minRchild = temp;
}

template<class T>
void Binary_tree<T>::swap(Node<T>* n1, Node<T>* n2){
    if(n1&&n2)
        std::swap(n1->elem, n2->elem);
}

template<class T>
void Binary_tree<T>::eraseTree(const Node<T>* r){
    if(r){
        eraseTree(r->lchild);
        eraseTree(r->rchild);
        delete r;
    }

}

template<class T>
Binary_tree<T>::~Binary_tree(){
    eraseTree(root);

}
#endif // BINARY_TREE_H
