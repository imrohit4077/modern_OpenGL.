#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawTriangle()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);    // Vertex 1 (bottom left)
    glVertex2f(0.5f, 0.0f);    // Vertex 2 (bottom right)
    glVertex2f(0.0f, 0.5f);    // Vertex 3 (top left)
    glEnd();
}

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the first triangle
    glColor3f(1.0f, 0.0f, 0.0f);    // Set color to red
    glLoadIdentity();
    glTranslatef(-0.5f, -0.5f, 0.0f);    // Translate to the bottom left corner
    drawTriangle();

    // Draw the second triangle
    glColor3f(0.0f, 1.0f, 0.0f);    // Set color to green
    glLoadIdentity();
    glTranslatef(0.5f, 0.5f, 0.0f);    // Translate to the top right corner
    drawTriangle();

    glFlush();
}

int main()
{
    // Initialize GLFW and create a window
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "2D Shapes", NULL, NULL);
    if (!window)
    {
        // Window creation failed, handle the error
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        // GLEW initialization failed, handle the error
        glfwTerminate();
        return -1;
    }

    // Set viewport
    glViewport(0, 0, 800, 600);

    // Set clear color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Main rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // Call the rendering function
        renderScene();

        // Swap buffers
        glfwSwapBuffers(window);

        // Process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwTerminate();
    return 0;
}
