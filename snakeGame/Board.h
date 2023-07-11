#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>


class Board {
protected:
	friend class Player;
	int width;
	int height;
	std::vector<std::vector<int>> matrix;
	std::string screen;

public:
	Board(int w,int h):width(w), height(h) {
		matrix.resize(height, std::vector<int>(width));
	}

	void cleanMatrix() {
		matrix.assign(height, std::vector<int>(width));
	}

	void addToMatrix(int x, int y, int data) {
		matrix[y][x] = data;
	}

	void print() {
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;

		cursorPos.X = 0;
		cursorPos.Y = 0;
		SetConsoleCursorPosition(hConsole, cursorPos);


		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (matrix[y][x] != 0) {
					screen += matrix[y][x];
				}
				else {
					screen += " ";
				}
			}
			screen += "\n";
		}

		std::cout << screen;
		screen.clear();
	}



};
