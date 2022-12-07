#include "My_List.h"
using namespace std;

void main()
{
	LIST<int> q;
	ifstream file("data.txt");
	q.create_by_queue(file);
	q.print();
}