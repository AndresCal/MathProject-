#include "mat3.h"
#include "vec3.h"
#include <iostream>
#include "math.h"

using namespace cgmath;

cgmath::mat3::mat3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			n[i][j] = 0;
		}
	}
}
//
//cgmath::mat3::mat3(float diagonal)
//{
//	for (int i = 1; i <= n; i++) {
//		if (i == 1) {
//			for (int j = 1; j <= i; j++) {
//				cout << m << "  ";
//			}
//			for (int k = 1; k <= n - i; k++) {
//				cout << k << "  ";
//			}
//		}
//		else {
//			for (k = i - 1; k >= 1; k--) {
//				cout << k << "  ";
//			}
//			cout << m << "  ";
//			for (j = 1; j <= n - i; j++) {
//				cout << j << "  ";
//			}
//		}
//}
//
//cgmath::mat3::mat3(const cgmath::vec3& a, const cgmath::vec3& b, const cgmath::vec3& c)
//{
//
//}