#include "head.h"

/*void graphic::init{{{*/
void graphic::init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT,GL_DONT_CARE);
    glHint(GL_POINT_SMOOTH_HINT,GL_DONT_CARE);
    glLineWidth(1.0);
    glPointSize(2.0);
}
/*}}}*/
/*void graphic::drawCircle{{{*/
void graphic::drawCircle(double x,double y,double radius)
{
    static int nn = 40;
    static double pi = 3.141592653;
    double coor[2];
    double angle;

    double theta = 2*pi/(1.0*nn);

    glBegin (GL_POLYGON);
    for(int i = 0;i < nn;i++)
    {
        angle   = theta * i;
        coor[0] = radius*cos(angle) + x;
        coor[1] = radius*sin(angle) + y;
        glVertex3f(coor[0],coor[1],0);
    }
    glEnd();
    
}
/*}}}*/
/*void graphic::display{{{*/
void graphic::display(void){
    // Called when opengl needs 
    // to update the display
    glClear( GL_COLOR_BUFFER_BIT);  
    glLoadIdentity();
    gluLookAt(0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    drawCircle(0.0,0.0,1.0);
    // force update of screen
    glFlush();


    glutSwapBuffers();

}
/*}}}*/
/*void graphic::keyboard{{{*/
void graphic::keyboard(unsigned char key, int x,int y){
    if ( key == 27 || key == 'q'    ){
        exit(0); // 27 is the "Escape" key
    }
}
/*}}}*/
/*void graphic:: reshape{{{*/
void graphic:: reshape(int width ,int height){
    /*
     * called when the window is created, moved or resized
     * */
    glViewport(0,0,(GLsizei)width,(GLsizei)height);
    glMatrixMode(GL_PROJECTION);  // select projection matrix
    glOrtho(- 1.0,1.0,- 1.0,1.0, - 1.0,1.0);  // the unit cube
}
/*}}}*/
/*void graphic:: idle{{{*/
void graphic:: idle(void)
{

    glutPostRedisplay();
}
/*}}}*/
/*void graphic::draw{{{*/
void graphic::draw(int argc,char *argv[])
{
    glutInit(&argc,argv);     // Initialise the opengl
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(300,0);
    glutInitWindowSize(800,800);
    glutCreateWindow("Xiaohengdao");  // create the window

    init();

    glutDisplayFunc(display); // register the "display" funcion
    glutReshapeFunc(reshape);
    glutKeyboardUpFunc(keyboard);  // register the "keyboard" funcion
    glutIdleFunc(idle);
    glutMainLoop();           // enter the opengl main loop
}
/*}}}*/
