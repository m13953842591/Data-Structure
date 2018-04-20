#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
#include "../queue/seqQueue.h"
#include "../stack/seqStack.h"
using namespace std;

template <class Type>
class binaryTree
{
private:
	struct Node
	{
		Type data;
		Node *left, *right;
		Node():left(NULL), right(NULL) {}
		Node(Type d, Node *l = NULL, Node *r = NULL):
			 data(d), left(l), right(r) {}
		~Node() {}
	};

	Node *root;

	void clear(Node * n);
    int height( Node *t ) const;
    int size( Node *t ) const;
    void preOrder( Node *t )  const;
    void postOrder( Node *t )  const;
    void midOrder( Node *t ) const;
    void createTreeRecursivly(Node *t, Type flag)const;

public:
	binaryTree(): root(NULL) {}
	binaryTree(const Type &value){root = new Node(value);};
	binaryTree(Node *p){root = p;}
	~binaryTree(){clear(root);}

	bool isEmpty(){return root == NULL;}
	Type getRoot() const {return root->data;}
	Type getLeft()const {return root->left->data;}
	Type getRight() const {return root->right->data;}
	int size() const {return size(root);}
	int height() const {return height(root);}


	void makeTree(const Type &x, binaryTree &lt, binaryTree&rt){
		clear();
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}

	void delLeft()
	{
		Node *tmp = root->left;
		root->left = NULL;
		clear(tmp);
	}

	void delRight()
	{
		Node *tmp = root->right;
		root->right = NULL;
		clear(tmp);
	}

	void clear()
	{
		if(root != NULL) clear(root);
		root = NULL;
	}
	void preOrder() const;
	void midOrder() const;
	void postOrder() const;
	void createTree(Type flag);
	void createTreeRecursivly(Type flag){
		clear(root);
		createTreeRecursivly(root, flag);
	}
};

#include "binaryTree.cpp"
#endif // BINARYTREE_H_INCLUDED
