#include "List.cpp"
#include <iostream>
using namespace std;
template<class T>
T ListsCentralElement(List<T>& list)
{
	Node<T>* p0 = list.get_first();
	Node<T>* p1 = p0;
	Node<T>* p2 = p0;
	bool b = false;
	while (p2 != NULL && p2->next != NULL)
	{
		if (b == true)
		{
			p0 = p0->next;
			b = false;
		}
		else
			b = true;

		p2 = p2->next->next;
		p1 = p1->next;
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
			if (b == true)
			{
				p0 = p0->next;
				b = false;
			}
			else
				b = true;

			p1 = p1->next;
			p2 = p2->next;
		}

		return list.get_data(p0);
	}

}