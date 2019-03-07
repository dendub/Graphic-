#include "glew.h"
#include "freeglut.h"

#include "Shader_Loader.h"
#include "Render_Utils.h"

GLuint program;
Core::Shader_Loader shaderLoader;

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	glUseProgram(program);
	
	// ZADANIE: Create a quad using 4 vertices and 6 indices (type of const int []) and draw it using Core::DrawVertexArray from Render_Utils.cpp
	const float vertices[] = { 
					  -0.5f, -0.5f, 0.0f, 1.0f, // bottom left corner
					  -0.5f,  0.5f, 0.0f, 1.0f,// top left corner
					   0.5f,  0.5f, 0.0f, 1.0f,// top right corner
					   0.5f, -0.5f, 0.0f, 1.0f }; // bottom right corner
	const int index[] = {0,1,2, // first triangle (bottom left - top left - top right)
                     0,2,3}; // second triangle (bottom left - top right - bottom right)

	Core::DrawVertexArrayIndexed(vertices, index, 6, 4);
	glUseProgram(0);
	glutSwapBuffers();
}

void init()
{
	program = shaderLoader.CreateProgram("shaders/shader_1_1.vert", "shaders/shader_1_1.frag");
}

void shutdown()
{
	shaderLoader.DeleteProgram(program);
}

void idle()
{
	glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Pierwszy Program");
	glewInit();

	init();
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	glutMainLoop();

	shutdown();

	return 0;
}
