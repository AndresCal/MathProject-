#pragma once

#include "scene.h"

class scene_grid : public scene
{
public:

	~scene_grid();

	void init();
	void awake(); //Configurar escena
	void sleep();
	void reset() { } //implementacion vacia
	void mainLoop(); //Dibujamos
	void resize(int width, int height); //Tamaño del viewport 
	void normalKeysDown(unsigned char key) { }
	void normalKeysUp(unsigned char key) { }
	void specialKeys(int key) { }
	void passiveMotion(int x, int y) { }

private:
	GLuint shader_program;

};
