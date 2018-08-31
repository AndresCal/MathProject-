#pragma once
#include <iostream>
#include <math.h>

namespace cgmath
{
	class vec4 
	{
	public: 
		float x;
		float y;
		float z;
		float w;


		vec4();

		vec4(float x, float y, float z, float w);

		float & operator[](int i);

		const float & operator[](int i) const;

		const bool operator==(const cgmath::vec4 & v);

		cgmath::vec4 & operator*=(float s);

		cgmath::vec4 & operator/=(float s);

		cgmath::vec4 & operator+=(const cgmath::vec4 & v);

		cgmath::vec4 & operator-=(const cgmath::vec4 & v);

	};
	std::ostream & operator<<(std::ostream & os, const vec4 & v);
};

inline cgmath::vec4 operator *(const cgmath::vec4& v, float s)
{
	return cgmath::vec4(v.x * s, v.y * s, v.z * s, v.w * s);
}

inline cgmath::vec4 operator*(float s, const cgmath::vec4& v)
{
	return cgmath::vec4(v.x * s, v.y * s, v.z * s, v.w * s);
}

inline cgmath::vec4 operator/(const cgmath::vec4& v, float s)
{
	return cgmath::vec4(v.x / s, v.y / s, v.z / s, v.w / s);
}

inline cgmath::vec4 operator+(const cgmath::vec4& a, const cgmath::vec4 b)
{
	return cgmath::vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline cgmath::vec4 operator-(const cgmath::vec4& a, const cgmath::vec4 b)
{
	return cgmath::vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline cgmath::vec4 operator-(const cgmath::vec4& v)
{
	return cgmath::vec4(-v.x, -v.y, -v.z, -v.w);
}




