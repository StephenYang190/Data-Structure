#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Queue.h"

statue TreeFull(BinaryTree t)
{
    if(BiTreeEmpty(t))
    {
        printf("Empty.\n");
        return true;
    }
    Queue q;
    InitQueue(&q);
    statue flag = true;
    int last_site = 0;
    EnQueue(&q,t.root,1);
    while(!QueueEmpty(q))
    {
        PointNode p;
        int e;
        DeQueue(&q,&p,&e);
        if(p->site != last_site + 1)
        {
            flag = false;
            break;
        }
        if(p->Left)
        {
            EnQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,e + 1);
        }
        last_site = p->site;
    }
    DestroyQueue(&q);
    if(flag)
        printf("it is full.\n");
    else
        printf("NO.\n");
    printf("\nCompare End.\n");
    return true;
}

int main() {

    BinaryTree tree_task;
    InitBitree(&tree_task);
    CreateBiTree(&tree_task,5);
    int times;
    printf("Enter times :");
    scanf("%d",&times);
    int local[30] = {0};
    int LrDirection[30] = {0};
    for(int i = 0;i < 30;i++)
    {
        if(i % 2)
        {
            local[i] = (int)(i / 2) + 1;
            LrDirection[i] = 2;
        }
        else
        {
            local[i] = (int)(i / 2) + 1;
            LrDirection[i] = 1;
        }

    }
    for(int i = 0;i < times;i++)
    {
        int data = i + 6;
        int localnumber = local[i];
        int LR = LrDirection[i];
        /*printf("Enter data %d :",i + 1);
        scanf("%d",&data);
        printf("Enter Local number :");
        scanf("%d",&localnumber);
        printf("Enter the direction :");
        scanf("%d",&LR);*/
        BinaryTree Tree_Pause;
        CreateBiTree(&Tree_Pause,data);
        InserChild(&tree_task,localnumber,LR,&Tree_Pause);
    }
    LevelOrderTraverse(tree_task);
   /* DeleteChild(&tree_task,5,2);
    printf("The depth : %d\n",BiTreeDepth(tree_task));
    printf("The parent : %d\n",Parent(&tree_task,8)->site);
    Assign(&tree_task,9,19);
    printf("The parent : %d\n",Parent(&tree_task,8)->site);
    LevelOrderTraverse(tree_task);*/
    /*printf("The LeftChilde : %d\n",LeftChilde(&tree_task,8)->site);
    printf("The RightChilde : %d\n",RightChilde(&tree_task,8)->site);
    if(LeftSibling(&tree_task,9))
    {
        printf("The LeftSibling : %d\n",LeftSibling(&tree_task,9)->site);
    }
    if(RightSibling(&tree_task,8))
    {
        printf("The RightSibling : %d\n",RightSibling(&tree_task,8)->site);
    }
    PreOrderTraverse(tree_task);
    PreOder(tree_task.root);
    InOrderTraverse(tree_task);
    InOrder(tree_task.root);
    PostOrderTraverse(tree_task);
    PostOrder(tree_task.root);*/
    TreeFull(tree_task);
    DeleteChild(&tree_task,5,2);
    TreeFull(tree_task);

    DestroyBiTree(&tree_task);

    return 0;
}