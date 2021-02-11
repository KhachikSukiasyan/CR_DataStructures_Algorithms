#include "List.cpp"
#include <iostream>
using namespace std;
template<class T>
T ListsCentralElement(List<T> list)
{
	Node<T>* p1 = list.get_first();
	Node<T>* p2 = p1;
	while (p2 != NULL && p2->next != NULL && p2->next->next != NULL)
	{
		p2 = p2->next->next;
		p1 = p1->next;
	}
	return list.get_data(p1);
}