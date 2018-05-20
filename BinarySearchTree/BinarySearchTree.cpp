#ifndef BINARYSEARCHTREE_CPP_INCLUDED
#define BINARYSEARCHTREE_CPP_INCLUDED
#include "BinarySearchTree.h"

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x, Node *t) const
{
    if (t == NULL)
        return false;
    else if (x < t->data)
        return find(x, t->left);
    else if (x > t->data)
        return find(x, t->right);
    else
        return true;
}
template <class Type>
void BinarySearchTree<Type>::insert(const Type &x, Node *&t)
{
    if (t == NULL)
        t = new Node(x);
    else if (x < t->data)
        insert(x, t->left);
    else if (x > t->data)
        insert(x, t->right);
}
template <class Type>
void BinarySearchTree<Type>::remove(const Type &x, Node *&t)
{
    if (t == NULL)
        return;
    else if (x < t->data)
        remove(x, t->left);
    else if (x > t->data)
        remove(x, t->right);
    else
    {
        if (t->left != NULL && t->right != NULL)
        {
            Node *tmp = t->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            t->data = tmp->data;
            remove(t->data, t->right);
        }
        else
        {
            Node *tmp = t;
            t = (t->left != NULL)? t->left : t->right;
            delete tmp;
        }
    }
}
template <class Type>
void BinarySearchTree<Type>::clear(Node *t)
{
    if(t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
}

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x) const
{
    return find(x, root);
}
template <class Type>
void BinarySearchTree<Type>::insert(const Type &x)
{
    insert(x, root);
}
template <class Type>
void BinarySearchTree<Type>::remove(const Type &x)
{
    remove(x, root);
}
template <class Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
    clear(root);
}

#endif // BINARYSEARCHTREE_H_INCLUDED
