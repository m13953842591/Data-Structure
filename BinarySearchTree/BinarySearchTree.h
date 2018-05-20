#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <iostream>
using namespace std;

template <class Type>
class BinarySearchTree
{
private:
  struct Node
  {
    Node *left;
    Node *right;
    Type data;
    Node() : left(NULL), right(NULL) {}
    Node(Type d, Node *l = NULL, Node *r = NULL) : data(d), left(l), right(r) {}
    ~Node() {}
  };

  Node *root;

  bool find(const Type &x, Node *t) const;
  void insert(const Type &x, Node *&t);
  void remove(const Type &x, Node *&t);
  void clear(Node *t);

public:
  BinarySearchTree() : root(NULL) {}
  bool isEmpty() { return root == NULL; }
  bool find(const Type &x) const;
  void insert(const Type &x);
  void remove(const Type &x);
  ~BinarySearchTree();
};
#include "BinarySearchTree.cpp"
#endif // BINARYSEARCHTREE_H_INCLUDED
