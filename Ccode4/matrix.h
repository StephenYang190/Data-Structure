//
// Created by HP on 2019/10/26.
//

#ifndef CCODE4_MATRIX_H
#define CCODE4_MATRIX_H

#define INIT_LONG 10
#define ADD_LONG 5
typedef enum  {false,true} statue;

typedef struct ADT_MATRIX{
    int x,y;
    int num;
}Node,*NodeSite;

typedef struct ADT_Front
{
    NodeSite ArFr;
    int xlon;
    int ylon;
    int longth;
    int nowsite;
}matrix;

statue Createmastrix(matrix * m,int x,int y);
statue Destroymatrix(matrix * m);
statue Printmatrix(matrix m);
statue Copymatrix(matrix m,matrix * t);
statue Addmatrix(matrix m1,matrix m2,matrix * t);
statue Subtmatrix(matrix m1,matrix m2,matrix * t);
statue Transposematrix(matrix m,matrix * t);
statue ADDmatrix(matrix * m,int x,int y,int num);

#endif //CCODE4_MATRIX_H
