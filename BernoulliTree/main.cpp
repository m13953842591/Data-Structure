#include "BernoulliTree.h"

int main()
{
/*     int x[5] = {5,4,3,2,1};
    BernoulliTree<int> b;
    for(int i = 0; i < 5; i++)
        b.enQueue(x[i]); */
    int x = 1;
    int y = 2;
    BernoulliTree<int> b;
    b.enQueue(y);
    b.enQueue(x);
    cout << b.deQueue() << endl;
    cout << b.deQueue() << endl;
    return 0;
}
