#pragma once
#include <math.h>
#include <iostream>

namespace cgmath {
	class vec2
	{
	public:
		float x;
		float y;

		vec2();
		vec2(float x, float y);

		const bool operator==(const cgmath::vec2 & v);

		const float magnitude();

		void normalize();

		static float magnitude(const cgmath::vec2 & v);

		static float dot(const cgmath::vec2 & a, const cgmath::vec2 & b);

		cgmath::vec2 & operator*=(float s);

		cgmath::vec2 & operator/=(float s);

		cgmath::vec2 & operator+=(const cgmath::vec2 & v);

		cgmath::vec2 & operator-=(const cgmath::vec2 & v);



		
	};
};

inline cgmath::vec2 operator*(const cgmath::vec2& v, float s)
{
	return cgmath::vec2(v.x * s, v.y * s);
}

inline cgmath::vec2 operator*(float s, const cgmath::vec2& v)
{
	return cgmath::vec2(v.x * s, v.y * s);
}

inline cgmath::vec2 operator/(const cgmath::vec2& v, float s)
{
	return cgmath::vec2(v.x / s,v.y / s);
}

inline cgmath::vec2 operator+(const cgmath::vec2& a, const cgmath::vec2 b)
{
	return cgmath::vec2(a.x + b.x, a.y + b.y);
}

inline cgmath::vec2 operator-(const cgmath::vec2& a, const cgmath::vec2 b)
{
	return cgmath::vec2(a.x - b.x, a.y - b.y);
}

inline cgmath::vec2 operator-(const cgmath::vec2& v)
{
	return cgmath::vec2(-v.x,-v.y);
}


