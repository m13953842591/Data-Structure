#ifndef BINARYTREE_CPP_INCLUDED
#define BINARYTREE_CPP_INCLUDED
#include "binaryTree.h"
#include "../stack/seqStack.h"
#include "../queue/seqQueue.h"
template<class Type>
void binaryTree<Type>::createTreeRecursivly(Node *t, Type flag)const
{
	if(t == NULL) return;
	Type ld,rd;
	cout << "please enter " + t->data +"'s children(first left then right):\n";
	cin >> ld >> rd;
	if(ld != flag)
		t->left = new Node(ld);
	if(rd != flag)
		t->right = new Node(rd);

	createTreeRecursivly(t->left, flag);
	createTreeRecursivly(t->right, flag);
}


template<class Type>
void binaryTree<Type>::clear(Node * t)
{
	if(t == NULL) return;
	clear(t->left);
	clear(t->right);
	delete t;
}

template<class Type>
int binaryTree<Type>::height( Node *t ) const
{
	if(t == NULL) return 0;
	int lh = height(t->left), rh = height(t->right);
	return 1 + ((lh > rh)? lh : rh);
}

template<class Type>
int binaryTree<Type>::size( Node *t ) const
{
	if(t == NULL) return 0;
	else return 1 + size(t->left) + size(t->right);
}

template<class Type>
void binaryTree<Type>::preOrder( Node *t )  const
{
	if(t == NULL) return;
	cout << t->data << ' ';
	preOrder(t->left);
	preOrder(t->right);
}


template<class Type>
void binaryTree<Type>::postOrder( Node *t )  const
{
	if(t == NULL) return;
	postOrder(t->left);
	postOrder(t->right);
	cout << t->data << ' ';
}

template<class Type>
void binaryTree<Type>::midOrder( Node *t ) const
{
	if(t == NULL) return;
	midOrder(t->left);
	cout << t->data << ' ';
	midOrder(t->right);
}

template<class Type>
void binaryTree<Type>::createTree(Type flag)
{
	clear(root);
	Type tmp, left, right;
	Node *p;
	seqQueue<Node*> q;
	cout << "please enter the data for root:";
	cin >> tmp;
	if(tmp == flag) return;
	root = new Node(tmp);
	q.enQueue(root);
	while(!q.isEmpty()){
		p = q.deQueue();
		cout << "please enter "<< p->data << "'s children(first left then right):\n";
		cin >> left >> right;
		if(left != flag) {
			p->left = new Node(left);
			q.enQueue(p->left);
		}
		if(right != flag) {
			p->right = new Node(right);
			q.enQueue(p->right);
		}
	}
	cout << "create completed!\n";
}
// traverse binaryTree recursively
/*template<class Type>
void binaryTree<Type>::preOrder() const{
    cout << "preOrder traversal: ";
    preOrder(root);
    cout << endl;
}
template<class Type>
void binaryTree<Type>::midOrder() const{
    cout << "midOrder traversal: ";
    midOrder(root);
    cout << endl;
}
template<class Type>
void binaryTree<Type>::postOrder() const{
    cout << "postOrder traversal: ";
    postOrder(root);
    cout << endl;
}*/

// traverse binaryTree unrecursively
template<class Type>
void binaryTree<Type>::preOrder() const{
	seqStack<Node*> s;
	Node *tmp;
	if(root == NULL) return;
	s.push(root);
	while(!s.isEmpty()){
		tmp = s.pop();
		cout << s->data << ' ';
		if(tmp->right != NULL) s.push(tmp->right);
		if(tmp->left != NULL) s.push(tmp->left);
	}
}

template<class Type>
void binaryTree<Type>::midOrder() const{
	seqstack<Node *> s;
	Node *tmp;
	if(root == NULL) return;
	tmp = root;
	while(tmp) {s.push(tmp); tmp = tmp->left;}
	while(!s.isEmpty()){
		tmp = s.pop();
		cout << s->data << ' ';
		tmp = tmp->right;
		while(tmp) {s.push(tmp); tmp = tmp->left;}
	}
}

template<class Type>
void binaryTree<Type>::postOrder() const{
   	seqstack<Node *> s; seqstack<int> f;
	Node *tmp;
	int flag, noChildVisited = 0, oneChildVisited = 1, twoChildVisited = 2;
	if(root == NULL) return;
	s.push(root); f.push(noChildVisited);
	while(!s.isEmpty()){
		tmp = s.pop(); flag = f.pop();
		switch(flag){
			case 0: s.push(tmp); f.push(oneChildVisited);
					if(tmp->left != NULL){
						s.push(tmp->left); f.push(noChildVisited);
					}
					break;
			case 1: s.push(tmp); f.push(twoChildVisited);
					if(tmp->right != NULL){
						s.push(tmp->right); f.push(noChildVisited);
					}
					break;
			case 3: cout << tmp->data << ' ';
		}
	}
}
#endif //BINARYTREE_CPP_INCLUDED
