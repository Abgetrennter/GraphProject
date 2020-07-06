#ifndef Graphy
#define Graphy

#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000000
#define INF 32767

typedef struct ANode {
    int adjvex;
    struct ANode * nextarc;
    int weight;
} ArcNode;

typedef struct Vnode {
    int data;
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[MAXV];
    int up_point, edge;
} AdjGraph;

typedef struct {
    int no;
} VertexType;

typedef struct {
    int edges[MAXV][MAXV];
    int up_point, edge;
    /*VertexType*/int vex[MAXV];
} MatGraph;

AdjGraph* C_DA_G(char name[], AdjGraph* g);

AdjGraph* Creat_Undirect_G(char name[], AdjGraph* g);

MatGraph* C_DM_G(char name[], MatGraph* g);

AdjGraph* free_CUG(AdjGraph*g);

int find_re(AdjGraph* g, int num1, int num2);

#endif
//search-cli.exe -g test.txt -s freeman