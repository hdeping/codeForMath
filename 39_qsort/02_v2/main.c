#include "head.h"

/*int cmp_int{{{*/
int cmp_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
/*}}}*/
/*int cmp_char{{{*/
int cmp_char(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}
/*}}}*/
/*int cmp_double{{{*/
int cmp_double(const void *a, const void *b)
{
    return *(double *)a>*(double *)b?1:-1;
}
/*}}}*/
/*void testInt{{{*/
void testInt()
{
    int arr[n];
    for(int i = 0;i < n;i++)
    {
        arr[i] = rand() % 100;
        printf("%d\n",arr[i]);
        
    }
    qsort(arr,n,sizeof(arr[0]),cmp_int);
    
    printf("\n");
    
    for(int i = 0;i < n;i++)
    {
        printf("%d\n",arr[i]);
    }
    
}
/*}}}*/
/*void testChar{{{*/
void testChar()
{

    char ch[40] = ",kieurdkfdkfjeiteijfdjfdgdababekkdfdktfe";
    printf("%s\n",ch);
    qsort(ch,40,sizeof (char),cmp_char);
    printf("%s\n",ch);
    
}
/*}}}*/
/*void testDouble{{{*/
void testDouble()
{
    
    double arrNew[n];
    
    for(int i = 0;i < n;i++)
    {
        arrNew[i] = (rand() / total) * 100.0;
        printf("%lf\n",arrNew[i]);
        
    }
    qsort(arrNew,n,sizeof (arrNew[0]),cmp_double);
    printf("\n");
    
    for(int i = 0;i < n;i++)
    {
        printf("%lf\n",arrNew[i]);
    }

}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    srand(time(NULL)); 

    testInt();
    testChar();
    testDouble();

}
/*}}}*/
