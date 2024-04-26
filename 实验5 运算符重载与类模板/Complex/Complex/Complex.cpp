#include "Complex.h"

// Complex + as binary operator
Complex Complex::operator+( const Complex& u ) const {
   return Complex ( real + u.real,
              imag + u.imag );
}

// Complex - as binary operator
Complex Complex::operator-(const Complex& u) const {
	return Complex(real - u.real,
		imag - u.imag);
}

// Complex * as binary operator
Complex Complex::operator*(const Complex& u) const {
	return Complex(real * u.real - imag * u.imag,
		imag * u.real + real * u.imag);
}

// Complex / as binary operator
Complex Complex::operator/(const Complex& u) const {
	double abs_sq = u.real * u.real + u.imag * u.imag;
	return Complex((real * u.real + imag * u.imag) / abs_sq,
		(imag * u.real - real * u.imag) / abs_sq);
}

istream& operator >> (istream& in, Complex& c) {
	return      in >> c.real >> c.imag;
}

ostream& operator << (ostream& out, Complex& c) {
	return      out << c.real << "+" << c.imag << "i";
}

Complex Complex::operator++()//Ç°ÖÃ
{
	real += 1;
	imag += 1;
	return *this;
}

Complex Complex::operator++(int)//ºóÖÃ
{
	Complex	temp(*this);
	real += 1;
	imag += 1;
	return temp;
}
