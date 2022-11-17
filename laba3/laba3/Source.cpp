#include <iostream>
#include <Windows.h>
#include "Triangle.h"

using namespace std;

Triangle CreateTriangle()
{
	cout << "Введите координаты треугольника: ";
	Triangle A;
	cin >> A;
	while (A.check())
	{
		cout << "Неправильно построен треугольник. Введите координаты треугольника: ";
		cin >> A;
	}
	return A;
}

void main()
{
	SetConsoleOutputCP(1251);
	Triangle A = CreateTriangle();
	int mode;
	cout << "Введите, что хотите сделать \n1)Поменять A \n2)Поменять B \n3)Поменять C \n4)Вывести коодинаты \n5)Вывести периметр \n6)Вывести Площадь \n7)Вывести длину высоты из угла A \n8)Вывести длину высоты из угла B\n9)Вывести длину высоты из угла C \n10) Вывести тип трегольника \n11) Проверить, правильно ли построен треугольник\n другое число чтобы выйти: ";
	cin >> mode;
	while (mode <= 11 && mode >= 1)
	{
		switch (mode)
		{
		case 1:
		{
			cout << "Введите новую координату: ";
			Point d;
			cin >> d;
			A.SetA(d);
			break;
		}
		case 2:
		{
			cout << "Введите новую координату: ";
			Point d;
			cin >> d;
			A.SetB(d);
			break;
		}
		case 3:
		{
			cout << "Введите новую координату: ";
			Point d;
			cin >> d;
			A.SetC(d);
			break;
		}
		case 4:
		{
			cout << A << "\n";
			break;
		}
		case 5:
		{
			cout << A.perimeter() << "\n";
			break;
		}
		case 6:
		{
			cout << A.square() << "\n";
			break;
		}
		case 7:
		{
			cout << A.heightA() << "\n";
			break;
		}
		case 8:
		{
			cout << A.heightB() << "\n";
			break;
		}
		case 9:
		{
			cout << A.heightC() << "\n";
			break;
		}
		case 10:
		{
			cout << A.type() << "\n";
			break;
		}
		case 11:
		{
			if (A.check())
				cout << "неправильно построен" << "\n";
			else
				cout << "правильно построен" << "\n";
		}
		default:
		{}
		}
		cout << "Введите, что хотите сделать: ";
		cin >> mode;
		cout << "\n";
	}
}