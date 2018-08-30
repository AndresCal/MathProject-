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


		cgmath::vec3 & operator*=(float s);

		cgmath::vec3 & operator/=(float s);

		cgmath::vec3 & operator+=(const cgmath::vec3 & v);
		cgmath::vec3 & operator-=(const cgmath::vec3 & v);

	};

};
