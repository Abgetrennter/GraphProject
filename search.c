
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

        for(j = 0; j < d; j++) {
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

void Dijkstra(AdjGraph *G, int u, int v)
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
            g->edges[i][p->adjvex] = p->weight ;
            p = p->nextarc;
        }
    } printf("%d %d %d \n", G->up_point , G->edge, G->maxd);

    g->up_point = G->up_point ;
    g->edge = G->edge ;
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

        for(j = 0; j < g->up_point; j++) {
            if(S[j] == 0) {
                if(g->edges[k][j] < INF && dist[k] + g->edges[k][j] < dist[j]) {
                    dist[j] = dist[k] + g->edges[k][j];
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
}
////////////////////////////////////////////////////////////////////////////////////////////ÒÔÉÏÊÇËâ·¨£¬²Î¿¼Êý¾Ý½á¹¹½Ì²Ä
char* shortestPath(int u, int v, char algorithm[], char name[])
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

