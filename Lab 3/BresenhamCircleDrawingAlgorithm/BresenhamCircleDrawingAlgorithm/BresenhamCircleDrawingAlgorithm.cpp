// BresenhamCircleDrawingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <math.h>
#include <gL/glut.h>

int xc, yc, r;

void plot_point(int x, int y) {
	glPointSize(10.0);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}
void bresenham_circle(int r) {
	int x = 0, y = r;
	float pk = (5.0 / 4.0) - r;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(-100, 0);
	glVertex2i(100, 0);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0, -100);
	glVertex2i(0, 100);
	glEnd();

	plot_point(x, y);
	int k;

	while (x < y) {
		x = x + 1;
		if (pk < 0) {
			pk = pk + 2 * x + 1;
		} else {
			y = y - 1;
			pk = pk + 2 * (x - y) + 1;
		}
		plot_point(x, y);
	}
	glFlush();
}
void circles(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	int radius1 = r;
	bresenham_circle(radius1);
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);

}

int main(int argc, char** argv) {
	printf("Enter the coordinates of the circle's centre:");
	scanf_s("%d %d", &xc, &yc);
	printf("Enter the radius of the circle:");
	scanf_s("%d", &r);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Bresenham Complete Circle");
	init();
	glutDisplayFunc(circles);
	glutMainLoop();

}