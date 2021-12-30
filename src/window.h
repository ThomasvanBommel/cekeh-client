/*
 * cekeh-client src/window.h
 * Created: 2021-12-29
 * Author : ThomasvanBommel
 * 
 * Modifications:
 */

#include <stdio.h>
#include <GLFW/glfw3.h>

class Window {
    public:
        Window(const char* title) {
            _title = title;
        }

        bool init() {
            if(!glfwInit()) {
                fprintf(stderr, "Failed to initialize GLFW\n");
                return false;
            }

            glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // ^
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use newer OpenGL

            _window = glfwCreateWindow(1024, 768, _title, NULL, NULL);

            if(_window == NULL) {
                fprintf(stderr, "Failed to open GLFW window. Ensure your device is OpenGL 3.3 compatable");
                glfwTerminate();
                return false;
            }

            glfwMakeContextCurrent(_window);
            glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

            return true;            
        }

        void run() {
            do {
                glClear(GL_COLOR_BUFFER_BIT);

                // draw nothing...

                glfwSwapBuffers(_window);
                glfwPollEvents();
            } while(glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(_window) == 0);
        }

    private:
        const char* _title;
        GLFWwindow* _window;
};