//
// Created by HP on 2019/10/26.
//
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    matrix m;
    Createmastrix(&m,5,5);
    for(int i = 1;i < 6;i++)
    {
        ADDmatrix(&m,i ,6 - i,i+10);
    }
    Printmatrix(m);

    printf("\n");
    matrix t;
    Createmastrix(&t,5,5);
    Copymatrix(m,&t);
    Printmatrix(t);

    printf("\n");
    Addmatrix(m,t,&t);
    Printmatrix(t);

    matrix m2;
    Createmastrix(&m2,5,5);
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
        ADDmatrix(&m2,sit_x,sit_y,num);
    }
    Printmatrix(m2);
    printf("\n");
    Addmatrix(m,m2,&t);
    Printmatrix(t);

    printf("\n");
    Subtmatrix(m,m2,&t);
    Printmatrix(t);

    printf("\n");
    Transposematrix(m2,&t);
    Printmatrix(t);

    return 0;
}