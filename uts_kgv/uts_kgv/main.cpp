// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#define _CRT_NONSTDC_NO_DEPRECATE
#include <glut.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h" 

#define COLUMNS 40
#define ROWS 40
#define FPS 10

using namespace std;

extern short sDirection;
bool gameOver = false;
int score = 0;

void display_callback();
void reshape_callback(int, int);
void timer_callback(int);
void keyboard_callback(int, int, int);

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Snake");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0, timer_callback, 0);
	glutSpecialFunc(keyboard_callback);
	init();
	glutMainLoop();
	return 0;
}


void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
		glColor3ub(255, 0, 0);
		glVertex2f(-50, 50);
		glColor3ub(255, 255, 0);
		glVertex2f(50, 50);
		glColor3ub(255, 255, 0);
		glVertex2f(50, -50);
		glColor3ub(255, 0, 0);
		glVertex2f(-50, -50);
	glEnd();
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();
	
	if (gameOver)
	{
		char _score[10];
		_itoa_s(score, _score, 10); //konversi integer ke char
		char text[50] = "Your Score : ";
		strcat_s(text, _score); //menambah string _score ke text
		MessageBox(NULL, text, "Game Over", 0);
		exit(0);
	}
}

void reshape_callback(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int) 
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

void keyboard_callback(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (sDirection != DOWN)
			sDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sDirection != UP)
			sDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sDirection != LEFT)
			sDirection = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (sDirection != RIGHT)
			sDirection = LEFT;
		break;
	default:
		break;
	}
}


// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
