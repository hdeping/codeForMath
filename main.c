#include "head.h"

/*extern functions{{{*/
extern point *get_point(double x,double y);
extern tri *get_triangle(point *p1,point *p2,point *p3);
extern void escribed_circle(tri *delta);
extern double inscribed_circle(tri *delta);
extern double circucircle(tri *delta);
extern void display_tri(tri *delta);
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    point *p1,*p2,*p3;
    radius *r;
    tri *delta;
    p1 = get_point(1.0,1.0);
    p2 = get_point(- 2.0,3.0);
    p3 = get_point(3.0,3.0);
    delta = get_triangle(p1,p2,p3);
    display_tri(delta);
    circucircle(delta);
    inscribed_circle(delta);
    escribed_circle(delta);
    free(p1);
    free(p2);
    free(p3);
    free(r);
    free(delta);
}
/*}}}*/
