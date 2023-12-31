#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <string>

class Display {
private:
public:
    std::vector<std::vector<int>> buffer;
    std::string screen;
    int width;
    int height;

public:
    Display(int width, int height)
        : width(width), height(height) {
        buffer.resize(height, std::vector<int>(width * 2, 0));
        InitializeConsole();
    }

    ~Display() {
        ResetConsole();
    }

    void clear() {
        buffer.assign(height, std::vector<int>(width * 2, 0));
    }

    void setPixel(int x, int y, int color) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            int startX = x * 2;
            int startY = y;

            for (int i = startY; i < startY + 1; i++) {
                for (int j = startX; j < startX + 2; j++) {
                    buffer[i][j] = color;
                }
            }
        }
    }

    void draw() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD cursorPos;

        cursorPos.X = 0;
        cursorPos.Y = 0;
        SetConsoleCursorPosition(hConsole, cursorPos);

        screen.clear();

        for (int y = 0; y < height; y++) {
            if (y == 0) {
                for (int k = 0; k < width+2; k++) {
                    screen += "\033[44m";
                    screen += "  ";
                }
                screen += "\n";
                screen += "\033[44m";
                screen += "  ";
            }
            else {
                screen += "\033[44m";
                screen += "  ";
            }

            for (int x = 0; x < width * 2; x++) {
                    int color = buffer[y][x];
                    screen += "\033[" + std::to_string(color) + "m";
                    screen += " ";
            }
            
            screen += "\033[44m";
            screen += "  ";
            screen += "\n";

            if (y == height - 1) {
                for (int k = 0; k < width + 2; k++) {
                    screen += "\033[44m";
                    screen += "  ";
                }
                screen += "\n";
            }
        }
        std::cout << screen;
    }

private:
    void InitializeConsole() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD consoleMode;
        GetConsoleMode(hConsole, &consoleMode);
        SetConsoleMode(hConsole, consoleMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }

    void ResetConsole() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD consoleMode;
        GetConsoleMode(hConsole, &consoleMode);
        SetConsoleMode(hConsole, consoleMode & ~ENABLE_VIRTUAL_TERMINAL_PROCESSING);

        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = TRUE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }
};
