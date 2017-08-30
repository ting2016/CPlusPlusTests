template<class T> class Binary_tree;
template<class T>
class Node{
friend class Binary_tree<T>;
private:
	T elem;
	Node* parent;
	Node* lchild;
	Node* rchild;
public:
	Node(const T& e):elem(e), parent(nullptr), lchild(nullptr), rchild(nullptr){};
	Node(const T&e, Node* parent, Node* lchild, Node* rchild):elem(e), parent(parent), lchild(lchild), rchild(rchild){} 
};
template <class T>
class Binary_tree{
private:
	Node<T>* root;
public:
	Binary_tree(Node<T>* r = nullptr):root(r){};
	void insert(const T& t);
	void print();
	Node<T>* find(const T& t);
	void move(const T& t);
};
