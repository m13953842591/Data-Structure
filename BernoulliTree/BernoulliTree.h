#ifndef BERNOULLITREE_H_INCLUDED
#define BERNOULLITREE_H_INCLUDED
#include <iostream>
using namespace std;

template <class Type>
class BernoulliTree
{

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
    void clear(Node *n);
    void copy(Node *n, Node *&res);
    void mergeNodes(Node * n1, Node * n2, Node *&res);
    void merge(Node **h1, int size1, Node **h2, int size2, Node **&resHeaders, int &resSize);
    void clearHeaders()
    {
        for (int i = 0; i < size; i++)
            clear(headers[i]);
        delete[] headers;
    }
    

  public:
    BernoulliTree():headers(NULL), size(0) {}
    BernoulliTree(Node **h, int s) : headers(h), size(s) {}
    BernoulliTree(const Type &x) //Bernoulli tree with only one Node
    {
        size = 1;
        headers = new Node *[1];
        headers[0] = new Node(x);
    }
    void mergeTree(const BernoulliTree<Type> &bt)
    {
        Node **resHeader = NULL;
        int resSize = 0;
        merge(headers, size, bt.headers, bt.size, resHeader, resSize);
        clearHeaders();
        headers = resHeader;
        size = resSize;
    }

    void enQueue(const Type &x);
    Type deQueue();
    ~BernoulliTree()
    {
        clearHeaders();
    }
};

#include "BernoulliTree.cpp"
#endif // BERNOULLITREE_H_INCLUDED
