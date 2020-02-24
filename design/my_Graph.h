//
// Created by 97927 on 2019/12/13.
//

#ifndef DESIGN_MY_GRAPH_H
#define DESIGN_MY_GRAPH_H

#include <string>
#include <vector>
#include <fstream>
#define MAX 65535

class edge{
public:
    int node1,node2;
    float distance;
    edge(int n1,int n2,float d)//initial
    {
        node1 = n1;
        node2 = n2;
        distance = d;
    }
    ~edge()= default;;
};
class GNode{
private:
    int site;
    std::string data;
protected:
public:
    std::vector<float> out_e;//out egde , undirected graph only use this
    std::vector<float> in_e;//in edge
    GNode(int s, std::string d)//initial
    {
        site = s;
        data = d;
    }
    GNode(int s, std::string d, int n)//initial
    {
        site = s;
        data = d;
        out_e.assign(n,MAX);
    }
    bool setSite(int s)//change this node's site
    {
        site = s;
        return true;
    }
    bool setData(std::string da)//change this node's data
    {
        data = da;
    }
    float distanceNode(int st)//return between this node and st
    {
        return out_e[st];
    }
    bool enOutEdge(int st,float dis)//set distance between this node and st
    {
        out_e[st] = dis;

        return true;
    }
    int outEdgeNumber()//return out edge number
    {
        return out_e.size();
    }
    bool show();//show this node information
    std::string getData();//return this node data
    int firstAdjVex();//return the nearest node
    int nextAdjVex(int node1);//return the nearest node after node1
    bool deleteVex(int node1);//delete edge with node1
    ~GNode()= default;
};
class my_Graph {
private:
    std::vector<GNode> frt;
    int nd_num;
    int eg_num;
public:
    my_Graph(int nd_n,int eg_n);//initial
    my_Graph(int nd_n,int eg_n,float dis);//initial
    my_Graph(std::string filename);//initial
    ~my_Graph();
    int locateVex(std::string str);//locate node
    std::string getVex(int site);//return node's data
    bool putVex(int site,std::string str);//change the data of the node which st == site
    GNode * firstAdjVex(int site);//return the nearest node of the ndoe st == site
    GNode * nextAdjVex(int node1,int node2);//return the nearest node after node1 of the ndoe st == site
    float primSpanningTree();//prim
    float kruskalSpinningTree();//kruskal
    bool InsertVex();//add node
    bool DeleteVex(int site);//delete node
    bool InsertArc(int node1,int node2);//add edge
    bool BFSTraverse(int bgn = 0);//BFS traverse the graph
    int getNodeNumber();//return the node number
    bool dijkstra(std::vector<float> & T,int bgn);//find short distance from bgn to other node
};
class gNode_plus : public GNode{
private:
public:
    std::vector<int> bus;
    gNode_plus(int s, std::string d):GNode(s,d){}//initial
    gNode_plus(int s, std::string d, int n):GNode(s, d, n){}//initial
    ~gNode_plus(){}
    bool enBus(int n);//add bus line
    bool deBus(int n);//delete bus line
};
class my_Graph_Bus {
private:
    std::vector<gNode_plus> frt;
    int nd_num;
    int eg_num;
public:
    my_Graph_Bus(std::string filename);//initial
    int locateVex(std::string str);//locate node
    bool BFSTraverse(int bgn = 0);//BFS traverse the graph
    bool bfsGo(std::string node1,std::string node2);//find the fast way
    bool dfsGo(std::string node1,std::string node2);//find the easiest way
    int someLine(int node1,int node2,int limit = 0);//return the same line between after limit
};
class bfsNode
{
public:
    int nw;
    int pa;
    bfsNode(int n = -1,int p = -1){
        nw = n;
        pa = p;
    }
    bool operator=(const bfsNode &b) {
        nw = b.nw;
        pa = b.pa;
    }
};
#endif //DESIGN_MY_GRAPH_H
