#include<iostream>
#include "Pair.h"
#include "Complex.h"
#include "Rational.h"
#include <Windows.h>

using namespace std;

void main()
{
	SetConsoleOutputCP(1251);
	int oper;
	int mode;
	bool flag = 1;
	while (flag)
	{
		Pair* p1 = nullptr, * p2 = nullptr;
		cout << "1)Complex\n2)Rational\n";
		cin >> mode;
		switch (mode)
		{
		case 1:
		{
			p1 = new Complex;
			p2 = new Complex;
			p1->inp();
			p2->inp();
			break;
		}
		case 2:
		{
			p1 = new Rational;
			p2 = new Rational;
			p1->inp();
			p2->inp();
			break;
		}
		default:
		{
			cout << "Error\n";
			break;
		}
		}
		cout << "1)+\n2)-\n3)*\n4)/\n5)=\n";
		int oper;
		cin >> oper;
		switch (oper)
		{
		case 1:
		{
			p1->sum(p2);
			break;
		}
		case 2:
		{
			p1->sub(p2);
			break;
		}
		case 3:
		{
			p1->mul(p2);
			break;
		}
		case 4:
		{
			p1->div(p2);
			break;
		}
		case 5:
		{
			cout << p1->equ(p2) << "\n";
			break;
		}
		default:
		{
			cout << "Error\n";
			break;
		}
		}
		cout << p1->print();
		cout << "Continue? (1 - Yes, 0 - No)\n";
		cin >> flag;
	}
}