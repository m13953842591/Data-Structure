#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <iostream>
#include <queue>
using namespace std;

template <class Type>
class AvlTree
{
  private:
    struct Node
    {
        Type data;
        Node *left;
        Node *right;
        int height;
        Node() : left(NULL), right(NULL), height(0) {}
        Node(Type d, Node *l = NULL, Node *r = NULL, int h = 0)
            : data(d), left(l), right(r), height(h) {}
        ~Node() {}
    };

    Node *root;

    bool find(const Type &x, Node *t) const;
    void insert(const Type &x, Node *&t);
    bool remove(const Type &x, Node *&t);
    void clear(Node *t);
    int getHeight(Node * t){ return (t == NULL)? -1 : t->height;}
    void LL(Node* &t);
    void LR(Node* &t);
    void RL(Node* &t);
    void RR(Node* &t);

  public:
    AvlTree():root(NULL){};
    bool isEmpty() { return root == NULL; }
    bool find(const Type &x) const;
    void insert(const Type &x);
    void remove(const Type &x);
    void traverse();
    ~AvlTree(){ clear(root);}
};

#include "AvlTree.cpp"
#endif // AVLTREE_H_INCLUDED
