#pragma once
#include <random>
#include "Board.h"

class Fruit {
	int x;
	int y;
	int point;
	int color;
public:
	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	int getPoint() {
		return point;
	}

	int getColor() {
		return color;
	}

	Fruit(Board* board) {
		color = 41;
		point = 1;

		std::random_device rd;

		std::mt19937 gen(rd());

		std::uniform_int_distribution<> distx(0, board->width - 1);
		std::uniform_int_distribution<> disty(0, board->height - 1);

		x =  distx(gen);
		y = disty(gen);
	}

	~Fruit() {

	}
};