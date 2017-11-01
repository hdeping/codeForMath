#include "head.h"

int a[1024][3];
/*void func_before{{{*/
void func_before()
{
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
   char *form[4] = { "000%d.txt", "00%2d.txt", "0%3d.txt", "%4d.txt"};
   char filename[10];
   for(int i = 0;i < 1024;i++)
   {
       int num = (int)log10(i+0.5);
       sprintf(filename,form[num],i);
       fp= fopen(filename,"w");
       for(int j = 0;j < 3;j++)
       {
           fprintf(fp,"%d\n",a[i][j]);
       }
       fclose(fp);
   }
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
   char *form[4] = { "000%d", "00%2d", "0%3d", "%4d"};
   char filename[10];
   for(int i = 0;i < 1024;i++)
   {
       int num = (int)log10(i+0.5) ;
       sprintf(filename,form[num],i);
       printf("filename=\"%s.txt\"\n",filename);
       printf("set output \"%s.eps\"\n",filename);
       printf("plot filename notitle\n");
   }
}
/*}}}*/
