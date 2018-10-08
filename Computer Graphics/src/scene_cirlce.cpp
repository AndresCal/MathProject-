#include "scene_circle.h"
#include "ifile.h"
#include "time.h"
#include <string>
#include <vector>
#include "math.h"
#include "vec2.h"

int number = 40.0;
int radius = 0.5;
int t = 2.0*3.1452423;
std::vector<cgmath::vec2> positionsCircle;

scene_circle::~scene_circle()
{
	glDeleteProgram(shader_program);
}

void scene_circle::init()
{
	for (int i = 0; i <= 40; i++)
	{
		positionsCircle.push_back(cgmath::vec2(i*t / number, radius*sinf(i*
			t / number)));
	}

	glGenVertexArrays(1, &vaoCircle); //Variable donde quiero vaciar 
	glBindVertexArray(vaoCircle);

	glGenBuffers(1, &positioonsVBOCircle); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positioonsVBOCircle); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * positionsCircle.size(),  //mandamos los datos
		positionsCircle.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void scene_circle::awake()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void scene_circle::sleep()
{
	//glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	//glDisable(GL_PROGRAM_POINT_SIZE);
}

void scene_circle::mainLoop()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);
	GLuint time_loc =
		glGetUniformLocation(shader_program, "time");
	glUniform1f(time_loc, time::elapsed_time().count());
	glDrawArrays(GL_TRIANGLE_FAN, 0, positionsCircle.size());
	glUseProgram(0);
}

void scene_circle::resize(int width, int height)
{
	glViewport(0, 0, width, height);
}


