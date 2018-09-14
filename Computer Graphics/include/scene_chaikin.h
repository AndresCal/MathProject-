#pragma once
#include <scene.h>
#include <vector>
#include <vec2.h>

class scene_chaikin : public scene
{
public:
	//void chaikin(std::vector<cgmath::vec2>& positions);
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
	GLuint positionsVBO;

};

