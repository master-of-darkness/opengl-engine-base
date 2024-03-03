#include "pch/pch.h"

#include "utils/Window.h"
#include "utils/common.h"
#include "utils/Shader.h"
#include "basics/camera/Camera.h"

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
    Window::Init(640, 480, "Hello World!");
    utils::common::imgui::Init(Window::window);
    Shader base("../basics/shader/basicShader.vert", "../basics/shader/basicShader.frag");

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    Camera* camera = new Camera(glm::vec3(0,0,1), glm::radians(90.0f));
    glm::mat4 model(1.0f);
    model = translate(model, glm::vec3(0.5f,0,0));

    bool draw_window = false;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(Window::window))
    {
        glfwPollEvents();

        glfwGetWindowSize(Window::window, &Window::width, &Window::height);
        if(ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Insert)))
            draw_window = !draw_window;

        utils::common::imgui::PrepareNewFrame();
        if(draw_window)
            ImGui::ShowDemoWindow();
        // Rendering
        ImGui::Render();

        glClear(GL_COLOR_BUFFER_BIT);


        base.use();
        base.uniformMatrix("model", model);
        base.uniformMatrix("projview", camera->getProjection()*camera->getView());


        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(Window::window);

        // Check if the ESC key was pressed or the window should be closed
        if (glfwGetKey(Window::window, GLFW_KEY_ESCAPE))
            break;

    }

    // Cleanup
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    utils::common::imgui::Destroy();
    glfwDestroyWindow(Window::window);

    glfwTerminate();
    return 0;
}