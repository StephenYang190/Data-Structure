//
// Created by 97927 on 2020/1/2.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include "function.h"
using namespace std;

#define MAZELENGTH 10
#define MAZEWIDE 10

/*0 = road / 1 = wall / 2 = beginning / 3 = ending / 4 = road have go / 5 = bfs road*/
class bfsNode{
public:
    int n1,n2;
    int p1,p2;//last node position
    bfsNode(int d1 = -1,int d2 = -1,int d3 = -1,int d4 = -1)
    {
        n1 = d1;
        n2 = d2;
        p1 = d3;
        p2 = d4;
    }
    bool set(int d1 = -1,int d2 = -1,int d3 = -1,int d4 = -1)
    {
        n1 = d1;
        n2 = d2;
        p1 = d3;
        p2 = d4;
    }
};
class dfsNode{
public:
    int n1,n2;
    int dir;//last direction
    dfsNode(int d1 = -1,int d2 = -1,int d3 = -1)
    {
        n1 = d1;
        n2 = d2;
        dir = d3;
    }
    bool operator=(const dfsNode &d)
    {
        n1 = d.n1;
        n2 = d.n2;
        dir = d.dir;
        return true;
    }
};

bool bfsTraverse(int  maze[][MAZELENGTH],int begin1,int begin2)
{
    queue<bfsNode> que;
    stack<bfsNode> s;
    bfsNode p;
    que.push(bfsNode(begin1, begin2));
    while(!que.empty())
    {
        p = que.front();
        que.pop();
        s.push(p);

        if(p.n2 - 1 > -1)
        {
            //find the end
            if(maze[p.n1][p.n2 - 1] == 3)
                break;
            if(maze[p.n1][p.n2 - 1] == 0)
            {
                bfsNode nw(p.n1, p.n2 - 1, p.n1, p.n2);
                que.push(nw);
                maze[p.n1][p.n2 - 1] = 4;
            }
        }
        if(p.n1 - 1 > -1)
        {
            //find the end
            if(maze[p.n1 - 1][p.n2] == 3)
                break;
            if(maze[p.n1 - 1][p.n2] == 0)
            {
                bfsNode nw(p.n1 - 1, p.n2, p.n1, p.n2);
                que.push(nw);
                maze[p.n1 - 1][p.n2] = 4;
            }
        }
        if(p.n1 + 1 < MAZEWIDE)
        {
            //find the end
            if(maze[p.n1 + 1][p.n2] == 3)
                break;
            if(maze[p.n1 + 1][p.n2] == 0)
            {
                bfsNode nw(p.n1 + 1, p.n2, p.n1, p.n2);
                que.push(nw);
                maze[p.n1 + 1][p.n2] = 4;
            }
        }
        if(p.n2 + 1 < MAZELENGTH)
        {
            //find the end
            if(maze[p.n1][p.n2 + 1] == 3)
                break;
            if(maze[p.n1][p.n2 + 1] == 0)
            {
                bfsNode nw(p.n1, p.n2 + 1, p.n1, p.n2);
                que.push(nw);
                maze[p.n1][p.n2 + 1] = 4;
            }
        }
    }
    if(!que.empty())
    {
        //find the road
        int node1 = p.p1,node2 = p.p2;
        maze[p.n1][p.n2] = 5;
        while(!s.empty())
        {
            bfsNode pause;
            pause = s.top();
            s.pop();
            if(maze[pause.n1][pause.n2] == 4)
                maze[pause.n1][pause.n2] = 0;
            //find the last node
            if(pause.n1 == node1 && pause.n2 == node2)
            {
                maze[pause.n1][pause.n2] = 5;
                node1 = pause.p1;
                node2 = pause.p2;
            }
        }
    }
    else{
        cout<<"don't have way"<<endl;
        return false;
    }
    //restitute the maze
    while(!que.empty())
    {
        bfsNode pause;
        pause = que.front();
        que.pop();
        if(maze[pause.n1][pause.n2] == 4)
            maze[pause.n1][pause.n2] = 0;
    }

    return true;
}

bool dfsTraverse(int  maze[][MAZELENGTH],int begin1,int begin2)
{
    stack<dfsNode> s;
    bool flag = true;
    bool end = false;
    s.push(dfsNode(begin1,begin2,0));
    while(!s.empty()) {
        dfsNode p;
        int dir;
        //don't need to change direction
        if (flag) {
            dir = 0;
        } else {
            dir = s.top().dir;
            maze[s.top().n1][s.top().n2] = 0;
            s.pop();
        }
        p = s.top();
        switch (dir) {
            case 0 : {
                if (p.n1 + 1 < MAZEWIDE) {
                    if (maze[p.n1 + 1][p.n2] == 3)
                    {
                        end = true;
                        break;
                    }
                    if (maze[p.n1 + 1][p.n2] == 0) {
                        s.push(dfsNode(p.n1 + 1, p.n2, 1));
                        maze[p.n1 + 1][p.n2] = 5;
                        flag = true;
                        break;
                    }
                }
            }
            case 1 : {
                if (p.n2 - 1 > 0) {
                    if (maze[p.n1 + 1][p.n2] == 3)
                    {
                        end = true;
                        break;
                    }
                    if (maze[p.n1][p.n2 - 1] == 0) {
                        s.push(dfsNode(p.n1, p.n2 - 1, 2));
                        maze[p.n1][p.n2 - 1] = 5;
                        flag = true;
                        break;
                    }
                }
            }
            case 2 : {
                if (p.n1 - 1 > 0) {
                    if (maze[p.n1 + 1][p.n2] == 3)
                    {
                        end = true;
                        break;
                    }
                    if (maze[p.n1 - 1][p.n2] == 0) {
                        s.push(dfsNode(p.n1 - 1, p.n2, 3));
                        maze[p.n1 - 1][p.n2] = 5;
                        flag = true;
                        break;
                    }
                }
            }
            case 3 : {
                if (p.n2 + 1 < MAZEWIDE) {
                    if (maze[p.n1 + 1][p.n2] == 3)
                    {
                        end = true;
                        break;
                    }
                    if (maze[p.n1][p.n2 + 1] == 0) {
                        s.push(dfsNode(p.n1, p.n2 + 1, 4));
                        maze[p.n1][p.n2 + 1] = 5;
                        flag = true;
                        break;
                    }
                }
            }
            default: {
                flag = false;
            }
        }
        if(end)
            break;
    }
    if(s.empty())
    {
        cout<<"don't have way"<<endl;
        return false;
    }
    return true;
}

int main()
{
    ifstream in("maze.txt");
    int maze[MAZEWIDE][MAZELENGTH] = {0};
    for(int i = 0;i < MAZEWIDE;i++)
    {
        for(int k = 0;k < MAZELENGTH;k++)
        {
            int node;
            in>>node;
            maze[i][k] = node;
        }
    }
    in.close();
    //printf the maze
    for(int i = 0;i < MAZEWIDE;i++)
    {
        for(int k = 0;k < MAZELENGTH;k++)
        {
            switch (maze[i][k]) {
                case 0 :
                    cout<<"o ";
                    break;
                case 1 :
                    cout<<'\24'<<" ";
                    break;
                case 2 :
                    cout<<"B ";
                    break;
                case 3 :
                    cout<<"$ ";
                    break;
                case 4 :
                case 5 :
                    cout<<"* ";
                    break;
            }
        }
        cout<<endl;
    }
    int node1,node2,node3,node4;
    while(true)
    {
        node1 = getInt("beginning node's raw");
        node2 = getInt("beginning node's column");
        //array site
        if(maze[node1 - 1][node2 - 1] == 0)
        {
            maze[node1 - 1][node2 - 1] = 2;
            break;
        }
        cout<<"This node is wall"<<endl;
    }
    while(true)
    {
        node3 = getInt("ending node's raw");
        node4 = getInt("ending node's column");
        if(maze[node3 - 1][node4 - 1] == 0)
        {
            maze[node3 - 1][node4 - 1] = 3;
            break;
        }
        cout<<"This node is wall"<<endl;
    }
    //show the road
    if(bfsTraverse(maze, node1 - 1, node2 - 1))
   {
        maze[node1 - 1][node2 - 1] = 2;
        for(int i = 0;i < MAZEWIDE;i++)
        {
            for(int k = 0;k < MAZELENGTH;k++)
            {
                switch (maze[i][k]) {
                    case 0 :
                        cout<<"o ";
                        break;
                    case 1 :
                        cout<<'\24'<<" ";
                        break;
                    case 2 :
                        cout<<"B ";
                        break;
                    case 3 :
                        cout<<"$ ";
                        break;
                    case 4 :
                    case 5 :
                        cout<<"* ";
                        break;
                }
            }
            cout<<endl;
        }
   }

    return 0;
}