#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


/*namespace graphic{{{*/
namespace graphic
{
    void init();
    void drawCircle(double x,double y,double radius);
    void display(void);
    void keyboard(unsigned char key, int x,int y);
    void reshape(int width ,int height);
    void idle(void);
    void draw(int argc,char *argv[]);
};
/*}}}*/
