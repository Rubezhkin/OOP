#pragma once
#include <string>
#include <iostream>

class Complex {
	double a,b;
public:
	Complex();
	Complex(double, double);
	double getA();
	double getB();
	void setA(double A);
	void setB(double B);
	Complex add(Complex sec);
	Complex sub(Complex sec);
	Complex mul(Complex sec);
	Complex div(Complex sec);
	bool equ(Complex sec);
	Complex conj();
	std::string toString();
};