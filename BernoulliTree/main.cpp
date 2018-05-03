#include "BernoulliTree.h"

int main()
{
    int x[5] = {1,2,3,4,5};
    cout << 1 << endl;
    BernoulliTree<int> b1;
    cout << 2 << endl;
    for(int i = 0; i < 5; i++) b1.enQueue(x[i]);
    cout << 3 << endl;
    for(int i = 0; i < 5; i++) cout << b1.deQueue() << endl;
    cout << 4 << endl;
    return 0;
}
