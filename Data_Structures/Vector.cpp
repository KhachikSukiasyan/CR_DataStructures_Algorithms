#include <math.h>
#include <iostream>
using namespace std;
template <class T>
class Vector
{
private:
	int size;
	int capacity;
	T* data;
public:
	Vector()
	{
		size = capacity = 0;
		data = NULL;
	}

	Vector(int cap, T value)
	{
		capacity = size = cap;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = value;
	}

	~Vector()
	{
		delete[] data;
		data = NULL;
	}
	void push_back(T value)
	{
		if (size == capacity)
		{
			int cap = capacity;
			if (capacity == 0) cap++;
			reserve((int)ceil(cap * 1.8));
		}
		data[size++] = value;
	}

	T pull_back()
	{
		if (size == 0)
			throw "Vector is empty";
		size--;
		return data[size];
	}

	void insert(int index, T value)
	{
		if (index < 0 || index > size)
		{
			throw "Index out of range";
			return;
		}
		if (size == capacity)
		{
			int cap = capacity;
			if (capacity == 0) cap++;
			reserve((int)ceil(cap * 1.8));
		}

		for (int i = size; i > index; i--)
			data[i] = data[i - 1];
		data[index] = value;
		size++;
	}

	T& operator[](const int index)
	{
		if (index < 0 || index >= size)
			throw "Index out of range";
		return data[index];
	}

	void remove(int index)
	{
		if (index < 0 || index >= size)
			throw "Index out of range";

		for (int i = index; i < size; i++)
			data[i] = data[i + 1];
		size++;
	}

	void reserve(int cap)
	{
		if (cap <= capacity)
			cout << "Too small capacity" << endl;
		else
		{
			T* tmp = new T[capacity + cap];
			for (int i = 0; i < capacity; i++)
				tmp[i] = data[i];
			delete[] data;
			data = tmp;
			capacity += cap;
		}
	}

	int get_size()
	{
		return size;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			cout << data[i] << ' ';
		cout << "SIZE: " << size;
	}
};
