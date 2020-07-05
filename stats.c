#include <stdio.h>
#include "stats.h"

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

    all = (int*)malloc(Max_int_size * sizeof(int));

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("%s\n", "Wrong");
        exit(2);
    }

    while((fscanf(fp, "%d%d%d", &p, &q, &n) != EOF)) {
        all[p] = 1;
        all[q] = 1;
    }

    for(i = 0; i < Max_int_size; ++i)
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
    printf("%s\n", "sorry,we don't choose it.~(￣▽￣)~*");
}

float freemanNetworkCentrality(char name[]) {
    printf("%s\n", "sorry,we don't choose it.~(￣▽￣)~*");
}