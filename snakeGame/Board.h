#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Coord.h"
#include "Display.h"

struct Coord;

class Board {
protected:
	friend class Player;
	friend class Fruit;
	int width;
	int height;
	std::string screen;

public:
	Display* display;
	Board(int w,int h):width(w), height(h) {
		display = new Display(width, height);
	}

	void cleanBoard() {
		display->clear();
	}

	void addToBoard(int x, int y, int color) {
		display->setPixel(x, y, color);
	}

	void addTailToBoard(std::vector<Coord> tail) {
		for (int i = 0; i < tail.size(); i++) {
			display->setPixel(tail[i].x,tail[i].y, 47);
		}
	}

	void print() {
		display->draw();
	}
};
