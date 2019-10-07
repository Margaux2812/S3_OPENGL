#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <cstddef>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>

const float rayon = 0.5f;
const unsigned int nbTriangles = 100;
const double pi = std::acos(-1);

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
    SDLWindowManager windowManager(800, 800, "TP1 exo 7 Disque avec IBO");

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

    glm::vec2 sommet1 = glm::vec2(0.f, rayon);
    glm::vec2 sommet2;
    float teta = 2.f*pi/nbTriangles;
    std::vector<Vertex2DColor> vertices;

    //On met le premier sommet au coordonnées de départ
    //On calcule les triangles

    //On met déj le premier sommet et le centre du cercle dans vertices

    vertices.push_back(Vertex2DColor(glm::vec2(0.f, 0.f), glm::vec3(0.f, 0.f, 1.f)));//centre en bleu
    vertices.push_back(Vertex2DColor(sommet1, glm::vec3(0.f, 1.f, 0.f)));//Premier sommet en vert

    for(int i = 0; i < nbTriangles; i++){
        sommet2.x = glm::cos(teta)*sommet1.x + glm::sin(teta)*sommet1.y;
        sommet2.y = glm::cos(teta)*sommet1.y - glm::sin(teta)*sommet1.x;

        vertices.push_back(Vertex2DColor(sommet2, glm::vec3(0.f, 1.f, 0.f)));//deuxieme sommet en vert

        sommet1 = sommet2;
    }

    //On a nbTriangles de points + le centre et le premier point
    glBufferData(GL_ARRAY_BUFFER, (nbTriangles+2) * sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    GLuint ibo;
    glGenBuffers(1, &ibo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    std::vector<unsigned int> indices;

    for(int i=1; i < nbTriangles+1; i++){
    	indices.push_back(0); //Le centre
    	indices.push_back(i);//Deuxieme sommet
    	indices.push_back(i+1);//Troisieme sommet
    }

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nbTriangles*3*sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao); //Binder la VAO

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

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

        glDrawElements(GL_TRIANGLES, nbTriangles*3, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0); //Debinder la VAO

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}
