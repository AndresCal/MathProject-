#pragma once
#include <scene.h>

class scene_nicomedes : public scene 
{
public:
	void init();
	void awake();
	void sleep();
	void reset() { } //implementacion vacia
	void mainLoop();
	void resize(int width, int height) { }
	void normalKeysDown(unsigned char key) { }
	void normalKeysUp(unsigned char key) { }
	void specialKeys(int key) { }
	void passiveMotion(int x, int y) { }

private: 
	GLuint vao;
	GLuint positioonsVBO;

};
