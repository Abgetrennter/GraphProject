#include "search.h"

int g_path[MAXV];
int flag = 0;

void DFS(AdjGraph *G, int u, int v, int dpath[], int d)
{
    ArcNode *p;
    int j, w;
    d++;
    dpath[d] = u;
    visited[u] = 1;

    if(u == v && d > 0) {
        flag = 1;

        for(j = 1; j < d; j++) {
            printf("%d->", dpath[j]);
        }

        printf("%d\n", dpath[d]);
        return;
    }

    p = G->adjlist[u].firstarc;

    while(p != NULL)
    {
        w = p->adjvex;

        if(visited[w] == 0 && flag == 0) {
            DFS(G, w, v, dpath, d);
        } else if(flag == 1) {
            return;
        }

        p = p->nextarc;
    }

    visited[u] = 0;
}

void Dijkstra(AdjGraph *G, int u, int v)
{
    MatGraph *g = (MatGraph *)malloc(sizeof(MatGraph));
    int i, j;

    for(i = 0; i < MAXV; i++) {
        for(j = 0; j < MAXV; j++) {
            if(i == j) {
                g->edges[i][j] = 0;
            } else {
                g->edges[i][j] = INF;
            }
        }
    }

    ArcNode *p;

    for(i = 0; i < G->maxd; i++) {
        p = G->adjlist[i].firstarc ;

        while(p != NULL) {
            g->edges[i][p->adjvex] = p->weight ;
            p = p->nextarc;
        }
    }

    printf("%d\n", G->maxd);

    g->n = G->n ;
    g->e = G->e ;
    g->maxd = G->maxd ;


    int *dist = (int *)malloc(MAXV * sizeof(int));
    int *path = (int *)malloc(MAXV * sizeof(int));
    int *S = (int *)malloc(MAXV * sizeof(int));
    int MINdis, k;

    for(i = 0; i < g->maxd; i++) {
        dist[i] = g->edges[u][i];
        S[i] = 0;

        if(g->edges[u][i] < INF) {
            path[i] = u;
        } else {
            path[i] = -1;
        }
    }

    S[u] = 1;
    path[u] = 0;

    for(i = 0; i < g->maxd - 1; i++) {
        MINdis = INF;

        for(j = 0; j < g->maxd; j++) {
            if(S[j] == 0 && dist[j] < MINdis) {
                k = j;
                MINdis = dist[j];
            }
        }

        S[k] = 1;

        for(j = 0; j < g->n; j++) {
            if(S[j] == 0) {
                if(g->edges[k][j] < INF && dist[k] + g->edges[k][j] < dist[j]) {
                    dist[j] = dist[k] + g->edges[k][j];
                    path[j] = k;
                }
            }
        }
    }

    int *apath = (int *)malloc(MAXV * sizeof(int));
    int d;
    d = 0;
    apath[d] = v;
    k = path[v];

    while(k != u) {
        d++;
        apath[d] = k;
        k = path[k];
    }

    d++;
    apath[d] = u;

    for(j = d; j > 0; j--) {
        printf("%d->", apath[j]);
    }

    printf("%d\n", apath[0]);

    free(g);
    free(apath);
    free(dist);
    free(path);
    free(S);
    return;
}


void BFS(AdjGraph *g, int u, int v)
{
    ArcNode *p;
    int w, i;
    int front, rear;
    front = rear = -1;
    rear++;

    qu[rear].data = u;
    qu[rear].parent = -1;

    visited[u] = 1;

    while(front != rear) {
        front++;
        w = qu[front].data;

        if(w == v) {
            i = front;
            int a = 0, b;
            int *apath = (int *)malloc(MAXV * sizeof(int));

            while(qu[i].parent != -1) {
                u_to_vs[i] = qu[i].data;
                apath[a] = qu[i].data;
                a++;
                i = qu[i].parent;
            }

            apath[a] = qu[i].data;

            for(b = a; b > 0; b--) {
                printf("%d->", apath[b]);
            }

            printf("%d\n", apath[b]);
            free(apath);
            return;
        }

        p = g->adjlist[w].firstarc;

        while(p != NULL) {
            if(visited[p->adjvex] == 0) {
                visited[p->adjvex] = 1;
                rear++;
                qu[rear].data = p->adjvex;
                qu[rear].parent = front;
            }

            p = p->nextarc;
        }
    }
}

char* shortestPath(int u, int v, char algorithm[], char name[])
{
    AdjGraph *g;
    char *s;
    s = (char*)malloc(MAXV * sizeof(char));
    int i;
    g = C_DA_G(name, g);

    for(i = 0; i < MAXV; i++) {
        visited[i] = 0;
    }

    if(strcmp(algorithm, "DFS") == 0 || strcmp(algorithm, "dfs") == 0)
    {
        DFS(g, u, v, g_path, 0);
    }
    else if(strcmp(algorithm, "BFS") == 0 || strcmp(algorithm, "bfs") == 0)
    {
        BFS(g, u, v);
    }
    else if(strcmp(algorithm, "Dijkstra") == 0)
    {
        Dijkstra(g, u, v);
    }

    return s;
}