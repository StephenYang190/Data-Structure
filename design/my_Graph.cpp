//
// Created by 97927 on 2019/12/13.
//

#include "my_Graph.h"
#include <iostream>
#include "function.h"
#include <queue>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
#define YTD

bool sortVector(std::vector<edge> &e)
{
    int length = e.size();
    for(int k = 0;k < length;k++)
    {
        int minW = e[k].distance;
        int minS = k;
        for(int i = k + 1;i < length;i++)
        {
            if(e[i].distance > minW)
            {
                minW = e[i].distance;
                minS = i;
            }
        }
        if(minS == k)
            continue;
        edge pause = e[minS];
        e.erase(e.begin() + minS);
        e.insert(e.begin() + k,pause);
    }
    return true;
}

my_Graph::my_Graph(int nd_n,int eg_n) {
    nd_num = nd_n;
    eg_num = eg_n;
    for(int i = 0;i < nd_n;i++)
    {
        std::string str = getString();
        GNode n_node(i,str,nd_n);
        frt.push_back(n_node);
        frt[i].show();
    }
    for(int i = 0;i < eg_n;i++)
    {
        int n_st1 = getInt("node1 site");
        int n_st2 = getInt("node2 site");
        float dis = getFloat("distance");
        frt[n_st1].enOutEdge(n_st2,dis);
        frt[n_st2].enOutEdge(n_st1,dis);
    }
}

int my_Graph::locateVex(std::string str) {
    for(int i = 0;i < nd_num;i++)
    {
        if(frt[i].getData() == str)
            return i;
    }
    return -1;
}

std::string my_Graph::getVex(int site) {
    return frt[site].getData();
}

bool my_Graph::putVex(int site, std::string str) {
    frt[site].setData(str);

    return true;
}

GNode *my_Graph::firstAdjVex(int site) {
    int st = frt[site].firstAdjVex();
    if(st == -1)
        return nullptr;
    return &frt[st];
}

GNode *my_Graph::nextAdjVex(int node1, int node2) {
    int st = frt[node1].nextAdjVex(node2);
    if(st == -1)
        return nullptr;
    return &frt[st];
}

bool my_Graph::InsertVex() {
    std::string str = getString();
    GNode n_node(nd_num,str,nd_num++);
    frt.push_back(n_node);
    for(int i = 0;i < nd_num;i++)
    {
        frt[i].out_e.push_back(MAX);
    }
    frt[nd_num].show();

    return true;
}

bool my_Graph::DeleteVex(int site) {
    char c;
    frt[site].show();
    cout<<"concern the command : ( y to yes)";
    //decide the delete
    cin>>c;
    if(c != 'y')
        return false;
    frt.erase(frt.begin() + site);
    nd_num--;
    for(int i = 0;i < nd_num;i++)
    {
        frt[i].deleteVex(site);
    }

    return true;
}

bool my_Graph::InsertArc(int node1, int node2) {
    float dis = getFloat("distance");
    frt[node1].enOutEdge(node2,dis);
    frt[node2].enOutEdge(node1,dis);

    return true;
}

bool my_Graph::BFSTraverse(int bgn) {
    //sign the node
    std::vector<int> D(nd_num,0);
    //store the node
    std::queue<int> P;
    frt[bgn].show();
    cout<<endl;
    D[bgn] = 1;
    //find near node
    for(int i = 0;i < nd_num;i++)
    {
        if(frt[bgn].out_e[i] == MAX)
            continue;
        P.push(i);
        D[i] = 1;
    }
    while(!P.empty()){
        int node1 = P.front();
        P.pop();
        frt[node1].show();
        cout<<endl;
        for(int i = 0;i < nd_num;i++)
        {
            if(D[i] || frt[node1].out_e[i] == MAX)
                continue;
            P.push(i);
            D[i] = 1;
        }
    }

    return true;
}

my_Graph::my_Graph(std::string filename) {
    std::ifstream in(filename);
    int nd_n;
    in>>nd_n;
    nd_num = nd_n;
    for(int i = 0;i < nd_n;i++)
    {
        std::string str;
        in>>str;
        GNode n_node(i,str,nd_n);
        frt.push_back(n_node);
        frt[i].show();
        cout<<endl;
    }
    while(!in.eof())
    {
        eg_num++;
        int n_st1,n_st2;
        std::string n1,n2;
        float dis;
        in>>n1>>n2>>dis;
        n_st1 = locateVex(n1);
        n_st2 = locateVex(n2);
        if(n_st1 == -1 || n_st2 == -1)
            continue;
        frt[n_st1].enOutEdge(n_st2,dis);
        frt[n_st2].enOutEdge(n_st1,dis);
    }
    in.close();
}

int my_Graph::getNodeNumber() {
    return nd_num;
}

float my_Graph::primSpanningTree() {
    //vector to concern the node have past
    std::vector<bool> D(nd_num,false);
    D[0] = true;
    float sum = 0;
    while(true)
    {
        float min = MAX;
        int node1 = 0,node2 = 0;
        bool flag = false;
        //find the nearest node
        for(int i  = 0;i < nd_num;i++)
        {
            if(D[i])
             {
                for(int k = 0;k < nd_num;k++)
                {
                    if(D[k])
                        continue;
                    if(frt[i].out_e[k] < min)
                    {
                        flag = true;
                        node1 = i;
                        node2 = k;
                        min = frt[i].out_e[k];
                    }
                }
             }
        }
        //do not have , break
        if(!flag)
        {
            break;
        }
        //output edge
        if(D[node1])
        {
#ifndef  YTD
            cout<<"enter ";
            frt[node2].show();
#endif
            D[node2] = true;
            cout<<"edge node1 : "<<frt[node1].getData()<<" node2 : "<<frt[node2].getData();
            cout<<" distance : "<<min<<endl;
        } else{
#ifndef YTD
            cout<<"enter node : ";
            frt[node1].show();
#endif
            D[node1] = true;
            cout<<endl<<"edge node1 : "<<frt[node1].getData()<<" node2 : "<<frt[node2].getData();
            cout<<" distance : "<<min<<endl;
        }
        sum += min;
    }
    cout<<"prim end."<<endl;
    return sum;
}

float my_Graph::kruskalSpinningTree() {
    //vector to concern the node have past ?
    std::vector<bool> D(nd_num,false);
    float sum = 0;
    std::vector<edge> P;
    //sort edge
    for(int i = 0;i < nd_num;i++)
    {
        for(int k = i + 1;k < nd_num;k++)
        {
            if(frt[i].out_e[k] != MAX)
            {
                edge nw_eg(i,k,frt[i].out_e[k]);
                P.push_back(nw_eg);
            }
        }
    }
    sortVector(P);
    while(!P.empty())
    {
        edge pause = P.back();
        P.pop_back();
        //find the shortest edge
        if(!D[pause.node1] || !D[pause.node2])
        {
            sum += pause.distance;
            D[pause.node1] = true;
            D[pause.node2] = true;
            cout<<"edge node1 : "<<frt[pause.node1].getData()<<" node2 : "<<frt[pause.node2].getData();
            cout<<" distance : "<<pause.distance<<endl;
        } else{
            continue;
        }
    }
    cout<<"kru end."<<endl;
    return sum;
}

my_Graph::my_Graph(int nd_n, int eg_n, float dis) {
    nd_num = nd_n;
    eg_num = eg_n;
    for(int i = 0;i < nd_n;i++)
    {
        std::string str;
        str += 'a' + i;
        GNode n_node(i,str,nd_n);
        frt.push_back(n_node);
        frt[i].show();
    }
    for(int i = 0;i < eg_n;i++)
    {
        int n_st1 = getInt("node1 site");
        int n_st2 = getInt("node2 site");;
        frt[n_st1 - 1].enOutEdge(n_st2 - 1,dis);
        frt[n_st2 - 1].enOutEdge(n_st1 - 1,dis);
    }
}

bool my_Graph::dijkstra(std::vector<float> & T,int bgn) {
    std::vector<bool> D(nd_num,false);
    for(int i = 0;i < nd_num;i++)
    {
        T.push_back(frt[bgn].out_e[i]);
    }
    int p = bgn;
    D[bgn] = true;
    while(true)
    {
        int min = -1;
        //find the nearest node do not be traverse
        for(int i = 0;i < nd_num;i++)
        {
            if(D[i])
                continue;
            if(min == -1 || T[i] < min)
            {
                min = T[i];
                p = i;
            }
        }
        if(min == -1)
            break;
        //refresh the distance
        for(int i = 0;i < nd_num;i++)
        {
            if(D[i])
                continue;
            if(T[i] > T[p] + frt[p].out_e[i])
            {
                T[i] = T[p] + frt[p].out_e[i];
            }
        }
        D[p] = true;
    }
    return true;
}

my_Graph::~my_Graph() = default;

bool GNode::show() {
    cout<<"node : "<<data<<" site : "<<site;

    return true;
}

std::string GNode::getData() {
    return data;
}

int GNode::firstAdjVex() {
    int i = 0;
    for(;i < out_e.size();i++)
    {
        if(out_e[i] != MAX)
        {
            break;
        }
    }
    if(out_e[i] != MAX)
        return i;
    return -1;
}

int GNode::nextAdjVex(int node1) {
    int i = node1 + 1;
    for(;i < out_e.size();i++)
    {
        if(out_e[i] != MAX)
            break;
    }
    if(out_e[i] != MAX)
        return i;
    return -1;
}

bool GNode::deleteVex(int node1) {
    out_e.erase(out_e.begin() + node1);
    return true;
}

bool gNode_plus::enBus(int n) {
    int i = 0;
    for(;i < bus.size();i++)
    {
        if(bus[i] == n)
            return false;
        if(bus[i] > n)
            break;
    }
    bus.insert(bus.begin() + i,n);

    return true;
}

bool gNode_plus::deBus(int n) {
    int i = 0;
    for(;i < bus.size();i++)
    {
        if(bus[i] == n)
            break;
        if(bus[i] > n)
            return false;
    }
    if(bus[i] == n)
        bus.erase(bus.begin() + i);

    return true;
}

my_Graph_Bus::my_Graph_Bus(std::string filename)
{
    std::ifstream in(filename);
    nd_num = 0;
    eg_num = 0;
    while(!in.eof())
    {
        int bsln;
        in>>bsln;
        int str_last = -1;
        while(true)
        {
            std::string str;
            in>>str;
            if(str == "z")
                break;
            int st = locateVex(str);
            if(st == -1)
            {
                frt.push_back(gNode_plus (nd_num,str,5652));
                st = nd_num;
                nd_num++;
            }
            frt[st].enBus(bsln);
            if(str_last != -1)
            {
                frt[st].enOutEdge(str_last,1);
                frt[str_last].enOutEdge(st,1);
                eg_num++;
            }
            str_last = st;
        }
    }

    in.close();
}

int my_Graph_Bus::locateVex(std::string str) {
    for(int i = 0;i < nd_num;i++)
    {
        if(frt[i].getData() == str)
            return i;
    }
    return -1;
}

bool my_Graph_Bus::BFSTraverse(int bgn) {
    std::vector<int> D(nd_num,0);
    std::queue<int> P;
    frt[bgn].show();
    cout<<endl;
    D[bgn] = 1;
    //find the near node
    for(int i = 0;i < nd_num;i++)
    {
        if(frt[bgn].out_e[i] == MAX)
            continue;
        P.push(i);
        D[i] = 1;
    }
    while(!P.empty()){
        int node1 = P.front();
        P.pop();
        frt[node1].show();
        cout<<endl;
        for(int i = 0;i < nd_num;i++)
        {
            if(D[i] || frt[node1].out_e[i] == MAX)
                continue;
            P.push(i);
            D[i] = 1;
        }
    }

    return true;
}

bool my_Graph_Bus::bfsGo(std::string node1, std::string node2) {
    int nst1 = locateVex(node1);
    int nst2 = locateVex(node2);

    std::vector<bool> D(nd_num, false);
    std::queue<bfsNode> P;
    std::stack<bfsNode> s;
    D[nst1] = true;
    P.push(bfsNode(nst1));

    while(!P.empty()){
        bfsNode nd = P.front();
        P.pop();
        s.push(nd);
        if(nd.nw == nst2)
            break;
        //find near nodes
        for(int i = 0;i < nd_num;i++)
        {
            if(D[i] || frt[nd.nw].out_e[i] == MAX)
                continue;
            P.push(bfsNode(i,nd.nw));
            D[i] = true;
        }
    }
    if(P.empty())
    {
        cout<<"Don't have way."<<endl;
        return false;
    }
    //find the node's pa from pause stack
    int pa = s.top().pa;
    bfsNode nd = s.top();
    int dr = someLine(nd.nw,nd.pa);
    int last_node = nd.nw;
    int count = 1;
    cout<<"最快 : "<<endl;
    cout<<frt[nd.nw].getData()<<" -> line "<<dr<<" : ";
    s.pop();
    while(!s.empty())
    {
        nd = s.top();
        if(nd.nw == pa)
        {
            count++;
            //when the line is changed
            if(dr != someLine(last_node,pa))
            {
                dr = someLine(last_node,pa);
                cout<<frt[last_node].getData()<<" "<<count<<"zhan"<<endl<<frt[last_node].getData()<<" -> ";
                cout<<"line "<<dr<<" : ";
                count = 1;
            }
            last_node = pa;
            pa = nd.pa;
        }
        s.pop();
        if(s.empty())
        {
            cout<<frt[nd.nw].getData();
            cout<<endl;
        }
    }
    return true;
}

bool dirPass(std::vector<int> dr,int dir)
{
    for(int i = 0;i < dr.size();i++)
    {
        if(dr[i] == dir)
            return true;
    }
    return false;
}

class dfsNode{
public:
    int nw;
    int bus;
    dfsNode(int n1 = -1,int n2 = -1)
    {
        nw = n1;
        bus = n2;
    }
    ~dfsNode();
};

dfsNode::~dfsNode() {
}

bool my_Graph_Bus::dfsGo(std::string node1, std::string node2) {
    std::stack<dfsNode> s;
    std::vector<bool> D(nd_num,false);
    std::vector<int> dr;//direction have go
    int site1 = locateVex(node1);
    D[site1] = true;
    int site2 = locateVex(node2);
    s.push(dfsNode(site1,frt[site1].bus[0]));
    bool flag = true;
    bool end = false;
    dr.push_back(frt[site1].bus[0]);
    dfsNode p;
    while(!s.empty()) {
        //do not have the node
        if(!flag){
            end = false;
            p = s.top();
            //change direction
            for(int i = 0;i < frt[p.nw].out_e.size();i++) {
                if (frt[p.nw].out_e[i] != 1 || D[i])
                    continue;
                int dir = someLine(p.nw, i,p.bus);
                if (dirPass(dr, dir)) {
                    continue;
                } else {
                    dr.push_back(dir);
                    s.push(dfsNode(i,dir));
                    end = true;
                    flag = true;
                    break;
                }
            }
            if(!end)
            {
                D[s.top().nw] = false;
                s.pop();
            }
            continue;
        }
        flag = false;
        p = s.top();
        //find the next node along line dir
        int dir = p.bus;
        int k;
        int i;
        for(i = 0;i < frt[p.nw].out_e.size();i++)
        {
            if(frt[p.nw].out_e[i] > 2 || D[i])
                continue;
            for(k = 0;k < frt[i].bus.size();k++)
            {
                if(frt[i].bus[k] == dir)
                {
                    s.push(dfsNode(i,dir));
                    D[i] = true;
                    flag = true;
                    /*cout<<frt[i].show()<<endl;*/
                    break;
                }
            }
            if(flag)
                break;
        }
        if(i == site2)
            break;
    }
    if(s.empty())
    {
        cout<<"don't have way"<<endl;
        return false;
    }
    else{
        cout<<"最少换程 : "<<endl;
        int last_node = s.top().nw;
        int count = 1;
        cout<<frt[s.top().nw].getData();
        int dr = s.top().bus;
        cout<<" -> line "<<dr<<" : ";
        while(!s.empty())
        {
            count ++;
            //if change bus
            if(dr != s.top().bus)
            {
                dr = s.top().bus;
                cout<<frt[s.top().nw].getData()<<" "<<count<<"zhan"<<endl;
                cout<<frt[s.top().nw].getData()<<" -> line "<<dr<<" : ";
                count = 1;
            }
            if(s.size() == 1)
                cout<<frt[s.top().nw].getData()<<endl;
            s.pop();
        }
    }
    return true;
}

int my_Graph_Bus::someLine(int node1, int node2, int n) {
    int i = 0;
    int k = 0;
    for(;i < frt[node1].bus.size();)
    {
        if(frt[node1].bus[i] == frt[node2].bus[k])
        {
            if(frt[node1].bus[i] < n)
            {
                i++;
                k++;
                continue;
            }
            return frt[node1].bus[i];
        } else if (frt[node2].bus[k] < frt[node1].bus[i])
        {
            k++;
        } else{
            i++;
        }
    }

    return -1;
}
