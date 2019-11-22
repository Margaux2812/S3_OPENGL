#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include <vector>
#include <math.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>

using namespace glimac;

struct Vertex2DUV{
    glm::vec2 position;
    glm::vec2 coordText;

    Vertex2DUV() = default;

    Vertex2DUV(glm::vec2 position, glm::vec2 coordText)
	: position(position), 
		coordText(coordText)
	{
	};
};


glm::mat3 rotate(const float a){
    float theta = a*M_PI/180;
    return glm::mat3(
        glm::vec3(cos(theta), sin(theta), 0),
        glm::vec3(-sin(theta), cos(theta), 0),
        glm::vec3(0, 0, 1)
    );
}

glm::mat3 translate(float tx, float ty){
    return glm::mat3(
        glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0),
        glm::vec3(tx, ty, 1)
    );
}

glm::mat3 scale(float sx, float sy){
    return glm::mat3(
        glm::vec3(sx, 0, 0),
        glm::vec3(0, sy, 0),
        glm::vec3(0, 0, 1)
    );
}

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);

    std::unique_ptr<Image> triforce = loadImage(applicationPath.dirPath() + "../../GLImac-Template/assets/textures/triforce.png");
    
    if(triforce == NULL) std::cout << "Image not loaded" << std::endl;

    Program program = loadProgram(applicationPath.dirPath() + "shaders/triforce.vs.glsl",
                              applicationPath.dirPath() + "shaders/triforce.fs.glsl");
    program.use();

    GLint uModelMatrixLocation = glGetUniformLocation(program.getGLId(), "uModelMatrix");
    GLint uTextureLocation = glGetUniformLocation(program.getGLId(), "uTexture");
    
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    std::cout << "uModelMatrixLocation : " << uModelMatrixLocation << std::endl;
    std::cout << "uTextureLocation : " << uTextureLocation << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    GLuint vbo;
    GLuint vao;
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_COORDINATE = 1;
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    std::vector<Vertex2DUV> vertices;
    vertices.push_back(Vertex2DUV(glm::vec2(0.5f, 0.f), glm::vec2(0.f, 0.f)));
    vertices.push_back(Vertex2DUV(glm::vec2(1.f, 1.f), glm::vec2(0.f, 0.f)));
    vertices.push_back(Vertex2DUV(glm::vec2(0.f, 1.f), glm::vec2(0.f, 0.f)));

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex2DUV), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao); //Binder la VAO

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COORDINATE);

    glBindBuffer(GL_ARRAY_BUFFER, vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), 0);
    glVertexAttribPointer(VERTEX_ATTR_COORDINATE, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), 0);
  
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glBindVertexArray(0); //Debinder la VAO

    //Textures
    GLuint texturesArray[1];

    glGenTextures(1, texturesArray);
    //Bind texture
    glBindTexture(GL_TEXTURE_2D, texturesArray[0]);
    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGBA,
        triforce->getWidth(),
        triforce->getHeight(),
        0,
        GL_RGBA,
        GL_FLOAT,
        triforce->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Debinder texture
    glBindTexture(GL_TEXTURE_2D, 0);

    // Application loop:
    bool done = false;
    glm::mat3 matrixRotated;
    float tours = 0.;

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

        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao); //Binder la VAO
        //binder texture
        glBindTexture(GL_TEXTURE_2D, texturesArray[0]);
        glUniform1i(uTextureLocation, 0);

        //1er triangle
        // translation 
        matrixRotated = rotate(tours);
        matrixRotated *= translate(-0.5, 0.5);
        //Scaling
        matrixRotated *= scale(0.25, 0.25);
        //Tourner
        matrixRotated *= rotate(tours);
        //Appliquer la matrice
        glUniformMatrix3fv(uModelMatrixLocation, 
            1,
            GL_FALSE,
            glm::value_ptr(matrixRotated));
        
        glDrawArrays(GL_TRIANGLES, 0, vertices.size()*3);
        
        //2e triangle
        // translation 
        matrixRotated = rotate(tours);
        matrixRotated *= translate(0.5, 0.5);
        //Scaling
        matrixRotated *= scale(0.25, 0.25);
        //Tourner
        matrixRotated *= rotate(tours);
        glUniformMatrix3fv(uModelMatrixLocation, 
            1,
            GL_FALSE,
            glm::value_ptr(matrixRotated));
        
        glDrawArrays(GL_TRIANGLES, 0, vertices.size()*3);
        
        //3e
        // translation 
        matrixRotated = rotate(tours);
        matrixRotated *= translate(-0.5, -0.5);
        matrixRotated *= scale(0.25, 0.25);
        matrixRotated *= rotate(-tours);
        glUniformMatrix3fv(uModelMatrixLocation, 
            1,
            GL_FALSE,
            glm::value_ptr(matrixRotated));
        
        glDrawArrays(GL_TRIANGLES, 0, vertices.size()*3);
        
        //4e
        // translation 
        matrixRotated = rotate(tours);
        matrixRotated *= translate(0.5, -0.5);
        matrixRotated *= scale(0.25, 0.25);
        matrixRotated *= rotate(-tours);
        glUniformMatrix3fv(uModelMatrixLocation, 
            1,
            GL_FALSE,
            glm::value_ptr(matrixRotated));
        
        glDrawArrays(GL_TRIANGLES, 0, vertices.size()*3);

        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0); //Debinder la VAO


        tours += 0.3;
        
        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteTextures(1, texturesArray);

    return EXIT_SUCCESS;
}
