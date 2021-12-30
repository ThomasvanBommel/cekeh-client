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
    
    // Initialize window
    if(!window->init())
        return NULL;

    // Set GLEW to use experimental mode
    glewExperimental = true;

    // Initialize GLEW
    if(glewInit() != GLEW_OK){
        fprintf(stderr, "Failed to initialize GLEW\n");
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