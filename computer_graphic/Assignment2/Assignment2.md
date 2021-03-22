# Assignment 2

**Name :** Aditya Kumar Singh
**Roll No:** 194CA004

Q1. Rectangular Prism : A 3D object that has 6 faces, 12 edges and 8 vertices – 4 of the faces
are rectangles

```c++
#include<GL/glut.h>
#include <vector>
using namespace std;

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    vector<pair<float, float>> rec1{{-40, -20}, {-40, 60}, {100, 60}, {100, -20}};
    vector<pair<float, float>> rec2{{-70, -40}, {-70, 40}, {70, 40}, {70, -40}};

    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0);
    for (auto p : rec1) {
        glVertex2f(p.first, p.second);
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    for (auto p : rec2) {
        glVertex2f(p.first, p.second);
    }
    glEnd();

    for (int i = 0; i < 4; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3f(0,0,1);
        glVertex2f(rec1[i].first, rec1[i].second);
        glVertex2f(rec2[i].first, rec2[i].second);
        glVertex2f(rec1[i].first, rec1[i].second);
        glEnd();
    }
    glFlush();
}

void Init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D (-200.0,200.0,-200.0,200.0);
}

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 2");
    Init();
    glutDisplayFunc(Display);
    glutMainLoop();
}

```

![](G:\Github\Lab\computer_graphic\Assignment2\pic1.png)

```c++
#include <bits/stdc++.h>
using namespace std;

struct point {
    float x, y, z;
};

GLfloat y;
void init(void) {
    glClearColor(0,0,0,0);

}

void display(void) {

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-10.5);
    glRotatef(y,0.0,1.0,0.0);
    glBegin(GL_QUADS);
    vector<point> rectangle{ {-1, -1, -1}, {1, -1, -1}, {1, -1, 1}, {-1, -1, 1},
        {-1, 1, -1}, {1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};
    vector<vector<int>> faces{ {0, 1, 2, 3}, {4, 5, 6, 7}, {0, 3, 7, 4},
        {1, 5, 6, 2}, {2, 6, 7, 3}, {0, 1, 5, 4}};
    vector<vector<float>> colors{{1, 0, 0}, {0, 1, 0}, {0, 0,1}, {1, 0.5, 0}, {1, 1, 0}, {1, 0, 1}};
    for (int i = 0; i < 6; i++) {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        for (auto &v : faces[i]) {
            glVertex3f(rectangle[v].x, rectangle[v].y, rectangle[v].z);

        }
    }
    glEnd();            // End Drawing The Cube
    glFlush();
}


void animation(void) {
    y += 0.1;
    display();
}

void reshape(int x, int y) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 2");
    init();
    glutDisplayFunc(DrawCube);
    glutReshapeFunc(reshape);
    glutIdleFunc(animation);
    glutMainLoop();
    return 0;
}

```

![](G:\Github\Lab\computer_graphic\Assignment2\pic11.png)

Q2. Square Pyramid: A square pyramid has a square base and triangle sides – 5 faces, 8 edges
and 5 vertices.

```cpp
#include<windows.h>
#include<GL/glut.h>
#include <vector>
#include <cmath>
using namespace std;

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    vector<pair<float, float>> sq{{-60,0}, {-10,40}, {60,0}, {10,-40}};
    float topx = 10;
    float topy = 80;

    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0);
    for (auto p : sq) {
        glVertex2f(p.first, p.second);
    }
    glEnd();
    for (auto p : sq) {
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 1, 0);
        glVertex2f(p.first, p.second);
        glVertex2f(topx, topy);
        glVertex2f(p.first, p.second);
        glEnd();
    }
    glFlush();
}

void Init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D (-200.0,200.0,-200.0,200.0);
}

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 2");
    Init();
    glutDisplayFunc(Display);
    glutMainLoop();
}

```

![](G:\Github\Lab\computer_graphic\Assignment2\pic2.png)

```cpp
#include <GL\glut.h>
#include <bits/stdc++.h>
using namespace std;

struct point {
    float x, y, z;
};

GLfloat z;
void init(void) {
    glClearColor(0,0,0,0);

}

void display(void) {
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-10.5);
    glRotatef(z,0.5,0.5,0.5);
    vector<point> rectangle{ {-1, -1, 0}, {1, -1, 0}, {1, 1, 0}, {-1, 1, 0},
        {0, 0, 1},};
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    for (auto p : {0, 1, 2, 3}) {
        glVertex3f(rectangle[p].x, rectangle[p].y, rectangle[p].z);
    }
    glEnd();
    vector<vector<int>> faces{{4, 0, 1}, {4, 1, 2}, {4, 2, 3}, {4, 3, 0}};
    vector<vector<float>> colors{{0, 1, 0}, {0, 0,1}, {1, 0.5, 0}, {1, 1, 0}};
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 4; i++) {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        for (auto &v : faces[i]) {
            glVertex3f(rectangle[v].x, rectangle[v].y, rectangle[v].z);

        }
    }
    glEnd();
    glFlush();
}


void animation(void) {
    z += 0.1;
    display();
}

void reshape(int x, int y) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 2");
    init();
    glutDisplayFunc(DrawCube);
    glutReshapeFunc(reshape);
    glutIdleFunc(animation);
    glutMainLoop();
    return 0;
}

```

![](G:\Github\Lab\computer_graphic\Assignment2\pic21.png)