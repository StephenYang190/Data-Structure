//
// Created by 97927 on 2019/12/3.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef TDY
typedef enum {false,true}statue;
#define TDY
#endif

int main()
{
    int times;
    printf("enter the times : ");
    scanf("%d",&times);
    int chess[3][3] = {0};
    for(int i = 0 ; i < times; i++)
    {
        for(int j = 0;j < 3;j++)
        {
            for(int k = 0;k < 3;k++)
            {
                scanf("%d",&chess[j][k]);
            }
        }
        int flag = 0;
        int zero_n = 0;
        statue flag_vic = false;
        for(int j = 0;j < 3;j ++)
        {
            for(int k = 0;k < 3;k++)
            {
                if(chess[j][k] == 0)
                {
                    zero_n++;
                    continue;
                }
                if(k == 2)
                    break;
                if(chess[j][k] != chess[j][k + 1])
                {
                    break;
                }
                if(k == 1)
                {
                    flag = chess[j][k];
                    if(chess[j][k - 1] != 0)
                        flag_vic = true;
                }

            }
        }
        if(flag == 0)
        {
            for(int j = 0;j < 3;j ++)
            {
                for(int k = 0;k < 2;k++)
                {
                    if(chess[k][j] == 0)
                        continue;
                    if(chess[k][j] != chess[k + 1][j])
                    {
                        break;
                    }
                    if(k == 1)
                    {
                        flag = chess[k][j];
                        if(chess[k - 1][j] != 0)
                            flag_vic = true;
                    }
                }
            }
        }
        if(flag == 0)
        {
            for(int j = 0;j < 3;j++)
            {
                if(chess[j][j] == 0)
                    continue;
                if(chess[j][j] != chess[j + 1][j + 1])
                    break;
                if(j == 1)
                {
                    if(chess[j - 1][j - 1] != 0)
                        flag_vic = true;
                    flag = chess[j][j];
                }

            }
            for(int j = 3;j > 0;j--)
            {
                if(chess[j][j] == 0)
                    continue;
                if(chess[j][j] != chess[j - 1][j - 1])
                    break;
                if(j == 1)
                {
                    if(chess[j - 1][j - 1] != 0)
                        flag_vic = true;
                    flag = chess[j][j];
                }
            }

        }
        if(flag == 0)
        {
            printf("0\n");
            continue;
        }

        if(flag == 1)
        {
            if(flag_vic)
                zero_n++;
            printf("%d\n",zero_n);
        }
        else
        {
            if(flag_vic)
                zero_n++;
            printf("-%d\n",zero_n);
        }
    }
    return 0;
}
