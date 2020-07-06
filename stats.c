#include <stdio.h>
#include "Graph.h"
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;

    if(x[0] != y[0]) {
        return x[0] - y[0];
    } else {
        return x[1] - y[1];
    }
}


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
}




float freemanNetworkCentrality(char name[]) {
    int num1, num2, n, i;
    AdjGraph *g;
    g = C_UDA_G(name, g);

    //if(g == NULL)


    g->edge = numberOfEdges(name);
    g->up_point = numberOfVertices(name);
    printf("%s\n", "1");
    //printf("%s\n", "q");

    /*ArcNode *vn;

    if(g->adjlist[p].firstarc == NULL)
    {
        vn = (ArcNode*)malloc(sizeof(ArcNode));
        vn->adjvex = q;
        vn->nextarc = NULL;
        g->adjlist[p].firstarc = vn;
        //g->adjlist[p].data++;
        //g->adjlist[q].data++;
    } else {
        ArcNode *vnp;

        for(vn = g->adjlist[i].firstarc; vn != NULL; vn = vn->nextarc)
        {
            if(vn->adjvex == q)
            {
                break;
            }

            vnp = vn;
        }

        if(vn != NULL)
        {
            continue;
        }

        vn = (ArcNode*)malloc(sizeof(ArcNode));
        vn->adjvex = q;
        vn->nextarc = NULL;
        vnp->nextarc = vn;
        //g->adjlist[p].data++;
        //g->adjlist[q].data++;
    }
    }*/

    long long max = 0, sum = 0;

    for(i = 0; i < MAXV; i++) {
        ArcNode *vn;

        for(vn = g->adjlist[i].firstarc; vn != NULL; vn = vn->nextarc)
        {
            g->adjlist[i].data++;
            //g->adjlist[vn->adjvex].data++;
        }
    }

    for(i = 0; i < MAXV; i++) {
        /*if(g->adjlist[i].firstarc == NULL)
        {
            continue;
        }*/

        if(g->adjlist[i].data > max)
        {
            max = g->adjlist[i].data;
        }


    }

//sum += g->adjlist[i].data;
    //  max *= g->up_point;

    for(i = 0; i < MAXV; ++i)
    {
        if(g->adjlist[i].data != 0)
        {
            sum += max - g->adjlist[i].data;
        }

    }


    //sum = max  - sum;
    printf("%d %lld %lld\n", max, sum, ((g->up_point - 1) * (g->up_point - 2)));
    double f, q;
    f =  1.0 * (sum) / (g->up_point - 1) ;
    f /= 1.0 * (g->up_point - 2);
    printf("%f\n", (float) f);
    return f;
}





/*
float freemanNetworkCentrality(char name[]) {

    //g = (MatGraph*)malloc(1*sizeof(MatGraph));
    int p, q, n, i, j, max, maxnum;
    int up_point;
    int **edges, *vex;
    FILE *fp;
    long long sum = 0;

    //if(g == NULL)
    printf("%s\n", "1");

    //g.up_point = 0;
    up_point = numberOfVertices(name);
    printf("%s\n", "1.1");

    vex = (int*)malloc(MAXV * sizeof(int));

    edges= (int**)malloc(MAXV * sizeof(int));

    printf("%s\n", "1.5");

    for(i = 0; i < MAXV; ++i)
    {
        vex[i] = 0;
        //printf("%f ", (float)i / MAXV);
    }

    printf("%s\n", "2");

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("%s\n", "Wrong");
        exit(2);
    }

    while((fscanf(fp, "%d%d%d", &p, &q, &n) != EOF)) {
        if(p < q)
        {
            edges[q][p] = 1;
        }
        else {
            edges[p][q] = 1;
        }
     //up_point++;
    }

    maxnum = 0;
    max = 0;
    printf("%s\n", "3");

    for(i = 0; i < up_point; ++i)
    {
        for(j = 0; j < up_point; j++) {
            if(edges[i][j] == 1)
            {
                vex[i]++;
            }
        }

        if(vex[i] > max)
        {
            maxnum = i;
            max = vex[i];
        }

        sum += vex[i];
    }

    sum -= (long long)(max) * (up_point);

    sum /= (long long)(up_point - 1) * (up_point - 2);
    printf("%s\n", "4");
    fclose(fp);
    //free(g);

    return (float)sum;

    //printf("%s\n", "sorry,we don't choose it.~(￣▽￣)~*");
}*/
/*{
    fscanf(fp, "%d%d%d", &node1, &node2, &weight1);
    int flag = 1;
    s = (ArcNode*)malloc(sizeof(ArcNode));
    q = (ArcNode*)malloc(sizeof(ArcNode));
    p = (ArcNode*)malloc(sizeof(ArcNode));
    q = G->adjlist[ node2]●firstarc;

    while(q != NULL) {
        if(q->adjvex == node1) {
            flag = 0;
            break;
        }

        q = q->nextarc;
    }

    if(flag == 1) {
        s->adjvex = node2;
        s->nextarc = G->adjlist[node1] . firstarc;
        G->adjlist[node1]. firstarc = s;
        p->adjvex = node1;
        p->nextarc = G->adjlist[ node2] . firstarc;
        G->adjlist[node2] .firstarc = p;
    }
*/