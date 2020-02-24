//
// Created by 97927 on 2019/11/26.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int site;
    int direction;//0 left 1right
}ball;
int FindMin(int *min,int n)
{
    int m = 65525;
    for(int i = 0;i < n;i++)
    {
        if(min[i] == -1)
            continue;
        if(min[i] < m)
            m = min[i];
    }

    return m;
}
void MoveBall(ball *b,int n,int s)
{
    for(int i = 0;i < n;i++)
    {
        if(b[i].direction)
        {
            b[i].site += s;
        }
        else
        {
            b[i].site -= s;
        }
    }
}
void TimeGo(ball * b,int n,int l,int t)
{
    int distance[n];
    while(t > 0)
    {
        for(int i = 0;i < n;i++)
        {
            printf("%d %d\n ",b[i].site,b[i].direction);
            if(i == 0)
            {
                if(b[i].direction == 0)
                {
                    distance[i] = b[i].site;
                }
                else
                {
                    if(b[i + 1].direction == 0)
                        distance[i] = (b[i + 1].site - b[i].site) / 2;
                    else
                        distance[i] = -1;
                }
                continue;
            }
            if(i == n - 1)
            {
                if(b[i].direction == 1)
                {
                    distance[i] =l -  b[i].site;
                }
                else
                {
                    if(b[i - 1].direction)
                        distance[i] = (b[i].site - b[i - 1].site) / 2;
                    else
                        distance[i] = -1;
                }
                continue;
            }
            if(b[i].direction)
            {
                if(b[i + 1].direction)
                {
                    distance[i] = -1;
                }
                else
                {
                    distance[i] = (b[i + 1].site - b[i].site) / 2;
                }
            }
            else
            {
                if(b[i - 1].direction)
                {
                    distance[i] = (b[i].site - b[i - 1].site) / 2;
                }
                else
                {
                    distance[i] = -1;
                }
            }
        }
        int cost_t = FindMin(distance,n);
        printf("%d\n\n",cost_t);
        if(t > cost_t)
             MoveBall(b,n,cost_t);
        else
            MoveBall(b,n,t);
        t -= cost_t;
        for(int i = 0;i < n;)
        {
            if(i == 0)
            {
                if(b[i].site == 0 || b[i].site == b[i + 1].site)
                {
                    b[i].direction = 1- b[i].direction;
                    if(b[i].site == b[i + 1].site)
                    {
                        b[i + 1].direction = 1 - b[i + 1].direction;
                        i += 2;
                        continue;
                    }
                }
                i++;
                continue;
            }
            if(i == n - 1)
            {
                if(b[i].site == l || b[i].site == b[i - 1].site)
                    b[i].direction = 1- b[i].direction;
                i++;
                continue;
            }
            if(b[i].site == b[i + 1].site)
            {
                b[i].direction = 1 - b[i].direction;
                b[i + 1].direction = 1 - b[i + 1].direction;
                i += 2;
                continue;
            }
            i++;
        }
    }
}
int main()
{
    int n,l,t;
    scanf("%d %d %d",&n,&l,&t);
    ball * b = (ball*)malloc(sizeof(ball) * n);
    for(int i = 0;i < n;i++)
    {
        int sit;
        scanf("%d",&sit);
        b[i].site = sit;
        b[i].direction = 1;
    }
    TimeGo(b,n,l,t);
    for(int i = 0;i < n;i++)
    {
        printf("%d\n",b[i].site);
    }

    return 0;
}
