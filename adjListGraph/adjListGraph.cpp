#ifndef ADJLISTGRAPH_CPP_INCLUDED
#define ADJLISTGRAPH_CPP_INCLUDED
#include "adjListGraph.h"

template <class TypeOfNode, class TypeOfEdge>
adjListGraph<TypeOfNode, TypeOfEdge>::adjListGraph(const TypeOfVer vers[], int vSize)
{
    verList = new verNode[vSize];
    for (int i = 0; i < vSize; i++)
    {
        verList[i].value = vers[i];
    }
    Vers = vSize;
    Edges = 0;
}
template <class TypeOfNode, class TypeOfEdge>
bool adjListGraph<TypeOfNode, TypeOfEdge>::exist(int u, int v) const
{
    if (u < 0 || u >= Vers || v < 0 || v >= Vers)
        return false;
    verNode *tmp = verList[u].head;
    while (tmp != NULL && tmp->end != v)
        tmp = tmp->next;
    if (tmp == NULL)
        return false;
    return true;
}
template <class TypeOfNode, class TypeOfEdge>
bool adjListGraph<TypeOfNode, TypeOfEdge>::insert(int u, int v, TypeOfEdge w)
{
    if (u < 0 || u >= Vers || v < 0 || v >= Vers)
        return false;
    verNode *tmp = verList[u].head;
    while (tmp != NULL && tmp->end != v)
        tmp = tmp->next;
    if (tmp != NULL)
        return false;
    verList[u].head = new edgeNode(v, w, verList[u].head);
    ++Edges;
}
template <class TypeOfNode, class TypeOfEdge>
void adjListGraph<TypeOfNode, TypeOfEdge>::remove(const TypeOfNode &n)
{
    //5 steps:
    //1.找到节点对应的下标i
    //2.删除节点链出的边,计数cnt
    //3.i + 1 ~ Vers-1的节点上移
    //4.遍历边节点，所有的边的end > i的都要减1，删除所有end == i的边节点，计数cnt
    //5.Vers - 1, Edges - cnt;
    int i = 0, cnt = 0;
    for (; i < Vers; i++)
    {
        if (verList[i].value == n)
            break;
    }

    edgeNode *tmp, *p, *q;
    while ((tmp = verList[i].head) != NULL)
    {
        verList[i].head = tmp->next;
        delete tmp;
        cnt++;
    }

    for (int j = i; j < Vers - 1; j++)
        verList[j] = verList[j + 1];

    for (int j = 0; j < Vers; j++)
    {
        p = verList[j].head;
        q = NULL;
        while (p != NULL)
        {
            if (p->value == i)
            {
                if (q == NULL)
                {
                    verList[j].head = p->next;
                    delete p;
                    p = verList[j].head;
                }
                else
                {
                    q->next = p->next;
                    delete p;
                    p = q->next;
                }
                cnt++;
            }
            else
            {
                if (p->value > i)
                {
                    p->value--;
                }
                q = p;
                p = p->next;
            }
        }
    }

    Vers = Vers - 1;
    Edges = Edges - cnt;//有向图
}
template <class TypeOfNode, class TypeOfEdge>
void adjListGraph<TypeOfNode, TypeOfEdge>::dfs()
{
    
}
template <class TypeOfNode, class TypeOfEdge>
void adjListGraph<TypeOfNode, TypeOfEdge>::bfs();
template <class TypeOfNode, class TypeOfEdge>
adjListGraph<TypeOfNode, TypeOfEdge>::~adjListGraph()
{
    edgeNode *tmp for (int i = 0; i < Vers; i++)
    {
        while ((tmp = verList[i].head) != NULL)
        {
            verList[i].head = tmp->next;
            delete tmp;
        }
    }
    delete[] verList;
}

#endif //ADJLISTGRAPH_CPP_INCLUDED