/*
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

char* shortestPath(int u, int v, char algorithm[], char name[])
{
    AdjGraph *g;
    int i;
    g = create_graph(g, name);

    for(i = 0; i < 410000; i++) {
        visited[i] = 0;
    }

    for(i = 0; i < 410000; i++) {
        dist[i] = 0;
    }

    for(i = 0; i < 410000; i++) {
        S[i] = 0;
    }

    for(i = 0; i < 410000; i++) {
        pp[i] = 0;
    }

    char *s;
    s = (char*)malloc(sizeof(char));

    char algo1[10] = "DFS";
    char algo2[10] = "BFS";
    char algo3[10] = "Dijkstra";

    if(cmp(algorithm, algo1) == 0) {
        Path *p = (Path*)malloc(sizeof(Path));
        p->d = -1;
        DFS(g, u, v, p);
    } else if(cmp(algorithm, algo2) == 0) {
        BFS(g, u, v);
    } else if(cmp(algorithm, algo3) == 0) {
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

Path *Dijkstra(AdjGraph *g, int u, int v, Path *P)
{

    int i;

    for(i = 0; i < 410000; i++) {
        dist[i] = inf;
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

        min = inf;

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

            while(qu[i].parent != -1) {
                pp[i] = qu[i].data;
                printf("%d -> ", qu[i].data);
                i = qu[i].parent;
            }

            printf("%d\n", qu[i].data);
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

/*void Dijkstra(AdjGraph *G, int u, int v)
{
    int i, j;
    //ÁÚ½ÓÁ´±í×ªÎªÁÚ½Ó¾ØÕó
    MatGraph *g = (MatGraph *)malloc(sizeof(MatGraph));


    for(i = 0; i < MAXV; i++) {
        for(j = 0; j < MAXV; j++) {
            if(i == j) {
                g->edges[i][j] = 0;
            } else {
                g->edges[i][j] = INF;
            }
        }
    }

    printf("%s\n", "Yes");
    ArcNode *p;

    for(i = 0; i < G->maxd; i++) {
        p = G->adjlist[i].firstarc ;

        while(p != NULL) {
            g.edges[i][p.adjvex] = p.weight ;
            p = p.nextarc;
        }
    } printf("%d %d %d \n", G->up_point , G->edge, G->maxd);

    g.up_point = G->up_point ;
    g.edge = G->edge ;
    g.maxd = G->maxd ;


    int *dist = (int *)malloc(MAXV * sizeof(int));
    int *path = (int *)malloc(MAXV * sizeof(int));
    int *S = (int *)malloc(MAXV * sizeof(int));
    int MINdis, k;

    for(i = 0; i < g.maxd; i++) {
        dist[i] = g.edges[u][i];
        S[i] = 0;

        if(g.edges[u][i] < INF) {
            path[i] = u;
        } else {
            path[i] = -1;
        }
    }

    S[u] = 1;
    path[u] = 0;

    for(i = 0; i < g.maxd - 1; i++) {
        MINdis = INF;

        for(j = 0; j < g.maxd; j++) {
            if(S[j] == 0 && dist[j] < MINdis) {
                k = j;
                MINdis = dist[j];
            }
        }

        S[k] = 1;

        for(j = 0; j < g.up_point; j++) {
            if(S[j] == 0) {
                if(g.edges[k][j] < INF && dist[k] + g.edges[k][j] < dist[j]) {
                    dist[j] = dist[k] + g.edges[k][j];
                    path[j] = k;
                }
            }
        }
    }

    //Êä³ö
    int *apath = (int *)malloc(MAXV * sizeof(int));
    int d;
    d = 0;
    apath[d] = v;//ÄæÐò´æ·ÅÂ·¾¶
    k = path[v];

    while(k != u) {
        d++;
        apath[d] = k;
        k = path[k];
    }

    d++;
    apath[d] = u;
    printf("%s\n", "ok");

    for(j = d; j > 0; j--) {
        printf("%d->", apath[j]);
    }

    printf("%d\n", apath[0]);

    //ÊÍ·Å
    free(g);
    free(apath);
    free(dist);
    free(path);
    free(S);
    return;
}*/
////////////////////////////////////////////////////////////////////////////////////////////ÒÔÉÏÊÇËâ·¨£¬²Î¿¼Êý¾Ý½á¹¹½Ì²Ä
char* shortestPath(int u, int v, char algorithm[], char name[]) {}/*
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

    if(strcmp(algorithm, "DFS") == 0 || strcmp(algorithm, "dfs") == 0)
    {
        DFS(G, u, v, dpath, 0);
    }
    else if(strcmp(algorithm, "BFS") == 0 || strcmp(algorithm, "bfs") == 0)
    {
    }
    else if(strcmp(algorithm, "Dijkstra") == 0)
    {
        Dijkstra(G, u, v);
    }

    return g_path;
}

*/