// Bresenham Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <gl/glut.h>
#include <stdio.h>
float x1, y1, x2, y2, dx, dy, x, y, p0, p;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);
    int i;
    glColor3ub(255, 0, 0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
    p = p0;

    for (i = 0; i < dx; i++) {
        printf("\nm= %f\n\n", (float)((y2 - y1) / (x2 - x1)));
        printf("dx= %f\n", dx);
        printf("dy= %f\n", dy);
        printf("(x,y): (%f,%f)", x, y);
        printf("\np= %f", p);
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
        if (p < 0) {
            x = x + 1;
            y = y;
            p = p + 2 * dy;
        } else {
            x = x + 1;
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
    }
    glFlush();
}

void init(void) {
    glClearColor(256, 256, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

int main(int argc, char** argv) {

    x1 = 5.2;
    y1 = 2.8;
    x2 = 163.9;
    y2 = 118.7;

    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    p0 = 2 * (y2 - y1) - dx;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}