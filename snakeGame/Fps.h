#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <string>
#include <thread>

class Fps {
    int frameCount;
    double fps;
    int delay = 0;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

    void SetConsoleWindowTitle(const std::string& title) {
        int len = MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, NULL, 0);
        wchar_t* wideStr = new wchar_t[len];
        MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, wideStr, len);
        SetConsoleTitle(wideStr);
        delete[] wideStr;
    }

public:
    Fps() {
        fps = 0;
        delay = 0;
        frameCount = 0;
        startTime = std::chrono::high_resolution_clock::now();
    }

    void counter() {
        frameCount++;
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

        if (deltaTime >= 1000) {
            fps = static_cast<double>(frameCount) / deltaTime * 1000;
            std::string title = "FPS: " + std::to_string(fps);
            SetConsoleWindowTitle(title);

            frameCount = 0;
            startTime = currentTime;
        }
    }
};

