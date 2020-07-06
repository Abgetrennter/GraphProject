#ifndef serrch_h
#define serrch_h

#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

int visited[MAXV] = {0};

char* shortestPath(int u, int v, char algorithm[], char name[]);

int visit[MAXV] = {0};//用于DFS标记该顶点是否被访问
int g_visited[MAXV] = {0};//用于BFS标记该顶点是否被访问
int g_minnum;//求最短路径中包含的顶点数目
int g_minlen;//求最短路径长度
int g_pathmin[MAXV];//存储由u到v的最短路径顶点序号
int g_dist[MAXV];//记录各顶点到u的距离
int g_path[MAXV];//记录char类型路径
int g_temp[MAXV];//记录逆序路径
Box g_box[MAXV];//记录将边分割为weight-1个顶点后的相对顶点位置

#endif