//
// Created by HP on 2019/11/1.
//
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

statue Createmastrix(matrix * m,int x,int y)
{
    m->ArFr = (NodeSite)malloc(sizeof(Node) * INIT_LONG);
    m->longth = 10;
    m->nowsite = 0;
    m->ylon = y;
    m->xlon = x;
}
statue Destroymatrix(matrix * m)
{
    free(m->ArFr);
    m->ArFr = NULL;
    m->longth = 0;
    m->nowsite = 0;
}
statue Printmatrix(matrix m)
{
/*    int * a = (int *)malloc(sizeof(int) * m.xlon * m.ylon);
    for(int i = 0;i < m.xlon * m.ylon;i++)
    {
        a[i] = 0;
    }
    for(int i = 0;i < m.nowsite;i++)
    {
        int sit = (m.ArFr[i].x - 1) * m.ylon + m.ArFr[i].y - 1;
        a[sit] = m.ArFr[i].num;
    }
    for(int i = 0;i < m.xlon;i++)
    {
        for(int k = 0;k < m.ylon;k++)
        {
            int sit = i * m.ylon + k;
            printf("%d ",a[sit]);
        }
        printf("\n");
    }
    free(a);*/
    int ma_sn = 0;
    for(int i = 0;i < m.xlon;i++)
    {
        for(int k = 0;k < m.ylon;k++)
        {
            int sit = -1;
            if(m.ArFr[ma_sn].x == i + 1)
                sit = m.ArFr[ma_sn].y;
            if(sit < 0)
            {
                for(;k < m.ylon;k++)
                {
                    printf("0 ");
                }
            }
            else
            {
                for(;k < sit - 1;k++)
                {
                    printf("0 ");
                }
                printf("%d ",m.ArFr[ma_sn].num);
                ma_sn++;
            }
        }
        printf("\n");
    }
    return true;
}
statue ADDmatrix(matrix * m,int x,int y,int num)
{
    m->ArFr[m->nowsite].x = x;
    m->ArFr[m->nowsite].y = y;
    m->ArFr[m->nowsite].num = num;
    m->nowsite++;
    if(m->nowsite == m->longth)
    {
        m->ArFr = realloc(m->ArFr,sizeof(Node) * (m->longth + ADD_LONG));
        m->longth += ADD_LONG;
    }

    return true;
}
statue Copymatrix(matrix m,matrix * t)
{
    t->ArFr = (NodeSite)malloc(sizeof(Node) * INIT_LONG);
    t->longth = 10;
    t->nowsite = 0;
    t->xlon = m.xlon;
    t->ylon = m.ylon;

    for(int i = 0;i < m.nowsite;i++)
    {
        ADDmatrix(t,m.ArFr[i].x,m.ArFr[i].y,m.ArFr[i].num);
    }

    return true;
}
statue Addmatrix(matrix m1,matrix m2,matrix * t)
{
    if(m1.xlon != m2.xlon || m1.ylon != m2.ylon)
        return false;
    int i = 0;// m1 sign
    int j = 0;// m2 sign
    while(1)
    {
        int add = 0;//0 = add m1 /1 = add m2
        if(i == m1.nowsite || j == m2.nowsite)
        {
            while(i < m1.nowsite)
            {
                ADDmatrix(t,m1.ArFr[i].x,m1.ArFr[i].y,m1.ArFr[i].num);
                i++;
            }
            while(j < m2.nowsite)
            {
                ADDmatrix(t,m2.ArFr[j].x,m2.ArFr[j].y,m2.ArFr[j].num);
                j++;
            }
            break;
        }

        if(m1.ArFr[i].x < m2.ArFr[j].x){
            add = 0;
        }
        else if(m1.ArFr[i].x > m2.ArFr[j].x){
            add = 1;
        }
        else
        {
            if(m1.ArFr[i].y < m2.ArFr[j].y)
                add = 0;
            else if(m1.ArFr[i].y > m2.ArFr[j].y)
                add = 1;
            else
            {
                ADDmatrix(t,m2.ArFr[j].x,m2.ArFr[j].y,\
                m2.ArFr[j].num + m1.ArFr[i].num);
                i++;
                j++;
                continue;
            }
        }
        if(add)
        {
            ADDmatrix(t,m2.ArFr[j].x,m2.ArFr[j].y,m2.ArFr[j].num);
            j++;
        }
        else
            {
                ADDmatrix(t,m1.ArFr[i].x,m1.ArFr[i].y,m1.ArFr[i].num);
                i++;
            }
    }

    return true;
}
statue Subtmatrix(matrix m1,matrix m2,matrix * t)
{
    if(m1.xlon != m2.xlon || m1.ylon != m2.ylon)
        return false;
    int i = 0;// m1 sign
    int j = 0;// m2 sign
    while(1)
    {
        int add = 0;//0 = add m1 /1 = add m2
        if(i == m1.nowsite || j == m2.nowsite)
        {
            while(i < m1.nowsite)
            {
                ADDmatrix(t,m1.ArFr[i].x,m1.ArFr[i].y,m1.ArFr[i].num);
                i++;
            }
            while(j < m2.nowsite)
            {
                ADDmatrix(t,m2.ArFr[j].x,m2.ArFr[j].y,-m2.ArFr[j].num);
                j++;
            }
            break;
        }

        if(m1.ArFr[i].x < m2.ArFr[j].x){
            add = 0;
        }
        else if(m1.ArFr[i].x > m2.ArFr[j].x){
            add = 1;
        }
        else
        {
            if(m1.ArFr[i].y < m2.ArFr[j].y)
                add = 0;
            else if(m1.ArFr[i].y > m2.ArFr[j].y)
                add = 1;
            else
            {
                ADDmatrix(t,m2.ArFr[j].x,m2.ArFr[j].y,\
                m1.ArFr[j].num - m2.ArFr[i].num);
                i++;
                j++;
            }
        }
        if(add)
        {
            ADDmatrix(t,m2.ArFr[j].x,m2.ArFr[j].y,-m2.ArFr[j].num);
            j++;
        }
        else
        {
            ADDmatrix(t,m1.ArFr[i].x,m1.ArFr[i].y,m1.ArFr[i].num);
            i++;
        }
    }

    return true;
}
statue Transposematrix(matrix m,matrix * t)
{
    int * a = (int *)malloc(sizeof(int) * m.xlon);
    for(int i = 0;i < m.xlon;i++)
    {
        a[i] = 0;
    }
    for(int i  = 0;i < m.nowsite;i++)
    {
        int sit = m.ArFr[i].x - 1;
        a[sit]++;
    }
    int * p = (int *)malloc(sizeof(int) * m.xlon);
    p[0] = 0;
    for(int i = 1;i < m.xlon;i++)
    {
        p[i] = p[i - 1] + a[i - 1];
        printf("p%d : %d\n",i,p[i]);
    }
    for(int i = 0;i < m.nowsite;i++)
    {
        int sit = p[m.ArFr[i].y];
        t->ArFr[sit].y = m.ArFr[i].x;
        t->ArFr[sit].x = m.ArFr[i].y;
        t->ArFr[sit].num = m.ArFr[i].num;
        p[m.ArFr[i].y]++;
    }
    t->xlon = m.ylon;
    t->ylon = m.xlon;
    t->nowsite = m.nowsite;

    free(a);
    free(p);

    return true;
}

