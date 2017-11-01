#include "head.h"
#define getsum(sum,arr,len) sum = 0;\
for(int i = 0;i < len;i++)\
{\
    sum += arr[i]; \
}


/*void getDegreeDistri{{{*/
void getDegreeDistri(igraph_t *graph)
{
    int n = igraph_vcount(graph);
    int *degDist;
    degDist = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++)
    {
        degDist[i] = 0;
    }

    // get degree
    igraph_vector_t degree;
    igraph_vector_init(&degree,0);
    igraph_degree(graph,&degree,igraph_vss_all(),IGRAPH_ALL ,0);
    // get distribution
    for(int i = 0;i < n;i++)
    {
        int ii = VECTOR(degree)[i];
        degDist[ii]++;
    }
    
    igraph_vector_destroy(&degree);

    // print degree distribution
    FILE *fp;
    fp= fopen("degDist.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < n;i++)
    {
        if ( degDist[i] != 0   )
        {
            fprintf(fp,"%d,%d\n",i,degDist[i]);
        }
        
    }
    fclose(fp);

    
    free(degDist);
}
/*}}}*/
/*void level1{{{*/
void level1()
{
    igraph_t graph;
    int n = 1000;
    int m = 10;
    igraph_static_power_law_game(&graph,n,n*m,2.0,- 1,0,0,0);
    getDegreeDistri(&graph);
    igraph_destroy(&graph);
}
/*}}}*/
/*void level2{{{*/
void level2(int argc, char *argv[])
{
    if ( argc == 1  )
    {
        printf("Please input a file\n");
        printf("For Example: '<command> <data.file>'\n");
        return ;
    }
    double power = atof(argv[1]);
    igraph_t graph;
    int n = 1000;
    int m = 10;
    int cy_times = 1000;

    // initialize degDist
    int *degDist;
    degDist = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++)
    {
        degDist[i] = 0;
    }

    igraph_vector_t degree;
    igraph_vector_init(&degree,0);
    for(int ii = 0;ii < cy_times;ii++)
    {
        // get a new graph
        igraph_static_power_law_game(&graph,n,n*m,power,- 1,0,0,0);
        // get degree
        igraph_degree(&graph,&degree,igraph_vss_all(),IGRAPH_ALL ,0);
        // get distribution
        for(int i = 0;i < n;i++)
        {
            int ii = VECTOR(degree)[i];
            degDist[ii]++;
        }
        igraph_destroy(&graph);
    }
    

    igraph_vector_destroy(&degree);

    // print degree distribution
    FILE *fp,*fp1;
    fp  = fopen("degDist.txt","w");
    fp1 = fopen("data.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < n;i++)
    {
        if ( degDist[i] != 0   )
        {
            fprintf(fp  ,"%d,%lf\n",i,(double)degDist[i]/cy_times);
            fprintf(fp1 ,"%d %lf\n",i,(double)degDist[i]/cy_times);
        }
    }
    fclose(fp);
    fclose(fp1);

    
    free(degDist);
}
/*}}}*/
/*void level3{{{*/
void level3(double power)
{
    igraph_t graph;
    int n = 1000;
    int m = 10;
    int cy_times = 1000;

    // initialize degDist
    int *degDist;
    degDist = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++)
    {
        degDist[i] = 0;
    }

    igraph_vector_t degree;
    igraph_vector_init(&degree,0);
    for(int ii = 0;ii < cy_times;ii++)
    {
        // get a new graph
        igraph_static_power_law_game(&graph,n,n*m,power,- 1,0,0,0);
        // get degree
        igraph_degree(&graph,&degree,igraph_vss_all(),IGRAPH_ALL ,0);
        // get distribution
        for(int i = 0;i < n;i++)
        {
            int ii = VECTOR(degree)[i];
            degDist[ii]++;
        }
        igraph_destroy(&graph);
    }
    

    igraph_vector_destroy(&degree);

    // print degree distribution
    FILE *fp,*fp1;
    char filename1[20];
    char filename2[20];
    sprintf(filename1,"degDist%d.txt",(int)(10*power));
    sprintf(filename2,"data%d.txt",(int)(10*power));
    
    fp  = fopen(filename1,"w");
    fp1 = fopen(filename2,"w");
    assert(fp != NULL);
    for(int i = 0;i < n;i++)
    {
        if ( degDist[i] != 0   )
        {
            fprintf(fp  ,"%d,%lf\n",i,(double)degDist[i]/cy_times);
            fprintf(fp1 ,"%d %lf\n",i,(double)degDist[i]/cy_times);
        }
    }
    fclose(fp);
    fclose(fp1);

    
    free(degDist);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int len = 11;
    for(int i = 0;i < len;i++)
    {
        double power = 2.0 + 0.1*i;
        printf("When power is %lf\n",power);
        
        level3(power);
    }
}
/*}}}*/
