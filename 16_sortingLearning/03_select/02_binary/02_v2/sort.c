#include "sort.h"

/*void selectSort{{{*/
void selectSort(int *num)
{
    // print_num(num);
    for(int i = 0;i < nn/2;i++)
    {
        int min  = i;
        int last = nn - i - 1;
        int max1 = last;
        for(int j = i;j < last+1;j++)
        {
            if ( num[j] < num[min] )
            {
                min = j;
            }
            if ( num[j] > num[max1] )
            {
                max1 = j;
            }
        }
        if ( i == max1  )
        {
            swap(num+max1,num+last);
            swap(num+min,num+i);
        }
        else if ( last == min )
        {
            swap(num+min,num+i);
            swap(num+max1,num+last);
        }
        else
        {
            swap(num+min,num+i);
            swap(num+max1,num+last);
        }
        // print_num(num);
    }
    int tmp = nn / 2 - 1;
    if ( num[tmp] > num[tmp+1] )
    {
        swap(num+tmp,num+tmp+1);
        // print_num(num);
    }
}
/*}}}*/
/*int sortTest{{{*/
int sortTest(int *num)
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
        return 1;
        
    }
    else if ( res == 1 - nn  )
    {
        printf("sequence is NEGATIVE order\n");
        return -1;
    }
    else
    {
        printf("there is no order\n");
        return 0;
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
    for(int i = 0;i < nn;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
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
