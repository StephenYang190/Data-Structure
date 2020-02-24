//
// Created by HP on 2019/11/9.
//

#ifndef CCODE5_BINARYTREE_H
#define CCODE5_BINARYTREE_H

/*The data difinit*/
#ifndef STATUE
typedef enum  {false,true} statue;
#define STATUE
#endif
typedef struct TREE_ADT
{
    int site;
    int data;
    int weight;
    struct TREE_ADT * Left;
    struct TREE_ADT * Right;
}BinaryTree,*PointTree;

/*operation difinit*/
//finish
statue InitBitree(BinaryTree * t);
//finish
statue DestroyBiTree(BinaryTree * t);
//finish
statue CreateBiTree(BinaryTree * t,int n,int w);
//finish
statue ClearBiTree(BinaryTree * t);
//finish
statue BiTreeEmpty(BinaryTree t);
//finish
int BiTreeDepth(BinaryTree t);
//finish
statue Assign(BinaryTree * t,int c,int n);
//finish
PointTree Parent(BinaryTree * t,int e);
//finish
PointTree LeftChilde(BinaryTree * t,int e);
//finish
PointTree RightChilde(BinaryTree * t,int e);
//finish
PointTree LeftSibling(BinaryTree * t,int e);
//finish
PointTree RightSibling(BinaryTree * t,int e);

//finish
statue DeleteChild(BinaryTree * t,int e,int LR);
//finish
statue PreOrderTraverse(BinaryTree t);
//finish
statue InOrderTraverse(BinaryTree t);
//finish
statue PostOrderTraverse(BinaryTree t);
//finish
statue LevelOrderTraverse(BinaryTree t);
//finish
statue PreOder(PointTree t);
//finish
statue InOrder(PointTree t);
//finish
statue PostOrder(PointTree t);

#endif //CCODE5_BINARYTREE_H
