#pragma once
#include <Windows.h>
#include "Board.h"



class Player {
public:
	Board* board;
	int direction;
	int lenght;
	int x;
	int y;

public:
	Player(Board *b){
		board = b;
		x = 0;
		y = 0;
		lenght = 1;
		direction = 3;
	}

	void move() {

		/*
		0 up
		1 down
		2 left
		3 right
		*/

		bool isUpArrowPressed = GetAsyncKeyState(38) & 0x8000;
		bool isDownArrowPressed = GetAsyncKeyState(40) & 0x8000;
		bool isLeftArrowPressed = GetAsyncKeyState(37) & 0x8000;
		bool isRightArrowPressed = GetAsyncKeyState(39) & 0x8000;

		if (isDownArrowPressed) {
			direction = 1;
		}

		if (isUpArrowPressed) {
			direction = 0;
		}

		if (isLeftArrowPressed) {
			direction = 2;

		}

		if (isRightArrowPressed) {
			direction = 3;

		}

		switch (direction)
		{
		case 0:
			y--;
			if (y <0) {
				y = board->height-1;
			}
			break;

		case 1:
			y++;
			if (y > board->height - 1) {
				y = 0;
			}
			break;

		case 2:
			x--;
			if (x < 0) {
				x = board->width-1;
			}
			break;

		case 3:
			x++;
			if (x > board->width - 1) {
				x = 0;
			}
			break;

		default:
			break;
		}
	}

};