#include "seqQueue.h"
#include "linkQueue.h"

int main()
{
    seqQueue<int> q;
    for (int i = 0; i < 30; ++ i)
        q.enQueue(i);
    for (int i = 0; i < 30; ++ i)
        printf("%d ", q.deQueue());
    printf("\n");

    linkQueue<int> q2;
     for (int i = 0; i < 30; ++ i)
        q2.enQueue(i);
    for (int i = 0; i < 30; ++ i)
        printf("%d ", q2.deQueue());
    printf("\n");
    return 0;
}
