/*
 * cekeh-client src/util/loader.hpp
 * Created: 2021-12-30
 * Author : ThomasvanBommel
 * 
 * Modifications:
 * 2022-01-09: Added header guard
 */

#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string LoadFile(const char* path) {
    string contents;
    ifstream fileStream (path, ios::in);

    if(fileStream.is_open()) {
        stringstream stream;
        stream << fileStream.rdbuf();
        contents = stream.str();
        fileStream.close();
    }else{
        printf("Unable to open file stream [%s]\n", path);
        return "";
    }

    return contents;
}

string ImportFile(const char* path) {
    string contents;
    ifstream fileStream (path, ios::in);

    if(fileStream.is_open()) {
        stringstream stream;
        stream << fileStream.rdbuf();
        contents = stream.str();
        fileStream.close();
    }else{
        printf("Unable to open file stream [%s]\n", path);
        return "";
    }

    return contents;
}

bool CompileShader(GLuint shader, string code) {
    const char* source = code.c_str();
    GLint result = GL_FALSE;
    int logLength;

    // Compilation
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    // Check
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

    // Log error
    if(logLength > 0) {
        vector<char> error (logLength + 1);
        glGetShaderInfoLog(shader, logLength, NULL, &error[0]);
        printf("Shader Error: %s\n", &error[0]);
        return false;
    }

    return true;
}

GLuint LoadShader(const char* vertexPath, const char* fragmentPath) {
    // Initialize shaders
    GLuint vertexShader   = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Import vertex shader code from file
    string vertexCode = ImportFile(vertexPath);

    if(vertexCode.empty()) {
        printf("Could not load contents of vertex shader file [%s]\n", vertexPath);
        return 0;
    }

    // Import fragment shader code from file
    string fragmentCode = ImportFile(fragmentPath);

    if(fragmentCode.empty()) {
        printf("Could not load contents of fragment shader file [%s]\n", fragmentPath);
        return 0;
    }

    // Compile vertex shader
    if(!CompileShader(vertexShader, vertexCode)) {
        printf("Shader did not compile [%s]\n", vertexPath);
        return 0;
    }

    // Compile fragment shader
    if(!CompileShader(fragmentShader, fragmentCode)) {
        printf("Shader did not compile [%s]\n", fragmentPath);
        return 0;
    }

    // Link program
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // Check program
    GLint result = GL_FALSE;
    int logLength;

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

    if(logLength > 0){
        vector<char> error (logLength + 1);
        glGetProgramInfoLog(program, logLength, NULL, &error[0]);
        printf("Program Error: %s\n", &error[0]);
    }

    // Detach + delete shaders
    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

#endif
