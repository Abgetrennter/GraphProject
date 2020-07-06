#ifndef Graphy
#define Graphy

#include <stdio.h>
#include <stdlib.h>
#define MAXV 500000
#define INF 1000000

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
    int up_point, edge, maxd;
} AdjGraph;

typedef struct {
    int no;
} VertexType;

typedef struct {
    int edges[MAXV][MAXV];
    int up_point, edge, maxd;
    int vex[MAXV];
} MatGraph;

typedef struct {
    int path[410000];
    int d;
} Path;

typedef struct {
    int data;
    int parent;
} Queue;

int visited[410000];
int dist[410000];
int S[410000];
int pp[410000];
Queue qu[410000];




AdjGraph* C_DA_G(char name[], AdjGraph* g);

AdjGraph* Creat_Undirect_G(char name[], AdjGraph* g);

AdjGraph* free_CUG(AdjGraph*g);

int find_re(AdjGraph* g, int num1, int num2);

#endif
//search-cli.exe -g test.txt -s freeman