#ifndef BERNOULLITREE_CPP_INCLUDED
#define BERNOULLITREE_CPP_INCLUDED
#include "BernoulliTree.h"
template <class Type>
void BernoulliTree<Type>::merge(Node **h1, int size1, Node **h2, int size2, Node **&resHeaders, int &resSize)
{
    resSize = max(size1, size2) + 1;
    resHeaders = new Node *[resSize];
    BernoulliTree<Type>::Node **hLarger, **hSmaller, **bcp1 = NULL, **bcp2 = NULL;
    BernoulliTree<Type>::Node *carry = NULL, *op1, *op2, *opb, *ops; //operands
    int i = 0;

    // first we make two copies of these two Bernoulli trees's headers
    if(size1 > 0)
    {
        bcp1 = new Node *[size1];
        for (int ii = 0; ii < size1; ii++)
            bcp1[ii] = copy(h1[ii]);
    }
    if(size2 > 0)
    {
        bcp2 = new Node *[size2];
        for (int ii = 0; ii < size1; ii++)
            bcp2[ii] = copy(h2[ii]);
    }


    // then we determine which headers are larger, which is smaller
    if (size1 < size2)
    {
        hSmaller = bcp1; //hLarger means "headers with larger size"
        hLarger = bcp2; // hSmaller means "headers with smaller size",
    }
    else
    {
        hSmaller = bcp2;
        hLarger = bcp1;
    }

    while (i < size1 && i < size2)
    {
        //step 1:
        //determine op1 and op2, in here we first consider op1, then op2;
        op1 = op2 = NULL;
        resHeaders[i] = NULL;
        if (carry != NULL)
            op1 = carry;
        if (h1[i] != NULL)
        {
            if (op1 == NULL)
                op1 = h1[i];
            else
                op2 = h1[i];
        }
        if (h2[i] != NULL)
        {
            if (op1 == NULL)
                op1 = h2[i];
            else if (op2 == NULL)
                op2 = h2[i];
        }

        // step 2:
        // determine headers[i] and carry, we solve this problem in two cases
        // case 1: in this case there is no need to merge!
        if (op1 == NULL || op2 == NULL)
        {
            if (op1 != NULL)
                resHeaders[i] = op1;
            else
                resHeaders[i] = NULL; // op1 is NULL, op2 definitely will be NULL
            carry = NULL;
            i++;
            continue;
        }
        // case 2:
        // in case 2, we first determine resHeaders[i]
        if (carry != NULL && h1[i] != NULL && h2[i] != NULL)
            // then op1 must be carry, and op2 must be h1[i]
            resHeaders[i] = h2[i];
        else
            // there is only two of carry, h1[i] and h2[i] that are not NULL
            resHeaders[i] = NULL;

        // merge two header and get carry
        if (op1->data > op2->data)
        {
            opb = op1; // opb means operand with bigger data
            ops = op2; // ops means operand with smaller data
        }
        else
        {
            opb = op2;
            ops = op1;
        }

        carry = ops;
        ops = ops->left;
        if (ops == NULL)
            carry->left = opb;
        else
        {
            while (ops->right != NULL)
                ops = ops->right;
            ops->right = op1;
        }
        i++;
    }

    // merge the rest headers
    while (i < resSize - 1)
    {
        resHeaders[i] = NULL;
        // case 1
        if (hLarger[i] == NULL && carry == NULL)
            resHeaders[i] = carry = NULL;

        // case 2
        else if (hLarger[i] != NULL && carry != NULL)
        {
            resHeaders[i] = NULL;

            if (hLarger[i]->data > carry->data)
            {
                opb = hLarger[i];
                ops = carry;
            }
            else
            {
                opb = carry;
                ops = hLarger[i];
            }

            carry = ops;
            ops = ops->left;
            if (ops == NULL)
                carry->left = opb;
            else
            {
                while (ops->right != NULL)
                    ops = ops->right;
                ops->right = op1;
            }
        }
        // case 3 and 4
        else
        {
            if (hLarger[i] != NULL) // then carry == NULL
                resHeaders[i] = hLarger[i];
            else // then hLarger[i] == NULL
                resHeaders[i] = carry;
            carry = NULL;
        }
        i++;
    }
    resHeaders[i] = carry;
}

template <class Type>
typename BernoulliTree<Type>::Node* BernoulliTree<Type>::copy(BernoulliTree<Type>::Node *n)
{
    Node *cp = NULL;
    if (n != NULL)
    {
        cp = new Node(n->data);
        cp->left = copy(n->left);
        cp->right = copy(n->right);
    }
    return cp;
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
    cout << 2.1 << endl;
    BernoulliTree<Type> tmp(x);
    cout << 2.2 << endl;
    Node **resHeader;
    int resSize;
    cout << 2.3 << endl;
    merge(tmp.headers, tmp.size, headers, size, resHeader, resSize);
    cout << 2.4 << endl;
    clearHeaders();
    cout << 2.5 << endl;
    headers = resHeader;
    size = resSize;
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
    BernoulliTree<Type>::Node **newHeaders = new Node *[min];
    BernoulliTree<Type>::Node *tmp = headers[min]->left;
    for (int i = 0; i < min; i++)
    {
        newHeaders[i] = tmp;
        tmp = tmp->right;
    }
    delete headers[min];
    //merge
    BernoulliTree<Type>::Node **resHeaders;
    int resSize;
    merge(newHeaders, min, headers, size, resHeaders, resSize);
    clearHeaders();
    headers = resHeaders;
    size = resSize;
    return res;
}

#endif // BERNOULLITREE_CPP_INCLUDED
