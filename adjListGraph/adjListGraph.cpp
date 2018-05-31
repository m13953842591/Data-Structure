#ifndef ADJLISTGRAPH_CPP_INCLUDED
#define ADJLISTGRAPH_CPP_INCLUDED
#include "adjListGraph.h"
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int v, bool visited[]) const
{
    cout << verList[v].value << '\t';
    visited[v] = true;
    edgeNode *tmp = verList[v].head;
    while (tmp != NULL)
    {
        if (visited[tmp->end] == false)
            dfs(tmp->end, visited);
        tmp = tmp->next;
    }
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(const TypeOfVer vers[], int vSize)
{
    verList = new verNode[vSize];
    for (int i = 0; i < vSize; i++)
    {
        verList[i].value = vers[i];
    }
    Vers = vSize;
    Edges = 0;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(int u, int v) const
{
    if (u < 0 || u >= Vers || v < 0 || v >= Vers)
        return false;
    edgeNode *tmp = verList[u].head;
    while (tmp != NULL && tmp->end != v)
        tmp = tmp->next;
    if (tmp == NULL)
        return false;
    return true;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::insert(int u, int v, TypeOfEdge w)
{
    if (u < 0 || u >= Vers || v < 0 || v >= Vers)
        return false;
    edgeNode *tmp = verList[u].head;
    while (tmp != NULL && tmp->end != v)
        tmp = tmp->next;
    if (tmp != NULL)
        return false;
    verList[u].head = new edgeNode(v, w, verList[u].head);
    ++Edges;
    return true;
}
template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::remove(int u, int v)
{
    edgeNode *p = verList[u].head, *q = NULL;

    while (p != NULL && p->end != v)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return false;

    if (q == NULL)
        verList[u].head = p->next;
    else
        q->next = p->next;
    delete p;
    Edges--;
    return true;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(const TypeOfVer &n)
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
    Edges = Edges - cnt; //有向图
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const
{
    bool *visited = new bool[Vers];

    for (int i = 0; i < Vers; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < Vers; i++)
    {
        if (visited[i]) continue;
        dfs(i, visited);
        cout << endl;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const
{
    bool *visited = new bool[Vers];
    queue<int> q;
    int v;
    edgeNode *tmp;
    for (int i = 0; i < Vers; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < Vers; i++)
    {
        if (visited[i])
            continue;
        q.push(i);
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            if (visited[v])
                continue;
            cout << verList[v].value << '\t';
            visited[v] = true;
            tmp = verList[v].head;
            while (tmp != NULL)
            {
                if (visited[tmp->end] == false)
                {
                    q.push(tmp->end);
                }
                tmp = tmp->next;
            }
        }
        cout << endl;
    }
}
template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph()
{
    edgeNode *tmp;
    for (int i = 0; i < Vers; i++)
    {
        while ((tmp = verList[i].head) != NULL)
        {
            verList[i].head = tmp->next;
            delete tmp;
        }
    }
    delete[] verList;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::Prim() const;

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::Dijkstra(int start, DijkstraNode *&res)
{

    TypeOfEdge minDst;
    DijkstraNode u;
    priorityQueue<DijkstraNode> q;
    edgeNode *p;

    res = new DijkstraNode[Vers];
    for (int i = 0; i < Vers; i++) //initialization
    {
        res[i].distance = INF;
        res[i].node = i; //no need to change
        res[i].known = false;
        res[i].len = INF;
        res[i].prev = -1;
    }

    res[start].distance = 0;
    res[start].len = 0;
    q.enQueue(res[start]);
    while (!q.isEmpty())
    {
        u = q.deQueue();
        if (res[u.node].known)
            continue; //防止一个点重复加入的情况
        res[u.node].known = true;
        minDst = res[u.node].distance;

        for (p = verList[u.node].head; p; p = p->next)
        {
            if (p->weight + minDst < res[p->end].distance)
            {
                res[p->end].distance = p->weight + minDst;
                res[p->end].prev = u.node;
                res[p->end].len = res[u.node].len + 1;
                q.enQueue(res[p->end]);
            }
            else if (p->weight + minDst == res[p->end].distance)
            {
                if (res[p->end].len > res[u.node].len + 1)
                {
                    res[p->end].distance = p->weight + minDst;
                    res[p->end].prev = u.node;
                    res[p->end].len = res[u.node].len + 1;
                    q.enQueue(res[p->end]);
                }
            }
        }
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::printPath(
    int start, int end, DijkstraNode *&res)
{
    if (start == end)
    {
        cout << start;
        return;
    }
    if (res[end].prev == -1)
    {
        cout << "no path from start to end" << endl;
        return;
    }
    printPath(start, res[end].prev, res);
    cout << ' ' << end;
}

#endif //ADJLISTGRAPH_CPP_INCLUDED
