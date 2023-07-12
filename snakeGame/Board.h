#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Display.h"


class Board {
protected:
	friend class Player;
	Display *display;
	int width;
	int height;
	std::string screen;

public:
	Board(int w,int h):width(w), height(h) {
		display = new Display(width, height);
	}

	void cleanBoard() {
		display->clear();
	}

	void addToBoard(int x, int y, int color) {
		display->setPixel(x, y, color);
	}

	void print() {
		display->draw();
	}



};
