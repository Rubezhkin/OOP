#include <iostream>
#include "Money.h"
#include <Windows.h>

using namespace std;

void main()
{
	SetConsoleOutputCP(1251);

	cout << "\n������� �������� �������: ";
	Money a;
	cin >> a;
	cout << a;
	cout << "�������, ��� ������ ������� (+, -, *, /, <, >, =, :): ";
	char mode;
	cin >> mode;
	switch (mode)
	{
	case  '+':
	{
		Money b;
		cout << "\n������� �������� �������: ";
		cin >> b;
		cout << b;
		Money c = a + b;
		cout << c;
		break;
	}
	case'-':
	{
		Money b;
		cout << "\n������� �������� �������: ";
		cin >> b;
		cout << b;
		Money c = a - b;
		cout << c;
		break;
	}
	case'*':
	{
		cout << "������� �����: ";
		double x;
		cin >> x;
		a * x;
		cout << a;
		break;
	}
	case'/':
	{
		cout << "������� �����: ";
		double x;
		cin >> x;
		a / x;
		cout << a;
		break;
	}
	case'<':
	{
		Money b;
		cout << "\n������� �������� �������: ";
		cin >> b;
		cout << b;
		cout << (a < b);
		break;
	}
	case'>':
	{
		Money b;
		cout << "\n������� �������� �������: ";
		cin >> b;
		cout << b;
		cout << (a > b);
		break;
	}
	case'=':
	{
		Money b;
		cout << "\n������� �������� �������: ";
		cin >> b;
		cout << b;
		cout << (a == b);
		break;
	}
	case':':
	{
		Money b;
		cout << "\n������� �������� �������: ";
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