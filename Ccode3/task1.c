#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int main() {

    Stack s;
    InitStack(&s);

    for(int i = 0;i < 5;i++)
    {
        Push(&s,i);
    }
    StackTraverse(s);

    int n;
    GetTop(s,&n);
    printf("%d\n",n);
    for(int i = 0;i < 2;i++)
    {
        Pop(&s,&n);
    }
    printf("%d\n",n);
    StackTraverse(s);

    ClearStack(&s);
    StackTraverse(s);

    return 0;
}