#include "head.h"

char *disk[10] = {"disk0", "disk1", "disk2", "disk3", "disk4",
"disk5", "disk6", "disk7", "disk8", "disk9"};
int num = 0;
property *hanoi;
/*void print_hanoi{{{*/
void print_hanoi(property *hanoi)
{
    assert(hanoi != NULL  );
    int *num1 = &hanoi -> num1; 
    int *num2 = &hanoi -> num2; 
    int *num3 = &hanoi -> num3; 
    printf("num1 num2 num3\n");
    printf("%5d%5d%5d\n",*num1,*num2,*num3);
}
/*}}}*/
/*property *get_hanoi{{{*/
property *get_hanoi(int n)
{
    assert(n > 0);
    property *hanoi;
    hanoi = (property *)malloc(sizeof(property)*1);
    int *num1 = &hanoi -> num1; 
    int *num2 = &hanoi -> num2; 
    int *num3 = &hanoi -> num3; 
    int *a = hanoi -> numa; 
    int *b = hanoi -> numb; 
    int *c = hanoi -> numc; 
    a = (int *)malloc(sizeof(int)*n);
    b = (int *)malloc(sizeof(int)*n);
    c = (int *)malloc(sizeof(int)*n);
    *num1 = n;
    *num2 = 0;
    *num3 = 0;
    for(int i = 0;i < *num1;i++)
    {
        a[i] = *num1 - 1 - i;
    }
    return hanoi;
}
/*}}}*/
/*property *free_hanoi{{{*/
property *free_hanoi(property *hanoi)
{
    assert(hanoi != NULL  );
    int *a = hanoi -> numa; 
    int *b = hanoi -> numb; 
    int *c = hanoi -> numc; 
    free(a);
    free(b);
    free(c);
    free(hanoi);
    hanoi = NULL ;
    return hanoi;
}
/*}}}*/
/*void hanoi{{{*/
// move from ch1 ot ch2 using ch3
void move(int n,char ch1,char ch2,char ch3)
{
    assert(n > 0);
    if ( n == 1  )
    {
        printf("move %s from %c to %c\n",disk[n-1],ch1,ch2);
        num++;
        hanoi -> num1--; 
        hanoi -> num2++; 
    }
    else
    {
        move(n-1,ch1,ch3,ch2);
        printf("move %s from %c to %c\n",disk[n-1],ch1,ch2);
        hanoi -> num1--; 
        hanoi -> num2++; 
        num++;
        move(n-1,ch3,ch2,ch1);
    }
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    int n = 9;
    hanoi = get_hanoi(n);
    print_hanoi(hanoi);
    move(n,'A','B','C');
    print_hanoi(hanoi);
    hanoi = free_hanoi(hanoi);
    printf("moving times are %d\n",num);
}
/*}}}*/
