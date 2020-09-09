#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 200 // get n degrees between (0,2*pi)
// some parameters
#define pi    3.1415926
#define beta  1.0
#define r1    100
#define r2    110
#define sigma 2.0
#define y0    50

#define r0 ((r1 + r2) / 2)
#define num (r2 - r1 + 1)
double gaussian[num];
double radius[num];
double degrees[n];
double x_coordinate[n][num];
double z_coordinate[n][num];
double intensity0[n][num];   // intensity for each point 
double intensity1[n][num];   // intensity for each point 
double phi[2*n];
/*double P2{{{*/
double P2(double x)
{
    double result;
    result = 1.0 / 2.0 *(3*x*x - 1.0);
    return result;
}
/*}}}*/
/*double I_theta{{{*/
double I_theta(double theta)
{
    double result;
    result = 1.0 / (4.0*pi) * (1.0 + \
            beta * P2(cos(theta)));
    return result;
}
/*}}}*/
/*void get_coordinate{{{*/
void get_coordinate()
{
    for(int i = 0;i < num;i++)
    {
        radius[i] = 1.0*(r1+i);
    }
    double delta = 1.0*pi / (1.0*n);
    for(int i = 0;i < n;i++)
    {
        degrees[i] = delta*i;
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < num;j++)
        {
            x_coordinate[i][j] = radius[j]*cos(degrees[i]);
            z_coordinate[i][j] = radius[j]*sin(degrees[i]);
        }
        
    }
    // get phi
    delta = 2.0*pi / (1.0*n);
    for(int i = 0;i < 2*n;i++)
    {
        phi[i] = i*delta;
    }
    
}
/*}}}*/
/*void get_gaussian{{{*/
void get_gaussian()
{
    double sum;
    sum = 0.0;
    double tmp;
    double factor = 1.0 / (sqrt(2*pi)*sigma);
    for(int i = 0;i < num;i++)
    {
        tmp = - pow(r1 + i - r0,2) / (2*pow(sigma,2));
        gaussian[i] = exp(tmp) * factor;
        sum += gaussian[i]; 
    }
    for(int i = 0;i < num;i++)
    {
        gaussian[i] /= sum; 
    }
    
}
/*}}}*/
/*void print_out{{{*/
void print_out()
{
    FILE *fp;
    /*
     * 
    fp= fopen("data.txt","w");
    for(int i = 0;i < num;i++)
    {
        fprintf(fp,"%3d   %15.7lf\n",i+1,gaussian[i]);
    }
     * */
    
    fp= fopen("intensity.txt","w");
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < num;j++)
        {
            fprintf(fp,"%18.9lf %18.9lf %18.9lf\n",\
                    x_coordinate[i][j] ,z_coordinate[i][j],intensity0[i][j]);
            fprintf(fp,"%18.9lf %18.9lf %18.9lf\n",\
                    x_coordinate[i][j] ,- z_coordinate[i][j],intensity0[i][j]);
        }
        
    }
    fclose(fp);
    

}
/*}}}*/
/*void get_4d_data{{{*/
void get_4d_data()
{
    FILE *fp;
    fp= fopen("total.txt","w");
    double x,y,z,w;
    int count;
    count = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < num;j++)
        {
            for(int k = 0;k < 2*n;k++)
            {
                x = radius[j]*sin(degrees[i])*cos(phi[k]);
                z = radius[j]*sin(degrees[i])*sin(phi[k]);
                y = radius[j]*cos(degrees[i]);
                w = intensity0[i][j];
                if ( abs(y) < y0 )
                {
                    fprintf(fp,"%18.9lf %18.9lf %18.9lf %18.9lf\n",x,y,z,w);
                }
                count++;
                printf("count = %d\n",count);
                
            }
            
        }
        
    }
    
    fclose(fp);
    
}
/*}}}*/
/*int main{{{*/
int main( int argc, char *argv[] ){
    
    get_coordinate();
    get_gaussian();
    // get intensity0

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < num;j++)
        {
            intensity0[i][j] = I_theta(degrees[i])*gaussian[j];
        }
        
    }
    // print_out();
    get_4d_data();
    
    return 0;
}

/*}}}*/
