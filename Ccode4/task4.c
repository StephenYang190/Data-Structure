//
// Created by HP on 2019/11/3.
//
#include <stdio.h>
#include <stdlib.h>
#include "SequenceLink.h"

int main()
{
    Sequence s;
    InitSeQuence(&s);
    int n;
    printf("Times : ");
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int e;
        printf("number : ");
        scanf("%d",&e);
        add(&s,e);
    }
    showlisk(&s);

    return 0;
}
