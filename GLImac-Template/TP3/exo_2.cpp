#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Program.hpp>
#include <glimac/Sphere.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "Sphere avec Lune");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/normal.fs.glsl");
    program.use();

    //Les variables uniformes du Vertex Shader
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    Sphere sphere(1, 32, 16);
    glm::mat4 ProjMatrix;
    glm::mat4 MVMatrix;
    glm::mat4 NormalMatrix;

    GLuint vbo;
    GLuint vao;
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMALE = 1;
    const GLuint VERTEX_ATTR_TEXCOORD = 2;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo); //Binder la VBO

    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao); //Binder la VAO

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMALE);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    glBindBuffer(GL_ARRAY_BUFFER, vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMALE, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, texCoords));
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glBindVertexArray(0); //Debinder la VAO

    glEnable(GL_DEPTH_TEST);
    
    ProjMatrix = glm::perspective(
        glm::radians(70.f),
        800.f/600.f,
        0.1f,
        100.f);
    MVMatrix = glm::translate(
        glm::mat4(),
        glm::vec3(0, 0, -5)
        );
    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    std::vector<glm::vec3> axesRotations;
    for (int i=0; i<32; i++) {
        glm::vec3 r = glm::sphericalRand(2.0f);
        axesRotations.push_back(r);
    }

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(vao); //Binder la VAO

        //Premiere planete
        MVMatrix = glm::translate(
        glm::mat4(),
        glm::vec3(0, 0, -5)
        );

        glUniformMatrix4fv(uMVPMatrix,
        	1,
        	GL_FALSE,
        	glm::value_ptr(ProjMatrix*MVMatrix)
        	);
        glUniformMatrix4fv(uMVMatrix,
        	1,
        	GL_FALSE,
        	glm::value_ptr(MVMatrix)
        	);
        glUniformMatrix4fv(uNormalMatrix,
        	1,
        	GL_FALSE,
        	glm::value_ptr(NormalMatrix)
        	);

       	glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        
        for(int i=0; i<32; i++){
            //Lune
            MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
            MVMatrix = glm::rotate(MVMatrix,
                                 windowManager.getTime(),
                                 axesRotations[i]); 
            MVMatrix = glm::translate(MVMatrix, glm::vec3(-2, 0, 0));
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2, 0.2, 0.2)); 

            glUniformMatrix4fv(uMVPMatrix,
                1,
                GL_FALSE,
                glm::value_ptr(ProjMatrix*MVMatrix)
                );
            glUniformMatrix4fv(uMVMatrix,
                1,
                GL_FALSE,
                glm::value_ptr(MVMatrix)
                );

            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        }

        glBindVertexArray(0); //Debinder la VAO

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
