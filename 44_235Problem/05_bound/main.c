#include "head.h"

   float factor[2] = {log(3.0)/log(2.0),log(5.0)/log(2.0)};


/*float getValue{{{*/
float getValue(sequence input)
{

    int ii = input.ii;
    int jj = input.jj;
    int kk = input.kk;
    float res;

    res = ii*log(2.0)+jj*log(3.0)+kk*log(5.0);
    
    return res;

}
/*}}}*/
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
/*int part{{{*/

/* 
 * 分治算法: 
 *    以division下标的元素值为分界点, 将数组分成左右两个部分. 
 *    返回分界点的下标. 
 * 过程: 
 *    1. 保留分界点元素的值. 
 *    2. 移动左指针, 直到一个值不小于分界值. 
 *    3. 判断是否已经划分了所有元素, 如果是, 跳出. 
 *    4. 将左指针目前的值复制到division位置, 重置division为left位置. 
 *    5. 和2-4步骤一样, 处理右指针. 
 *    6. 将分界值放入最终确定的分界下标. 
 *    7. 返回分界下标. 
 */  
int part(sequence array[], int division, int left, int right) {  
   sequence tmp = array[division];  
   while(1) 
   {  
       while(isBig(tmp,array[left])) 
       {  
           left ++;  
       }  
       if(left >=  right) break;  
       array[division] = array[left];  
       division = left;  
       while(isBig(array[right] , tmp)) 
       {  
           right --;  
       }  
       if(left >= right) break;  
       array[division] = array[right];  
       division = right;  
   }  
   array[division] = tmp;  
   return division;  
}  
/*}}}*/
/*void sort{{{*/
/* 
 * 过程: 
 *    1. 将整个left到right位置分治(分治之后左子数组, 分界值, 右子数组是有序的.) 
 *    2. 将分治得到的左子数组和右子数组分别分治. 
 *    3. 如果传入的left >= right, 说明要排序的部分元素少于或等于1个,  
 *   那么必然是有序的,所以直接返回. 
 */  
void sort(sequence array[], int left, int right) {  
   if(left >= right) {  
      return ;  
   }  
   int division = (left + right) / 2;  
   /*  
    * printf("division: %d, ", array[division]); 
    */  
   int partition = part(array, division, left, right);  
   /* 
    *  printf("partition: %d, left: %d, right: %d, ", partition, left, right); 
    *  printArray(array, LENGTH); 
    */  
   sort(array, left, partition - 1);  
   sort(array, partition + 1, right);  
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
/*sequence getSeq1500{{{*/
sequence getSeq1500(int max1,int max2,int max3)
{


   sequence *res1500;
   int maxNum[3] = {max1,max2,max3};
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
   sort(res1500,0,num-1);
   sequence res = res1500[1499];
   free(res1500);
   return res;
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    sequence res;
    for(int i = 20;i < 41;i++)
    {
        for(int j = 10;j < 21;j++)
        {
            for(int k = 10;k < 21;k++)
            {
                res = getSeq1500(i,j,k);
                /**
                 * 
                int ii = res.ii;
                int jj = res.jj;
                int kk = res.kk;
                printf("(%3d,%3d,%3d),(%3d,%3d,%3d)\n",
                         i,j,k,ii,jj,kk);
                 * */
                
                int index = (i-20)*121+(j-10)*11+k-10;
                printf("%d,%f\n",index,getValue(res));
                
            }
            
        }
        
    }
    
}
/*}}}*/
