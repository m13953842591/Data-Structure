#ifndef BERNOULLITREE_CPP_INCLUDED
#define BERNOULLITREE_CPP_INCLUDED
#include "BernoulliTree.h"

template <class Type>
void BernoulliTree<Type>::mergeNodes(Node *&n1, Node *&n2, Node *&res)
{
    if (n1 == NULL || n2 == NULL)
    {
        res = (n1 != NULL) ? n1 : n2;
        return;
    }
    Node *tmp = NULL;

    if ((n1->data) > (n2->data))
    {
        res = n2;
        if (n2->left == NULL)
        {
            n2->left = n1;
            return;
        }
        tmp = n2->left;
        while (tmp->right != NULL)
            tmp = tmp->right;
        tmp->right = n1;
    }
    else
    {
        res = n1;
        if (n1->left == NULL)
        {
            n1->left = n2;
            return;
        }
        tmp = n1->left;
        while (tmp->right != NULL)
            tmp = tmp->right;
        tmp->right = n2;
    }
}

template <class Type>
void BernoulliTree<Type>::merge(Node **&h1, int size1, Node **&h2, int size2, Node **&resHeaders, int &resSize)
{

    if (h1 == NULL || h2 == NULL)
    {
        if (h1 != NULL)
        {
            resHeaders = h1;
            resSize = size1;
        }
        else
        {
            resHeaders = h2;
            resSize = size2;
        }
        return;
    }

    resSize = max(size1, size2) + 1;
    resHeaders = new Node *[resSize];
    BernoulliTree<Type>::Node *carry = NULL, *sum = NULL;
    int i = 0, cond;

    //determine which kind of case
    while (i < min(size1, size2))
    {

        if (h1[i] != NULL && h2[i] != NULL && carry != NULL)
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
            mergeNodes(h1[i], carry, sum);
            carry = sum;
            break;
        case 4: //h1[i] is NULL
            mergeNodes(h2[i], carry, sum);
            carry = sum;
            break;
        case 5: //only h1[i] is not NULL
            carry = h1[i];
            break;
        case 6: //only h2[i] is not NULL
            carry = h2[i];
        default:
            break;
        }
        i++;
    }

    Node **h = (size1 > size2) ? h1 : h2;
    while (i < resSize - 1)
    {
        resHeaders[i] = NULL;
        if (h[i] != NULL && carry != NULL)
        {
            mergeNodes(h1[i], carry, sum);
            carry = sum;
        }
        else if (h[i] == NULL && carry != NULL)
        {
            resHeaders[i] = carry;
            carry = NULL;
        }
        else if (h[i] != NULL && carry == NULL)
        {
            resHeaders[i] = h[i];
            carry = NULL;
        }
        else
            carry = NULL;
        i++;
    }
    resHeaders[resSize - 1] = carry;
}

template <class Type>
void BernoulliTree<Type>::copyNode(const Node *n, Node *&res)
{
    if (n == NULL)
    {
        res = NULL;
        return;
    }
    res = new Node(n->data);
    copyNode(n->left, res->left);
    copyNode(n->right, res->right);
}

template <class Type>
void BernoulliTree<Type>::copyHeaders(Node **h, int s, Node **&res)
{
    res = new Node *[s];
    for (int i = 0; i < s; i++)
    {
        copyNode(h[i], res[i]);
    }
}

template <class Type>
void BernoulliTree<Type>::mergeTree(const BernoulliTree<Type> &bt)
{
    Node **tmpHeaders, **resHeaders;
    int resSize = 0;
    copyHeaders(bt.headers, bt.size, tmpHeaders);
    merge(tmpHeaders, bt.size, headers, size, resHeaders, resSize);
    headers = resHeaders;
    size = resSize;
}

template <class Type>
void BernoulliTree<Type>::clear(Node *n)
{
    if (n == NULL)
        return;
    clear(n->left);
    clear(n->right);
    delete n;
    n = NULL;
}

template <class Type>
void BernoulliTree<Type>::enQueue(const Type &x)
{
    BernoulliTree<Type> bt(x);
    mergeTree(bt);
}

template <class Type>
Type BernoulliTree<Type>::deQueue()
{
    int min = 0;
    Type res;
    for (; min < size; min++)
    {
        if (headers[min] != NULL)
            break;
    }

    for (int i = min; i < size; i++)
    {
        if (headers[i] != NULL && headers[i]->data < headers[min]->data)
            min = i;
    }
    res = headers[min]->data;

    //create tmpHeaders
    if (min == 0)
    {
        delete headers[0];
        headers[0] = NULL;
        return res;
    }
    BernoulliTree<Type>::Node **tmpHeaders = new Node *[min];
    BernoulliTree<Type>::Node *tmpNode = headers[min]->left;
    for (int i = 0; i < min; i++)
    {
        tmpHeaders[i] = tmpNode;
        tmpNode = tmpNode->right;
        tmpHeaders[i]->right = NULL;
    }
    delete headers[min];
    headers[min] = NULL;

    BernoulliTree<Type> tmp(tmpHeaders, min);
    mergeTree(tmp);
    return res;
}

#endif // BERNOULLITREE_CPP_INCLUDED
