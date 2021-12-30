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

#include <GL/glew.h>
#include <window.h>

// #include <glm/glm.hpp>
// using namespace glm;

Window* initialize() {
    // Create window
    Window* window = new Window(APPLICATION_TITLE);

    // Set GLEW to use experimental mode
    glewExperimental = true;

    // Initialize window
    bool successful = window->init();

    // Initialize GLEW
    if(glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        successful = false;
    }

    // Clean up if unsuccessful
    if(!successful){
        delete window;
        return NULL;
    }

    return window;
}

int main() {
    // Log to console
    printf("%s\n", APPLICATION_TITLE);

    // Initialize application
    Window* window = initialize();

    // Ensure successful initialization
    if(window != NULL){
        // Start application
        window->run();

        // Delete window
        delete window;
    }

    // Log to conosle
    printf("exit(0)\n");
    return 0;
}