#include "head.h"

char *disk[10] = {"disk0", "disk1", "disk2", "disk3", "disk4",
"disk5", "disk6", "disk7", "disk8", "disk9"};
int num = 0;
char ch[3] = {'A','B','C'};
property *hanoi;
/*void print_hanoi{{{*/
void print_hanoi(property *hanoi)
{
    assert(hanoi != NULL  );
    int *num = hanoi -> num; 
    for(int i = 0;i < 3;i++)
    {
        printf("%4d",num[i]);
    }
    printf("\n");
}
/*}}}*/
/*property *get_hanoi{{{*/
property *get_hanoi(int n)
{
    assert(n > 0);
    property *hanoi;
    hanoi = (property *)malloc(sizeof(property)*1);
    int *num  = &hanoi -> num[0]; 
    int **arr = hanoi  -> arr; 
    num[0] = n;
    num[1] = 0;
    num[2] = 0;
    for(int i = 0;i < 3;i++)
    {
        arr[i] = (int *)malloc(sizeof(int)*n);
    }
    for(int i = 0;i < num[0];i++)
    {
        arr[0][i] = num[0] - 1 - i;
    }
    return hanoi;
}
/*}}}*/
/*property *free_hanoi{{{*/
property *free_hanoi(property *hanoi)
{
    int **arr = hanoi -> arr; 
    for(int i = 0;i < 3;i++)
    {
        free(arr[i]);
    }
    hanoi = NULL ;
    return hanoi;
}
/*}}}*/
/*void move{{{*/
// move from ch1 ot ch2 using ch3
void move(int n,int i,int j)
{
    assert(i > 0 && i <= 3 );
    assert(j > 0 && j <= 3 );
    assert(n > 0);
    int k = 6 - i - j;
    if ( n == 1  )
    {
        printf("move %s from %c to %c\n",disk[n-1],ch[i-1],ch[j-1]);
        hanoi -> num[i-1]--;
        hanoi -> num[j-1]++;
        print_hanoi(hanoi);
        num++;
    }
    else
    {
        move(n-1,i,k);
        printf("move %s from %c to %c\n",disk[n-1],ch[i-1],ch[j-1]);
        hanoi -> num[i-1]--;
        hanoi -> num[j-1]++;
        num++;
        print_hanoi(hanoi);
        move(n-1,k,j);
    }
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    int n = 10;
    hanoi = get_hanoi(n);
    print_hanoi(hanoi);
    move(n,1,2);
    hanoi = free_hanoi(hanoi);
    printf("moving times are %d\n",num);
}
/*}}}*/
