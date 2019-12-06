#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Program.hpp>
#include <glimac/Sphere.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glimac/Image.hpp>

using namespace glimac;

struct EarthProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uEarthTexture;
    GLint uCloudTexture;

    EarthProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uEarthTexture = glGetUniformLocation(m_Program.getGLId(), "uEarthTexture");
        uCloudTexture = glGetUniformLocation(m_Program.getGLId(), "uCloudTexture");
    }
};

struct MoonProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;

    MoonProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/tex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};

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
    std::unique_ptr<Image> cloudMap = loadImage(applicationPath.dirPath() + "../../GLImac-Template/assets/textures/CloudMap.jpg");
    
    if(earth == NULL) std::cout << "Earth's image not loaded" << std::endl;
    if(moon == NULL) std::cout << "Moon's image not loaded" << std::endl;
    if(cloudMap == NULL) std::cout << "CloudMap's image not loaded" << std::endl;

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl");
    program.use();

    //Les variables uniformes du Vertex Shader
    EarthProgram earthProgram(applicationPath);
    MoonProgram moonProgram(applicationPath);
    
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    earthProgram.m_Program.use();
    moonProgram.m_Program.use();

    Sphere sphere(1, 32, 16);

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

    glm::mat4 ProjMatrix = glm::perspective(
        glm::radians(70.f),
        800.f/600.f,
        0.1f,
        100.f);

    std::vector<glm::vec3> axesRotations;
    for (int i=0; i<32; i++) {
        glm::vec3 r = glm::sphericalRand(2.0f);
        axesRotations.push_back(r);
    }

    //Textures
    GLuint texturesArray[3];

    glGenTextures(3, texturesArray);
    //Bind texture Earh
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

    //Bind texture Lune
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

    //Bind texture CloudMap
    glBindTexture(GL_TEXTURE_2D, texturesArray[2]);
    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGBA,
        cloudMap->getWidth(),
        cloudMap->getHeight(),
        0,
        GL_RGBA,
        GL_FLOAT,
        cloudMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //Debinder texture
    glBindTexture(GL_TEXTURE_2D, 0);

    /*Name the textures*/
    GLuint earthTexture = texturesArray[0];
    GLuint moonTexture = texturesArray[1];
    GLuint cloudTexture = texturesArray[2];

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
        earthProgram.m_Program.use();

        glUniform1i(earthProgram.uEarthTexture, 0);
        glUniform1i(earthProgram.uCloudTexture, 1);

        glm::mat4 globalMVMatrix = glm::translate(
            glm::mat4(),
            glm::vec3(0, 0, -5)
        );

        glm::mat4 earthMVMatrix = glm::rotate(globalMVMatrix, 
            windowManager.getTime(), 
            glm::vec3(0, 1, 0)
        );

        glm::mat4 earthNormalMatrix = glm::transpose(glm::inverse(earthMVMatrix));

        /*On envoie aux shaders*/
        glUniformMatrix4fv(earthProgram.uMVPMatrix, 
            1, 
            GL_FALSE, 
            glm::value_ptr(ProjMatrix * earthMVMatrix)
        );

        glUniformMatrix4fv(earthProgram.uMVMatrix, 
            1, 
            GL_FALSE, 
            glm::value_ptr(earthMVMatrix)
        );

        glUniformMatrix4fv(earthProgram.uNormalMatrix, 
            1, 
            GL_FALSE, 
            glm::value_ptr(earthNormalMatrix)
        );

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, earthTexture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, cloudTexture);

        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        glBindTexture(GL_TEXTURE_2D, 0);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, moonTexture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 0);

        moonProgram.m_Program.use();
        for(int i=0; i<32; i++){
            //Lune
            glm::mat4 moonMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5*axesRotations[i].x*axesRotations[i].y*axesRotations[i].z));
            moonMVMatrix = glm::rotate(moonMVMatrix,
                                 windowManager.getTime(),
                                 axesRotations[i]); 
            moonMVMatrix = glm::translate(moonMVMatrix, glm::vec3(-2, 0, 0));
            moonMVMatrix = glm::scale(moonMVMatrix, glm::vec3(0.2, 0.2, 0.2)); 

            glUniformMatrix4fv(moonProgram.uMVPMatrix,
                1,
                GL_FALSE,
                glm::value_ptr(ProjMatrix*moonMVMatrix)
                );
            glUniformMatrix4fv(moonProgram.uMVMatrix,
                1,
                GL_FALSE,
                glm::value_ptr(moonMVMatrix)
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
    glDeleteTextures(3, texturesArray);

    return EXIT_SUCCESS;
}
