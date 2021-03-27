#include<GL/glut.h>
#include <vector>
using namespace std;

int x1, y1, r;
void Plot(float x, float y){
    glBegin(GL_POINTS);
	glVertex2f(x+x1, y+y1);
	glEnd();
}

void DrawCircle() {
    int v = 1, n = 0;
    float s, x, y;
    while (v < r) {
        v  *= 2;
        n++;
    }
    s = pow(2, -n);
    x = 0, y = r;
    while (x <= y) {
        Plot(x + x1,y + y1);
        Plot(-x + x1,y + y1);
        Plot(-x + x1,-y + y1);
        Plot(x + x1,-y + y1);
        Plot(y + x1,x + y1);
        Plot(-y + x1,x + y1);
        Plot(-y + x1,-x + y1);
        Plot(y + xc,-x + y1);
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

    x1 = 300;
    y1 = 300;
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
