#include "hfTree.h"

int main()
{
    int d[5] = {1,2,3,4,5};
    int w[5] = {1,2,3,4,5};
    hfTree<int> tree(d, w, 5);
    hfTree<int>::hfCode res[5];
    tree.getCode(res);
    for(int i = 0; i < 5; i++){
        cout << res[i].data << ' ' << res[i].code << endl;
    }
    return 0;
}
