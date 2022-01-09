/*
 * cekeh-client src/graphics/shader.hpp
 * Created: 2021-12-30
 * Author : ThomasvanBommel
 * 
 * Modifications:
 * 2022-01-09: Added header guard
 */

#ifndef SHADER_H
#define SHADER_H

#include <util/loader.hpp>
#include <string>
#include <stdio.h>
#include <vector>

class Shader {
    public:
        Shader(const char* vertPath, const char* fragPath) {
            _vertPath = vertPath;
            _fragPath = fragPath;
        }

        bool init() {
            // Initialize
            _vertShader = glCreateShader(GL_VERTEX_SHADER);
            _fragShader = glCreateShader(GL_FRAGMENT_SHADER);

            // Load and compile
            if(!load(&_vertShader, _vertPath) || !load(&_fragShader, _fragPath)) {
                cleanUp();
                return false;
            }

            // Attach shaders and link program
            _program = glCreateProgram();
            glAttachShader(_program, _vertShader);
            glAttachShader(_program, _fragShader);
            glLinkProgram(_program);

            int length;
            glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &length);

            // Check and log program errors
            if(length > 0) {
                vector<char> err (length + 1);
                
                glGetProgramInfoLog(_program, length, NULL, &err[0]);
                printf("Program [%d] error: %s\n", _program, &err[0]);

                cleanUp();
                return false;
            }

            // Clean up
            glDetachShader(_program, _vertShader);
            glDetachShader(_program, _fragShader);
            glDeleteShader(_vertShader);
            glDeleteShader(_fragShader);

            return true;
        }

        void use() {
            glUseProgram(_program);
        }

        void cleanUp() {
            glDeleteShader(_vertShader);
            glDeleteShader(_fragShader);
            glDeleteProgram(_program);
        }

    private:
        const char* _vertPath;
        const char* _fragPath;

        GLuint _vertShader;
        GLuint _fragShader;
        GLuint _program;

        bool load(GLuint* shader, const char* path) {
            // Load code from file
            std::string code = LoadFile(path);

            // Ensure code loaded
            if(code.empty()){
                printf("Shader [%d] file couldn't load or is empty [%s]\n", *shader, path);
                return false;
            }

            const char* src = code.c_str();
            int length;

            // Compilation
            glShaderSource(*shader, 1, &src, NULL);
            glCompileShader(*shader);
            glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &length);

            // Check and log shader errors
            if(length > 0) {
                vector<char> err (length + 1);

                glGetShaderInfoLog(*shader, length, NULL, &err[0]);
                printf("Shader [%d] error [%s]: %s\n", *shader, path, &err[0]);

                return false;
            }

            return true;
        }
};

#endif
