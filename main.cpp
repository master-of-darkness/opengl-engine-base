
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

int main(void)
{
    int width, height, x;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        double t = glfwGetTime();

        // Get window size (may be different than the requested size)
        glfwGetWindowSize(window, &width, &height);

        // Special case: avoid division by zero below
        height = height > 0 ? height : 1;

        glViewport(0, 0, width, height);

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

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

        // Check if the ESC key was pressed or the window should be closed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE))
            break;

    }

    glfwTerminate();
    return 0;
}