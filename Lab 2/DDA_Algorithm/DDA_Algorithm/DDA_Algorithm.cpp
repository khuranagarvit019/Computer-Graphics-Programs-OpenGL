// DDA_Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <gl/glut.h>
#include <stdio.h>
float x1, y1, x2, y2, dx, dy, x, y;
float m;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3ub(255, 0, 0);

    int i = 1;
    glColor3ub(255, 0, 0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();

    if (m <= 1) {
        while (i <= dx) {
            x = x + (x/dx);
            y = y + (y/dx);
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            i++;
        }
    } else {

        while (i <= dy) {
            x = x + (x/dy);
            y = y + (y/dy);
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            i++;
        }
    }
    glFlush();
}

void init(void) {
    glClearColor(0,0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

int main(int argc, char** argv) {

    x1 = 50.2;
    y1 = 27.8;
    x2 = 763.9;
    y2 = 589.7;

    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    m = (float) dy / (float) dx;
    printf("%f %f\n", x1, y1);
    printf("%f %f\n", x2, y2);
    printf("%f %f %f\n", dx, dy, m);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line using DDA Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
