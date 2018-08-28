#include "vec2.h"

using namespace cgmath;

cgmath::vec2::vec2() : x(0.0f), y(0.0)
{
}

cgmath::vec2::vec2(float x, float y) : x(x), y(y)
{

}

cgmath::vec2 & vec2::operator[](int i)
{

	return *this;
}


