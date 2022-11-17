#include <iostream>
#include <Windows.h>
#include "Triangle.h"

using namespace std;

Triangle CreateTriangle()
{
	cout << "������� ���������� ������������: ";
	Triangle A;
	cin >> A;
	while (A.check())
	{
		cout << "����������� �������� �����������. ������� ���������� ������������: ";
		cin >> A;
	}
	return A;
}

void main()
{
	SetConsoleOutputCP(1251);
	Triangle A = CreateTriangle();
	int mode;
	cout << "�������, ��� ������ ������� \n1)�������� A \n2)�������� B \n3)�������� C \n4)������� ��������� \n5)������� �������� \n6)������� ������� \n7)������� ����� ������ �� ���� A \n8)������� ����� ������ �� ���� B\n9)������� ����� ������ �� ���� C \n10) ������� ��� ����������� \n11) ���������, ��������� �� �������� �����������\n ������ ����� ����� �����: ";
	cin >> mode;
	while (mode <= 11 && mode >= 1)
	{
		switch (mode)
		{
		case 1:
		{
			cout << "������� ����� ����������: ";
			Point d;
			cin >> d;
			A.SetA(d);
			break;
		}
		case 2:
		{
			cout << "������� ����� ����������: ";
			Point d;
			cin >> d;
			A.SetB(d);
			break;
		}
		case 3:
		{
			cout << "������� ����� ����������: ";
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
				cout << "����������� ��������" << "\n";
			else
				cout << "��������� ��������" << "\n";
		}
		default:
		{}
		}
		cout << "�������, ��� ������ �������: ";
		cin >> mode;
		cout << "\n";
	}
}