// Draw Window using OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <gl/glut.h>
#include <stdlib.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


void init() {
    glClearColor(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("green window");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}