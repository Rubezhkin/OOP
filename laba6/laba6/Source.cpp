#include "My_List.h"
using namespace std;

void main()
{
	LIST<int> q;
	ifstream file("data.txt");
	q.create_by_queue(file);
	file.close();
	q.print();

	NODE<int>* ptr3 = q.get_head();
	q.searchS(ptr3, 3);
	NODE<int>* ptr5 = q.get_head();
	q.searchS(ptr5, 5);

	LIST<int> p;
	file.open("data.txt");
	p.create_by_queue(file);
	p.print();
	file.close();

	NODE<int>* k1 = p.get_head()->next;
	NODE<int>* k2 = p.get_head()->next;
	p.searchS(k1, 2);
	p.searchS(k2, 3);
	NODE<int>* ptr = q.get_head()->next;
	std::cout << q.searchG(ptr, ptr3, ptr5) << "\n";
	std::cout << ptr->info << "\n";
	ptr = q.get_head()->next;
	q.group_switch(ptr, ptr5, k1, k2);
	std::cout << q.searchG(ptr, ptr3, ptr5) << "\n";
	q.print();
}
