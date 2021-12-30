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

int main() {
    printf("%s\n", APPLICATION_TITLE);

    Window window = Window(APPLICATION_TITLE);
    
    if(!window.init())
        return 1;

    glewExperimental = true;

    if(glewInit() != GLEW_OK){
        fprintf(stderr, "Failed to initialize GLEW\n");
        return 1;
    }

    window.run();

    return 0;
}