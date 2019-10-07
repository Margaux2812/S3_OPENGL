#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>

using namespace glimac;

struct Vertex2DColor{
	glm::vec2 position;
	glm::vec3 color;

	Vertex2DColor(){
		this->position.x = 0;
		this->position.y = 0;
		this->color.r = 0;
		this->color.g = 0;
		this->color.b = 0;
	}

	Vertex2DColor(glm::vec2 position, glm::vec3 color)
	: position(position), 
		color(color)
	{
	}
};

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "TP1 exo 3 Structure Vertex");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
                              applicationPath.dirPath() + "shaders/triangle.fs.glsl");
    program.use();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    GLuint vbo;
    GLuint vao;
    const GLuint VERTEX_ATTR_POSITION = 3;
    const GLuint VERTEX_ATTR_COULEUR = 8;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo); //Binder la VBO

    Vertex2DColor vertices[] = { 
    	Vertex2DColor(glm::vec2(-0.5f, -0.5f), glm::vec3(1.f, 0.f, 0.f)), //Premier sommet rouge
        Vertex2DColor(glm::vec2(0.5f, -0.5f), glm::vec3(0.f, 1.f, 0.f)), //Deuxieme sommet vert
        Vertex2DColor(glm::vec2(0.0f, 0.5f), glm::vec3(0.f, 0.f, 1.f)) //Troisieme sommet bleu
    };

    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao); //Binder la VAO

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COULEUR);

    glBindBuffer(GL_ARRAY_BUFFER, vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), 0);
    glVertexAttribPointer(VERTEX_ATTR_COULEUR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*)(2*sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glBindVertexArray(0); //Debinder la VAO


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

        glClear(GL_COLOR_BUFFER_BIT);


        glBindVertexArray(vao); //Binder la VAO

        glDrawArrays(GL_TRIANGLES, 0, 3);


        glBindVertexArray(0); //Debinder la VAO

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}
