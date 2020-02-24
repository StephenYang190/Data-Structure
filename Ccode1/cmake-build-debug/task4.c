//
// Created by HP on 2019/9/26.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("How long the r\y\g lights cotinue?");
    int red,green,yellow;
    scanf("%d %d %d",&red,&yellow,&green);
    if(red > 106 || green > 106 || yellow > 106)
    {
        printf("input again.");
        scanf("%d %d %d",&red,&yellow,&green);
    }
    int n;
    printf("sum of :");
    scanf("%d",&n);
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        int k,t;
        scanf("%d %d",&k,&t);
        switch(k)
        {
            case 0:
                sum += t;
                break;
            case 1:
                sum += t;
                break;
            case 2:
                sum += t + red;
        }
    }

    printf("%d",sum);

    return 0;
}
