//
// Created by 97927 on 2019/12/31.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

class b_Tree {
private:
    vector<int> data;
    int size;//size of the tree
    int nowsize;
    vector<b_Tree *> child;
    b_Tree *root;
    b_Tree *pa;

    b_Tree *upOn(b_Tree *p);//split to up
    b_Tree *dowmDe(b_Tree * p,int &n);//merge to bottom
    bool mergeTree(b_Tree *p1, b_Tree *p2, int pa_dt);//merge the pa and child
    //find this tree is the nth child of parent
    int siteForParent(b_Tree * p)
    {
        int i = 0;
        for(;i< p->pa->child.size();i++)
        {
            if(p->pa->child[i] == p)
                break;
        }
        return i;
    }
    //find this data's site
    int siteForDate(b_Tree * p,int dt)
    {
        for(int k = 0;k < p->data.size();k++)
        {
            if(p->data[k] == dt)
            {
                return k;
            }
        }
        return -1;
    }


public:
    //initial
    b_Tree(int dt, int sz, b_Tree *parent = nullptr) {
        data.push_back(dt);
        size = sz;
        nowsize = 1;
        pa = parent;
        root = this;
    }
    //initial
    b_Tree(int dt, int sz, b_Tree *parent, b_Tree *rt) {
        data.push_back(dt);
        size = sz;
        nowsize = 1;
        pa = parent;
        root = rt;
    }
    //initial
    b_Tree(vector<int> &dt, int sz, b_Tree *parent = nullptr) {
        data.insert(data.begin(), dt.begin(), dt.end());
        size = sz;
        nowsize = 1;
        pa = parent;
        root = this;
    }
    //initial add child
    bool inchild(vector<b_Tree *> &c) {
        child.insert(child.end(), c.begin(), c.end());

        return true;
    }
    //add new data
    bool append(int dt) {
        b_Tree *p = root;
        while (p) {
            //find the position
            bool flag = false;
            int i = 0;
            while (i < p->data.size()) {
                if (p->data[i] > dt) {
                    flag = true;
                    break;
                }
                i++;
            }

            if (p->child.empty()) {
                //leaves
                if (flag) {
                    //add to the ith position
                    p->data.insert(p->data.begin() + i, dt);
                } else {
                    //add back
                    p->data.push_back(dt);
                }
                //if this full out
                b_Tree *q = upOn(p);
                while (q) {
                    q = upOn(q);
                }
                break;
            } else {
                //find in child
                if (!flag) {
                    p = p->child.back();
                } else {
                    p = p->child[i];
                }
            }
        }
    }

    bool show() {
        std::queue<b_Tree *> q;
        b_Tree *p = root;
        cout << "(";
        for (int i = 0; i < p->data.size(); i++) {
            cout << p->data[i] << ",";
        }
        cout << ")" << endl;
        if (!p->child.empty()) {
            for (int i = 0; i < p->child.size(); i++) {
                q.push(p->child[i]);
            }
        }
        q.push(nullptr);
        while (!q.empty()) {
            p = q.front();
            if (p == nullptr) {
                q.pop();
                cout << endl;
                if (!q.empty())
                    q.push(nullptr);
                continue;
            }
            cout << "(";
            for (int i = 0; i < p->data.size(); i++) {
                cout << p->data[i] << ",";
            }
            cout << ")" << "\t";
            q.pop();
            if (!p->child.empty()) {
                for (int i = 0; i < p->child.size(); i++) {
                    q.push(p->child[i]);
                }
            }
        }
        cout << endl << "levelOrderTraverse finish." << endl;

        return true;
    }
    //delete data
    bool delt(int dt)
    {
        b_Tree * p = root;
        int i = 0;
        while(p)
        {
            bool flag = false;
            i = 0;
            //find data
            while (i < p->data.size()) {
                if (p->data[i] >= dt) {
                    flag = true;
                    break;
                }
                i++;
            }
            if(p->data[i] == dt)
                break;
            if(!p->child.empty())
            {
                if (!flag) {
                    p = p->child.back();
                } else {
                    p = p->child[i];
                }
            }
        }
        if(p->data[i] == dt)
        {
            int n = dt;
            while(p)
            {
                p = dowmDe(p,n);
            }
        }
        return true;
    }
};

b_Tree *b_Tree::upOn(b_Tree *p) {
    b_Tree * q = nullptr;
    if(p->data.size() > p->size) {
        //split to two trees
        vector<int>  dt2;
        int dt_mi = p->data[size / 2];
        int st = size / 2;
        dt2.insert(dt2.begin(), p->data.begin() + st + 1, p->data.end());
        p->data.erase(p->data.begin() + st, p->data.end());
        b_Tree * t2 = new b_Tree(dt2, size, p->pa);
        if (!p->child.empty()) {
            vector<b_Tree *>  c2;
            for(int i = st + 1;i < p->child.size();i++)
            {
                c2.push_back(p->child[i]);
                p->child[i]->pa = t2;
            }
            t2->inchild(c2);
            p->child.erase(p->child.begin() + st + 1, p->child.end());
        }
        q = p->pa;
        if(q)
        {   int i = 0;
            while(i < q->data.size())
            {
                if(dt_mi < q->data[i])
                    break;
                i++;
            }
            q->data.insert(q->data.begin() + i,dt_mi);
            q->child.insert(q->child.begin() + i + 1,t2);
        } else{
            q = new b_Tree(dt_mi,size);
            q->child.push_back(p);
            q->child.push_back(t2);
            p->pa = q;
            t2->pa = q;
            root = q;
            return nullptr;
        }
    }
    //up on to the parent node and deal with the parent node
    return q;
}

b_Tree *b_Tree::dowmDe(b_Tree *p, int &n) {
    b_Tree * parent = p->pa;
    int st = size / 2 - 1;
    int dt_st = siteForDate(p,n);
    //if it is leaf
    if(p->child.empty())
    {
        p->data.erase(p->data.begin() + dt_st);
        //if have n / 2 + 1 numbers
        if(p->data.size() > st)
        {
            return nullptr;
        }
        else{

            bool flag = false;
            int i = siteForParent(p);
            //if left tree have n / 2 + 1 numbers
            if(parent->child[i + 1]->data.size() > st + 1)
            {
                flag = true;
            }
            if(flag)
            {
                //replace the number by parent number , replace the parent number by left tree number
                p->data.push_back(parent->data[i]);
                parent->data.erase(parent->data.begin() + i);
                parent->data.insert(parent->data.begin() + i,parent->child[i + 1]->data.front());
                n = parent->child[i + 1]->data.front();
                return parent->child[i + 1];
            }
            else{
                //merge two trees
                mergeTree(p,parent->child[i + 1],parent->data[i]);
                parent->child.erase(parent->child.begin() + i);
                n = parent->data[i];
                return parent;
            }
        }
    } else{
        int nw_dt = p->child[dt_st]->data.back();
        n = nw_dt;
        p->data[dt_st] = nw_dt;
        return p->child[dt_st];
    }
}
//merge two trees and the parent number
bool b_Tree::mergeTree(b_Tree *p1, b_Tree *p2, int pa_dt) {
    p1->data.push_back(pa_dt);
    p1->data.insert(p1->data.end(),p2->data.begin(),p2->data.end());
    delete p2;
}

int main()
{
    int nm;
    string filename("opinion19.txt");
    ifstream in(filename);
    in>>nm;
    b_Tree t(nm,3);
    while(!in.eof())
    {
        in>>nm;
        cout<<nm<<endl;
        t.append(nm);
        t.show();
    }
    in.close();
    t.show();
    t.delt(11);
    t.show();
    return 0;
}