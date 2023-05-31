#include <iostream>
using namespace std;

template<class T>
class Tree
{
private:

	T data;
public:
	Tree<T>* left;
	Tree<T>* right;
	Tree();
	Tree(T data, Tree<T>* L = NULL, Tree<T>* R = NULL);

	T Getdata() { return this->data; }
	void static Preorder(Tree<T>* node);
	void static Postorder(Tree<T>* node);
	void static Inorder(Tree<T>* node);
	int countNodes()
	{
		int lcount = 0,rcount = 0;
		if (left != NULL) { lcount = left->countNodes(); }
		if (rcount != NULL) { rcount = left->countNodes(); }

		return 1 + rcount + lcount;
	}

};

template<class T>
Tree<T>::Tree()
{
	left = NULL;
	right = NULL;
}

template<class T>
Tree<T>::Tree(T data, Tree<T>* L, Tree<T>* R)
{
	this->data = data;
	left = L;
	right = R;

}
template<class T>
void Tree<T>::Preorder(Tree<T>* node)
{
	if (node != NULL)
	{
		std::cout << node->data << " ";
		Preorder(node->left);
		Preorder(node->right);
	}
}

template<class T>
void Tree<T>::Postorder(Tree<T>* node)
{
	if (node != NULL)
	{
		Postorder(node->left);
		Postorder(node->right);
		std::cout << node->data << " ";
	}

}

template<class T>
void Tree<T>::Inorder(Tree<T>* node)
{
	if (node != NULL)
	{
		Postorder(node->left);
		std::cout << node->data << " ";
		Postorder(node->right);
	}
}


int main()
{
	Tree<int>* LChild3 = new Tree<int>(4);
	Tree<int>* LChild2 = new Tree<int>(3, LChild3);
	Tree<int>* LChild1 = new Tree<int>(2, LChild2);

	Tree<int> T1(1, LChild1);

	cout << "Tree root value: " << T1.Getdata()<<endl;
	cout << "Child1: " << LChild1->Getdata()<<endl;
	cout << "Child2: " << LChild2->Getdata()<<endl;
	cout << "Child3: " << LChild3->Getdata()<<endl;

	cout << "Preorder Traversal: ";
	Tree<int>::Preorder(&T1);
	cout << endl;
	cout << "Postorder Traversal: ";
	Tree<int>::Postorder(&T1);
	cout << endl;
	cout << "Inorder Traversal: ";
	Tree<int>::Inorder(&T1);
	cout << endl<<endl;

	cout << "Count Nodes: " << T1.countNodes()<<endl;

	delete LChild1;
	delete LChild2;
	delete LChild3;
	return 0;
}