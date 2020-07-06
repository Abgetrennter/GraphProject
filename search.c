#include "search.h"

void enQueue(Queue *qu, int k)
{
    if(qu->empty == 1)
    {
        qu->empty = 0;
    }
    else
    {
        qu->front = (qu->front + 1) % MAXV;
    }

    qu->data[qu->front] = k;
    //printf("enQueue: %d\n", e);
}

int deQueue(Queue *qu)
{
    int k = qu->data[qu->rear];

    if(qu->front != qu->rear)
    {
        qu->rear = (qu->rear + 1) % MAXV;
    }
    else
    {
        qu->empty = 1;
    }

    //printf("deQueue: %d\n", e);
    return k;
}

//采用邻接表的DFS算法：
void DFS(AdjGraph *G, int u, int v, bool &has)//参考数据结构教材
//has表示u到v是否有路径，初值为false
void DFS(AdjGraph *G, int u, int v, int dpath[], int d) //d初值为-1；dpath由主函数定义
{
    ArcNode *p;
    int j, w;
    d++;
    dpath[d] = u;
    visit[u] = 1;

    if(u == v && d > 0) {
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

        if(visit[w] == 0)
            DFS(G, w, v, dpath, d);

        p = p->nextarc;
    }

    visit[u] = 0;
}

//采用邻接表的BFS算法：
void BFS(AdjGraph *G, int u, int v)//求顶点u到顶点v的最短路径
{   //采用从顶点u出发广度优先搜索方法，当搜索到顶点v时，在队列中找出对应的路径
    int i, e;
    int count = 0;
    ArcNode *t;
    Queue *qu;
    qu = (Queue*)malloc(sizeof(Queue));
    qu->rear = qu->front = 0;
    qu->empty = 1;

    for(i = 0; i <= G->maxnum; i++)
    {
        g_box[i].pre = -1;
        g_box[i].current = 1;
    }

    g_visited[u] = 1;
    g_box[u].weight = 0;
    enQueue(qu, u);

    while(qu->empty == 0)
    {
        e = deQueue(qu);

        if(e == v && g_box[e].current == g_box[e].weight)
        {
            break;
        }

        if(g_box[e].current >= g_box[e].weight)
        {
            t = G->adjlist[e].firstarc;

            while(t != NULL)
            {
                if(g_visited[t->adjvex] == 0 || t->weight <= g_box[t->adjvex].weight - g_box[t->adjvex].current)
                {
                    g_box[t->adjvex].weight = t->weight;
                    g_box[t->adjvex].current = 1;
                    g_box[t->adjvex].pre = e;

                    if(g_visited[t->adjvex] == 0)
                    {
                        g_visited[t->adjvex] = 1;
                        enQueue(q, t->adjvex);
                    }
                }

                t = t->nextarc;
            }
        }
        else
        {
            g_box[e].current++;
            enQueue(qu, e);
        }
    }

    if(g_box[v].pre == -1) { //未找到路径直接返回
        return;
    }

    i = v;
    g_minlen = 0;

    while(i != -1) {
        g_minlen += g_box[i].weight;
        g_temp[count] = i;//逆序记录路径
        count++;
        i = g_box[i].pre;
    }

    g_minnum = count;

    for(i = 0; i < count; i++) {
        g_pathmin[i] = g_temp[count - i - 1];//保存最短路径
        //printf("%d: %d\n", temp[count - i - 1], b[temp[count - i - 1]].weight);
    }
}

//采用邻接矩阵的Dijkstra算法
void Dijkstra(AdjGraph *G, int u, int v)
{
    MatGraph *g = (MatGraph *)malloc(sizeof(MatGraph));//邻接链表转为邻接矩阵

    for(int i = 0; i < MAXV; i++) {
        for(int j = 0; j < MAXV; j++) {
            if(i == j) {
                g->edges[i][j] = 0;
            } else {
                g->edges[i][j] = INF;
            }
        }
    }

    ArcNode *p;

    for(int i = 0; i < G->maxd; i++) {
        p = G->adjlist[i].firstarc ;

        while(p != NULL) {
            g->edges[i][p->adjvex] = p->weight ;
            p = p->nextarc;
        }
    }

    g->n = G->n ;
    g->e = G->e ;
    g->maxd = G->maxd ;


    int *dist = (int *)malloc(MAXV * sizeof(int));
    int *path = (int *)malloc(MAXV * sizeof(int));
    int *S = (int *)malloc(MAXV * sizeof(int));
    int MINdis, i, j, k;

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

    //输出
    int *apath = (int *)malloc(MAXV * sizeof(int));
    int d;
    d = 0;
    apath[d] = v;//逆序存放路径
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

    //释放
    free(g);
    free(apath);
    free(dist);
    free(path);
    free(S);
    return;
}

char* shortestPath(int u, int v, char algorithm[], char name[])
{
    AdjGraph *G;
    int i, j, k;
    //调用stats里面的函数把图的邻接表做出来

    G = createAdjGraph(name, G);

    for(i = 0; i <= G->maxnum; i++)//visit数组，g_pathmin赋值
    {
        g_visited[i] = 0;
    }

    g_minnum = INF;
    g_minlen = INF;

    printf("\nUsing %s:\n", algorithm);

    if(strcmp(algorithm, "DFS") == 0 || strcmp(algorithm, "dfs") == 0)
    {
        DFS(G, u, v, 0);
    }
    else if(strcmp(algorithm, "BFS") == 0 || strcmp(algorithm, "bfs") == 0)
    {
        BFS(G, u, v);
    }
    else if(strcmp(algorithm, "Dijkstra") == 0)
    {
        Dijkstra(G, u, v);
    }

    destroyAdjGraph(G);

    //for (i = 0; i < g_minnum; i++)
    //{
    //	printf("%d ", g_pathmin[i]);
    //}

    if(g_minnum == INF || g_minnum == 1)  //未找到路径返回NULL
    {
        printf("\tNo path exists!");
        return NULL;
    }

    if(strcmp(algorithm, "dfs") != 0 && strcmp(algorithm, "DFS") != 0)
    {
        printf("Cost: %d\n", g_minlen);
    }

    printf("Path: ");
    char *pathmin; //将路径以字符串形式储存
    int length = 0; //记录所有顶点数字位数之和
    int temp;

    for(i = 0; i < g_minnum; i++)  //统计每一个顶点数值的位数
    {
        temp = g_pathmin[i];

        if(temp == 0) //判断顶点数值是否为零
        {
            length++;
            continue;
        }

        while(temp != 0)
        {
            temp /= 10;
            length++;
        }
    }

    pathmin = (char *)malloc((4 * (g_minnum - 1) + length + 1) * sizeof(char)); //分配存储空间
    int pos = 0; //记录当前存储位置
    int temp_pos; //记录每个顶点数值的相对存储位置

    for(i = 0; i < g_minnum; i++)
    {
        temp = g_pathmin[i];

        if(temp != 0)
        {
            temp_pos = -1;
        }
        else
        {
            temp_pos = 0;
        }

        while(temp != 0)
        {
            temp /= 10;
            temp_pos++;
        }

        temp = g_pathmin[i];

        for(j = pos + temp_pos; j >= pos; j--)  //逆序存储数值并生成对应的字符
        {
            pathmin[j] = temp - temp / 10 * 10 + '0';
            temp /= 10;
        }

        if(i != g_minnum - 1)  //存入箭头指向
        {
            pathmin[pos + temp_pos + 1] = ' ';
            pathmin[pos + temp_pos + 2] = '-';
            pathmin[pos + temp_pos + 3] = '>';
            pathmin[pos + temp_pos + 4] = ' ';
            pos += (temp_pos + 5);
        }
        else //若为最后一个顶点则存入字符串结束标志
        {
            pathmin[pos + temp_pos + 1] = '\0';
        }
    }

    return pathmin;
}

int strcmp(const char *strOne, const char *strTwo)//比较字符串
{
    while((*strOne != '\0') && (*strTwo != '\0') && (*strOne == *strTwo))
    {
        strOne++;
        strTwo++;
    }

    return (*strOne - *strTwo);
}