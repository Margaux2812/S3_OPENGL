#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Program.hpp>
#include <glimac/Sphere.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glimac/Image.hpp>

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

    std::unique_ptr<Image> earth = loadImage(applicationPath.dirPath() + "../../GLImac-Template/assets/textures/EarthMap.jpg");
    std::unique_ptr<Image> moon = loadImage(applicationPath.dirPath() + "../../GLImac-Template/assets/textures/MoonMap.jpg");
    
    if(earth == NULL) std::cout << "Earth's image not loaded" << std::endl;
    if(moon == NULL) std::cout << "Moon's image not loaded" << std::endl;

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/tex3D.fs.glsl");
    program.use();

    //Les variables uniformes du Vertex Shader
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uTextureLocation = glGetUniformLocation(program.getGLId(), "uTexture");
    
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    std::cout << "uTextureLocation : " << uTextureLocation << std::endl;

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

    //Textures
    GLuint texturesArray[2];

    glGenTextures(2, texturesArray);
    //Bind texture 1
    glBindTexture(GL_TEXTURE_2D, texturesArray[0]);
    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGBA,
        earth->getWidth(),
        earth->getHeight(),
        0,
        GL_RGBA,
        GL_FLOAT,
        earth->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //Debinder texture
    glBindTexture(GL_TEXTURE_2D, 0);

    //Bind texture 2
    glBindTexture(GL_TEXTURE_2D, texturesArray[1]);
    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGBA,
        moon->getWidth(),
        moon->getHeight(),
        0,
        GL_RGBA,
        GL_FLOAT,
        moon->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //Debinder texture
    glBindTexture(GL_TEXTURE_2D, 0);

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
        //binder texture
        glBindTexture(GL_TEXTURE_2D, texturesArray[0]);
        glUniform1i(uTextureLocation, 0);

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

        glUniform1i(uTextureLocation, 0);
        glBindTexture(GL_TEXTURE_2D, texturesArray[0]);

       	glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        glBindTexture(GL_TEXTURE_2D, 0);
        
        glBindTexture(GL_TEXTURE_2D, texturesArray[1]);

        for(int i=0; i<32; i++){
            //Lune
            MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5*axesRotations[i].x*axesRotations[i].y*axesRotations[i].z));
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

        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0); //Debinder la VAO

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteTextures(2, texturesArray);

    return EXIT_SUCCESS;
}
