#include "head.h"
/*int main{{{*/
int main( int argc,char *argv[]){
    srand(1991); 
    getdat(nn);
    readdat(nn);
    double time[m];
    int *p;
    for(int i = 0;i < 2;i++)
    {
        p = num[i];
        printf("i = %d\n",i);
        sortTest(p);
        new_time start,end;
        gettimeofday(&start,NULL );
        selectSort(p);
        gettimeofday(&end,NULL );
        time[i] = get_time(start,end);
        sortTest(p);
    }
    analyze_time(time);
    print_time(time);
}
/*}}}*/
/*void selectSort{{{*/
void selectSort(int *num)
{
    for(int i = 0;i < nn/2;i++)
    {
        int min = i;
        int max = nn - i - 1;
        for(int j = i + 1;j < nn - i - 1;j++)
        {
            if ( num[j] < num[min] )
            {
                min = j;
            }
            if ( num[j] > num[max] )
            {
                max = j;
            }
        }
        swap(num+min,num+i);
        swap(num+max,num+nn - i - 1);
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
/*void print_time{{{*/
void print_time(double *num)
{
    printf("----start------\n");
    FILE *fp;
    fp= fopen("time1.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < m;i++)
    {
        fprintf(fp,"%lf\n",num[i]);
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
        printf("%lf\n",num[i]);
    }
}
/*}}}*/
/*double get_time{{{*/
double get_time(new_time start,new_time end)
{
    double time;
    time = end.tv_sec-start.tv_sec;
    time += 1E-6*(end.tv_usec-start.tv_usec);
    printf("time is %lf\n",time );
    return time;
}
/*}}}*/
/*void swap{{{*/
void swap(int *a,int *b)
{
    int tmp = *a;
    *a      = *b;
    *b      = tmp;
}
/*}}}*/
/*void analyze_time{{{*/
void analyze_time(double *time)
{
    double average,standard;
    average = 0.0;
    for(int i = 0;i < m;i++)
    {
        average += time[i]; 
    }
    average /= m;
    printf("average time :%lf\n",average);
    standard = 0.0;
    for(int i = 0;i < m;i++)
    {
        standard += pow((time[i] - average),2); 
    }
    standard = sqrt(standard);
    printf("standard error:%lf\n",standard);
    printf("time ranges in (%lf,%lf)\n",
              average-2*standard,average+2*standard);
}
/*}}}*/
