#pragma once
#include <iostream>
#include <math.h>

namespace cgmath {
	class vec3 {
	public:
		float x;
		float y;
		float z;

		vec3();

		vec3(float x, float y, float z);

		const bool operator==(const cgmath::vec3 & v);

		const float magnitude();

		void normalize();

		static float magnitude(const cgmath::vec3 & v);
		static float dot(const cgmath::vec3 & a, const cgmath::vec3 & b);


		cgmath::vec3 & operator*=(float s);
		cgmath::vec3 & operator/=(float s);
		cgmath::vec3 & operator+=(const cgmath::vec3 & v);
		cgmath::vec3 & operator-=(const cgmath::vec3 & v);



	};

};

inline cgmath::vec3 operator *(const cgmath::vec3& v, float s)
{
	return cgmath::vec3(v.x * s, v.y * s, v.z * s);
}

inline cgmath::vec3 operator*(float s, const cgmath::vec3& v)
{
	return cgmath::vec3(v.x * s, v.y * s, v.z * s);
}

inline cgmath::vec3 operator/(const cgmath::vec3& v, float s)
{
	return cgmath::vec3(v.x / s, v.y / s,v.z / s);
}

inline cgmath::vec3 operator+(const cgmath::vec3& a, const cgmath::vec3 b)
{
	return cgmath::vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline cgmath::vec3 operator-(const cgmath::vec3& a, const cgmath::vec3 b)
{
	return cgmath::vec3(a.x - b.x, a.y - b.y,a.z - b.z);
}

inline cgmath::vec3 operator-(const cgmath::vec3& v)
{
	return cgmath::vec3(-v.x, -v.y,-v.z);
}




