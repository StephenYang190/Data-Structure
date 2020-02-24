//
// Created by HP on 2019/11/9.
//

#ifndef CCODE5_BINARYTREE_H
#define CCODE5_BINARYTREE_H

/*The data difinit*/
typedef enum {false,true}statue;
typedef struct Node
{
    int site;
    int data;
    struct Node * Left;
    struct Node * Right;
}Node,*PointNode;
typedef struct BinaryTree
{
    PointNode root;
}BinaryTree,*PointTree;
/*operation difinit*/
//finish
statue InitBitree(BinaryTree * t);
//finish
statue DestroyBiTree(BinaryTree * t);
//finish
statue CreateBiTree(BinaryTree * t,int n);
//finish
statue ClearBiTree(BinaryTree * t);
//finish
statue BiTreeEmpty(BinaryTree t);
//finish
int BiTreeDepth(BinaryTree t);
//finish
statue Assign(BinaryTree * t,int c,int n);
//finish
PointNode Parent(BinaryTree * t,int e);
//finish
PointNode LeftChilde(BinaryTree * t,int e);
//finish
PointNode RightChilde(BinaryTree * t,int e);
//finish
PointNode LeftSibling(BinaryTree * t,int e);
//finish
PointNode RightSibling(BinaryTree * t,int e);
//finish
statue InserChild(BinaryTree * t,int e,int LR,BinaryTree * c);
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
statue PreOder(PointNode t);
//finish
statue InOrder(PointNode t);
//finish
statue PostOrder(PointNode t);

#endif //CCODE5_BINARYTREE_H
