/*
 * cekeh-client src/graphics/mesh.h
 * Created: 2021-12-30
 * Author : ThomasvanBommel
 * 
 * Modifications:
 */

class Mesh {
    public:
        Mesh(GLfloat* vertices, int size, GLuint shader) {
            _vertices = vertices;
            _vertexCount = size / 3;
            _shader = shader;

            glGenBuffers(1, &_buffer);
            glBindBuffer(GL_ARRAY_BUFFER, _buffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * size, vertices, GL_STATIC_DRAW);
        }

        void render() {
            glUseProgram(_shader);

            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, _buffer);
            glVertexAttribPointer(0, _vertexCount, GL_FLOAT, GL_FALSE, 0, (void*) 0);
            glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
            glDisableVertexAttribArray(0);
        }

    private:
        GLuint _shader;
        GLuint _buffer;
        int _vertexCount;
        GLfloat* _vertices;
};