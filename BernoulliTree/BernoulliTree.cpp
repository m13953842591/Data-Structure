#ifndef BERNOULLITREE_CPP_INCLUDED
#define BERNOULLITREE_CPP_INCLUDED
#include "BernoulliTree.h"

// Notice in "mergeNodes" and "copy" function
// we don't care the previous value of "res" , which means it may cause
// memory leak, so be careful using it, we recommend you create a variable
// to catch the previous value of "res" at first, or just to clear the res
// using "clear(res);"

template <class Type>
void BernoulliTree<Type>::mergeNodes(Node *n1, Node *n2, Node *&res)
{
    
    if (n1 == NULL || n2 == NULL)
    {
        res = NULL;
        return;
    }
    if (n1->data > n2->data)
    {
        n2->right = n1;
        copy(n2, res);
    }
    else
    {
        n1->right = n2;
        copy(n1, res);
    }
}

template <class Type>
void BernoulliTree<Type>::merge(Node **h1, int size1, Node **h2, int size2, Node **&resHeaders, int &resSize)
{
    resSize = max(size1, size2) + 1;
    resHeaders = new Node *[resSize];
    BernoulliTree<Type>::Node *carry = NULL, tmp = NULL;
    int i = 0, cond;
    //determine which kind of case
    while (i < resSize - 1)
    {
        if (h1[i] != NULL && p2[i] != NULL && carry != NULL)
            cond = 1;
        else if (h1[i] != NULL && h2[i] != NULL && carry == NULL)
            cond = 2;
        else if (h1[i] != NULL && h2[i] == NULL && carry != NULL)
            cond = 3;
        else if (h1[i] == NULL && h2[i] != NULL && carry != NULL)
            cond = 4;
        else if (h1[i] != NULL && h2[i] == NULL && carry == NULL)
            cond = 5;
        else if (h1[i] == NULL && h2[i] != NULL && carry == NULL)
            cond = 6;
        else
            cond = 7;
        // step 2:
        // determine headers[i] and carry, we solve this problem in two cases
        // case 1: in this case there is no need to merge!
        resHeaders[i] = NULL;
        switch (cond)
        {
        case 1:
            resHeaders[i] = carry;
        case 2: //carry is NULL
            mergeNodes(h1[i], h2[i], carry);
            break;
        case 3: //h2[i] is NULL
            tmp = carry;
            mergeNodes(h1[i], tmp, carry);
            clear(tmp);
            break;
        case 4: //h1[i] is NULL
            tmp = carry;
            mergeNodes(h2[i], tmp, carry);
            clear(tmp);
            break;
        case 5: //only h1[i] is not NULL
            copy(h1[i], carry);
            break;
        case 6: //only h2[i] is not NULL
            copy(h2[i], carry);
        default:
            break;
        }
    }
    resHeaders[resSize - 1] = carry;
}

template <class Type>
void BernoulliTree<Type>::copy(Node *n, Node *&res)
{
    if (n == NULL)
        return;
    res = new Node(n->data);
    copy(n->left, res->left);
    copy(n->right, res->right);
}

template <class Type>
void BernoulliTree<Type>::clear(Node *n)
{
    if (n == NULL)
        return;
    clear(n->left);
    clear(n->right);
    delete n;
}

template <class Type>
void BernoulliTree<Type>::enQueue(const Type &x)
{
    BernoulliTree<Type> tmp(x);
    mergeTree(tmp);
}

template <class Type>
Type BernoulliTree<Type>::deQueue()
{
    int min = 0;
    Type res;
    for (int i = 0; i < size; i++)
    {
        if (headers[i]->data < headers[min]->data)
            min = i;
    }
    res = headers[min]->data;
    if (min == 0)
    {
        delete headers[0];
        return res;
    }
    BernoulliTree<Type>::Node **tmpHeaders = new Node *[min];
    BernoulliTree<Type>::Node *tmpNode = headers[min]->left;
    for (int i = 0; i < min; i++)
    {
        tmpHeaders[i] = tmpNode;
        tmpNode = tmpNode->right;
    }
    delete headers[min];
    
    //merge
    BernoulliTree<Type> tmp(tmpHeaders, min);
    mergeTree(tmp);
    return res;
}

#endif // BERNOULLITREE_CPP_INCLUDED
