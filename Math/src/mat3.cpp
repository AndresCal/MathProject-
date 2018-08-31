#include "mat3.h"
#include <iostream>
#include "math.h"

using namespace cgmath;

cgmath::mat3::mat3() {
	int i;
	int j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			n[i][j] = 0;
		}
	}
}