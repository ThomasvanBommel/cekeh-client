/*
 * cekeh-client src/window.h
 * Created: 2021-12-29
 * Author : ThomasvanBommel
 * 
 * Modifications:
 */

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <graphics/mesh.h>

class Window {
    public:
        // Constructor: create a new window
        Window(const char* title) {
            _title = title;
        }

        // Initialize GLFW window
        bool init() {
            // Ensure GLFW initialized correctly
            if(!glfwInit()) {
                fprintf(stderr, "Failed to initialize GLFW\n");
                return false;
            }

            // Configure GLFW
            glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // ^
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use newer OpenGL

            // Create a new window
            _window = glfwCreateWindow(1024, 768, _title, NULL, NULL);

            // Ensure window was successfully created
            if(_window == NULL) {
                fprintf(stderr, "Failed to open GLFW window. Ensure your device is OpenGL 3.3 compatable");
                glfwTerminate();
                return false;
            }

            // Make it the current window and allow keyboard input
            glfwMakeContextCurrent(_window);
            glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

            return true;            
        }

        bool shouldClose() {
            return glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || 
                   glfwWindowShouldClose(_window) != 0;
        }

        // Start event loop
        void run() {
            GLuint vertexArray;
            glGenVertexArrays(1, &vertexArray);
            glBindVertexArray(vertexArray);

            GLfloat vertices[] = {
                -1.0f, -1.0f, 0.0f,
                 1.0f, -1.0f, 0.0f,
                 0.0f,  1.0f, 0.0f
            };

            Mesh mesh = Mesh(vertices, 9);

            do {
                // Clear background buffer
                glClear(GL_COLOR_BUFFER_BIT);

                // RENDERING
                mesh.render();
                // END

                // Swap background and foreground buffers
                glfwSwapBuffers(_window);

                // Poll window for events
                glfwPollEvents();

                // Keep looping until escape is pressed or window is closed
            } while(!shouldClose());
        }

    private:
        const char* _title;
        GLFWwindow* _window;
};