//
// Created by 97927 on 2019/12/25.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "my_Graph.h"
#include <vector>
#include "function.h"
using namespace std;

int main()
{
    my_Graph g("spanningtree.txt");
    //g.BFSTraverse();
    cout<<endl;
    cout<<"kruskal"<<endl<<g.kruskalSpinningTree()<<endl;
    cout<<"prim"<<endl<<g.primSpanningTree()<<endl;

    system("read -p 'Press Enter to continue...' var");
    return 0;
}