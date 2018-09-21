#include "scene_chaikin2.h"
#include "vec2.h"
#include <vector>
#include <math.h>
#include <GL/glut.h>



std::vector<cgmath::vec2> positionss;

void scene_chaikin2::init()

{
	//Family Guy St
	positionss.push_back(cgmath::vec2(0.5681f, 0.5198f)); //Izquierda
	positionss.push_back(cgmath::vec2(0.4599f, 0.722f));
	positionss.push_back(cgmath::vec2(0.3203f, 0.8513f));

	positionss.push_back(cgmath::vec2(0.1155f, 0.9193f)); //Oreja Izquierda 
	positionss.push_back(cgmath::vec2(-0.0699f, 0.9167f));
	positionss.push_back(cgmath::vec2(-0.2170f, 0.8498f));
	positionss.push_back(cgmath::vec2(-0.3231f, 0.7442f));
	positionss.push_back(cgmath::vec2(-0.4004f, 0.6321f)); //abajo


	positionss.push_back(cgmath::vec2(-0.4680f, 0.4782f));
	positionss.push_back(cgmath::vec2(-0.5090f, 0.4944f));
	positionss.push_back(cgmath::vec2(-0.5500f, 0.4207f));
	positionss.push_back(cgmath::vec2(-0.5236f, 0.3532f)); //Izquierda
	positionss.push_back(cgmath::vec2(-0.4730f, 0.3530f));

	positionss.push_back(cgmath::vec2(-0.3889f, 0.1537f)); //Oreja Izquierda 
	positionss.push_back(cgmath::vec2(-0.2734f, 0.02175f));
	positionss.push_back(cgmath::vec2(-0.1699f, -0.0331f));
	positionss.push_back(cgmath::vec2(-0.2111f, -0.2192f));
	positionss.push_back(cgmath::vec2(-0.2233f, -0.4182f)); //abajo


	positionss.push_back(cgmath::vec2(-0.2258f, -0.4952f));
	positionss.push_back(cgmath::vec2(-0.2042f, -0.5370f));
	positionss.push_back(cgmath::vec2(-0.1994f, -0.5242f));
	positionss.push_back(cgmath::vec2(-0.1873f, -0.5435f)); //Oreja Derecha
	positionss.push_back(cgmath::vec2(-0.1656f, -0.7683f));
	positionss.push_back(cgmath::vec2(-0.2432f, -0.8900f));
	positionss.push_back(cgmath::vec2(-0.1372f, -0.9160f));
	positionss.push_back(cgmath::vec2(-0.0456f, -0.8906f)); //Derecha
	positionss.push_back(cgmath::vec2(0.0579f, -0.9199f));
	positionss.push_back(cgmath::vec2(0.2050f, -0.8112f));
	positionss.push_back(cgmath::vec2(0.2053f, -0.5769f));

	positionss.push_back(cgmath::vec2(0.2222f, -0.5673f));
	positionss.push_back(cgmath::vec2(0.2342f, -0.5769f));
	positionss.push_back(cgmath::vec2(0.2537f, -0.4229f));
	positionss.push_back(cgmath::vec2(0.2683f, -0.3138f));
	positionss.push_back(cgmath::vec2(0.2467f, -0.1693f));
	positionss.push_back(cgmath::vec2(0.2011f, -0.0600f));
	positionss.push_back(cgmath::vec2(0.32649f, -0.0122f));
	positionss.push_back(cgmath::vec2(0.4639f, 0.0900f));
	positionss.push_back(cgmath::vec2(0.54606f, 0.2277f));
	positionss.push_back(cgmath::vec2(0.5727f, 0.3496f));
	positionss.push_back(cgmath::vec2(0.6426f, 0.3847f));
	positionss.push_back(cgmath::vec2(0.6331f, 0.4747f));
	positionss.push_back(cgmath::vec2(0.5752f, 0.4909f));

	for (int i = 0; i < 10; i++)
	{
		chaikin(positionss);
	}

	glGenVertexArrays(1, &vao); //Variable donde quiero vaciar 
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * positionss.size(),  //mandamos los datos
		positionss.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void scene_chaikin2::chaikin(std::vector<cgmath::vec2>& positions)
{
	std::vector<cgmath::vec2> points;
	points.push_back(positionss[0]);
	for (unsigned int i = 0; i < (positionss.size() - 1); ++i) {
		cgmath::vec2& p0 = positionss[i];
		cgmath::vec2& p1 = positionss[i + 1];
		cgmath::vec2 a;
		cgmath::vec2 b;

		a.x = 0.75f*p0.x + 0.25f*p1.x;
		a.y = 0.75f*p0.y + 0.25f*p1.y;

		b.x = 0.25f*p0.x + 0.75f*p1.x;
		b.y = 0.25f*p0.y + 0.75f*p1.y;

		points.push_back(a);
		points.push_back(b);
	}
	points.push_back(positionss[positionss.size() - 1]);

	positionss = points;
}

void scene_chaikin2::awake() //congigurar el frame buffer de color 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(20.0f);
}

void scene_chaikin2::sleep()
{

}

void scene_chaikin2::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//dibujar
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, positionss.size());
	glBindVertexArray(0);
}

//Referencias
//https://nccastaff.bournemouth.ac.uk/jmacey/RobTheBloke/www/opengl_programming.html
//Graficador de puntos https://apps.automeris.io/wpd/

