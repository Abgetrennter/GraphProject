#include <stdio.h>
#include "Graph.h"
#include <stdlib.h>

int numberOfEdges(char name[]) {
    int num = 0, n;
    FILE *fp;

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("%s\n", "Wrong");
        exit(2);
    }

    while((fscanf(fp, "%d%d%d", &n, &n, & n) != EOF))
    {
        num++;
    }

    fclose(fp);
    return num;
}

int numberOfVertices(char name[]) {
    int num = 0, p, q, n, i;
    FILE *fp;
    int *all;

    all = (int*)malloc(MAXV * sizeof(int));

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("%s\n", "Wrong");
        exit(2);
    }

    while((fscanf(fp, "%d%d%d", &p, &q, &n) != EOF)) {
        all[p] = 1;
        all[q] = 1;
    }

    for(i = 0; i < MAXV; ++i)
    {
        if(all[i] == 1)
        {
            num++;
        }
    }

    free(all);
    fclose(fp);
    return num;
}

float closenessCentrality(char name[], int node) {
    printf("%s\n", "sorry,we don't choose it.~(￣~￣)~*");
    return 0;
}

float freemanNetworkCentrality(char name[]) {
    int num1, num2, n, i;
    AdjGraph *g;
    g = Creat_Undirect_G(name, g);

    g->e = numberOfEdges(name);
    g->n = numberOfVertices(name);

    long long max = 0, sum = 0;

    for(i = 0; i < MAXV; i++) {
        ArcNode *vn;

        for(vn = g->adjlist[i].firstarc; vn != NULL; vn = vn->nextarc)
        {
            g->adjlist[i].data++;

        }
    }

    for(i = 0; i < MAXV; i++) {

        if(g->adjlist[i].data > max)
        {
            max = g->adjlist[i].data;
        }


    }

    for(i = 0; i < MAXV; ++i)
    {
        if(g->adjlist[i].data != 0)
        {
            sum += max - g->adjlist[i].data;
        }
    }

    double f, q;

    f =  1.0 * (sum) / (g->n - 1) ;
    f /= 1.0 * (g->n - 2);

    printf("%f\n", (float) f);

    return f;
}



