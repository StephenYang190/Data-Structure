//
// Created by 97927 on 2019/12/13.
//

#include "my_BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
using std::cout;
using std::endl;

my_BinaryTree::my_BinaryTree(char ch,int n) {
    site = 0;
    data = ch;
    weight = n;
    pa = nullptr;
    lft_child = nullptr;
    rght_child = nullptr;
}

my_BinaryTree::~my_BinaryTree() {}

int my_BinaryTree::depth() {
    //store node
    std::queue<my_BinaryTree *> q;
    int level = 1;

    my_BinaryTree pu_tr(-1);
    if(lft_child)
        q.push(lft_child);
    if(rght_child)
        q.push(rght_child);
    //empty node
    q.push(&pu_tr);
    while(q.size() != 1)
    {
        my_BinaryTree * tree;
        tree = q.front();
        q.pop();
        //if find empty node
        if(tree->site == -1)
        {
            level++;
            q.push(tree);
            //if traverse is finished
            if(q.empty())
                break;
            continue;
        }
        if(tree->lft_child)
        {
            q.push(tree->lft_child);
        }
        if(tree->rght_child)
        {
            q.push(tree->rght_child);
        }
    }

    return level;
}

int my_BinaryTree::getSite() {
    return site;
}

my_BinaryTree *my_BinaryTree::leftChild(int st) {
    return lft_child;
}

my_BinaryTree *my_BinaryTree::rightChild(int st) {
    return rght_child;
}

my_BinaryTree *my_BinaryTree::parent(int st) {
    return pa;
}

char my_BinaryTree::getData() {
    return data;
}

bool my_BinaryTree::inserChild(int st, int LR, my_BinaryTree *ct) {
    my_BinaryTree * tree = locateTree(st);
    if(!tree)
        return false;
    switch (LR){
        case 1 :
        {
            //if this have right child
            if(tree->rght_child)
            {
                //add this's right child to this's right bottom
                my_BinaryTree * pause_tree = tree->rght_child;
                tree->rightBottom()->rght_child = pause_tree;
            }

            tree->rght_child = ct;
            ct->site = tree->site * 2 + 1;
        }
        break;
        default:
        {
            //if this have left child
            if(tree->lft_child)
            {
                //add this's left child to this's left bottom
                my_BinaryTree * pause_tree = tree->lft_child;
                tree->leftBottom()->lft_child = pause_tree;
            }
            tree->lft_child = ct;
            ct->site = tree->site * 2;
        }
    }
    tree->weight += ct->weight;
    ct->pa = tree;
    return true;
}

bool my_BinaryTree::setParent(my_BinaryTree * pr) {
    pa = pr;

    return true;
}

my_BinaryTree *my_BinaryTree::locateTree(int st) {
    std::queue<my_BinaryTree *> q;
    q.push(this);
    my_BinaryTree * tree = nullptr;
    if(lft_child)
        q.push(lft_child);
    if(rght_child)
        q.push(rght_child);
    while(!q.empty())
    {
        tree = q.front();
        q.pop();
        //if find this node
        if(tree->site == st)
            break;
        if(tree->lft_child)
        {
            q.push(tree->lft_child);
        }
        if(tree->rght_child)
        {
            q.push(tree->rght_child);
        }
    }
    if(!tree || tree->site != st)
        return nullptr;
    return tree;
}

my_BinaryTree *my_BinaryTree::rightBottom() {
    my_BinaryTree * q = rght_child;
    while(q->rght_child)
    {
        q = q->rght_child;
    }

    return q;
}

my_BinaryTree *my_BinaryTree::leftBottom() {
    my_BinaryTree * q = lft_child;
    while(q->lft_child)
    {
        q = q->lft_child;
    }
    return q;
}

bool my_BinaryTree::assign(int st,char ch) {
    my_BinaryTree * tree = locateTree(st);
    if(!tree)
        return false;
    tree->data = ch;
    return true;
}

bool my_BinaryTree::deleteChild(int st, int LR) {
    my_BinaryTree * tree = locateTree(st);
    if(!tree)
        return false;
    switch (LR){
        case 1 :
        {
            tree->weight -= tree->lft_child->weight;
            tree->lft_child = nullptr;
        }
        break;
        default:
        {
            tree->weight -= tree->rght_child->weight;
            tree->rght_child = nullptr;
        }
    }
    return true;
}

bool my_BinaryTree::preOrderTraverse() {
    std::stack<my_BinaryTree *> s;
    my_BinaryTree * tree = this;

    do{
        //do not have left child
        if(!tree)
        {
            tree = s.top();
            s.pop();
            tree = tree->rght_child;
            continue;
        }
        cout<<"site "<<tree->site<<" , data : "<<tree->data<<" "<<endl;
        s.push(tree);
        tree = tree->lft_child;
    }while(!s.empty() || tree);
    cout<<endl<<"preOrderTraverse finish."<<endl;

    return true;
}

bool my_BinaryTree::inOrderTraverse() {
    std::stack<my_BinaryTree *> s;
    my_BinaryTree * tree = this;

    do{
        //do not have left child
        if(!tree)
        {
            tree = s.top();
            cout<<"site "<<tree->site<<" , data : "<<tree->data<<" ";
            s.pop();
            tree = tree->rght_child;
            continue;
        }
        s.push(tree);
        tree = tree->lft_child;
    }while(!s.empty());
    cout<<endl<<"inOrderTraverse finish."<<endl;

    return true;

}

bool my_BinaryTree::postOrderTraverse() {
    std::stack<my_BinaryTree *> s;
    my_BinaryTree * tree = this;

    do{
        //do not have child
        if(!tree)
        {
            tree = s.top();
            s.pop();
            cout<<"site "<<tree->site<<" , data : "<<tree->data<<" ";
            tree = tree->rght_child;
            continue;
        }
        s.push(tree);
        if(tree->lft_child)
            tree = tree->lft_child;
        else if (tree->rght_child)
            tree = tree->rght_child;
        else
            tree = nullptr;
    }while(!s.empty());
    cout<<endl<<"postOrderTraverse finish."<<endl;

    return true;
}

bool my_BinaryTree::levelOrderTraverse() {
    //store node
    std::queue<my_BinaryTree *> q;
    cout<<"site "<<site<<" , data : "<<data<<" "<<" , weight : "<<weight<<endl;
    my_BinaryTree * tree = nullptr;
    if(lft_child)
        q.push(lft_child);
    if(rght_child)
        q.push(rght_child);
    while(!q.empty())
    {
        tree = q.front();
        cout<<"site "<<tree->site<<" , data : "<<tree->data<<" "<<" , weight : "<<tree->weight<<endl;
        q.pop();
        if(tree->lft_child)
        {
            q.push(tree->lft_child);
        }
        if(tree->rght_child)
        {
            q.push(tree->rght_child);
        }
    }
    cout<<endl<<"levelOrderTraverse finish."<<endl;

    return tree;
}

int my_BinaryTree::getWeight() {
    return weight;
}

bool my_BinaryTree::show() {
    cout<<"site "<<site<<" , data : "<<data<<" "<<" , weight : "<<weight;
    return true;
}

bool my_BinaryTree::coding(std::string file) {
    std::ofstream out(file);
    std::queue<my_BinaryTree *> q;
    my_BinaryTree * tree = nullptr;
    q.push(this);
    while(!q.empty())
    {
        tree = q.front();
        if(tree->data != '\0')
            {
                out<<tree->data<<" "<<tree->weight<<" "<<tree->code<<endl;
            }
        q.pop();
        //left add 0
        if(tree->lft_child)
        {
            q.push(tree->lft_child);
            tree->lft_child->code = tree->code + '0';
        }
        //right add 1
        if(tree->rght_child)
        {
            q.push(tree->rght_child);
            tree->rght_child->code = tree->code + '1';
        }
    }
    out.close();


    return true;
}

std::string my_BinaryTree::getCode() {
    return code;
}

std::string splitInt(unsigned int n)
{
    std::string str(32,'0');
    for(int i = 31;n != 0;i--)
    {
        str[i] = '0' + n % 2;
        n /= 2;
    }

    return str;
}
bool my_BinaryTree::deCodeFile(std::string filename) {
    std::ifstream in(filename);
    std::string str;
    my_BinaryTree * p = this;
    int i = 0;
    while(!in.eof())
    {
        i = 0;
        unsigned int nm;
        in>>nm;
        str = splitInt(nm);
        while(true)
        {
            //output the data
            if(p->data != '\0')
            {
                if(p->data != '\r')
                    cout<<p->data;
                p = this;
            }
            //this int decode finish
            if(i > 31)
                break;
            //0 turn left
            if(str[i] == '0')
            {
                p = p->lft_child;
            }
            //1 turn right
            else{
                p = p->rght_child;
            }
            i++;
        }
    }
    in.close();
    return true;
}