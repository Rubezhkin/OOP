#include "Complex.h"

	 Complex::Complex() { a = 0; b = 0; }
	 Complex::Complex(double A, double B)
	{
		a = A;
		b = B;
	}
	 double Complex::getA()
	 {
		 return this->a;
	 }
	 double Complex::getB()
	 {
		 return this->b;
	 }
	 void Complex::setA(double A)
	 {
		 this->a = A;
	 }
	 void Complex::setB(double B)
	 {
		this -> b = B;
	 }
	Complex Complex::add(Complex sec)
	{
		Complex temp;
		temp.a = a + sec.a;
		temp.b = b + sec.b; 
		return temp;
	}
	Complex Complex::sub(Complex sec)
	{
		Complex temp;
		temp.a = a - sec.a;
		temp.b = b - sec.b;
		return temp;
	}
	Complex Complex::mul(Complex sec)
	{
		Complex temp;
		temp.a = a * sec.a - b * sec.b;
		temp.b = a * sec.b + b * sec.a;
		return temp;
	}
	Complex Complex::div(Complex sec)
	{
		Complex temp;
		temp.a = (a * sec.a + b * sec.b) / (sec.a * sec.a + sec.b * sec.b);
		temp.b = (b*sec.a - a*sec.b) / (sec.a * sec.a + sec.b * sec.b);
		return temp;
	}
	bool Complex::equ(Complex sec)
	{
		return (a == sec.a && b == sec.b);
	}
	Complex Complex::conj()
	{
		Complex temp;
		temp.a = a;
		temp.b = b*( - 1);
		return temp;
	}
	std::string Complex::toString()
	{
		return "\nДействительная часть: " + std::to_string(a) + "\nМнимая часть: " + std::to_string(b);
	}