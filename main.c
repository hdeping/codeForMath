#include "head.h"


/*int main{{{*/
int main( int argc,char *argv[]){
    char *p;
    char p1[10],*p2;
    p = "bc";
    printf("p = %s\n",p);
    scanf("%s",p1);
    printf("p1 = %s\n",p1);
    p2 = p1;
    printf("p2 = %s\n",p2);
    printf("len is %d\n",strlen(p2));
}
/*}}}*/

