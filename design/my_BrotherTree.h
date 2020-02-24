//
// Created by 97927 on 2019/12/13.
//

#ifndef DESIGN_MY_BROTHERTREE_H
#define DESIGN_MY_BROTHERTREE_H


#include <string>

class my_BrotherTree {
private:
    int layer;
    std::string name;
    my_BrotherTree * parent;
    my_BrotherTree * child;
    my_BrotherTree * brother;
protected:
    virtual my_BrotherTree * findPeople(std::string nm);//locate the people
public:
    my_BrotherTree(std::string nm);//initial
    my_BrotherTree();//initial
    virtual bool assign(my_BrotherTree * t,std::string parent_name);//assign parent_name chile
    virtual bool showTreeLayer(int layer);//show the nth layer people
    bool show();//show this node information
    bool showLevel();//show all people information as level
    int layers();//return layer
    std::string names();//return name
    bool showName();//show this node's name
    bool showLayer();//shwo this node's layer
    bool setLayer(int n);//change this node's layer
    bool setName(std::string nm1);//change this node's name

    ~my_BrotherTree();
};
class my_BrotherTree_plus : public my_BrotherTree{
private:
    std::string borndate;
    std::string deathdate;
    std::string addre;
    bool marige;
    bool live;
    my_BrotherTree_plus * parent;
    my_BrotherTree_plus * child;
    my_BrotherTree_plus * brother;
protected:
    my_BrotherTree_plus * findPeople(std::string nm);//locate people
public:
    my_BrotherTree_plus(std::string nm,std::string born,\
    std::string addre,bool marige,bool l,std::string death = "");//initial
    my_BrotherTree_plus(std::string filename);//initial from file
    bool assign(my_BrotherTree_plus * t,std::string parent_name);//assign parent_name's child
    bool showTreeLayer(int layer);//show nth layer people
    bool deletePeople(std::string peo);//delete a people and all his childeren
    bool find(std::string nm);//show a people all information
    bool setBorn(std::string nm,std::string born);//set born data
    bool setAddress(std::string nm,std::string add);//set address
    bool setMar(std::string nm,bool mrg);//set marige
    bool setLive(std::string nm,bool lf);//set live condition
    bool setDeathdate(std::string nm,std::string death);//set death date
    bool setNames(std::string nm,std::string nm1);//set name
    bool showAll();//show all people as level
    bool outToFile();//out to file
    ~my_BrotherTree_plus();
    bool showBron();//show as born date oder
    int size();//return the number of nodes
    int relationship(std::string nm1,std::string nm2);//relationship between two people
};

#endif //DESIGN_MY_BROTHERTREE_H
