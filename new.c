#include <stdio.h>
#include <assert.h>

int a[1024][3];
/*int main{{{*/
int main( int argc,char *argv[]){
   FILE *fp;
   fp= fopen("data1.txt","r");
   assert(fp != NULL);
   for(int i = 0;i < 1024;i++)
   {
       for(int j = 0;j < 3;j++)
       {
         fscanf(fp,"%d",a[i]+j);
       }
   }
   fclose(fp);
   fp= fopen("new.txt","w");
   assert(fp != NULL);
   for(int i = 0;i < 3;i++)
   {
       for(int j = 0;j < 1024;j++)
       {
         fprintf(fp,"%d ",a[j][i]);
       }
       fprintf(fp,"\n");
   }
   fclose(fp);
}
/*}}}*/
