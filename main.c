#include "head.h"
/*int main{{{*/
int main( int argc,char *argv[]){
    srand(1991); 
    getdat(nn);
    readdat(nn);
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
        selectSort(p);
        gettimeofday(&end,NULL );
        recordOrder +=  sortTest(p);
        // print_num(p);
    }
    analyze_time(time);
    print_time(time);
    printf("record Order is %d\n",recordOrder);
    
}
/*}}}*/
