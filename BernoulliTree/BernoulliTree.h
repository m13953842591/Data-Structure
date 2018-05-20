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
    void mergeNodes(Node *&n1, Node *&n2, Node *&res);
    void merge(Node **&h1, int size1, Node **&h2, int size2, Node **&resHeaders, int &resSize);
    void copyNode(const Node *n, Node *&res);
    void copyHeaders(Node **h, int s, Node **&res);
    void clearHeaders()
    {
        for (int i = 0; i < size; i++)
            clear(headers[i]);
        delete[] headers;
        headers = NULL;
    }

  public:
    BernoulliTree() : headers(NULL), size(0) {}
    BernoulliTree(Node **h, int s) : headers(h), size(s) {}
    //note that if you transmit "h" and "s", it can't be reused!
    BernoulliTree(const Type &x) //Bernoulli tree with only one Node
    {
        size = 1;
        headers = new Node *[1];
        headers[0] = new Node(x);
    }
    bool isEmpty()
    {
        for (int s = 0; s < size; s++)
        {
            if (headers[s] != NULL)
                return false;
        }
        return true;
    }
    void mergeTree(const BernoulliTree<Type> &bt);
    void enQueue(const Type &x);
    Type deQueue();
    ~BernoulliTree() { clearHeaders(); }
};

#include "BernoulliTree.cpp"
#endif // BERNOULLITREE_H_INCLUDED
