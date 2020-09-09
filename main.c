#include "head.h"

/*void perm{{{*/
void perm(int *list, int k, int m) 
{     
    int i;     
    if(k > m)     
    {          
        for(i = 0; i <= m; i++)
        {
            fprintf(fp,"%d ", list[i]);         
        }
        fprintf(fp,"\n");         
        countNumber++;
    }     
    else     
    {         
        for(i = k; i <= m; i++)         
        {             
            swap(list[k], list[i]);             
            perm(list, k + 1, m);             
            swap(list[k], list[i]);         
        }     
    } 
} 
/*}}}*/
/*int main{{{*/
int main() 
{     
    fp= fopen("data.txt","w");
    assert(fp != NULL);
    int list[10] ;
    for(int i = 0;i < 10;i++)
    {
        list[i] = i+1;
    }
    perm(list, 0, 9);     
    printf("count Number :%d\n", countNumber);     
    fclose(fp);
    return 0; 
}  
/*}}}*/
