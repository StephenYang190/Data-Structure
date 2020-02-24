//
// Created by HP on 2019/11/16.
//

#ifndef CCODE6_GRAPH_H
#define CCODE6_GRAPH_H

#ifndef TDY
typedef enum {false,true}statue;
#define TDY
#endif

#define MAX_NUMBER 65535

typedef struct ADT_GRAPH
{
    int site;
    char data;
}GraphNode,* PointNode;
typedef struct
{
    int node1;
    int node2;
    int distance;
}GraphEdge,* PointEdge;
typedef struct
{
    PointNode node;
    int ** edge;
    int node_nowsite;
    int node_length;

}Graph,* GraphPoint;

/*finish*/
statue CreateGraph(GraphPoint g);
/*finish*/
statue DestroyGraph(GraphPoint g);
/*finish*/
int LocateVex(Graph g,char elem);
/*finish*/
char GetVex(Graph g,int site);
/*finish*/
statue PutVex(GraphPoint g,int site,char elem);
/*finish*/
PointNode FirstAdjVex(GraphPoint g,int site);
/*finish*/
PointNode NextAdjVex(GraphPoint g,int node1,int node2);
/*finish*/
statue InsertVex(GraphPoint g);
statue DeleteVex(GraphPoint g,int site);
/*finish*/
statue InsertArc(GraphPoint g,int node1,int node2);
/*finish*/
statue DFSTraverse(Graph g);
/*finish*/
statue BFSTraverse(Graph g);

#endif //CCODE6_GRAPH_H
