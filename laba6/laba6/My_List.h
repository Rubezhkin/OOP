#pragma once
#include <iostream>
#include <fstream>

template <class TInfo>
struct NODE
{
	TInfo info;
	NODE<TInfo>* next;

	NODE(TInfo info, NODE<TInfo>* ptr = nullptr) :info(info), next(ptr) {}
	~NODE()
	{
		next = nullptr;
	}
};

template <class TInfo>
class LIST
{
private:
	NODE<TInfo>* head,* tail;
	size_t size;
public:
	LIST()
	{
		head = new NODE<TInfo>(0);
		tail = head;
		size = 0;
	}
	~LIST();
	NODE<TInfo>* get_head()
	{
		return head;
	}
	TInfo get_first()
	{
		return head->next->info;
	}
	TInfo get_size()
	{
		return size;
	}
	bool empty();
	void add_by_pointer(NODE<TInfo>* ptr, TInfo elem);
	void del_by_pointer(NODE<TInfo>* ptr);
	void clear(NODE<TInfo>* ptr);
	void add_to_head(TInfo elem);
	void add_to_tail(TInfo elem);
	void add_after(NODE<TInfo>* ptr, TInfo elem);
	void del_from_head();
	void del_after(NODE<TInfo>* ptr);
	void create_by_queue(std::ifstream& file);
	void group_add(NODE<TInfo>* p, NODE<TInfo>* addptr1, NODE<TInfo>* addptr2);
	void group_del(NODE<TInfo>* delptr1, NODE<TInfo>* delptr2);
	void group_switch(NODE<TInfo>* ptr1h, NODE<TInfo>* ptr1e, NODE<TInfo>* ptr2h, NODE<TInfo>* ptr2e);
	NODE<TInfo>* searchS(NODE<TInfo>* ptr, TInfo T);
	NODE<TInfo>* searchG(NODE<TInfo>* ptr, NODE<TInfo>* ptr1h, NODE<TInfo>* ptr1e);
	void print();
};

template <class TInfo>
void LIST<TInfo>::add_by_pointer(NODE<TInfo>* ptr, TInfo elem)
{
	NODE<TInfo>* p = new NODE<TInfo>(elem, ptr);
	ptr = p;
}

template <class TInfo>
void LIST<TInfo>::del_by_pointer(NODE<TInfo>* ptr)
{
	NODE<TInfo>* p = ptr;
	ptr = p->next;
	delete p;
}

template<class TInfo>
inline void LIST<TInfo>::clear(NODE<TInfo>* ptr)
{
	if (!empty)
		clear(ptr->next);
	del_by_pointer(ptr);
}

template <class TInfo>
LIST<TInfo>::~LIST()
{
	//	std::cout << "destr\n";
	while (!empty())
	{
		del_from_head();
	}

	delete head;
}

template <class TInfo>
bool LIST<TInfo>::empty()
{
	return !head->next;
}

template <class TInfo>
void LIST<TInfo>::add_to_head(TInfo elem)
{
	add_by_pointer(head->next, elem);
	if (head == tail)
		tail = tail->next;
	++size;
}

template <class TInfo>
void LIST<TInfo>::add_to_tail(TInfo elem)
{
	add_by_pointer(tail->next, elem);
	tail = tail->next;
}

template <class TInfo>
void LIST<TInfo>::add_after(NODE<TInfo>* ptr, TInfo elem)
{
	if (ptr)
	{
		add_by_pointer(ptr->next, elem);
		if (ptr == tail)
			tail = tail->next;
	}
}

template <class TInfo>
void LIST<TInfo>::del_from_head()
{
	if (head->next)
	{
		del_by_pointer(head->next);
		if (!head->next)
			tail = head;
		--size;
	}
}

template <class TInfo>
void LIST<TInfo>::del_after(NODE<TInfo>* ptr)
{
	if (ptr && ptr->next)
	{
		if (ptr->next == tail)
			tail = ptr;
		del_by_pointer(ptr->next);
		if (empty())
			tail = head;
		--size;
	}
}

template <class TInfo>
void LIST<TInfo>::create_by_queue(std::ifstream& file)
{
	TInfo elem;
	while (file >> elem)
		add_to_tail(elem);
}

template<class TInfo>
inline void LIST<TInfo>::group_add(NODE<TInfo>* p, NODE<TInfo>* addptr1, NODE<TInfo>* addptr2)
{
	LIST<TInfo>* ptr = p->next;
	p->next = addptr1;
	addptr2->next = ptr;
}

template<class TInfo>
inline void LIST<TInfo>::group_del(NODE<TInfo>* delptr1, NODE<TInfo>* delptr2)
{
	while (delptr1->next != delptr2)
		del_after(delptr1);
	del_after(delptr1);
}

template<class TInfo>
inline void LIST<TInfo>::group_switch(NODE<TInfo>* ptr1h, NODE<TInfo>* ptr1e, NODE<TInfo>* ptr2h, NODE<TInfo>* ptr2e)
{
	ptr1h = ptr2h;
	ptr2h->next = ptr1e->next;
}

template<class TInfo>
inline NODE<TInfo>* LIST<TInfo>::searchS(NODE<TInfo>* ptr, TInfo T)
{
	while (ptr->next)
	{
		if (ptr->info == T)
			return ptr;
		ptr = ptr->next;
	}
	return nullptr;
}

template<class TInfo>
inline NODE<TInfo>* LIST<TInfo>::searchG(NODE<TInfo>* ptr, NODE<TInfo>* ptr1h, NODE<TInfo>* ptr1e)
{
	while (ptr->next)
	{
		if (ptr.info == ptr1h->info)
		{
			bool flag = true;
			NODE<TInfo>* p = ptr;
			NODE<TInfo>* p1 = ptr1h;
			while (p->next && p1 != ptr1e && flag)
			{
				if (p->info != p1) flag = false;
				p = p->next;
				p1 = p1->next;
			}
			if (flag)return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}

template <class TInfo>
void LIST<TInfo>::print()
{
	NODE<TInfo>* p = head->next;
	if (empty())
		std::cout << "no elem\n";
	while (p)
	{
		std::cout << p->info << ' ';
		p = p->next;
	}
}