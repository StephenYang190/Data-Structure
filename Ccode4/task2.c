//
// Created by HP on 2019/11/2.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5][5] = {0};
    while(1)
    {
        int sit_x;
        int sit_y;
        int num;
        printf(("x "));
        if(!scanf("%d",&sit_x))
            break;
        printf("y :");
        if(!scanf("%d",&sit_y))
            break;
        printf("num :");
        if(!scanf("%d",&num))
            break;
        a[sit_x - 1][sit_y - 1] = num;
    }

    for(int i = 0;i < 5;i++)
    {
        int sit[5] = {0};
        int max = a[i][0];
        for(int k = 1;k < 5;k++)
        {
            if(max < a[i][k])
            {
                max = a[i][k];
                for(int j = 0;j < 5;j++)
                    sit[j] = 0;
                sit[k] = 1;

            }
            else if(max == a[i][k])
                sit[k] = 1;
        }

        for(int j = 0;j < 5;j++)
        {
            if(sit[j] == 0)
                continue;
            int k = 0;
            for(;k < 5;k++)
            {
                if(k == i)
                    continue;
                if(a[k][sit[j]] < max)
                    break;
            }
            if(k == 5)
                printf("(%d , %d)\n",i,sit[j]);
        }

    }

    return 0;
}
