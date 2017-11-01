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
   int tmp = array[division];  
   while(1) {  
      while(array[left] < tmp) {  
     left ++;  
      }  
      if(left >= right) break;  
      array[division] = array[left];  
      division = left;  
      while(array[right] >= tmp) {  
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
void sort(int array[], int left, int right) {  
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

