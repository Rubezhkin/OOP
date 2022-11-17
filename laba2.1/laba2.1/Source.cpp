#include <iostream>
#include "Money.h"
#include <Windows.h>

using namespace std;

void main()
{
	SetConsoleOutputCP(1251);

	cout << "\nВведите элементы объекта: ";
	Money a;
	cin >> a;
	cout << a;
	cout << "Введите, что хотите сделать (+, -, *, /, <, >, =, :): ";
	char mode;
	cin >> mode;
	switch (mode)
	{
	case  '+':
	{
		Money b;
		cout << "\nВведите элементы объекта: ";
		cin >> b;
		cout << b;
		Money c = a + b;
		cout << c;
		break;
	}
	case'-':
	{
		Money b;
		cout << "\nВведите элементы объекта: ";
		cin >> b;
		cout << b;
		Money c = a - b;
		cout << c;
		break;
	}
	case'*':
	{
		cout << "Введите число: ";
		double x;
		cin >> x;
		a * x;
		cout << a;
		break;
	}
	case'/':
	{
		cout << "Введите число: ";
		double x;
		cin >> x;
		a / x;
		cout << a;
		break;
	}
	case'<':
	{
		Money b;
		cout << "\nВведите элементы объекта: ";
		cin >> b;
		cout << b;
		cout << (a < b);
		break;
	}
	case'>':
	{
		Money b;
		cout << "\nВведите элементы объекта: ";
		cin >> b;
		cout << b;
		cout << (a > b);
		break;
	}
	case'=':
	{
		Money b;
		cout << "\nВведите элементы объекта: ";
		cin >> b;
		cout << b;
		cout << (a == b);
		break;
	}
	case':':
	{
		Money b;
		cout << "\nВведите элементы объекта: ";
		cin >> b;
		cout << b;
		a = b;
		cout << a;
		break;
	}
	default:
	{}
	}
}