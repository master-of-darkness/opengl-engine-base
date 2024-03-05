#include "common.h"
#include "Window.h"

using namespace cppzt::utils::common;

static bool key_pressed = true;

void imgui::Init(GLFWwindow *window) {
    if(window == nullptr)
        return;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL3_Init();
}

void imgui::PrepareNewFrame() {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void imgui::Destroy() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void imgui::DebugWindow(){
    ImGui::Begin("Debug Window", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus);
    {
        ImGui::Text("Framerate: %f", ImGui::GetIO().Framerate);
    }
    ImGui::End();
}

bool event::keyboard::IsPressed(int key) {
    bool check = glfwGetKey(utils::Window::window, key);

    if(check == GLFW_PRESS && key_pressed){
        return false;
    }else if(check == GLFW_PRESS){
        key_pressed = true;
        return true;
    }else if(check == GLFW_RELEASE && !key_pressed){
        return false;
    }else if(check == GLFW_RELEASE){
        key_pressed = false;
        return false;
    }
}