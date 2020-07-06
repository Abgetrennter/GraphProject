#include "Graph.h"
#include "stats.h"
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
        int flag = 1;
        ArcNode *p, *q, *pn, *qn;
        q = g->adjlist[num1].firstarc;
        p = g->adjlist[num2].firstarc;

        while(q != NULL) {
            if(q->adjvex == num2) {
                flag = 0;
                break;
            }

            q = q->nextarc;
        }

        if(flag == 1) {
            p = (ArcNode*)malloc(sizeof(ArcNode));
            q = (ArcNode*)malloc(sizeof(ArcNode));

            p->adjvex = num2;
            p->nextarc = g->adjlist[num1].firstarc;
            g->adjlist[num1].firstarc = p;

            q->adjvex = num1;
            q->nextarc = g->adjlist[num2].firstarc;
            g->adjlist[num2].firstarc = q;

        }
    }

    return g;
}

AdjGraph *C_DA_G(char name[], AdjGraph* g)
{

    int num1, num2, n, i, maxd = 0;
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
        ArcNode *p;
        p = (ArcNode*)malloc(sizeof(ArcNode));

        p->adjvex = num2;
        p->weight = n;

        p->nextarc = g->adjlist[num1].firstarc;
        g->adjlist[num1].firstarc = p;
    }

    g->n = numberOfEdges(name);
    g->e = numberOfVertices(name);

    for(i = 0; i < MAXV; ++i)
    {
        if(g->adjlist[i].firstarc != NULL && i > g->maxd)
        {
            g->maxd = i;
        }
    }

    return g;
}


AdjGraph* free_CUG(AdjGraph * g) {
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

int find_re(AdjGraph * g, int num1, int num2) {
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