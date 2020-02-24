//
// Created by HP on 2019/11/15.
//

#include <stdio.h>
#include <stdlib.h>

int ** SlideTask(int ** p,int n,int m)
{
    int frnum;
    int flag = -1;
    int ** SignMatirx = (int **)malloc(sizeof(int *) * n);
    for(int i = 0;i < n;i++)
    {
        SignMatirx[i] = (int *)malloc(sizeof(int) * m);
        SignMatirx[i][0] = 0;
        frnum = p[i][0];
        flag = -1;
        for(int j = 1;j < m;j++)
        {
            SignMatirx[i][j] = 0;
            if(p[i][j] == frnum)
            {
                if(flag == p[i][j])
                {
                    SignMatirx[i][j - 2] = 1;
                    SignMatirx[i][j - 1] = 1;
                    SignMatirx[i][j] = 1;
                }
                else
                {
                    flag = p[i][j];
                }
            }
            else
            {
                flag = -1;
            }
            frnum = p[i][j];
        }
    }
    flag = -1;
    for(int i = 0;i < m;i++)
    {
        flag = -1;
        frnum = p[0][i];
        for(int j = 1;j < n;j++)
        {
            if(p[j][i] == frnum)
            {
                if(flag == p[j][i])
                {
                    SignMatirx[j - 2][i] = 1;
                    SignMatirx[j - 1][i] = 1;
                    SignMatirx[j][i] = 1;
                }
                else
                {
                    flag = p[j][i];
                }
            }
            else
            {
                flag = -1;
            }
            frnum = p[j][i];
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(SignMatirx[i][j])
                p[i][j] = 0;
        }
    }

    return p;
}



int main()
{
    int n,m;
    printf("enter the number of row and colunmn : ");
    scanf("%d %d",&n,&m);
    int ** p ;
    if(n > 0 && m > 0)
    {
        p = (int **)malloc(sizeof(int *) * n);
        for(int i = 0;i < n;i++)
        {
            p[i] = (int *)malloc(sizeof(int) * m);
            for(int j = 0;j < m;j++)
            {
                int ennum;
                scanf("%d",&ennum);
                p[i][j] = ennum;
            }
        }
    }
    p = SlideTask(p,n,m);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }

    return 0;
}