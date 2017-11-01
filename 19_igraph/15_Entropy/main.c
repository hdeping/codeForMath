#include "head.h"
#define getsum(sum,arr,len) sum = 0.0;\
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
/*double getEntropy{{{*/
double getEntropy(double *arr,int len)
{
    double entropy = 0.0;
    
    for(int i = 0;i < len;i++)
    {
        if ( arr[i] > 0.0 )
        {
            entropy += arr[i] * log(arr[i]); 
        }
    }
    entropy = - entropy;
    return entropy;
}
/*}}}*/
/*void level3{{{*/
void level3(int m)
{
    igraph_t graph;
    int n = 1000;
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
    // get a new graph
    igraph_erdos_renyi_game_gnm(&graph,n,m,
            IGRAPH_UNDIRECTED,IGRAPH_NO_LOOPS);
    // get degree
    igraph_degree(&graph,&degree,igraph_vss_all(),IGRAPH_ALL ,0);
    // get distribution
    for(int i = 0;i < n;i++)
    {
        int ii = VECTOR(degree)[i];
        degDist[ii]++;
    }
    igraph_destroy(&graph);
    

    igraph_vector_destroy(&degree);

    // print degree distribution
    
    double *degDistNorm;
    degDistNorm = (double *)malloc(sizeof(double)*n);
    int len = 0;
    double sum;
    getsum(sum,degDist,n);
    for(int i = 0;i < n;i++)
    {
        if ( degDist[i] != 0   )
        {
            degDistNorm[len] = (double)degDist[i] / sum;
            len ++;
        }
    }
    double entropy;
    entropy = getEntropy(degDistNorm,len);
    printf("entropy is %lf\n",entropy);
    
    free(degDistNorm);

    
    free(degDist);
}
/*}}}*/
/*void levelSF{{{*/
void levelSF(int m)
{
    igraph_t graph;
    int n = 1000;
    int cy_times = 1000;

    // initialize degDist
    int *degDist;
    degDist = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++)
    {
        degDist[i] = 0;
    }

    igraph_t g1;
    igraph_full(&g1,10,IGRAPH_UNDIRECTED ,IGRAPH_NO_LOOPS );
    igraph_vector_t degree;
    igraph_vector_init(&degree,0);
    // get a new graph
    igraph_barabasi_game(&graph,n,m,1,0,1E-3,0,0,
            IGRAPH_BARABASI_PSUMTREE,&g1);
    // get degree
    igraph_destroy(&g1);
    igraph_degree(&graph,&degree,igraph_vss_all(),IGRAPH_ALL ,0);
    // get distribution
    for(int i = 0;i < n;i++)
    {
        int ii = VECTOR(degree)[i];
        degDist[ii]++;
    }
    igraph_destroy(&graph);
    

    igraph_vector_destroy(&degree);

    // print degree distribution
    
    double *degDistNorm;
    degDistNorm = (double *)malloc(sizeof(double)*n);
    int len = 0;
    double sum;
    getsum(sum,degDist,n);
    for(int i = 0;i < n;i++)
    {
        if ( degDist[i] != 0   )
        {
            degDistNorm[len] = (double)degDist[i] / sum;
            len ++;
        }
    }
    double entropy;
    entropy = getEntropy(degDistNorm,len);
    printf("entropy is %lf\n",entropy);
    
    free(degDistNorm);

    
    free(degDist);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int len = 11;

    srand(time(NULL)); 
    for(int i = 1;i < 10;i++)
    {
        level3(i);
        levelSF(i);
    }
}
/*}}}*/
