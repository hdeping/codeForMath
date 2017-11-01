#include "head.h"

/*void getChar58{{{*/
void getChar58(char *ch)
{
    int num = 0;
    // number 0~9
    for(int i = 0;i < 10;i++)
    {
        ch[num] = '0'+i;
        num++;
    }
    // lower character
    char tmp;
    for(int i = 0;i < 26;i++)
    {
        
        tmp = 'a'+i;
        if ( tmp !=  'l' && tmp != 'o'    )
        {
            ch[num] = tmp;
            num++;
        }
        
    }
    // upper character
    for(int i = 0;i < 26;i++)
    {
        
        tmp = 'A'+i;
        if ( tmp !=  'I' && tmp != 'O'    )
        {
            ch[num] = tmp;
            num++;
        }
        
    }
    
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    srand(time(NULL)); 
    unsigned long privateKey[4];
    unsigned long randNum ;

    char ch[58];
    // get char
    getChar58(ch);
    for(int i = 0;i < 58;i++)
    {
        printf("%c",ch[i]);
        
    }
    printf("\n");
    


    for(int i = 0;i < 4;i++)
    {
        randNum = rand();
        privateKey[i] = randNum*randNum;
        printf("%ld\n",privateKey[i]);
    }

}
/*}}}*/

