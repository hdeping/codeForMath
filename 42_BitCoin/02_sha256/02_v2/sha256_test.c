/*********************************************************************
* Filename:   sha256.c
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Performs known-answer tests on the corresponding SHA1
	          implementation. These tests do not encompass the full
	          range of available test vectors, however, if the tests
	          pass it is very, very likely that the code is correct
	          and was compiled properly. This code also serves as
	          example usage of the functions.
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha256.h"

/*********************** FUNCTION DEFINITIONS ***********************/
/*void fprint_buf{{{*/
void fprint_buf(BYTE *buf,FILE *fp)
{
    for(int i = 0;i < SHA256_BLOCK_SIZE;i++)
    {
        if ( buf[i] < 16 )
        {
            fprintf(fp,"0%x",buf[i]);
        }
        else
        {
            fprintf(fp,"%x",buf[i]);
        }
        
        
    }
    fprintf(fp,"\n");
    
    
}
/*}}}*/
/*void print_buf{{{*/
void print_buf(BYTE *buf)
{
    for(int i = 0;i < SHA256_BLOCK_SIZE;i++)
    {
        if ( buf[i] < 16 )
        {
            printf("0%x",buf[i]);
        }
        else
        {
            printf("%x",buf[i]);
        }
        
        
    }

    printf("\n");
    
    
}
/*}}}*/
/*int sha256_test{{{*/
int sha256_test()
{
	// BYTE text1[] = {"abc"};
	// BYTE text1[] = {"aba"};
	BYTE text1[30]; 
	// BYTE text1[] = {"huangDeping x=3"};
	BYTE buf[SHA256_BLOCK_SIZE];
	SHA256_CTX ctx;
	int idx;
	int pass = 1;

    int num = 10000000;
    FILE *fp;
    fp= fopen("hash.txt","w");
    assert(fp != NULL);

    int count = 0;
    int i;
    while (1)
    {
        i  = rand();
        sprintf(text1,"huangDeping x=%d",i);
	    sha256_init(&ctx);
	    sha256_update(&ctx, text1, strlen(text1));
	    sha256_final(&ctx, buf);
        // if ( buf[0] + buf[1] + buf[2] == 0  )
        if ( buf[0] + buf[1] == 0  )
        // if ( buf[0] == 0  )
        {
            printf("nounce = %d ",i);
            print_buf(buf);
            count++;
            
        }
        if ( count == 2  )
        {
            break; 
        }
        
    }
    printf("count is %d\n",count);
    
    fclose(fp);
}
/*}}}*/

int main()
{
    srand(time(NULL)); 
    sha256_test();
	return(0);
}
