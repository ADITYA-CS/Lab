#include<GL/glut.h>
#include <cmath>
using namespace std;

int X, Y, r;
void Plot(double x, double y){
    glBegin(GL_POINTS);
	glVertex2f(x+X, y+Y);
	glEnd();
}

void DrawCircle() {
    int v = 1, n = 0;
    double s, x, y;
    while (v < r) {
        v  *= 2;
        n++;
    }
    s = pow(2, -n);
    x = 0, y = r;
    while (x <= y) {
        Plot(x + X,y + Y);
        Plot(-x + X,y + Y);
        Plot(-x + X,-y + Y);
        Plot(x + X,-y + Y);
        Plot(y + X,x + Y);
        Plot(-y + X,x + Y);
        Plot(-y + X,-x + Y);
        Plot(y + X,-x + Y);
        x += s * y; 
        y -= s * x;
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
