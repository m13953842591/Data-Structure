#include "priorityQueue.h"

int main()
{

    int arr[5] = {5,4,3,2,1};
    priorityQueue<int> p(arr, 5);
    while(!p.isEmpty()){
        cout << p.deQueue() << endl;
    }
    return 0;
}
