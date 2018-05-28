#include "adjListGraph.h"

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    adjListGraph<int, int> g(a, 10);
    g.insert(0, 1, 1);
    g.insert(2, 3, 1);
    g.insert(0, 2, 1);
    g.insert(4, 5, 1);
    g.dfs();
    return 0;
}
