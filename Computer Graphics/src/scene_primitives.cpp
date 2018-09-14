#include "scene_primitives.h"
#include "vec2.h"
#include <vector>

void scene_primitives::init()
{
	std::vector<cgmath::vec2> positions;
	positions.push_back(cgmath::vec2(0.0f, 0.0f));
	positions.push_back(cgmath::vec2(-1.0f, 0.0f));
	positions.push_back(cgmath::vec2(0.0f, -0.4f));
	positions.push_back(cgmath::vec2(1.0f, 0.0f));

	glGenVertexArrays(1, &vao); //Variable donde quiero vaciar 
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * positions.size(),  //mandamos los datos
		positions.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0); 

}

void scene_primitives::awake() //congigurar el frame buffer de color 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(20.0f);
}

void scene_primitives::sleep()
{

}

void scene_primitives::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//dibujar
	glBindVertexArray(vao);
	glDrawArrays(GL_LINES, 0, 4);
	glBindVertexArray(0);

}