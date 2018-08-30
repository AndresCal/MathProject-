#include "vec3.h"
#include <iostream>

using namespace cgmath;

cgmath::vec3::vec3() : x(0.0f), y(0.0f), z(0.0f)
{

}

cgmath::vec3::vec3(float x, float y, float z) : x(x), y(y), z(z)
{

}

cgmath::vec3 & vec3::operator*=(float s) {
	x *= s;
	y *= s;
	z *= s;

	return *this;

}

cgmath::vec3 & vec3::operator/=(float s) {
	x /= s;
	y /= s;
	z /= s;

	return *this;

}

cgmath::vec3 & vec3::operator+=(const cgmath::vec3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

cgmath::vec3 & vec3::operator-=(const cgmath::vec3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}



