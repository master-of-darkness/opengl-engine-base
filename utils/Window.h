#pragma once
#include "../pch/pch.h"


class Window {
public:
    static int width;
    static int height;
    static GLFWwindow* window;
    static int Init(int width, int height, const char* title);
    static void terminate();

    static void setCursorMode(int mode);
    static bool isShouldClose();
    static void setShouldClose(bool flag);
    static void swapBuffers();
    static void enableVerticalSynchronizing();
};


