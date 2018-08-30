#include "vec4.h"
#include "math.h"

using namespace cgmath;

cgmath::vec4::vec4() : x(0.0f),y(0.0f),z(0.0f),w(0.0f)
{
}

cgmath::vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
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

