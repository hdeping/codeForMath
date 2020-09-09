#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>


struct Property
{
    int n;
    int  num[3];
    int *arr[3];
};
typedef struct Property property;
