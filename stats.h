#ifndef status
#define status

#include <stdio.h>
#include "Graph.h"
#include <stdlib.h>

int numberOfEdges(char name[]);

int numberOfVertices(char name[]);

float freemanNetworkCentrality(char name[]);

float closenessCentrality(char name[], int node);

#endif