﻿#include <iostream>
using namespace std;

template <class T>
struct Node {
	T info;
	Node<T>* next;
};

template <class T>
class List {
private:
	Node<T>* first;
	int size;
	bool contains(Node<T>* node)
	{
		Node<T>* p = first;
		int i;
		for (i = 0; i < size; i++)
		{
			if (p == node)
				break;
		}
		if (i == size)
			return false;
		return true;
	}
public:
	List()
	{
		first = NULL;
		size = 0;
	}

	List(const List& list) {
		Node<T>* p = NULL, * temp, * p1 = list.first;

		for (int i = 0; i < list.size; i++)
		{
			temp = new Node<T>{ get_data(p1),NULL };
			p1 = p1->next;
			if (i == 0)
			{
				first = temp;
				p = temp;
				continue;
			}
			p->next = temp;
			p = p->next;
		}
		size = list.size;
	}

	~List() {
		Node<T>* p = first;
		for (int i = 0; i < size; i++)
		{
			p = p->next;
			delete first;
			first = p;
		}
	}

	bool is_empty() { return size == 0; }
	int get_size() { return size; }
	Node<T>* get_first() const { return first; }

	T& get_data(Node<T>* node) {
		if (node != NULL)
			return node->info;
		throw "NULL node";
	}

	T& get_at(int n) {
		if (n < 0 || n >= size)
			throw "Wrong index";
		Node<T>* p = first;
		for (int i = 0; i < n; i++)
			p = p->next;
		return p->info;
	}

	void insert_after(Node<T>* node, T value) {
		//if (!contains(node)) ????????????? ոնց ստուգեմ,թե էդ List-ի node-ն ա,թե չէ
		//	throw "Wrong node pointer";
		Node<T>* n = new Node<T>{ value, node->next };
		node->next = n;
		size++;
	}
	void insert_at(int n, T value) {
		if (n < 0 || n > size)
			throw "Wrong index";
		if (n == 0)
		{
			Node<T>* p = new Node<T>{ value ,first };
			first = p;
			size++;
			return;
		}
		Node<T>* p = first;
		for (int i = 0; i < n - 1; i++)
			p = p->next;
		insert_after(p, value);
	}

	void delete_after(Node<T>* node) {
		if (is_empty())
			throw "List is empty";
		if (node->next == NULL)
			throw "Can't delete";
		Node<T>* p = node->next;
		node->next = p->next;
		delete p;
		size--;
	}
	void delete_at(int n) {
		if (n < 0 || n >= size)
			throw "Wrong index";
		if (n == 0 && size > 0)
		{
			Node<T>* p = first;
			first = first->next;
			delete p;
			size--;
			return;
		}
		Node<T>* p = first;
		for (int i = 0; i < n - 1; i++)
			p = p->next;
		delete_after(p);
	}

	void print()
	{
		Node<T>* p = first;
		for (int i = 0; i < size; i++)
		{
			cout << p->info << ' ';
			p = p->next;
		}
		cout << "SIZE:" << size << endl;
	}


	void splice(const List<T>& list)
	{
		Node<T>* p = first;
		for (int i = 0; i < size - 1; i++)
			p = p->next;
		p->next = list.first;
		size += list.size;
	}

};