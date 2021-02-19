#include "List.cpp"
#include <iostream>
using namespace std;
template<class T>
T ListsCentralElement(List<T>& list)
{
	Node<T>* p1 = list.get_first();
	Node<T>* p2 = p1;
	while (p2 != NULL && p2->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
			break;
	}
	if (p2 == NULL || p2->next == NULL)
		return list.get_data(p1);
	else
	{
		p1 = list.get_first();
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		Node<T>* cycle_start = p1;
		bool b = false;
		p1 = list.get_first();//slow
		p2 = p1;//fast
		while (p2 != cycle_start && p2->next != cycle_start || b == false)
		{
			if (p2 == cycle_start)
				b = true;
			p1 = p1->next;
			p2 = p2->next->next;
		}
		return list.get_data(p1);
	}
}