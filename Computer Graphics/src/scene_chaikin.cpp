#include "scene_chaikin.h"
#include "vec2.h"
#include <vector>
#include <math.h>
#include <GL/glut.h>



std::vector<cgmath::vec2> positions;

void scene_chaikin::init()

{
	//Goku
	positions.push_back(cgmath::vec2(0.4654f, -0.7936f));
	positions.push_back(cgmath::vec2(0.4779f, -0.6334f));
	positions.push_back(cgmath::vec2(0.46855f, -0.4482f));
	positions.push_back(cgmath::vec2(0.4528f, -0.2661f));
	positions.push_back(cgmath::vec2(0.3364f, -0.1250f));
	positions.push_back(cgmath::vec2(0.2106f, -0.04676f));
	positions.push_back(cgmath::vec2(0.1383f, -0.0060f));
	positions.push_back(cgmath::vec2(0.0911f, 0.0755f));
	positions.push_back(cgmath::vec2(0.2893f, 0.2076f));
	positions.push_back(cgmath::vec2(0.1981f, 0.2075f));
	positions.push_back(cgmath::vec2(0.4213f, 0.3460f));

	positions.push_back(cgmath::vec2(0.1981f, 0.3394f));
	positions.push_back(cgmath::vec2(0.4465f, 0.4905f));
	positions.push_back(cgmath::vec2(0.2735f, 0.5153f));


	positions.push_back(cgmath::vec2(-0.0723f, 0.4522f));
	positions.push_back(cgmath::vec2(-0.1352f, 0.5900f));
	positions.push_back(cgmath::vec2(-0.2169f, 0.6809f));
	positions.push_back(cgmath::vec2(-0.4874f, 0.7935f));
	positions.push_back(cgmath::vec2(-0.2955f, 0.5741f));
	positions.push_back(cgmath::vec2(-0.4245f, 0.6304f));
	positions.push_back(cgmath::vec2(-0.6132f, 0.5893f));

	positions.push_back(cgmath::vec2(-0.7861f, 0.5136f));
	positions.push_back(cgmath::vec2(-0.5503f, 0.4324f));
	positions.push_back(cgmath::vec2(-0.6603f, 0.3066f));
	positions.push_back(cgmath::vec2(-0.7232f, 0.1338f));
	positions.push_back(cgmath::vec2(-0.5471f, 0.2252f));
	positions.push_back(cgmath::vec2(-0.5911f, 0.1403f));
	positions.push_back(cgmath::vec2(-0.5849f, 0.03362f));
	positions.push_back(cgmath::vec2(-0.5345f, 0.1059f));
	positions.push_back(cgmath::vec2(-0.4842f, 0.1311f));
	positions.push_back(cgmath::vec2(-0.4748f, 0.0432f));
	positions.push_back(cgmath::vec2(-0.4182f, 0.0119f));

	positions.push_back(cgmath::vec2(-0.4371f, 0.06839f));
	positions.push_back(cgmath::vec2(-0.4119f, 0.0433f));
	positions.push_back(cgmath::vec2(-0.3710f, 0.0465f));
	positions.push_back(cgmath::vec2(-0.3899f, -0.0539f));
	positions.push_back(cgmath::vec2(-0.3553f, -0.0539f));
	positions.push_back(cgmath::vec2(-0.3396f, -0.0758f));
	positions.push_back(cgmath::vec2(-0.3207f, -0.0789f));
	positions.push_back(cgmath::vec2(-0.3144f, -0.1009f));
	positions.push_back(cgmath::vec2(-0.2767f, -0.1165f));
	positions.push_back(cgmath::vec2(-0.2547f, -0.1542f));
	positions.push_back(cgmath::vec2(-0.2075f, -0.1541f));

	positions.push_back(cgmath::vec2(-0.15094f, -0.1038f));
	positions.push_back(cgmath::vec2(-0.1446f, -0.1572f));
	positions.push_back(cgmath::vec2(-0.1855f, -0.2389f));
	positions.push_back(cgmath::vec2(-0.2893f, -0.3677f));
	positions.push_back(cgmath::vec2(-0.2924f, -0.4148f));
	positions.push_back(cgmath::vec2(-0.3270f, -0.5122f));
	positions.push_back(cgmath::vec2(-0.3459f, -0.7603f));
	positions.push_back(cgmath::vec2(0.02515f, -0.8382f));

	for (int i = 0; i < 10; i++)
	{
		chaikin(positions);
	}

	glGenVertexArrays(1, &vao); //Variable donde quiero vaciar 
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * positions.size(),  //mandamos los datos
		positions.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void scene_chaikin::chaikin(std::vector<cgmath::vec2>& positions)
{
	std::vector<cgmath::vec2> points;
	points.push_back(positions[0]);
	for (unsigned int i = 0; i < (positions.size() - 1); ++i) {
		cgmath::vec2& p0 = positions[i];
		cgmath::vec2& p1 = positions[i + 1];
		cgmath::vec2 a;
		cgmath::vec2 b;

		a.x = 0.75f*p0.x + 0.25f*p1.x;
		a.y = 0.75f*p0.y + 0.25f*p1.y;

		b.x = 0.25f*p0.x + 0.75f*p1.x;
		b.y = 0.25f*p0.y + 0.75f*p1.y;

		points.push_back(a);
		points.push_back(b);
	}
	points.push_back(positions[positions.size() - 1]);

	positions = points;
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
	glDrawArrays(GL_LINE_LOOP, 0, positions.size());
	glBindVertexArray(0);
}

//Referencias
//https://nccastaff.bournemouth.ac.uk/jmacey/RobTheBloke/www/opengl_programming.html
//Graficador de puntos https://apps.automeris.io/wpd/

