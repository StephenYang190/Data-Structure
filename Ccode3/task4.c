//
// Created by HP on 2019/10/20.
//
#include "SeQuence.h"
#include <stdio.h>
#include <stdlib.h>

int SortSeQuence(Sequence *q)
{
    int i = 0;
    int *D = (int *)malloc(sizeof(int) * q->nowside);
    /*Init a detect array*/
    for(int k = 0;k < q->nowside;k++)
    {
        D[k] = 1;
    }

    while(1)
    {
        if(i == q->nowside - 1)
            break;
        if(!D[i]){
            i++;
            continue;
        }
        int max = q->Frst[i].data;
        int sit = i;
        for(int k = i + 1;k < q->nowside;k++)
        {
            if(!D[k])
                continue;
            if(q->Frst[k].data == max)
            {
                D[k] = 0;
            }
            else if(q->Frst[k].data > max)
            {
                sit = k;
                max = q->Frst[k].data;
            }

        }
        if(sit > i)
        {
            q->Frst[sit].data = q->Frst[i].data;
            q->Frst[i].data = max;

        }
        i++;
    }
    showlisk(q);
    i = 0;
    for(int times = 1;i < q->nowside;i++)
    {
        if(!D[i])
        {
            int n;
            SeQuenceDelete(q,i + 1,&n);
            times--;
        }
    }
    showlisk(q);
    if(q->nowside % 2)
        return q->Frst[(int)q->nowside / 2].data;

}
int main()
{
    Sequence qs;
    InitSeQuence(&qs);

    int num;
    printf("How many numbers do you want to enter :");
    scanf("%d",&num);

    for(int i = 0;i < num;i++)
    {
        int k;
        scanf("%d",&k);
        add(&qs,k);
    }
    printf("%d",SortSeQuence(&qs));

    return 0;
}
