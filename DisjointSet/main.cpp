#include "DisjointSet.h"

int main()
{
    DisjointSet s1(10);
    cout << s1.FindNonRecur(1) << endl;
    cout << s1.FindNonRecur(0) << endl;
    return 0;
}
