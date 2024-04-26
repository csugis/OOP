#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0)
		:real(r), imag(i) {}
	virtual ~Complex(void) {}
	// operator methods
	Complex operator+(const Complex& ) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;
	friend istream& operator >> (istream& in, Complex& c);
	friend ostream& operator << (ostream& out, Complex& c);
	double get_real() const { return real; }
	void set_real(double r) { real = r; }
	double get_imag() const { return imag; }
	void set_imag(double i) { imag = i; }
	Complex operator++();
	Complex operator++(int);
private:
	double real;
	double imag;
};

istream& operator >> (istream& in, Complex& c);
ostream& operator << (ostream& out, Complex& c);
