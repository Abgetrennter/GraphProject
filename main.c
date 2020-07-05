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

    //printf("%s\n", argv[1]);

    pointpath u_to_v;

    if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
    {
        print_help(); //help-fun
    }
    else if(!strcmp(argv[1], "-g") || !strcmp(argv[1], "-gragh"))
    {
        strcpy(file_name, argv[2]);

        //fun of zhaotu

        if(!strcmp(argv[3], "-sp") || !strcmp(argv[3], "--shortestpath"))
        {
            strcpy(u_to_v.search_path, argv[4]);

            u_to_v.u = atoi(argv[6]);
            u_to_v.v = atoi(argv[8]);

            //u_to_v.path = shortestpath(u_to_v.u, u_to_v.v, u_to_v.search_path, file_name);

            /*for(int i = 0;; ++i)
            {
                /* code
            } */

        }
    }
    else if(!strcmp(argv[1], "-j"))
    {
        print_st();
    }

    //
    return 0;
}