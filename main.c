#include "head.h"
/*void run{{{*/
void run()
{
    double time[m];
    int *p;
    int recordOrder = 0;
    for(int i = 0;i < m;i++)
    {
        printf("-------i = %d -------\n",i);
        p = num[i];
        sortTest(p);
        new_time start,end;
        gettimeofday(&start,NULL );
        heapSort(p);
        gettimeofday(&end,NULL );
        time[i] = get_time(start,end);
        recordOrder +=  sortTest(p);
    }
    analyze_time(time);
    print_time(time);
    printf("record Order is %d\n",recordOrder);
}
/*}}}*/
/*void test{{{*/
void test()
{
    int recordOrder = 0;
    int *p = num[0];
    sortTest(p);
    heapSort(p);
    print_num(p,nn);
    recordOrder +=  sortTest(p);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    srand(1991); 
    getdat(nn);
    readdat(nn);
    // run();
    test();
}
/*}}}*/
