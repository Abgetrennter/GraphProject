#include "Graph.h"

AdjGraph *Creat_Undirect_G(char name[], AdjGraph* g) {

    int num1, num2, n, i;
    g = (AdjGraph*)malloc(sizeof(AdjGraph));
    FILE *fp;

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("%s\n", "Wrong");
        exit(2);
    }

    for(i = 0; i < MAXV; ++i)
    {
        g->adjlist[i].data = 0;
        g->adjlist[i].firstarc = NULL;
    }


    while((fscanf(fp, "%d%d%d", &num1, &num2, &n) != EOF)) {
        ArcNode *p, *q;

        if(find_re(g, num1, num2)) {
            p = (ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex = num2;
            p->nextarc = g->adjlist[num1].firstarc;
            g->adjlist[num1].firstarc = p;


            q = (ArcNode*)malloc(sizeof(ArcNode));
            q->adjvex = num1;
            q->nextarc = g->adjlist[num2].firstarc;
            g->adjlist[num2].firstarc = q;

            g->adjlist[num1].data++;
            g->adjlist[num2].data++;
        }
    }

    return g;
}

AdjGraph* free_CUG(AdjGraph*g) {
    int i;

    for(i = 0; i < MAXV; ++i)
    {
        ArcNode *p, *q;

        for(p = g->adjlist[i].firstarc; p != NULL;) {
            q = p;
            p = p->nextarc;

            free(q);
        }
    }

    free(g);

    g = NULL;

    return g;
}

int find_re(AdjGraph *g, int num1, int num2) {
    ArcNode *p, *q;
    q = g->adjlist[num1].firstarc;

    while(q != NULL) {
        if(q->adjvex == num2) {
            return 0;
        }

        q = q->nextarc;
    }

    return 1;
}