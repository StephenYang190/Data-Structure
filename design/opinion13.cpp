//
// Created by 97927 on 2019/12/27.
//
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#define MAX 65535
class GNode{
private:
    int site;
    std::string data;
protected:
public:
    std::vector<int> out_e;//big road
    std::vector<int> in_e;//small road
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
        in_e.assign(n,MAX);
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
    bool enOutEdge(int st,int dis)//set distance between this node and st
    {
        out_e[st] = dis;

        return true;
    }
    int outEdgeNumber()//return out edge number
    {
        return out_e.size();
    }
    bool enInEdge(int st,int dis)
    {
        in_e[st] = dis;
        return true;
    }
    bool show();//show this node information
    ~GNode()= default;
};
class my_Graph {
private:
    std::vector<GNode> frt;
    int nd_num;
    int eg_num;
public:
    my_Graph(std::string filename);//initial
    ~my_Graph() = default;
    bool dijkstra(std::vector<int> & T,int bgn);

};
my_Graph::my_Graph(string filename)
{
    std::ifstream in(filename);
    int nd_n;
    in>>nd_n;
    nd_num = nd_n;
    for(int i = 0;i < nd_n;i++)
    {
        std::string str;
        str += '0' + (i / 10);
        str += '0' + (i % 10);
        GNode n_node(i,str,nd_n);
        frt.push_back(n_node);
        frt[i].show();
        cout<<endl;
    }
    in>>eg_num;
    while(!in.eof())
    {
        int tp;
        int n_st1,n_st2;
        int dis;
        in>>tp;
        in>>n_st1>>n_st2>>dis;
        if(n_st1 == -1 || n_st2 == -1)
            continue;
        if(tp == 0)
        {
            frt[n_st1 - 1].enOutEdge(n_st2 - 1,dis);
            frt[n_st2 - 1].enOutEdge(n_st1 - 1,dis);
        } else{
            frt[n_st1 - 1].enInEdge(n_st2 - 1,dis);
            frt[n_st2 - 1].enInEdge(n_st1 - 1,dis);
        }
    }
    in.close();
}

bool my_Graph::dijkstra(std::vector<int> &T, int bgn) {
    //sign the node have passed
    std::vector<bool> D(nd_num,false);
    //double Fatigue value
    std::vector<int> doubleT(nd_num,0);
    //initial distance
    for(int i = 0;i < nd_num;i++)
    {
        T.push_back(frt[bgn].out_e[i]);
    }
    //if small road is shorter
    for(int i = 0;i < nd_num;i++)
    {
        if(frt[bgn].in_e[i] == MAX)
            continue;
        int dis = frt[bgn].in_e[i] * frt[bgn].in_e[i];
        if(dis < T[i])
        {
            T[i] = dis;
            //store the fatigue value
            doubleT[i] = frt[bgn].in_e[i];
        }
    }
    int p = bgn;
    bool flag = false;
    D[bgn] = true;
    while(true)
    {
        int p_last = p;
        int min = -1;
        for(int i = 0;i < nd_num;i++)
        {
            if(D[i])
                continue;
            if(min == -1 || T[i] < min)
            {
                min = T[i];
                p = i;
                //if drive on big road
                flag = doubleT[i] > 0;
            }
        }
        if(min == -1)
            break;
        cout<<"from "<<p_last + 1<<" to "<<p + 1<<" by road ";
        if(flag)
            cout<<1;
        else
            cout<<0;
        cout<<" totally cost "<<T[p]<<endl;
        //if this time on small road
        if(flag)
        {
            int t = doubleT[p];
            for(int i = 0;i < nd_num;i++)
            {
                doubleT[i] = t;
            }
        } else{
            //clear the fatigue value
            for(int i = 0;i < nd_num;i++)
            {
                doubleT[i] = 0;
            }
        }
        //refresh distance
        for(int i = 0;i < nd_num;i++)
        {
            if(D[i])
                continue;
            if(frt[p].in_e[i] == MAX)
            {
                if(T[i] > T[p] + frt[p].out_e[i])
                {
                    T[i] = T[p] + frt[p].out_e[i];
                    doubleT[i] = 0;
                }
            } else {
                int dis = (frt[p].in_e[i] + 2 * doubleT[i]) * frt[p].in_e[i];
                if (dis > frt[p].out_e[i]) {
                    if (T[i] > T[p] + frt[p].out_e[i]) {
                        T[i] = T[p] + frt[p].out_e[i];
                        doubleT[i] = 0;
                    }
                } else {
                    if (T[i] > T[p] + dis) {
                        T[i] = T[p] + dis;
                        doubleT[i] += frt[p].in_e[i];
                    }
                }
            }
        }
        D[p] = true;
    }
    return true;
}

bool GNode::show() {
    cout<<"node : "<<data<<" site : "<<site;

    return true;
}
int main()
{
    std::string filename = "road13.txt";
    my_Graph g(filename);
    std::vector<int> T;
    g.dijkstra(T,0);
    cout<<T.back();

    return 0;
}
