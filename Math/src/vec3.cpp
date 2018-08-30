#include "vec3.h"
#include <iostream>

using namespace cgmath;

cgmath::vec3::vec3() : x(0.0f), y(0.0f), z(0.0f)
{

}

cgmath::vec3::vec3(float x, float y, float z) : x(x), y(y), z(z)
{

}

//Index

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

const bool cgmath::vec3::operator==(const cgmath::vec3& v)
{
	return (x == v.x && y == v.y && z == v.z);
}

const float cgmath::vec3::magnitude()
{
	float a;
	return a = sqrtf(x * x + y * y + z * z);
}

void cgmath::vec3::normalize()
{
	float a;
	a = sqrtf(x * x + y * y + z * z);
	x /= a;
	y /= a;
	z /= a;
}

float cgmath::vec3::magnitude(const cgmath::vec3& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

//normalize

float cgmath::vec3::dot(const cgmath::vec3& a, const cgmath::vec3& b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

//cgmath::vec3 & vec3::cross(cgmath::vec3& a, cgmath::vec3& b)
//{
//	return (a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
//}




