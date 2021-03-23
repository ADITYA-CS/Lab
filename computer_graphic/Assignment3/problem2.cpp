#include<GL/glut.h>
#include <vector>
using namespace std;

vector<pair<int, int>> points;

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0);
    for (auto point : points) 
        glVertex2f(point.first, point.second);
    glEnd();
    glFlush();
}

void Init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D (0.0,200.0,0.0,200.0);
}

void Line(int x1, int y1, int x2, int y2) {
    points.push_back({x1, y1});
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < dy) {
        int d = dx - dy / 2;
        while (y1 < y2) {
            y1++;
            if (d < 0) d += dx;
            else d += dx - dy, x1++;
        }
        points.push_back({x1, y1});
    } else {
        int d = dy - dx / 2;
        while (x1 < x2) {
            x1++;
            if (d < 0) d += dy;
            else d += dy - dx, y1++;
        }
        points.push_back({x1, y1});
    }
}

int main(int argc,char** argv) {

    Line(20, 20, 120, 120);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 3");
    Init();
    glutDisplayFunc(Display);
    glutMainLoop();
}
