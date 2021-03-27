#include<GL/glut.h>
#include <vector>
using namespace std;

int x1, y1, r;
void Plot(int x, int y){
    glBegin(GL_POINTS);
	glVertex2i(x+x1, y+y1);
	glEnd();
}

void DrawCircle() {
    int x = 0;
    int y = r;
    float d = 1.25 - r;
    Plot(x, y);
    while (y > x) {
        if (d < 0) {
            x++;
            d += 2 * x + 1;
        } else {
            y--;
            x++;
            d += 2 * (x - y) + 1;
        }
        Plot(x, y);
		Plot(x, -y);
		Plot(-x, y);
		Plot(-x, -y);
		Plot(y, x);
		Plot(-y, x);
		Plot(y, -x);
		Plot(-y, -x);
    }
}

void Display(void){
    glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
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
