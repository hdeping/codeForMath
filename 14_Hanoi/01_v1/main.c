#include "head.h"

char *disk[10] = {"disk0", "disk1", "disk2", "disk3", "disk4",
"disk5", "disk6", "disk7", "disk8", "disk9"};
int num = 0;
/*void hanoi{{{*/
// move from ch1 ot ch2 using ch3
void hanoi(int n,char ch1,char ch2,char ch3)
{
    assert(n > 0);
    if ( n == 1  )
    {
        printf("ch1 ch2 %c %c\n",ch1,ch2);
        sleep(1);
        printf("move %s from %c to %c\n",disk[n-1],ch1,ch2);
        num++;
    }
    else
    {
        hanoi(n-1,ch1,ch3,ch2);
        printf("ch1 ch2 %c %c\n",ch1,ch2);
        sleep(1);
        printf("move %s from %c to %c\n",disk[n-1],ch1,ch2);
        num++;
        hanoi(n-1,ch3,ch2,ch1);
    }
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    hanoi(3,'A','B','C');
    printf("moving times are %d\n",num);
}
/*}}}*/
