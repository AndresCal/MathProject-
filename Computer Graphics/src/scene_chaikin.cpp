#include "scene_chaikin.h"
#include "vec2.h"
#include <vector>
#include <math.h>
#include <GL/glut.h>




void scene_chaikin::init()
{
	std::vector<cgmath::vec2> positions;

	//Ejes x y y
	positions.push_back(cgmath::vec2(-1.0f, 0.0f));
	positions.push_back(cgmath::vec2(1.0f, 0.0f));
	positions.push_back(cgmath::vec2(0.0f, 1.0f));
	//chaikin(positions);
	positions.push_back(cgmath::vec2(0.0f, -1.0f));

	//Hey Arnold 
	//Cabeza
	
	positions.push_back(cgmath::vec2(-0.5f, 0.8f));
	positions.push_back(cgmath::vec2(-0.5f, 0.8f));
	positions.push_back(cgmath::vec2(0.5f, -0.8f));
	positions.push_back(cgmath::vec2(0.5f, -0.8f));


		
	//chaikin(positions);
	//chaikin(positions);



	
	//Cabello izq 
	positions.push_back(cgmath::vec2(-0.4f, 0.9f));
	positions.push_back(cgmath::vec2(-0.4f, 0.8f));
	positions.push_back(cgmath::vec2(-0.2f, 0.8f));
	positions.push_back(cgmath::vec2(-0.19f, 0.91f));

	//Cabello derecho
	positions.push_back(cgmath::vec2(0.18f, 0.9f));
	positions.push_back(cgmath::vec2(-0.1f, 0.9f));
	positions.push_back(cgmath::vec2(-0.1f, 0.8f));
	positions.push_back(cgmath::vec2(0.1f, 0.8f));
	

	//Gorrita
	positions.push_back(cgmath::vec2(-0.029f, 0.85f));
	positions.push_back(cgmath::vec2(0.029f, 0.85f));
	positions.push_back(cgmath::vec2(0.04f, 0.80f));
	positions.push_back(cgmath::vec2(-0.06f, 0.80f));

	//Cuerpo
	positions.push_back(cgmath::vec2(-0.2f, 0.4f));
	positions.push_back(cgmath::vec2(0.2f, 0.4f));
	positions.push_back(cgmath::vec2(0.2f, -0.6f));
	positions.push_back(cgmath::vec2(-0.2f, -0.6f));

	//Pie izquierdo
	positions.push_back(cgmath::vec2(-0.1f, -0.6f));
	positions.push_back(cgmath::vec2(-0.05f, -0.6f));
	positions.push_back(cgmath::vec2(-0.05f, -0.75f));
	positions.push_back(cgmath::vec2(-0.1f, -0.75f));


	//Pie derecho 
	positions.push_back(cgmath::vec2(0.1f, -0.6f));
	positions.push_back(cgmath::vec2(0.05f, -0.6f));
	positions.push_back(cgmath::vec2(0.05f, -0.75f));
	positions.push_back(cgmath::vec2(0.1f, -0.75f));
	

	glGenVertexArrays(1, &vao); //Variable donde quiero vaciar 
	glBindVertexArray(vao);

	glGenBuffers(2, &positionsVBO); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * positions.size(),  //mandamos los datos
		positions.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void scene_chaikin::awake() //congigurar el frame buffer de color 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(20.0f);
}

void scene_chaikin::sleep()
{

}

void scene_chaikin::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//dibujar
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE, 0, 4);
	glColor3f(0.245f, 0.189f, 0.189f);
	glDrawArrays(GL_LINE_LOOP, 4, 4);
	glColor3f(1.0f, 1.0f, 0.0f); //Cabello
	glDrawArrays(GL_LINE_LOOP, 8, 4);
	glDrawArrays(GL_LINE_LOOP, 12, 4);
	glColor3f(0.0f, 0.0, 1.0); //Gorrita
	glDrawArrays(GL_LINE_LOOP, 16, 4);
	glColor3f(0.0f, 0.174, 0.201f); //Playera
	glDrawArrays(GL_LINE_LOOP, 20, 4);
	glColor3f(1.0f, 0.0, 0.0); //piernas
	glDrawArrays(GL_LINE_LOOP, 24, 4);
	glDrawArrays(GL_LINE_LOOP, 28, 4);
	glDrawArrays(GL_LINE_LOOP, 32, 4);



	glBindVertexArray(0);
}

