#include "vec4.h"
#include "math.h"

using namespace cgmath;

cgmath::vec4::vec4() : x(0.0f),y(0.0f),z(0.0f),w(0.0f)
{
}

cgmath::vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

float& cgmath::vec4::operator[](int i)
{
	float* ptrX = &x;
	return *(ptrX + i);
}

const float& cgmath::vec4::operator[](int i) const
{
	const float* ptrX = &x;
	return *(ptrX + i);
}

cgmath::vec4 & vec4::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;

	return *this;
}

cgmath::vec4 & vec4::operator/=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	w /= s;

	return *this;
}

cgmath::vec4 & vec4::operator+=(const cgmath::vec4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}

cgmath::vec4 & vec4::operator-=(const cgmath::vec4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}

const bool cgmath::vec4::operator==(const cgmath::vec4& v)
{
	return (x == v.x && y == v.y && z == v.z && w == v.w);
}

std::ostream& cgmath::operator<<(std::ostream& os, const vec4& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return os;
}