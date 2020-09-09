#include "sort.h"

/*void heapSort{{{*/
void heapSort(int *num)
{
    //build a headp
    /*
     * 
    printf("before heaping\n");
    print_num(num,nn);  
    printf("after heaping\n");
    print_num(num,nn);  
     * */
    BuildingHeap(num,nn);  
    // adjust the list from the last element
    for (int i = nn - 1; i > 0; --i)  
    {  
        swap(num,num+i);
        // print_num(num,i+1);  
        HeapAdjust(num,0,i);  
        // heapTest2(num,i);
  }  
}
/*}}}*/
/*void HeapAdjust{{{*/
void HeapAdjust(int *num,int s, int length)  
{  
    int child;
    child = 2*s+1;
    int tmp = num[s];
    while ( child < length )
    {
        if ( child+1<length && num[child+1]>num[child]  )
        {
            child++;
        }
        if ( num[child] > num[s] )
        {
            swap(num+s,num+child);
            s = child;
            child=2*s+1;
        }
        else
        {
            break; 
        }
    }
}  
/*}}}*/
/*void BuildingHeap{{{*/
void BuildingHeap(int *num, int length)  
{   
    for(int i = (length - 1) / 2;i > 0 ;i--)
    {
        HeapAdjust(num,0,i);
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
        // printf("sequence is POSITIVE order\n");
        return 1;
        
    }
    else if ( res == 1 - nn  )
    {
        // printf("sequence is NEGATIVE order\n");
        return -1;
    }
    else
    {
        // printf("there is no order\n");
        return 0;
    }
}
/*}}}*/
/*void heapTest{{{*/
void heapTest(int *num,int size)
{
    int tmp = 0;
    for(int i = 0;i < size;i++)
    {
        int i1,i2;
        i1 = 2*i+1;
        i2 = i1+1;
        if ( num[i] > num[i1])
        {
            tmp++;
        }
        if ( i2 >= size  )
        {
            break;
        }
        if (num[i] > num[i2])
        {
            tmp++;
        }
    }
    if ( tmp == 0  )
    {
        printf("Minimal Heap!\n");
    }
    else
    {
        printf("NOT Heap\n");
    }
}
/*}}}*/
/*void heapTest2{{{*/
void heapTest2(int *num,int size)
{
    int tmp = 0;
    for(int i = 0;i < size;i++)
    {
        int i1,i2;
        i1 = 2*i+1;
        i2 = i1+1;
        if ( num[i] < num[i1])
        {
            tmp++;
        }
        if ( i2 >= size  )
        {
            break;
        }
        if (num[i] < num[i2])
        {
            tmp++;
        }
    }
    if ( tmp == 0  )
    {
        printf("Maximal Heap!\n");
    }
    else
    {
        printf("NOT Heap\n");
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
void print_num(int *num,int size)
{
    int layer;
    layer = (int)(log2(size*1.0)) + 1;
    int *blankNum;
    int *count;
    blankNum = (int *)malloc(sizeof(int)*layer);
    count = (int *)malloc(sizeof(int)*layer);
    count[0] = 0;
    blankNum[layer - 1] = 0;
    for(int i = 0;i < layer - 1;i++)
    {
        count[i+1] = 2*count[i] + 1;
        int j = layer-2-i;
        blankNum[j] = count[i]*4+2;
    }
    int uplimit;
    // print the result
    for(int i = 0;i < layer;i++)
    {
        if ( i == layer - 1  )
        {
            uplimit = size;
        }
        else
        {
            uplimit = count[i + 1];
        }
        // print blanks in the head
        for(int j = 0;j < blankNum[i];j++)
        {
            printf(" ");
        }
        // print number
        for(int j = count[i];j < uplimit;j++)
        {
            printf("%4d",num[j]);
            for(int k = 0;k < count[layer - 1 - i];k++)
            {
                printf("    ");
            }
        }
        printf("\n\n");
    }
    free(count);
}
/*}}}*/
/*double get_time{{{*/
double get_time(new_time start,new_time end)
{
    double time;
    time = end.tv_sec-start.tv_sec;
    time += 1E-6*(end.tv_usec-start.tv_usec);
    // printf("time is %lf\n",time );
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
    printf("average time :%lf\n",time[m-2]);
    standard = 0.0;
    for(int i = 0;i < m;i++)
    {
        standard += pow((time[i] - average),2); 
    }
    standard = sqrt(standard);
    printf("standard error:%lf\n",standard);
    /*
     * 
    printf("time ranges in (%lf,%lf)\n",
              average-2*standard,average+2*standard);
     * */
}
/*}}}*/
