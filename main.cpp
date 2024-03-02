#include "basics/camera.h"
#include "utils/Window.h"
#include "utils/common.h"

float vertices[] = {
        // x    y     z     u     v
        -1.0f,-1.0f, 0.0f, 0.0f, 0.0f,
        1.0f,-1.0f, 0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,

        1.0f,-1.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
};

int main(void)
{
    int width, height, x;

    Window::initialize(640, 480, "Hello World!");
    utils::common::imgui::InitImGui(Window::window);


    bool draw_window = false;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(Window::window))
    {
        double t = glfwGetTime();

        // Get window size (may be different than the requested size)
        glfwGetWindowSize(Window::window, &width, &height);

        // Special case: avoid division by zero below
        height = height > 0 ? height : 1;

        glViewport(0, 0, width, height);

        if(ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Insert)))
            draw_window = !draw_window;

        utils::common::imgui::PrepareNewFrame();

        if(draw_window)
            ImGui::ShowDemoWindow();

        // Rendering
        ImGui::Render();

        // Clear color buffer to black
        glClearColor(0.f, 0.f, 0.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);


        // Select and setup the projection matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(65.f, (GLfloat) width / (GLfloat) height, 1.f, 100.f);

        // Select and setup the modelview matrix
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        gluLookAt(0.f, 1.f, 0.f,    // Eye-position
                  0.f, 20.f, 0.f,   // View-point
                  0.f, 0.f, 1.f);   // Up-vector

        // Draw a rotating colorful triangle
        glTranslatef(0.f, 14.f, 0.f);
        glRotatef(0.3f * (GLfloat) x + (GLfloat) t * 100.f, 0.f, 0.f, 1.f);

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-5.f, 0.f, -4.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(5.f, 0.f, -4.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.f, 6.f);
        glEnd();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(Window::window);
        glfwPollEvents();

        // Check if the ESC key was pressed or the window should be closed
        if (glfwGetKey(Window::window, GLFW_KEY_ESCAPE))
            break;

    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(Window::window);

    glfwTerminate();
    return 0;
}