#include "head.h"

int recordNum[100];

/*void printData{{{*/
void printData(int *data,int n,int m)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            int index = i*m + j;
            printf("%3d ",data[index]);
            
        }
        printf("\n");
        
    }
}
/*}}}*/
/*void getMatMul{{{*/
void getMatMul(int *out,int *arr1,int *arr2,int size)
{
    int index1,index2,index3;
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
        {
            index1 = i*size + j;
            int sum = 0;

            for(int k = 0;k < size;k++)
            {
                index2 = i*size + k;
                index3 = k*size + j;
                sum += arr1[index2]*arr2[index3];

            }
            out[index1] = sum;
            
        }
        
    }
    
}
/*}}}*/
/*void getResidueMat{{{*/
void getResidueMat(int *arr,int value,int finalNum,int size)
{
    int *arr1,*result;
    int *arr2;

    result = (int *)malloc(sizeof(int)*4);
    arr1 = (int *)malloc(sizeof(int)*4);
    arr2 = (int *)malloc(sizeof(int)*4);
    
    int *tmp;

    result[0] = 1;
    result[1] = 0;
    result[2] = 0;
    result[3] = 1;
    
    for(int i = 0;i < size;i++)
    {
        arr1[0] = 1;
        arr1[3] = 1;
        int j = i%2;
        arr1[j+1] = 0;
        arr1[2-j] = -arr[i];
        // arr1[2-j] = arr[size - 1 - i];
        // printData(arr1,2,2);
        // exchange arr2 and result
        tmp  = arr2;
        arr2 = result;
        result = tmp;

        getMatMul(result,arr2,arr1,2);

        
    }
    printf("Result is :\n");
    printData(result,2,2);


    // get final solutions!
    if ( size%2 == 0  )
    {
        arr1[0] = 0;
        arr1[1] = 1;
        arr1[2] = value;
        arr1[3] = - finalNum;
    }
    else
    {
        arr1[0] = value;
        arr1[1] = - finalNum;
        arr1[2] = 0;
        arr1[3] = 1;
        
    }
    
    
    getMatMul(arr2,result,arr1,2);
    int num1,num2,num;
    for(int i = 0;i < 2;i++)
    {
        if ( arr2[2*i+1] < 0 )
        {

            num  = arr2[2*i]/abs(arr2[2*i+1]);
            num1 = arr2[2*i]%abs(arr2[2*i+1]);
            num2 = arr2[2 - 2*i] + arr2[3 - 2*i]*num;

        }
        
    }
    
    printf("%d,%d,%d\n",num,num1,num2);
    
    
    printf("a: (%d) + (%d)t \n",num1,arr2[1]);
    printf("a: (%d) + (%d)t \n",num2,arr2[3]);
    



    
    free(arr1);
    free(arr2);
    free(result);
}
/*}}}*/
/*void runResidue{{{*/
void runResidue(int num1,int num2,int value)
{
    int tmp;
    int i = 0;
    while ( num2 != 1  )
    {
        recordNum[i] = num1 / num2;
        tmp = num1%num2;
        num1 = num2;
        num2 = tmp;
        i++;
        
    }
    int n = i;
    printf("%d,%d n = %d\n",num1,num2,n);
    printData(recordNum,1,n);


    // num1 is the final number
    // num1,num2 = finalNum,1
    getResidueMat(recordNum,value,num1,n);

}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    // n*a + m*c = value
    // what is the integer solution?
    // bigger one is in the front
    // such as : 73 27!

    // There is no need that n > m
    // n > m or m > n, anyway!
    
    int n     = 79;
    int m     = 117;
    int value = 20000;

    runResidue(n,m,value);
    

}
/*}}}*/

