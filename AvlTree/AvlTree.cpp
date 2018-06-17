#ifndef AVLTREE_CPP_INCLUDED
#define AVLTREE_CPP_INCLUDED
#include "AvlTree.h"

template <class Type>
bool AvlTree<Type>::find(const Type &x, Node *t) const
{
    if (t == NULL)
        return false;
    else if (x > t->data)
        return find(x, t->right);
    else if (x < t->data)
        return find(x, t->left);
    else
        return true;
}
template <class Type>
void AvlTree<Type>::insert(const Type &x, Node *&t)
{
    if (t == NULL){
        t = new Node(x);
        return;
    }
    if (x > t->data)
        insert(x, t->right);
    else
        insert(x, t->left);

    int bf = getHeight(t->left) - getHeight(t->right), lbf, rbf;
    switch (bf)
    {
    case 2:
        lbf = getHeight(t->left->left) - getHeight(t->left->right);
        if (lbf == 1)
            LL(t);
        else
            LR(t);
        break;
    case -2:
        rbf = getHeight(t->right->left) - getHeight(t->right->right);
        if (rbf == -1)
            RR(t);
        else
            RL(t);
        break;
    default:
        t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
        break;
    }
}
template <class Type>
bool AvlTree<Type>::remove(const Type &x, Node *&t)
{
    if (t == NULL)
        return true;
    bool flag;
    int prevHeight = getHeight(t);
    if (x > t->data)
        flag = remove(x, t->right);
    else if (x < t->data)
        flag = remove(x, t->left);
    else
    {
        if (t->left != NULL && t->right != NULL)
        {
            Node *tmp = t->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            t->data = tmp->data;
            flag = remove(t->data, t->right);
        }
        else
        {
            Node *tmp = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete tmp;
            return false;
        }
    }
    if (flag)
        return true; //no need to adjust

    int bf = getHeight(t->left) - getHeight(t->right), lbf, rbf;
    switch (bf)
    {
    case 2:
        lbf = getHeight(t->left->left) - getHeight(t->left->right);
        if (lbf == 1)
            LL(t);
        else
            LR(t);
        break;
    case -2:
        rbf = getHeight(t->right->left) - getHeight(t->right->right);
        if (rbf == -1)
            RR(t);
        else
            RL(t);
        break;
    default:
        t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
        break;
    }

    return (prevHeight == getHeight(t)) ? true : false;
}
template <class Type>
void AvlTree<Type>::clear(Node *t)
{
    if(t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
}

template <class Type>
void AvlTree<Type>::LL(Node *&t)
{
    Node *tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;
    t = tmp;
    t->right->height = max(getHeight(t->right->left), getHeight(t->right->right)) + 1;
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
}
template <class Type>
void AvlTree<Type>::RR(Node *&t)
{
    Node *tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    t = tmp;
    t->left->height = max(getHeight(t->left->left), getHeight(t->left->right)) + 1;
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
}
template <class Type>
void AvlTree<Type>::LR(Node *&A)
{
    Node *C = A->left->right;
    Node *B = A->left;
    B->right = C->left;
    A->left = C->right;
    C->left = B;
    C->right = A;
    A = C;
    A->right->height = max(getHeight(A->right->left), getHeight(A->right->right)) + 1;
    A->left->height = max(getHeight(A->left->left), getHeight(A->left->right)) + 1;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
}

template <class Type>
void AvlTree<Type>::RL(Node *&A)
{
    Node *C = A->right->left;
    Node *B = A->right;
    B->left = C->right;
    A->right = C->left;
    C->left = A;
    C->right = B;
    A = C;
    A->right->height = max(getHeight(A->right->left), getHeight(A->right->right)) + 1;
    A->left->height = max(getHeight(A->left->left), getHeight(A->left->right)) + 1;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
}

template <class Type>
bool AvlTree<Type>::find(const Type &x) const
{
    return find(x, root);
}
template <class Type>
void AvlTree<Type>::insert(const Type &x)
{
    insert(x, root);
}
template <class Type>
void AvlTree<Type>::remove(const Type &x)
{
    remove(x, root);
}
template <class Type>
void AvlTree<Type>::traverse()
{
    queue<Node*> q1;
    queue<int> q2;
    q1.push(root);
    q2.push(1);
    Node *tmp;
    int level = 1;
    while(!q1.empty())
    {
        tmp = q1.front();
        q1.pop();
        if(level == q2.front())
            cout << tmp->data << ' ';
        else{
            cout << endl << tmp->data << ' ';
            level = q2.front();
        }
        q2.pop();
        if(tmp->left) {
            q1.push(tmp->left);
            q2.push(level + 1);
        }
        if(tmp->right) {
            q1.push(tmp->right);
            q2.push(level + 1);
        }
    }
}
#endif //AVLTREE_CPP_INCLUDED
