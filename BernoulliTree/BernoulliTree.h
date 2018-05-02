#ifndef BERNOULLITREE_H_INCLUDED
#define BERNOULLITREE_H_INCLUDED
#include <iostream>
using namespace std;
template <class Type>
class BernoulliTree;

template <class Type>
BernoulliTree<Type> merge(BernoulliTree<Type> &b1, BernoulliTree<Type> &b2);

template <class Type>
class BernoulliTree
{
    friend BernoulliTree<Type> merge(BernoulliTree<Type> &b1, BernoulliTree<Type> &b2);

  private:
    struct Node
    {
        Type data;
        Node *left, *right; //left children and right brother
        Node() : left(NULL), right(NULL) {}
        Node(Type d, Node *l = NULL, Node *r = NULL) : data(d), left(l), right(r) {}
    };
    Node **headers;
    int size;

  public:
    BernoulliTree(Node **h, int s) : headers(h), size(s) {}
    BernoulliTree(const Type &x)
    {
        size = 1;
        headers = new Node *[1];
        headers[0] = new Node(x);
    }
    void enQueue(const Type &x);
    Type deQueue();
};

#include "BernoulliTree.cpp"
#endif // BERNOULLITREE_H_INCLUDED
