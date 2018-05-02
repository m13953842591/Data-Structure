#ifndef BERNOULLITREE_CPP_INCLUDED
#define BERNOULLITREE_CPP_INCLUDED
#include "BernoulliTree.h"
template <class Type>
BernoulliTree<Type> merge(BernoulliTree<Type> &b1, BernoulliTree<Type> &b2)
{
    int resSize = max(b1.size, b2.size) + 1, i = 0;
    Node **resHeaders = new Node *[resSize], **hl, **hs;
    Node *carry = NULL, *op1, *op2, *opb, *ops; //operands

    if (b1.size < b2.size)
    {
        hs = b1.headers; //hl means "headers with larger size"
        hl = b2.headers; // hs means "headers with smaller size",
    }
    else
    {
        hs = b2.headers;
        hl = b1.headers;
    }

    while (i < b1.size && i < b2.size)
    {
        //step 1:
        //determine op1 and op2, in here we first consider op1, then op2;
        op1 = op2 = NULL;
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
                op2 = h2[i]
        }

        // step 2:
        // determine resHeaders[i] and carry, we solve this problem in two cases
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
            resheaders[i] = NULL;

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
        // case 1
        if (hl[i] == NULL && carry == NULL)
            resHeaders[i] = carry = NULL;

        // case 2
        else if (h1[i] != NULL && carry != NULL)
        {
            resHeaders[i] = NULL;

            if (h1[i]->data > carry->data)
            {
                opb = h1[i];
                ops = carry;
            }
            else
            {
                opb = carry;
                ops = h1[i];
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
            if (hl[i] != NULL) // then carry == NULL
                resHeaders[i] = hl[i];
            else // then hl[i] == NULL
                resHeaders[i] = carry;
            carry = NULL;
        }
        i++;
    }
    resHeaders[i] = carry;
    delete [] b1;
    delete [] b2;
    return BernoulliTree<Type>::BernoulliTree(resHeaders, resSize);
}

template <class Type>
void BernoulliTree<Type>::enQueue(const Type &x)
{

}
template <class Type>
Type BernoulliTree<Type>::deQueue();
#endif // BERNOULLITREE_CPP_INCLUDED
