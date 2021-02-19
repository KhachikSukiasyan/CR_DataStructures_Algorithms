#include "List.cpp"
#include <iostream>
using namespace std;
template<class T>
bool RemoveCycle(List<T>& list)
{
	Node<T>* first = list.get_first();
	Node<T>* p1 = first;
	Node<T>* p2 = first;
	while (p2 != NULL && p2->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1->next == p2->next->next)
			break;
	}
	if (p2 == NULL || p2->next == NULL)
		return false;

	if (p1->next == first)
	{
		p2->next = NULL;
		return true;
	}
	else
	{
		p1 = first;
		p2 = p2->next->next;
		while (p1->next != p2->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = NULL;
		return true;
	}
}