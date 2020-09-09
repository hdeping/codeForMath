#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
   int i1,i2,i3,i4;
   int i,j;
   int a[n][n],b[m][n];
   i = 0;
   for(i1 = 0;i1 < n;i1++){
       for(i2 = 0;i2 < n;i2++){
           if ( i1 == i2 ){
               continue ;
           }
           
           for(i3 = 0;i3 < n;i3++){
               if ( i3 == i2 || i3 == i1 ){
                   continue ;
               }
               
               for(i4 = 0;i4 < n;i4++){
                   if ( i4 == i3 || i4 == i2 || i4 == i1 ){
                       continue ;
                   }
                   i++;
                   a[i][0] = i1;
                   a[i][1] = i2;
                   a[i][2] = i3;
                   a[i][3] = i4;
               }
           }
       }
   }
}
/*}}}*/
