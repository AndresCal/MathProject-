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

//float cgmath::vec2::operator[](int i)
//{
//	x = i;
//	y = i;
//
//	return (x,y);
//}

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

//<<{const}>> operator==(v:const vec2&):bool
// std::cout << real << " + " << imag << "i" << std::endl;
// std::cout << " -1 == 1? " << (n == n2) << '\n'

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


float cgmath::vec2::dot(const cgmath::vec2& a, const cgmath::vec2& b)
{
	return (a.x * b.x + a.y * b.y);
}


