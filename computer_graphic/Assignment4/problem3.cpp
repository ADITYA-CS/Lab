#include<GL/glut.h>
#include <cmath>
using namespace std;

int X, Y, r;
void Plot(int x,int y){
    glBegin(GL_POINTS);
	glVertex2i(X + x, Y + y);
    glVertex2i(X+ x, Y - y);
    glVertex2i(X + y, Y + x);
    glVertex2i(X + y, Y - x);
    glVertex2i(X - x, Y - y);
    glVertex2i(X - y, Y - x);
    glVertex2i(X - x, Y + y);
    glVertex2i(X - y, Y + x);
	glEnd();
}

void DrawCircle() {
    int x = 0,y = r;
    float t =1.25 - r;
    Plot(x,y);
    int k;
    while(x < y) {
        x = x + 1;
        if(t < 0)
            t = t + 2 * x + 1;
        else {
            y = y - 1;
            t = t + 2 * (x - y) + 1;
        }
        Plot(x,y);
    }
}

void Display(void){
    glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glPointSize(2.0);
    DrawCircle();
	glFlush ();
}

void Init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

int main(int argc,char** argv) {

    X = 300;
    Y = 300;
    r = 200;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 4");
    Init();
    glutDisplayFunc(Display);
    glutMainLoop();
}
