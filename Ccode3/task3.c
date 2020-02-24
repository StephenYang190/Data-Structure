//
// Created by HP on 2019/10/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "Stackdouble.h"

statue ComputeNext(Stack s,int *n,int k);
int EightQueen(Stack *s)
{
    /*int n;
    printf("Enter the seat of the first queen :");
    scanf("%d",&n);*/

    Push(s,0,0);
    int k = 1;
    int pause = 0;
    int flag = 0;//0 continue 1 back
    int sum = 0;
    int n = 0;
    while(1)
    {
        if(StackEmpty(*s))
            break;
        if(k == 8)
        {
            StackTraverse(*s);
            printf("\n");
            flag = 1;
            k--;
            sum++;
            continue;
        }

        int j = -1;
        int i = 0;
        if(flag)
        {
            int pause1;
            Pop(s,&pause1,&pause);
            i = pause + 1;
            flag = 0;
        }

        int sit[8] = {0};//1 = dont 0 = do
        ComputeNext(*s,sit,k);

        for(;i < 8;i++)
        {
            if(!sit[i])
            {
                j = i;
                break;
            }
        }
        if(j < 0)
        {
            flag = 1;

            k--;
            continue;
        }
        Push(s,k,j);
        k++;
    }

    return sum;
}
statue ComputeNext(Stack s,int *n,int k)
{
    int i = 0;
   while(!StackEmpty(s))
   {
       int x,y;
       Pop(&s,&x,&y);
       n[y] = 1;
       int sum,min;
       sum = x + y - k;
       if(sum >= 0)
       {
           n[sum] = 1;
       }
       min = y - x + k;
       if(min < 8)
       {
           n[min] = 1;
       }
   }

   return 0;
}
int main()
{
    Stack s;
    InitStack(&s);

    printf("%d\n",EightQueen(&s));

    StackTraverse(s);

    return 0;
}
