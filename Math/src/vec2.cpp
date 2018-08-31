#include "vec2.h"
#include <iostream>
#include "math.h"


using namespace cgmath;

cgmath::vec2::vec2() : x(0.0f), y(0.0f)
{
}

cgmath::vec2::vec2(float x, float y) : x(x), y(y)
{

}

float& cgmath::vec2::operator[](int i)
{
	float* ptrX = &x;
	return *(ptrX + i);
}

const float& cgmath::vec2::operator[](int i) const
{
	const float* ptrX = &x;
	return *(ptrX + i);
}

cgmath::vec2 & vec2::operator*=(float s)
{
	x *= s;
	y *= s;
	return *this;
}

cgmath::vec2 & vec2::operator/=(float s)
{
	x /= s;
	y /= s;

	return *this;
}

cgmath::vec2 & vec2::operator+=(const cgmath::vec2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

cgmath::vec2 & vec2::operator-=(const cgmath::vec2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

const bool cgmath::vec2::operator==(const cgmath::vec2& v)
{
	return (x == v.x && y == v.y);
}

const float cgmath::vec2::magnitude()
{
	float a;
	return a = sqrtf(x * x + y * y);
}


void cgmath::vec2::normalize()
{
	float a;
	a = sqrtf(x * x + y * y);
	x /= a;
	y /= a;
}

float cgmath::vec2::magnitude(const cgmath::vec2& v)
{
	return sqrtf(v.x * v.x + v.y * v.y);
}

cgmath::vec2  cgmath::vec2::normalize(const cgmath::vec2& v) 
{
	float a; 
	a = sqrtf(v.x * v.x + v.y * v.y);
	
	return vec2(v.x / a, v.y / a);
}

float cgmath::vec2::dot(const cgmath::vec2& a, const cgmath::vec2& b)
{
	return (a.x * b.x + a.y * b.y);
}

std::ostream& cgmath::operator<<(std::ostream& os, const vec2& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}

