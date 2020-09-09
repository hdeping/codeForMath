#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Point
{
    double x;
    double y;
};
struct Radius
{
    double r1;
    double r2;
    double r3;
};
struct Triangle
{
    double a;
    double b;
    double c;
};
typedef struct Triangle tri;
typedef struct Radius radius;
typedef struct Point point;

