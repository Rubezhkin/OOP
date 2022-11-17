#include <iostream>
#include <Windows.h>
#include "Complex.h"
using namespace std;

void main()
{
	SetConsoleOutputCP(1251);
	Complex a(3, -4),b(2,5);
	Complex c = a.add(b);
	Complex d = a.sub(b);
	Complex e = a.mul(b);
	Complex f = a.div(b);
	Complex g(5, 6);
	cout << c.toString() << d.toString() << e.toString() << f.toString() << "\n" << g.equ(a) << " " << g.equ(b);
	g.conj();
	cout << g.toString(); 
}