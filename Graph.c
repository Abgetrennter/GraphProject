#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

AdjGraph *C_UDA_G(char name[], AdjGraph* g) {

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

    printf("%s\n", "3");

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
            p->adjvex = num2;
            p->nextarc = g->adjlist[num1].firstarc;
            g->adjlist[num1].firstarc = p;
            //g->adjlist[num1].data++;

            q = (ArcNode*)malloc(sizeof(ArcNode));
            q->adjvex = num1;
            q->nextarc = g->adjlist[num2].firstarc;
            g->adjlist[num2].firstarc = q;
            //g->adjlist[num2].data++;
        }
    }

    return g;
}