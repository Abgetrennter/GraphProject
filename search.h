#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include "text.h"

#ifndef _Queue_H_
#define _Queue_H_
//ÒÔÏÂ¶¨Òå¶ÓÁÐÏà¹ØÀàÐÍ
typedef struct {
    int data[MAXV];
    int front;
    int rear;
    int empty;
} Queue;

typedef struct {
    int weight;
    int current;
    int pre;
} Box;

void enQueue(Queue *qu, int e);//½ø¶Ó
int deQueue(Queue *qu);//³ö¶Ó
///////////////////////////////////////////////////////////////////////////////////ÒÔÉÏ¶¼Òª
#endif          /*_Queue_H_*/

#ifndef _SEARCH_H_
#define _SEARCH_H_
//void DFS(AdjGraph *G, int u, int v, char dpath[], int d); //Êä³ö¶¥µãuµ½vµÄÒ»ÌõÂ·¾¶
//void BFS(AdjGraph *G, int u, int v);//Çó¶¥µãuµ½¶¥µãvµÄ×î¶ÌÂ·¾¶
void Dijkstra(AdjGraph *G, int u, int v);//Çó¶¥µãuµ½¶¥µãvµÄ×î¶ÌÂ·¾¶
char* shortestPath(int u, int v, char algorithm[], char name[]);//ÒÔ×Ö·û´®ÐÎÊ½·µ»Ø×î¶ÌÂ·¾¶
#endif         /*_Search_H_*/