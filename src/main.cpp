/*
 * cekeh-client src/main.cpp
 * Created: 2021-12-28
 * Author : ThomasvanBommel
 * 
 * Modifications:
 * 2021-12-29 - Added GLFW window
 */

#include <config.h>
#include <stdio.h>

#include <GLFW/glfw3.h>

// #include <GL/glew.h>
// #include <glm/glm.hpp>
// using namespace glm;

int main() {
    char title [50];
    sprintf(title, "cekeh-client v%d.%d", CONFIG_VERSION_MAJOR, CONFIG_VERSION_MINOR);

    printf("%s\n", title);

    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return 1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // ^
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use newer OpenGL

    GLFWwindow* window = glfwCreateWindow(1024, 768, title, NULL, NULL);

    if(window == NULL) {
        fprintf(stderr, "Failed to open GLFW window. Ensure your device is OpenGL 3.3 compatable");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        glClear(GL_COLOR_BUFFER_BIT);

        // draw nothing...

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    return 0;
}