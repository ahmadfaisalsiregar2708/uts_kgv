#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define MessageBox MessageBoxA
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAX 60

void initGrid(int, int);
void drawGrid();
void drawFood();
void drawSnake();
void random(int&, int&);


#endif 
