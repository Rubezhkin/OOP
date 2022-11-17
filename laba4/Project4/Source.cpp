#include "Pair.h"
#include "Money.h"
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleOutputCP(1251);
	int mode;
	do {
		cout << "1)Pair \n2)Money\n";
		cin >> mode;
		switch (mode)
		{
			case 1:
			{
			Pair a;
			cout << "Pair: ";
			cin >> a;
			cout << a;

			cout << "1)+= \n2) *=\n";
			int mode1;
			cin >> mode1;
			switch (mode1)
			{
				case 1:
				{
					Pair b;
					cout << "Pair: ";
					cin >> b;
					cout << b;
					a += b;
					cout << a;
					break;
				}
				case 2:
				{
					int n;
					cout << "n: ";
					cin >> n;
					a *= n;
					cout << a;
					break;
				}
			}
			break;
		}
			case 2:
			{
			Money a;
			cout << "Money: ";
			cin >> a;
			cout << a;

			cout << "1)+\n2)-\n3)/\n4)>\n5)<\n";
			int mode1;
			cin >> mode1;
			switch (mode1)
			{
			case 1:
			{
				Money b;
				cout << "Money: ";
				cin >> b;
				cout << b;
				a += b;
				cout << a;
				break;
			}
			case 2:
			{
				Money b;
				cout << "Money: ";
				cin >> b;
				cout << b;
				a -= b;
				cout << a;
				break;
			}
			case 3:
			{
				int n;
				cout << "n: ";
				cin >> n;
				a /= n;
				cout << a;
				break;
			}
			case 4:
			{
				Money b;
				cout << "Money: ";
				cin >> b;
				cout << b;
				cout << (a > b) << "\n";
				break;
			}
			case 5:
			{
				Money b;
				cout << "Money: ";
				cin >> b;
				cout << b;
				cout << (a < b) << "\n";
				break;
			}
			}
			break;
		}
			cin >> mode;
		}
	}while (mode != 0);
}