#ifndef Graphy
#define Graphy

#define MAXV 1000000

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

AdjGraph* C_UDA_G(char name[], AdjGraph* g);

MatGraph* C_DM_G(char name[], MatGraph* g);

#endif
//search-cli.exe -g test.txt -s freeman