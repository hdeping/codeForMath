#include "head.h"

struct HuffmanTree
{
    char ch;
    int weight;
    struct HuffmanTree *left,*right;
};
typedef struct HuffmanTree tree;
#define swap(x,y) tmp = (x);\
(x) = (y);\
(y) = tmp;

#define dispaly_array(arr,len) for(int ii = 0;ii < len;ii++) \
{\
    printf("%d ",arr[ii]);\
}\
printf("\n");

/*void sort{{{*/
void sort(int *arr,int *index,int len)
{
    int tmp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = i + 1;j < len;j++)
        {
            if ( arr[i] < arr[j] )
            {
                swap(arr[i],arr[j]);
                swap(index[i],index[j]);
            }
        }
    }
}
/*}}}*/
/*void firstTraverse{{{*/
void firstTraverse(tree *node)
{
    if ( node )
    {
        printf("node is %c\n",node ->  ch);
        firstTraverse(node -> left );
        firstTraverse(node -> right );
    }
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    char num[5] = "abcde";
    int weight[5] = {1,2,4,8,9};
    int index[5]  = {0,1,2,3,4};
    tree data[9];
    

    for(int i = 0;i < 5;i++)
    {
        data[i].ch     = num[i];
        data[i].weight = weight[i];
        data[i].left   = NULL ;
        data[i].right  = NULL ;
    }
    for(int i = 0;i < 4;i++)
    {
        sort(weight,index,5 - i);
        dispaly_array(weight,5 - i);
        weight[3 - i]  +=   weight[4 - i];
        int j = 5 + i;
        data[j].ch = '0';
        data[j].weight = weight[3-i];
        data[j].left   = data + index[3-i];
        data[j].right  = data + index[4-i];
        index[3 - i]   = j;
        dispaly_array(index,5 - i);
    }
    firstTraverse(data+8);
}
/*}}}*/
