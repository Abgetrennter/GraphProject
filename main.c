#include <stdio.h>
#include <stdlib.h>
#define Max_char_size 100

char file_name[Max_char_size];

typedef  struct $
{
    int u;
    int v;
    char way[Max_char_size];
    char* path;
} pointpath;

int main(int argc, char const *argv[])
{
    int n, c;


    pointpath u_to_v;

    if(strcmps(argv[1], "-h") == 0 || strcmps(argv[1], "--help") == 0)
    {
        print_help(); //help-fun
    }
    else if(strcmps(argv[1], "-g")  == 0 || strcmps(argv[1], "-gragh") == 0)
    {
        strcpys(file_name, argv[2]);

        if(strcmps(argv[3], "-sp") == 0 || strcmps(argv[3], "--shortestpath") == 0)
        {
            strcpys(u_to_v.way, argv[4]);
            u_to_v.u = atoi(argv[6]);
            u_to_v.v = atoi(argv[8]);
            shortestPath(u_to_v.u, u_to_v.v, u_to_v.way, file_name);

        } else if(strcmps(argv[3], "-s") == 0 || strcmps(argv[3], "--stats") == 0)
        {
            if(strcmps(argv[4], "edges") == 0)
            {
                printf("%d\n", numberOfEdges(file_name));
            } else if(strcmps(argv[4], "vertices") == 0)
            {
                printf("%d\n", numberOfVertices(file_name));
            } else if(strcmps(argv[4], "freeman") == 0)
            {
                float q ;
                q = freemanNetworkCentrality(file_name);
            } else if(strcmps(argv[4], "closeness node") == 0)
            {
                float q;
                closenessCentrality(file_name, 0);
            }
        }
    }
    else if(!strcmps(argv[1], "-j"))
    {
        print_st();
    }

    //
    return 0;
}