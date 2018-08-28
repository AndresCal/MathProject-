#include "complex.h"

complex::complex() : real(0.0f), imag(0.0f)
{
}

complex::complex(float real, float imag) : real(real), imag(imag)
{
}

void complex::print() const
{
	std::cout << real << " + " << imag << "i" << std::endl;
}

void complex::add(const complex& other)
{
	real += other.real;
	imag += other.imag;
}

complex& complex::operator+=(const complex& other)
{
	real += other.real;
	imag += other.imag;

	return *this;
}

complex complex::add(const complex& a, const complex& b)
{
	return complex(a.real + b.real, a.imag + b.imag);
}