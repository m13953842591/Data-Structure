#ifndef ADJMATRIXGRAPH_CPP_INCLUDED
#define ADJMATRIXGRAPH_CPP_INCLUDED
#include "AdjMatrixGraph.h"
template <class TypeOfVer, class TypeOfEdge>
AdjMatrixGraph<TypeOfVer, TypeOfEdge>::AdjMatrixGraph(int vSize, TypeOfVer v[], TypeOfEdge noEdgeFlag)
{
    if (vSize <= 0)
        return;
    Vers = vSize;
    Edges = 0;
    noEdge = noEdgeFlag;
    ver = new TypeOfVer[vSize];
    for (int i = 0; i < vSize; i++)
    {
        ver[i] = v[i];
    }
    edge = new TypeOfEdge* [vSize];
    for (int i = 0; i < vSize; i++)
    {
        edge[i] = new TypeOfEdge[vSize];
        for (int j = 0; j < vSize; j++)
        {
            edge[i][j] = noEdgeFlag;
        }
        edge[i][i] = 0;
    }
}
//insert an edge
template <class TypeOfVer, class TypeOfEdge>
bool AdjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(int u, int v, TypeOfEdge w)
{
    if (u < 0 || u >= Vers || v < 0 || v >= Vers)
        return false;
    if (edge[u][v] != noEdge)
        return false;
    edge[u][v] = w;
    Edges += 1;
    return true;
}
//remove an edge
template <class TypeOfVer, class TypeOfEdge>
bool AdjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(int u, int v)
{
    if (u < 0 || u >= Vers || v < 0 || v >= Vers)
        return false;
    if (edge[u][v] == noEdge)
        return false;
    edge[u][v] = noEdge;
    Edges -= 1;
    return true;
}
//see if E(u, v) exist
template <class TypeOfVer, class TypeOfEdge>
bool AdjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(int u, int v)
{
    if (u < 0 || u >= Vers || v < 0 || v >= Vers || u == v)
        return false;
    return (edge[u][v] != noEdge);
}
template <class TypeOfVer, class TypeOfEdge>
void AdjMatrixGraph<TypeOfVer, TypeOfEdge>::traverse()
{
    cout << '\t';
    for (int i = 0; i < Vers; i++)
        cout << ver[i] << '\t';
    cout << endl;

    for (int i = 0; i < Vers; i++)
    {
        cout << ver[i] << '\t';
        for (int j = 0; j < Vers; j++)
            cout << edge[i][j] << '\t';
        cout << endl;
    }
}
template <class TypeOfVer, class TypeOfEdge>
AdjMatrixGraph<TypeOfVer, TypeOfEdge>::~AdjMatrixGraph()
{
    delete[] ver;
    for (int i = 0; i < Vers; i++)
    {
        delete[] edge[i];
    }
}

#endif // ADJMATRIXGRAPH_CPP_INCLUDED
