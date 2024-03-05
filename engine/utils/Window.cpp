#include "Window.h"
using namespace cppzt::utils;
GLFWwindow* Window::window;

int Window::width = 0;
int Window::height = 0;

int Window::Init(int width, int height, const char* title){
    /* Initialize the library */
    if (!glfwInit()){
        spdlog::error("Failed to initialize GLFW; Terminating!");
        return -1;
    }


    spdlog::info("Running GLFW {}", glfwGetVersionString());

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    return 0;
}

void Window::setCursorMode(int mode){
    glfwSetInputMode(window, GLFW_CURSOR, mode);
}

void Window::terminate(){
    glfwTerminate();
}

bool Window::isShouldClose(){
    return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool flag){
    glfwSetWindowShouldClose(window, flag);
}

void Window::swapBuffers(){
    glfwSwapBuffers(window);
}

void Window::enableVerticalSynchronizing() {
    glfwSwapInterval(1);
}