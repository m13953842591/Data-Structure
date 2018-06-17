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
    dst = new TypeOfEdge[vSize];
    len = new int[vSize];
    prev = new int[vSize];
    EularCircuit = NULL;
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
        if (visited[i])
            continue;
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

struct node
{
    int ver, dst;
    bool operator<(const node &x)
    {
        return dst < x.dst;
    }
    node(int v, int d) : ver(v), dst(d) {}
};

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::Dijkstra(int start)
{
    for (int i = 0; i < Vers; i++)
    {
        dst[i] = INF;
        len[i] = INF;
    }
    dst[start] = 0;
    len[start] = 0;

    priorityQueue<node> q;
    q.enQueue(node(start, 0));
    node u;
    while (!q.isEmpty())
    {
        u = q.deQueue();
        for (p = verList[u.ver].head; p; p = p->next)
        {
            if ((p->weight + u.dst < dst[p->end]) ||
                ((p->weight + u.dst == dst[p->end]) && (len[p->end] > len[u.ver] + 1)))
            {
                dst[p->end] = p->weight + u.dst;
                prev[p->end] = u.ver;
                len[p->end] = len[u.ver] + 1;
                q.enQueue(node(p->end, dst[p->end]));
            }
        }
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::printPath(int start, int end)
{
    if (start == end)
    {
        cout << start;
        return;
    }
    printPath(start, prev[end]);
    cout << ' ' << end;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const
{
    linkQueue<int> q;
    edgeNode *p;
    int current, *inDegree = new int[Vers];
    for (int i = 0; i < Vers; ++i)
        inDegree[i] = 0;
    for (i = 0; i < Vers; ++i)
    {
        for (p = verList[i].head; p != NULL; p = p->next)
            ++inDegree[p->end];
    }
    for (i = 0; i < Vers; ++i)
        if (inDegree[i] == 0)
            q.enQueue(i);
    cout << "topSort:" << endl;
    while (!q.isEmpty())
    {
        current = q.deQueue();
        cout << verList[current].ver << '\t';
        for (p = verList[current].head; p != NULL; p = p->next)
            if (--inDegree[p->end] == 0)
                q.enQueue(p->end);
    }
    cout << endl;
}
#endif //ADJLISTGRAPH_CPP_INCLUDED
