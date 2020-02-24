//
// Created by 97927 on 2019/12/13.
//

#ifndef DESIGN_MY_BINARYTREE_H
#define DESIGN_MY_BINARYTREE_H

#include <string>

class my_BinaryTree {
private:
    int site;
    int weight;
    char data;
    std::string code;
    my_BinaryTree * pa;
    my_BinaryTree * lft_child;
    my_BinaryTree * rght_child;
protected:
    my_BinaryTree * locateTree(int st);
    my_BinaryTree * leftBottom();
    my_BinaryTree * rightBottom();
public:
    my_BinaryTree(char ch,int n = 0);//initial
    ~my_BinaryTree();
    int getWeight();//return weight
    int getSite();//return site
    int depth();//return tree depth
    char getData();//get this node's data
    bool assign(int st,char ch);//change the data
    my_BinaryTree * parent(int st);//find parent
    my_BinaryTree * leftChild(int st);//find leftchild
    my_BinaryTree * rightChild(int st);//find rightchild
    bool inserChild(int st,int LR,my_BinaryTree * ct);//LR 1 right
    bool setParent(my_BinaryTree * pr);//change parent
    bool deleteChild(int st,int LR);
    bool preOrderTraverse();
    bool inOrderTraverse();
    bool postOrderTraverse();
    bool levelOrderTraverse();
    bool show();//show this node's information
    bool coding(std::string file);//code
    std::string getCode();//return code
    bool deCodeFile(std::string filename);//decode from file
};


#endif //DESIGN_MY_BINARYTREE_H
