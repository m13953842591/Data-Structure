#include "seqStack.h"
#include "linkStack.h"

int main()
{
    printf("seqStack\n");
    seqStack<int> st;
    linkStack <int> lst;
    for (int i = 0; i < 15; ++ i) {
        st.push(i);
        lst.push(i);
    }
    while (!st.isEmpty())
        printf("%d ", st.pop());

    printf("\n\nlinkStack\n");
    while (!lst.isEmpty())
        printf("%d ", lst.pop());

    printf("\n");

    return 0;
}
