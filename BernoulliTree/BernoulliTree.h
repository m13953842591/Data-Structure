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
    void merge(Node **h1, int size1, Node **h2, int size2, Node **&resHeaders, int &resSize);
    void clearHeaders()
    {
        for (int i = 0; i < size; i++)
            clear(headers[i]);
        delete[] headers;
    }
    Node* copy(Node *n);

  public:
    BernoulliTree():headers(NULL), size(0) {}
    BernoulliTree(Node **h, int s) : headers(h), size(s) {}
    BernoulliTree(const Type &x) //Bernoulli tree with only one Node
    {
        size = 1;
        headers = new Node *[1];
        headers[0] = new Node(x);
    }
    void mergeTrees(const BernoulliTree<Type> &b1, const BernoulliTree<Type> &b2)
    {
        Node **resHeader;
        int resSize;
        merge(b1.headers, b1.size, b2.headers, b2.size, resHeader, resSize);
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
