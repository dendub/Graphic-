#include "glew.h"
#include "freeglut.h"

#include "Shader_Loader.h"
#include "Render_Utils.h"

GLuint program; // Shader ID
Core::Shader_Loader shaderLoader;

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	
	// Activating shader
	glUseProgram(program);
	
	// ZADANIE: Create a triangle from 3 vertices (type of const float []) and draw it using Core::DrawVertexArray from Render_Utils.cpp
	// Shader expects 4 coordinates (x, y, z, w).
	static const float vertexArray[] = {
   -0.5f, -0.5f, 0.0f, 0.5f,
   0.5f, -0.5f, 0.0f, 0.5f,
   0.0f,  0.5f, 0.0f, 0.5f
	};
	

	Core::DrawVertexArray(vertexArray, 3, 4);



	// Deactivating shader
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
