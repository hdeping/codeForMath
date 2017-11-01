#include "head.h"
/*int main{{{*/
int main( int argc,char *argv[]){
    srand(1991); 
    readdat(nn);
    int *p = num[0];
    sortTest(p);
    bubbleSort(p);
    sortTest(p);
}
/*}}}*/
/*void bubbleSort{{{*/
void bubbleSort(int *num)
{
    for(int i = 0;i < nn;i++)
    {
        for(int j = 0;j < nn - 1;j++)
        {
            int tmp;
            int k = j + 1;
            if ( num[j] > num[k] )
            {
                tmp    = num[k];
                num[k] = num[j];
                num[j] = tmp;
            }
        }
    }
    
}
/*}}}*/
/*void sortTest{{{*/
void sortTest(int *num)
{
    int res = 0;
    int equal = 0;
    bool p1,p2;
    for(int i = 0;i < nn - 1;i++)
    {
        p1 = ( num[i] > num[i+1] );
        p2 = ( num[i] < num[i+1] );
        if (p1)
        {
            res++;
        }
        else if (p2)
        {
            res--;
        }
        else
        {
            equal++;
        }
    }
    if ( res > 0 )
    {
        res += equal; 
    }
    else
    {
        res -= equal; 
    }
    
    if ( res == nn - 1  )
    {
        printf("sequence is POSITIVE order\n");
        
    }
    else if ( res == 1 - nn  )
    {
        printf("sequence is NEGATIVE order\n");
    }
    else
    {
        printf("there is no order\n");
    }
}
/*}}}*/
/*void getdat{{{*/
void getdat(int n)
{
    FILE *fp;
    char filename[20];
    sprintf(filename,"data%d.dat",n);
    fp= fopen(filename,"w");
    assert(fp != NULL);
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            num[i][j] = rand() % max;
        }
        fwrite(num[i],sizeof(int)*n,1,fp);
    }
    fclose(fp);
    
}
/*}}}*/
/*void readdat{{{*/
void readdat(int n)
{
    FILE *fp;
    char filename[20];
    sprintf(filename,"data%d.dat",n);
    fp= fopen(filename,"r");
    assert(fp != NULL);
    for(int i = 0;i < m;i++)
    {
        fread(num[i],sizeof(int)*n,1,fp);
    }
    fclose(fp);
}
/*}}}*/
/*void print_num{{{*/
void print_num(int *num)
{
    printf("----start------\n");
    for(int i = 0;i < nn;i++)
    {
        printf("%d\n",num[i]);
    }
}
/*}}}*/
/*void get_time{{{*/
void get_time(new_time start,new_time end)
{
    double time;
    time = end.tv_sec-start.tv_sec;
    time += 1E-6*(end.tv_usec-start.tv_usec);
    printf("time = %lf\n",time);
}
/*}}}*/
