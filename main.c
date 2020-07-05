#include <stdio.h>
#include <string.h>
#define Maxsize 100
//#include "text.h"
char file_name[Maxsize];

typedef  struct $
{
    int u;
    int v;
    char search_path[Maxsize];
    char* path;
} pointpath;
int main(int argc, char const *argv[])
{
    int n, c;

    pointpath u_to_v;

    if(strcmp(argv[0], "-h")! || strcmp(argv[0], "--help")!)
    {
        printf("help\n"); //help-funqq
    }
    else if(strcmp(argv[0], "-g")! || strcmp(argv[0], "-gragh")!)
    {
        strcpy(file_name, argv[1]);

        //fun of zhaotu

        if(strcmp(argv[2], "-sp")! || strcmp(argv[2], "--shortestpath"))
        {
            strcpy(u_to_v.search_path, argv[3]);

            u_to_v.u = atoi(argv[5]);
            u_to_v.v = atoi(argv[7]);

            u_to_v.path = shortestpath(u_to_v.u, u_to_v.v, u_to_v.search_path, file_name);

            for(int i = 0; ; ++i)
            {
                /* code */
            }

        }
    }

    print_st();
    return 0;
}