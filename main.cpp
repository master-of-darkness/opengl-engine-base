#include "engine/pch/pch.h"

#include "engine/utils/Window.h"
#include "engine/utils/common.h"
#include "engine/utils/Shader.h"
#include "engine/basics/camera/Camera.h"

using namespace cppzt;
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
    if(utils::Window::Init(640, 480, "Hello World!") != 0){
        glfwTerminate();
    }
    utils::common::imgui::Init(utils::Window::window);
    utils::Shader base("../engine/basics/shader/basicShader.vert", "../engine/basics/shader/basicShader.frag");
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
    basics::Camera* camera = new basics::Camera(glm::vec3(0,0,1), glm::radians(90.0f));
    glm::mat4 model(1.0f);
    model = translate(model, glm::vec3(0.5f,0,0));

    bool draw_window = false;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(utils::Window::window))
    {

        glfwPollEvents();

        glfwGetWindowSize(utils::Window::window, &utils::Window::width, &utils::Window::height);
        if(utils::common::event::keyboard::IsPressed(GLFW_KEY_INSERT))
            draw_window = !draw_window;

        utils::common::imgui::PrepareNewFrame();
        utils::common::imgui::DebugWindow(draw_window);

        glClear(GL_COLOR_BUFFER_BIT);

        base.use();
        base.uniformMatrix("model", model);
        base.uniformMatrix("projview", camera->getProjection()*camera->getView());

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(utils::Window::window);

        // Check if the ESC key was pressed or the window should be closed
        if (glfwGetKey(utils::Window::window, GLFW_KEY_ESCAPE))
            break;

    }

    // Cleanup
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    utils::common::imgui::Destroy();
    glfwDestroyWindow(utils::Window::window);

    glfwTerminate();
    return 0;
}