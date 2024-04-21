#include <vector>
#include <thread>
#include <random>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "Cone.h"
#include "Cylinder.h"
#include "Plane.h"
#include "TriangularPrism.h"
#include "Shader.hpp"

using namespace glm;
using namespace std;

const char *getError();
inline void startUpGLFW();
inline void startUpGLEW();
inline GLFWwindow *setUp();

int main()
{
    GLFWwindow *window;

    try
    {
        window = setUp();
    }
    catch (const char *e)
    {
        cout << e << endl;
        throw;
    }

    glClearColor(0.2, 0.2, 0.2, 0.2);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint programID = LoadShaders("VertexShader.glsl", "FragmentShader.glsl");

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    GLuint colorBuffer;
    glGenBuffers(1, &colorBuffer);

    bool on = false;
    double power = 0.02;
    bool wireframe = false;

    Shape *shp = new Plane();

    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);

        GLfloat *vertices = shp->toVertexLineArray();
        GLfloat *colors = shp->toColourLineArray();

        if (!wireframe)
        {
            GLfloat *vertices = shp->toVertexArray();
            GLfloat *colors = shp->toColourArray();

            glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[shp->numVertices()]), vertices, GL_STATIC_DRAW);

            glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[shp->numColours()]), colors, GL_STATIC_DRAW);
        }
        else
        {
            GLfloat *vertices = shp->toVertexLineArray();
            GLfloat *colors = shp->toColourLineArray();

            glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[shp->numVertices() * 2]), vertices, GL_STATIC_DRAW);

            glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[shp->numVertices() * 3]), colors, GL_STATIC_DRAW);
        }

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

        if (!wireframe)
        {
            glDrawArrays(GL_TRIANGLES, 0, shp->numPoints());
        }
        else
        {
            glDrawArrays(GL_LINES, 0, shp->numVertices() * 2);
        }

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (on)
        {
            shp->shapes[12]->rotate(power);
        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            double a = cos(0.02);
            double b = sin(0.02);

            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, 0},
                    new double[4]{0, a, -b, 0},
                    new double[4]{0, b, a, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix rotationX(4, 4, array);
            shp->applyMatrix(rotationX);
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            double a = cos(-0.02);
            double b = sin(-0.02);

            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, 0},
                    new double[4]{0, a, -b, 0},
                    new double[4]{0, b, a, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix rotationX(4, 4, array);
            shp->applyMatrix(rotationX);
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            double a = cos(0.02);
            double b = sin(0.02);

            double **array = new double *[4]
            {
                new double[4]{a, 0, b, 0},
                    new double[4]{0, 1, 0, 0},
                    new double[4]{-b, 0, a, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix rotationY(4, 4, array);
            shp->applyMatrix(rotationY);
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            double a = cos(-0.02);
            double b = sin(-0.02);

            double **array = new double *[4]
            {
                new double[4]{a, 0, b, 0},
                    new double[4]{0, 1, 0, 0},
                    new double[4]{-b, 0, a, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix rotationY(4, 4, array);
            shp->applyMatrix(rotationY);
        }

        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {
            double a = cos(0.02);
            double b = sin(0.02);

            double **array = new double *[4]
            {
                new double[4]{a, -b, 0, 0},
                    new double[4]{b, a, 0, 0},
                    new double[4]{0, 0, 1, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix rotationZ(4, 4, array);
            shp->applyMatrix(rotationZ);
        }

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            double a = cos(-0.02);
            double b = sin(-0.02);

            double **array = new double *[4]
            {
                new double[4]{a, -b, 0, 0},
                    new double[4]{b, a, 0, 0},
                    new double[4]{0, 0, 1, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix rotationZ(4, 4, array);
            shp->applyMatrix(rotationZ);
        }

        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
        {
            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, 0},
                    new double[4]{0, 1, 0, 0.02},
                    new double[4]{0, 0, 1, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix translation(4, 4, array);
            shp->applyMatrix(translation);
        }

        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        {
            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, 0},
                    new double[4]{0, 1, 0, -0.02},
                    new double[4]{0, 0, 1, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix translation(4, 4, array);
            shp->applyMatrix(translation);
        }

        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        {
            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, 0.02},
                    new double[4]{0, 1, 0, 0},
                    new double[4]{0, 0, 1, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix translation(4, 4, array);
            shp->applyMatrix(translation);
        }

        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        {
            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, -0.02},
                    new double[4]{0, 1, 0, 0},
                    new double[4]{0, 0, 1, 0},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix translation(4, 4, array);
            shp->applyMatrix(translation);
        }

        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        {
            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, 0},
                    new double[4]{0, 1, 0, 0},
                    new double[4]{0, 0, 1, 0.02},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix translation(4, 4, array);
            shp->applyMatrix(translation);
        }

        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
        {
            double **array = new double *[4]
            {
                new double[4]{1, 0, 0, 0},
                    new double[4]{0, 1, 0, 0},
                    new double[4]{0, 0, 1, -0.02},
                    new double[4] { 0, 0, 0, 1 }
            };

            Matrix translation(4, 4, array);
            shp->applyMatrix(translation);
        }

        if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
        {
            wireframe = !wireframe;
            // std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        {
            on = !on;
        }

        if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
        {
            power += 0.01;
        }

        if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
        {
            power -= 0.01;
        }

        delete[] vertices;
        delete[] colors;

    } while (glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    delete shp;
}

const char *getError()
{
    const char *errorDescription;
    glfwGetError(&errorDescription);
    return errorDescription;
}

inline void startUpGLFW()
{
    glewExperimental = true;
    if (!glfwInit())
    {
        throw getError();
    }
}

inline void startUpGLEW()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw getError();
    }
}

inline GLFWwindow *setUp()
{
    startUpGLFW();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;
    window = glfwCreateWindow(1000, 1000, "u21525600", NULL, NULL);

    if (window == NULL)
    {
        cout << getError() << endl;
        glfwTerminate();
        throw "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
    }

    glfwMakeContextCurrent(window);
    startUpGLEW();

    return window;
}