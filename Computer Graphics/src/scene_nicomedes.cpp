#include "scene_nicomedes.h"
#include "vec2.h"
#include <vector>
#include <math.h>

std::vector<cgmath::vec2> positionsnico;
std::vector<cgmath::vec2> positionsnico2;

void scene_nicomedes::init()
{
	double xmax, ymax, xmin, ymin;
	double a = 1.0f, b = 2.0f;
	double pi = 4.0f * atan(1.0f); //arctan
	double r = 0.05;
	double t;
	double x1, x2, y1, y2;
	//Ejes
	xmax = a - b - 1.0f;
	xmin = a + b + 1.0f;
	ymax = ymin = 0.0f;

	for (t = -pi / 2.0f + r; t < pi / 2.0f; t += r) {

		x1 = a + b * cos(t);
		if (xmax < x1)
		{
			xmax = x1;
		}

		if (xmin > x1)
		{
			xmin = x1;
		}
		x2 = a - b * cos(t);
		if (xmax < x2)
		{
			xmax = x2;
		}
		if (xmin > x2)
		{
			xmin = x2;
		}

		y1 = a * tan(t) + b * sin(t);
		if (ymax < y1)
		{
			ymax = y1;
		}
		if (ymin > y1)
		{
			ymin = y1;
		}
		y2 = a * tan(t) - b * sin(t);
		if (ymax < 2)
		{
			ymax = y2;
		}
		if (ymin > y2)
		{
			ymin = y2;
		}
	}
	if (abs(xmax) > abs(xmin))
	{
		xmax = abs(xmax);
	}
	else
	{
		xmax = abs(xmin);
	}

	if (abs(ymax) > abs(ymin))
	{
		ymax = abs(ymax);
	}
	else
	{
		ymax = abs(ymin);
	}

	for (t = -pi / 2 + r; t < pi / 2; t += r) {
		x1 = (a + b * cos(t)) / xmax;
		x2 = (a - b * cos(t)) / xmax;
		y1 = (a * tan(t) + b * sin(t)) / ymax;
		y2 = (a * tan(t) - b * sin(t)) / ymax;

		positionsnico.push_back(cgmath::vec2(x1 * 0.4f, y1 * 2.5f));
	}
	for (t = -pi / 2 + r; t < pi / 2; t += r) {
		x1 = (a + b * cos(t)) / xmax;
		x2 = (a - b * cos(t)) / xmax;
		y1 = (a * tan(t) + b * sin(t)) / ymax;
		y2 = (a * tan(t) - b * sin(t)) / ymax;

		positionsnico2.push_back(cgmath::vec2(x2 * 0.4f, y2 * 2.5f));
	}

	//Y1 y X2
	glGenVertexArrays(1, &vao); //Variable donde quiero vaciar 
	glBindVertexArray(vao);

	glGenBuffers(1, &positioonsVBO); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positioonsVBO); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * positionsnico.size(),  //mandamos los datos
		positionsnico.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	//Y2 y X2
	glGenVertexArrays(1, &vao1); //Variable donde quiero vaciar 
	glBindVertexArray(vao1);

	glGenBuffers(1, &positioonsVBO1); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positioonsVBO1); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * positionsnico2.size(),  //mandamos los datos
		positionsnico2.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void scene_nicomedes::awake() //congigurar el frame buffer de color 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glPointSize(20.0f);
}

void scene_nicomedes::sleep()
{

}

void scene_nicomedes::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//dibujar

	//Y1 y X1
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_STRIP, 0, positionsnico.size());
	glBindVertexArray(0);

	//Y2 y X2
	glBindVertexArray(vao1);
	glDrawArrays(GL_LINE_STRIP, 0, positionsnico2.size());
	glBindVertexArray(0);
}


//Referencias
//https://github.com/jesusjimsa/Computer-Graphics-UAIC/blob/master/Homework%202/t02p1%20jimenezsanchezjesus%20rodriguezcalvojosemanuel.cpp
