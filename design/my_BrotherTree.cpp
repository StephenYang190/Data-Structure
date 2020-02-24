//
// Created by 97927 on 2019/12/13.
//

#include "my_BrotherTree.h"
#include <stack>
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include "function.h"
#include <fstream>
#include <iomanip>
using namespace std;

my_BrotherTree::my_BrotherTree(std::string nm) {
    name = nm;
    layer = 1;
    parent = nullptr;
    child = nullptr;
    brother = nullptr;
}

bool my_BrotherTree::assign(my_BrotherTree *t, std::string parent_name) {
    my_BrotherTree * pa = findPeople(parent_name);
    //set t's layer
    t->layer = pa->layer + 1;
    //if parent have child
    if(pa->child)
    {
        pa = pa->child;
        //find the last child
        while(pa->brother)
        {
            pa = pa->brother;
        }
        pa->brother = t;
    } else{
        pa->child = t;
    }
    return true;
}

bool my_BrotherTree::showLevel() {
    using std::cout;
    using std::endl;
    //store the node
    std::queue<my_BrotherTree *> q;
    q.push(this);
    while(!q.empty())
    {
        my_BrotherTree * t = q.front();
        q.pop();
        cout<<"name : "<<name<<" "<<layer;
        if(t->parent)
            cout<<" parent : "<<t->parent->name;
        if(t->child)
        {
            cout<<endl;
            //if child exist
            my_BrotherTree * p = t->child;
            while(p)
            {
                q.push(p);
                cout<<p->name<<" ";
                p = p->brother;
            }
            cout<<endl;
        }
    }
    cout<<"Show level end."<<endl;

    return true;
}

bool my_BrotherTree::showTreeLayer(int layer) {
    using std::cout;
    using std::endl;
    //store node
    std::queue<my_BrotherTree *> q;
    q.push(this);
    while(!q.empty())
    {
        my_BrotherTree * t = q.front();
        q.pop();
        //if layer == n , output
        if(t->layer == layer)
        {
            cout<<"name : "<<name<<" "<<layer;
            if(t->parent)
                cout<<" parent : "<<t->parent->name;
            cout<<endl;
        }

        if(t->child)
        {
            my_BrotherTree * p = t->child;
            while(p)
            {
                q.push(p);
                if(t->layer == layer)
                    cout<<p->name<<" ";
                p = p->brother;
            }
            cout<<endl;
        }
    }

    return true;
}

my_BrotherTree *my_BrotherTree::findPeople(std::string nm) {
    //store node
    std::queue<my_BrotherTree *> q;
    my_BrotherTree * t = nullptr;
    q.push(this);
    while(!q.empty())
    {
         t = q.front();
        q.pop();
        if(t->name == nm)
            break;
        if(t->child)
        {
            my_BrotherTree * p = t->child;
            while(p)
            {
                q.push(p);
                p = p->brother;
            }
        }
    }
    //if find success
    if(t->name == nm)
        return t;
    return nullptr;
}

int my_BrotherTree::layers() {
    return layer;
}

std::string my_BrotherTree::names() {
    return name;
}

bool my_BrotherTree::showName() {
    using std::cout;
    cout<<name;
    return true;
}

bool my_BrotherTree::showLayer() {
    using std::cout;
    cout<<layer;

    return true;
}

bool my_BrotherTree::show() {
    using std::cout;
    using std::endl;
    cout<<"name : "<<name<<" "<<layer<<" ";
    if(parent)
        cout<<" parent : "<<parent->name;
    if(child)
    {
        cout<<endl;
        my_BrotherTree * p = child;
        while(p)
        {
            cout<<p->name<<" ";
            p = p->brother;
        }
        cout<<endl;
    }

    return true;
}

bool my_BrotherTree::setLayer(int n) {
    layer = n;
    return true;
}

bool my_BrotherTree::setName(std::string nm1) {
    name = nm1;
    return true;
}

my_BrotherTree::my_BrotherTree() {
    layer = 1;
    parent = nullptr;
    child = nullptr;
    brother = nullptr;
}

my_BrotherTree::~my_BrotherTree() = default;


my_BrotherTree_plus::my_BrotherTree_plus(std::string nm, std::string born,std::string addre,
                                         bool marige, bool l,std::string death) :my_BrotherTree(nm){
    borndate = born;
    deathdate = death;
    my_BrotherTree_plus::addre = addre;
    my_BrotherTree_plus::marige = marige;
    live = l;
    parent = nullptr;
    brother = nullptr;
    child = nullptr;
}

bool my_BrotherTree_plus::showTreeLayer(int layer) {
    using std::cout;
    using std::endl;

    //store node
    std::queue<my_BrotherTree_plus *> q;
    q.push(this);
    while(!q.empty())
    {
        my_BrotherTree_plus * t = q.front();
        q.pop();
        int n_lay = t->layers();
        std::string names = t->names();
        //if layer == n , output
        if(n_lay == layer)
        {
            cout<<endl<<"name : "<<names<<" "<<layer;
            if(t->parent)
            {
                cout<<" parent : ";
                t->parent->showName();
            }

            cout<<endl;
        }

        if(t->child)
        {
            my_BrotherTree_plus * p = t->child;
            while(p)
            {
                q.push(p);
                if(n_lay == layer)
                {
                    cout<<endl<<"child : ";
                    p->showName();
                    cout<<" ";
                }
                p = p->brother;
            }
        }
    }

    return true;
}

bool my_BrotherTree_plus::find(std::string nm) {
    using std::cout;
    using std::endl;
    my_BrotherTree_plus * t = findPeople(nm);
    //if don't have the people
    if(!t)
        return false;
    t->show();
    cout<<"born :"<<t->borndate<<endl;
    if(!live)
        cout<<"dead : "<<t->deathdate<<endl;
    cout<<"address :"<<t->addre;
    cout<<endl;

    return true;
}
my_BrotherTree_plus *my_BrotherTree_plus::findPeople(std::string nm) {
    using std::cout;
    using std::endl;
    //store node
    std::queue<my_BrotherTree_plus *> q;
    my_BrotherTree_plus * t = nullptr;
    std::string names;
    q.push(this);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        names = t->names();
        if(names == nm)
            break;
        if(t->marige)
        {
            my_BrotherTree_plus * p = t->child;
            while(p)
            {
                q.push(p);
                p = p->brother;
            }
        }
    }
    //if find success
    if(t->names() == nm)
        return t;
    return nullptr;
}

bool my_BrotherTree_plus::assign(my_BrotherTree_plus *t, std::string parent_name) {
    my_BrotherTree_plus * pa = findPeople(parent_name);
    if(!pa)
    {
        return false;
    }
    //assign to parent
    if(!pa->child)
    {
        pa->child = t;
    } else{
        my_BrotherTree_plus * ch = pa->child;
            while(ch->brother)
            {
                ch = ch->brother;
            }
            ch->brother = t;
    }
    //set t's layer
    t->setLayer(pa->layers() + 1);
    //set t's parent
    t->parent = pa;
    return true;
}

bool my_BrotherTree_plus::deletePeople(std::string peo) {
    using std::cout;
    using std::endl;
    my_BrotherTree_plus * thepro = findPeople(peo);
    if(!thepro)
    {
        cout<<"don't have this people."<<endl;
        return false;
    }
    //certain the choice
    cout<<"certain the delete command.(1 means yes)"<<endl<<"delete : ";
    thepro->show();
    int cer = getInt("command");
    //if quit
    if(cer != 1)
        return false;
    std::queue<my_BrotherTree_plus *> q;
    //delete from parent
    my_BrotherTree_plus * t = thepro->parent->child;
    //if this node's parent have two or more children
    if(t->brother)
    {
        //find brother
        while(t->brother)
        {
            if(t->brother == thepro)
            {
                t->brother = t->brother->brother;
                break;
            }
        }
    }
    //have one child
    else{
        thepro->parent->child = nullptr;
    }
    std::string names;
    q.push(thepro);
    //delete all children
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(t->marige)
        {
            my_BrotherTree_plus * p = t->child;
            while(p)
            {
                q.push(p);
                p = p->brother;
            }
        }
        delete t;
    }
    return true;
}

bool my_BrotherTree_plus::setBorn(std::string nm,std::string born) {
    my_BrotherTree_plus * p = findPeople(nm);
    if(!p)
    {
        cout<<"don't have this people."<<endl;
        return false;
    }
    p->borndate = born;
    return true;
}

bool my_BrotherTree_plus::setAddress(std::string nm,std::string add) {
    my_BrotherTree_plus * p = findPeople(nm);
    if(!p)
    {
        cout<<"don't have this people."<<endl;
        return false;
    }
    p->addre = add;
    return true;
}

bool my_BrotherTree_plus::setMar(std::string nm,bool mrg) {
    my_BrotherTree_plus * p = findPeople(nm);
    if(!p)
    {
        cout<<"don't have this people."<<endl;
        return false;
    }
    p->marige = mrg;
    return true;
}

bool my_BrotherTree_plus::setLive(std::string nm,bool lf) {
    my_BrotherTree_plus * p = findPeople(nm);
    if(!p)
    {
        cout<<"don't have this people."<<endl;
        return false;
    }
    bool pause = p->live;
    p->live = lf;
    if(pause)
    {
        //if change from exist to death
        if(!lf)
        {
            std::string death = getString("deathdate");
            deathdate = death;
        }
    } else{
        if(lf)
        {
            deathdate = "";
        }
    }

    return true;
}

bool my_BrotherTree_plus::setDeathdate(std::string nm, std::string death) {
    my_BrotherTree_plus * p = findPeople(nm);
    if(!p)
    {
        cout<<"don't have this people."<<endl;
        return false;
    }
    //if people exist
    if(p->live)
    {
        using std::cout;
        using std::endl;
        cout<<nm<<" is alive."<<endl;
        return false;
    }
    p->deathdate = death;

    return true;
}

my_BrotherTree_plus::my_BrotherTree_plus(std::string filename) {
    std::ifstream in(filename);
    std::string names;
    in>>names;
    setName(names);
    std::string born;
    in>>born;
    borndate = born;
    std::string add;
    in>>add;
    addre = add;
    int lv;
    std::string death;
    in>>lv;
    live = (lv == 1);
    if(!lv)
    {
        in>>death;
        deathdate = death;
    }
    int mar;
    in>>mar;
    marige = (mar == 1);
    parent = nullptr;
    child = nullptr;

    while(!in.eof())
    {
        in>>names;
        in>>born;
        in>>add;
        in>>lv;
        if(!lv)
        {
            in>>death;
        }
        in>>mar;
        std::string pa;
        in>>pa;
        my_BrotherTree_plus * p = new my_BrotherTree_plus(names,born,add,mar == 1,lv == 1,death);
        assign(p,pa);
    }
    in.close();
}

bool my_BrotherTree_plus::setNames(std::string nm, std::string nm1) {
    my_BrotherTree_plus * p = findPeople(nm);
    if(p)
    {
        p->setName(nm1);
        return true;
    }
    return false;
}

bool my_BrotherTree_plus::showAll() {
    using std::cout;
    using std::endl;
    int lay = 1;
    //store node
    std::queue<my_BrotherTree_plus *> q;
    q.push(this);
    while(!q.empty())
    {
        my_BrotherTree_plus * t = q.front();
        q.pop();
        //if this node is at next layer
        if(t->layers() != lay)
        {
            cout<<endl;
            lay = t->layers();
        }
        cout<<t->showName()<<" ";
        if(t->child)
        {
            my_BrotherTree_plus * p = t->child;
            while(p)
            {
                q.push(p);
                p = p->brother;
            }
        }
    }
    cout<<"Show Finish."<<endl;

    return true;
}

my_BrotherTree_plus::~my_BrotherTree_plus() = default;

bool my_BrotherTree_plus::outToFile() {
    std::ofstream out_tx("task4result.txt");
    using std::endl;
    std::queue<my_BrotherTree_plus *> q;
    q.push(this);
    my_BrotherTree_plus * p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        out_tx<<p->names()<<" "<<p->borndate<<" "<<p->addre<<" ";
        if(p->live == 0)
            out_tx<<"0 "<<p->deathdate<<" ";
        if(p->marige == 1)
            out_tx<<"1 ";
        else
            out_tx<<"0 ";
        if(p->parent)
            out_tx<<p->parent->names();
        out_tx<<'\n';
        if(p->child)
        {
            my_BrotherTree_plus * t = p->child;
            while(t)
            {
                q.push(t);
                t = t->brother;
            }
        }
    }
    out_tx.close();
    return true;
}

bool inVector(vector<my_BrotherTree_plus *> &v,string nm)
{
    for(int i = 0;i < v.size();i++)
    {
        if(v[i]->names() == nm)
            return true;
    }
    return false;
}

bool my_BrotherTree_plus::showBron() {
    cout<<std::left;
    //store node
    vector<my_BrotherTree_plus *> v;
    std::queue<my_BrotherTree_plus *> q;
    q.push(this);
    int courn = 0;//node number
    while(!q.empty())
    {
        my_BrotherTree_plus * t = q.front();
        v.push_back(t);
        q.pop();
        courn++;
        if(t->child)
        {
            my_BrotherTree_plus * p = t->child;
            while(p)
            {
                q.push(p);
                p = p->brother;
            }
        }
    }
    for(int i = 0;i < courn;i++)
    {
        my_BrotherTree_plus * min = v[i];
        int min_s = i;
        for(int k = i + 1;k < courn;k++)
        {
            if(min->borndate > v[k]->borndate)
            {
                min = v[k];
                min_s = k;
            }
        }
        if(min_s == i)
            continue;
        v.erase(v.begin() + min_s);
        v.insert(v.begin() + i,min);
    }
    cout <<setw(20)<<"name"<<"\t\t";
    cout <<setw(20)<<"born date"<<endl;
    for(int i = 0;i < courn;i++)
    {
        cout <<setw(20)<<v[i]->names()<<"\t\t";
        cout <<setw(20)<<v[i]->borndate<<endl;
    }

    return false;
}

int my_BrotherTree_plus::size() {
    std::queue<my_BrotherTree_plus *> q;
    q.push(this);
    int courn = 0;
    while(!q.empty())
    {
        my_BrotherTree_plus * t = q.front();
        q.pop();
        courn++;
        if(t->child)
        {
            my_BrotherTree_plus * p = t->child;
            while(p)
            {
                q.push(p);
                p = p->brother;
            }
        }
    }

    return courn;
}
//1 = nm2 parent \ 2 = nm1 parent \ 3 = nm2 grandparent \ 4 = nm1 grandparent \ 5 = brother
int my_BrotherTree_plus::relationship(std::string nm1, std::string nm2) {
    my_BrotherTree_plus * pro1 = findPeople(nm1);
    my_BrotherTree_plus * pro2 = findPeople(nm2);
    if(pro1->layers() == pro2->layers())
    {
        return 5;
    }
    if(pro1->layers() > pro2->layers())
    {
        if(pro1->parent == pro2)
            return 1;
        if(pro1->parent->parent == pro2)
            return 3;
    }
    else{
        if(pro2->parent == pro1)
            return 2;

        if(pro2->parent->parent == pro1)
            return 4;
    }

    return 0;
}
