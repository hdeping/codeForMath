#include "head.h"
#include <gsl/gsl_linalg.h>

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
/*double get_dis{{{*/
double get_dis(point *p1,point *p2)
{
    double res;
    res = pow(p1 -> x - p2 -> x,2.0  );
    res += pow(p1 -> y - p2 -> y,2.0  ); 
    res = sqrt(res);
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
    double a,b,c,p;
    a = get_dis(p1,p2);
    b = get_dis(p2,p3);
    c = get_dis(p3,p1);
    p = (a+b+c) / 2.0;
    radius *res;
    r1 = p - a;
    r2 = p - b;
    r3 = p - c;
    res = get_radius(r1,r2,r3);
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
/*tri *get_triangle{{{*/
tri *get_triangle(point *p1,point *p2,point *p3)
{
    tri *res;
    res = (tri *)malloc(sizeof(tri));
    res -> a = get_dis(p1,p2); 
    res -> b = get_dis(p1,p3); 
    res -> c = get_dis(p3,p2); 
}
/*}}}*/
/*void display_tri{{{*/
void display_tri(tri *delta)
{
    printf("Triangle: \n");
    printf("a = %9.5lf\n",delta -> a );
    printf("b = %9.5lf\n",delta -> b );
    printf("c = %9.5lf\n",delta -> c );
}
/*}}}*/
/*void get_triangle_edges{{{*/
void get_triangle_edges(double *a,double *b,double *c,tri *delta)
{
    *a = delta -> a; 
    *b = delta -> b; 
    *c = delta -> c; 
}
/*}}}*/
/*int judge_triangle{{{*/
int judge_triangle(double a,double b,double c)
{
    bool p,p1,p2,p3;
    p1 = (a+b>c);
    p2 = (a+c>b);
    p3 = (c+b>a);
    p  = p1 && p2 && p3;  
    if ( p )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
/*}}}*/
/*double get_area{{{*/
double get_area(tri *delta)
{
    double a,b,c,p;
    get_triangle_edges(&a,&b,&c,delta);
    if ( judge_triangle(a,b,c) == 0  )
    {
        printf("triangle error!!!!!\n");
        printf("A,B,C can not construct a triangle!!!!\n");
        return 0.0;
    }
    double res;
    p   = (a+b+c) / 2.0;
    res = p*(p-a)*(p-b)*(p-c);
    res = sqrt(res);
    return res ;
}
/*}}}*/
// get radius
/*double circucircle{{{*/
double circucircle(tri *delta)
{
    double res;
    double a,b,c,area;
    get_triangle_edges(&a,&b,&c,delta);
    area = get_area(delta);
    res = a*b*c/(4.0*area);
    printf("the radius of circucircle is :\n");
    printf("    R = %lf\n",res);
    return res;
}
/*}}}*/
/*double inscribed_circle{{{*/
double inscribed_circle(tri *delta)
{
    double res;
    double a,b,c,area,p;
    get_triangle_edges(&a,&b,&c,delta);
    area = get_area(delta);
    p    = (a+b+c) / 2.0;
    res  = area / p;
    printf("the radius of inscribed circle is :\n");
    printf("    R = %lf\n",res);
    return res;
}
/*}}}*/
/*void escribed_circle{{{*/
void escribed_circle(tri *delta)
{
    double res;
    double a,b,c,area,p;
    get_triangle_edges(&a,&b,&c,delta);
    printf("the radius of escribed circle is :\n");
    area = get_area(delta);
    p    = (a+b-c) / 2.0;
    res  = area / p;
    printf("    R1 = %lf\n",res);
    p    = (c+b-a) / 2.0;
    res  = area / p;
    printf("    R2 = %lf\n",res);
    p    = (c+a-b) / 2.0;
    res  = area / p;
    printf("    R3 = %lf\n",res);
}
/*}}}*/
// get circle dot
/*point * dot_circucircle{{{*/
point * dot_circucircle(point *line1,point *p1,point *line2,point *p2)
{

}
/*}}}*/
