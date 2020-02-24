//
// Created by HP on 2019/11/2.
//
#include <stdlib.h>
#include <stdio.h>
#include "Sequence.h"

int main()
{
    Sequence s;
    InitSeQuence(&s);
    int n;
    printf("The number : ");
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int num;
        printf("number : ");
        scanf("%d",&num);
        add(&s,num);
    }

    /*Find max*/
    int max = s.Frst[0].data;
    for(int i = 1;i < s.nowside;i++)
    {
        if(s.Frst[i].data > max)
            max = s.Frst[i].data;
    }
    /*Find difference*/
    int * p = (int *)malloc(sizeof(int) * max);
    for(int i = 0;i < max;i++)
        p[i] = 0;
    for(int i = 0;i < s.nowside;i++)
    {
        p[max - s.Frst[i].data] = 1;
    }
    int sum = 0;
    for(int i = 1;i < max ;i++)
    {
        if(p[i] && p[i - 1])
            sum++;
    }
    printf("%d",sum);

    return 0;
}