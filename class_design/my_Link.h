//
// Created by 97927 on 2019/12/2.
//

#ifndef CLASS_DESIGN_MY_LINK_H
#define CLASS_DESIGN_MY_LINK_H

class LNode{
public:
    int data;
    LNode * next;
    LNode(int n = 0,LNode * nxt = nullptr);
};
class my_Link {
private:
     LNode * Fst;
    LNode * Lst;
    int Length;
public:
    my_Link();//create first node which don't store data
    bool empty();//true = empty
    int length();//return the length
    bool getElem(int i,int *e);//get the ith data ; e to store the data
    int locateElem(int e);//locate the data e
    bool priorElem(int e,LNode * pre);//find data e prior
    bool nextElem(int e,LNode * next);//find data e next
    bool clearLink();//delete all nodes expect the first node
    bool insert(int i,int e);//insert data e to site i
    bool deleteNode(int i = 1,int * e = nullptr);//delete ith node , e to store,default i = 1,e = null
    bool addLink(int e);//add data to last
    bool showLink();//show all data

    ~my_Link();
};


#endif //CLASS_DESIGN_MY_LINK_H
