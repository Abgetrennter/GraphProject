#include "search.h"


int visit[MAXV] = {0};
int g_visited[MAXV] = {0};//ÓÃÓÚ±ê¼Ç¸Ã¶¥µãÊÇ·ñ±»·ÃÎÊ
int g_path[MAXV];
int flag = 0;

void DFS(AdjGraph *G, int u, int v, int dpath[], int d) //d???-1;dpath??????
{
    ArcNode *p;
    int j, w;
    d++;
    dpath[d] = u;
    visit[u] = 1;

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

        if(visit[w] == 0 && flag == 0) {
            DFS(G, w, v, dpath, d);
        } else if(flag == 1) {
            return;
        }

        p = p->nextarc;
    }

    visit[u] = 0;
}
Path *Dijkstra(AdjGraph *g, int u, int v, Path *P)
{

    int i;

    for(i = 0; i < 410000; i++) {
        dist[i] = INF;
    }

    S[u] = 1;
    dist[u] = 0;

    ArcNode *q;
    q = (ArcNode *)malloc(sizeof(ArcNode));
    q = g->adjlist[u].firstarc;

    while(q != NULL) {
        P->path[q->adjvex] = u;
        dist[q->adjvex] = q->weight;
        q = q->nextarc;
    }

    int min;
    int j;
    int k;

    for(i = 0; i < 410000; i++) {
        if(g->adjlist[i].firstarc == NULL) {
            continue;
        }

        min = INF;

        for(j = 0; j < 410000; j++) {
            if(g->adjlist[j].firstarc == NULL) {
                continue;
            }

            if(S[j] == 0 && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }

        S[k] = 1;
        q = g->adjlist[k].firstarc;

        while(q != NULL) {
            if(dist[k] + q->weight < dist[q->adjvex]) {
                dist[q->adjvex] = dist[k] + q->weight;
                P->path[q->adjvex] = k;
            }

            q = q->nextarc;
        }
    }

    return P;
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
                pp[i] = qu[i].data;
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

    for(i = 0; i < 410000; i++) {
        visited[i] = 0; dist[i] = 0; S[i] = 0; pp[i] = 0;
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
        Path *p = (Path*)malloc(sizeof(Path));
        p = Dijkstra(g, u, v, p);
        int i = 0;

        while(p->path[v] != u) {
            pp[i] = v;
            v = p->path[v];
            i++;
        }

        pp[i++] = v;
        pp[i] = u;

        while(i > 0) {
            printf("%d -> ", pp[i]);
            i--;
        }

        printf("%d\n", pp[0]);
        pp[i++] = v;
        pp[i] = u;
        int j = 0;
    }

    return s;
}


/*
{
    AdjGraph *G;
    int i, j, k;

    int *dpath;
    dpath = (int *)malloc(MAXV * sizeof(int));


    //µ÷ÓÃstatsÀïÃæµÄº¯Êý°ÑÍ¼µÄÁÚ½Ó±í×ö³öÀ´

    G = C_DA_G(name, G);

    for(i = 0; i < MAXV; ++i)
    {
        g_path[i] = 0;
        dpath[i] = 0;
    }

    for(i = 0; i <= MAXV; i++)//visitÊý×é£¬g_pathmin¸³Öµ
    {
        g_visited[i] = 0;
    }


    printf("\nUsing %s:\n", algorithm);



    return g_path;
}

*/