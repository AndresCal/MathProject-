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

		cgmath::vec4 & operator*=(float s);

		cgmath::vec4 & operator/=(float s);

		cgmath::vec4 & operator+=(const cgmath::vec4 & v);

		cgmath::vec4 & operator-=(const cgmath::vec4 & v);

	};
};

