#include "head.h"

   float factor[2] = {log(3.0)/log(2.0),log(5.0)/log(2.0)};

/*void printNum{{{*/
void printNum(int m)
{
   printf("%f\n",log(m*1.0)/log(2.0));
   printf("%f\n",log(m*1.0)/log(3.0));
   printf("%f\n",log(m*1.0)/log(5.0));
}
/*}}}*/
/*int isBig{{{*/
int isBig(sequence res1,sequence res2)
{
    float sum[2];
    sum[0]  = res1.ii;
    sum[0] += factor[0]*res1.jj;
    sum[0] += factor[1]*res1.kk;
    sum[1]  = res2.ii;
    sum[1] += factor[0]*res2.jj;
    sum[1] += factor[1]*res2.kk;
    if ( sum[0] > sum[1] )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
/*}}}*/
/*void sort{{{*/
void sort(sequence *res1500,int num)
{
    for(int i = 0;i < num - 1;i++)
    {
        for(int j = i+1;j < num;j++)
        {
            sequence tmp;
            if ( isBig(res1500[i],res1500[j]) )
            {
                tmp = res1500[i];
                res1500[i] = res1500[j];
                res1500[j] = tmp;
            }
            
        }
        
    }
    
}
/*}}}*/
/*void printSeq{{{*/
void printSeq(sequence *res1500,int num)
{
    for(int i = 0;i < num;i++)
    {
        int ii = res1500[i].ii;
        int jj = res1500[i].jj;
        int kk = res1500[i].kk;
        printf("%4d,(%3d,%3d,%3d)\n",i+1,ii,jj,kk);
        
    }
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{


   sequence *res1500;
   int maxNum[3] = {50,25,13};
   int num = maxNum[0]*maxNum[1]*maxNum[2];
   res1500 = (sequence *)malloc(sizeof(sequence)*num);
   int ii,jj,kk;
   int count = 0;
   for(int ii = 0;ii < maxNum[0];ii++)
   {
       for(int jj = 0;jj < maxNum[1];jj++)
       {
           for(int kk = 0;kk < maxNum[2];kk++)
           {
               res1500[count].ii = ii;
               res1500[count].jj = jj;
               res1500[count].kk = kk;
               count++;
           }
       }
   }
   sort(res1500,num);
   printSeq(res1500,2000);
   sequence res1 = {20,0,0};
   sequence res2 = {6,8,6};
   printf("%d\n",isBig(res1,res2));
   
   printf("%f,%f\n",factor[0],factor[1]);
   
   
   free(res1500);
   
}
/*}}}*/

