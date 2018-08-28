#pragma once

namespace cgmath {
	class vec2
	{
	public:
		float x;
		float y;

		vec2();
		vec2(float x, float y);
		cgmath::vec2 & operator[](int i);


	};
};

