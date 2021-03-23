#include<windows.h>
#include<GL/glut.h>
#include <vector>
using namespace std;
vector<pair<float, float>> points;

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

void Line(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    dx /= step;
    dy /= step;
    for (int i = 0; i < step; i++) {
        points.push_back({x1, y1});
        x1 += dx;
        y1 += dy;
    }
}

int main(int argc,char** argv) {

    Line(20, 20, 120, 120);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 2");
    Init();
    glutDisplayFunc(Display);
    glutMainLoop();
}
