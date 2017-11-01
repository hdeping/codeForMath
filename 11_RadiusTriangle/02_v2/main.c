#include "head.h"

/*point *get_point{{{*/
point *get_point(double x,double y)
{
    point *res;
    res = (point *)malloc(sizeof(point));
    res -> x = x;
    res -> y = y;
    return res;
}
/*}}}*/
/*radius *get_radius{{{*/
radius *get_radius(double r1,double r2,double r3)
{
    radius *res;
    res = (radius *)malloc(sizeof(radius));
    res -> r1 = r1;
    res -> r2 = r2;
    res -> r3 = r3;
    return res;
}
/*}}}*/
/*radius *get_triangle_radius{{{*/
radius *get_triangle_radius(point *p1,point *p2,point *p3)
{
    double r1,r2,r3;
    double x[3],y[3];
    double d[3],r[3];
    x[0] = p1 -> x; 
    x[1] = p2 -> x; 
    x[2] = p3 -> x; 
    y[0] = p1 -> y; 
    y[1] = p2 -> y; 
    y[2] = p3 -> y; 
    int j;
    double peri = 0.0;
    for(int i = 0;i < 3;i++)
    {
        j      = (i+1)%3;
        d[i] = pow(x[j]-x[i],2.0)+pow(y[j]-y[i],2.0);
        d[i] = sqrt(d[i]);
        peri += d[i]; 
    }
    peri /= 2.0;
    for(int i = 0;i < 3;i++)
    {
        r[i] = peri - d[i];
    }
    radius *res;
    res = get_radius(r[0],r[1],r[2]);
    return res;
}
/*}}}*/
/*void display_radius{{{*/
void display_radius(radius *r)
{
    printf("r1 = %lf\n",r -> r1 );
    printf("r2 = %lf\n",r -> r2 );
    printf("r3 = %lf\n",r -> r3 );
}
/*}}}*/
/*void display_point{{{*/
void display_point(point *p)
{
    printf("x = %lf\n",p -> x );
    printf("y = %lf\n",p -> y );
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    point *p1,*p2,*p3;
    radius *r;
    p1 = get_point(1.0,1.0);
    p2 = get_point(3.0,1.0);
    p3 = get_point(1.0,3.0);
    display_point(p1);
    display_point(p2);
    display_point(p3);
    r = get_triangle_radius(p1,p2,p3);
    display_radius(r);
    free(p1);
    free(p2);
    free(p3);
    free(r);
}
/*}}}*/
