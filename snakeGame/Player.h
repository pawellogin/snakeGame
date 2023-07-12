#pragma once
#include <Windows.h>

class Board;

class Player {
	bool containsValues( int targetX, int targetY) {
		for (const Coord& coord : tail) {
			if (coord.x == targetX && coord.y == targetY) {
				return true;
			}
		}
		return false;
	}

	std::vector<Coord> tail;
	Board* board;
	int direction;
	int startLenght;
	int x;
	int y;
public:

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	std::vector<Coord> getTail() {
		return tail;
	}

	Player(Board *b){
		board = b;
		x = 0;
		y = 0;
		startLenght = 3;
		direction = 3;

		for (int i = 0; i < startLenght; i++) {
			tail.push_back(*new Coord);
		}
	}

	void move() {
		for (int i = tail.size() - 1; i > 0; i--) {
			tail[i].x = tail[i - 1].x;
			tail[i].y = tail[i - 1].y;
		}

		tail[0].x = x;
		tail[0].y = y;
 
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

		if (isDownArrowPressed && direction !=0) {
			direction = 1;
		}

		if (isUpArrowPressed && direction !=1) {
			direction = 0;
		}

		if (isLeftArrowPressed && direction !=3) {
			direction = 2;
		}

		if (isRightArrowPressed && direction != 2) {
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

		if (containsValues(x, y)) {
			exit(2);
		}
	}

	void growTail() {
		tail.push_back(*new Coord(this->x,this->y));
	}
};