#include "Array.h"
#include <iostream>
#include <stdarg.h>
using namespace std;

bool Array::isValidIndex(int index) const
{
	if (index >= 0 && index < size)
		return true;
	else
		return false;
}
void Array::initailize()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}
Array::Array(int cap)
{
	cap < 0 ? size = 0 : size = cap;
	if (cap == 0)
	{
		data = nullptr;
	}
	else
	{
		data = new int[size];
		initailize();
	}
}
//Array::Array()
//{
//	data = nullptr;
//	capacity = 0;
//}
Array::~Array()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

int& Array::operator[](int index)
{
	return data[index];
	exit(0);
}
int Array::getSize() const
{
	return size;
}
void Array::reSize(int newCapacity)
{
	if (newCapacity < 0)
	{
		this->~Array();
		size = 0;
		return;
	}
	int* temp = new int[newCapacity];
	int i = 0;
	while (i < size && i < newCapacity)
	{
		temp[i] = data[i];
		i++;
	}
	size = newCapacity;
	this->~Array();
	data = temp;
}
//void Array::display() const
//{
//	if (data != nullptr)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << data[i] << " ";
//		}
//	}
//
//const int Array::num=13;
//Array::Array(int cnt, ...)
//{
//	va_list list;
//	va_start(list, cnt);
//	size = cnt;
//	data = new int[size];// Allocate memory for the data array
//	for (int i = 0; i < cnt; i++)
//	{
//		int val = va_arg(list, int);
//		data[i] = val;
//	}
//	va_end(list);
//}
//int& Array::getSet(int i)
//{
//	if (isValidIndex(i))
//	{
//		return data[i];
//	}
//}
Array::Array(const Array& rfs)
{
	if (rfs.data != nullptr)
	{
		size = rfs.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = rfs.data[i];
		}
	}
}
Array& Array::operator =(const Array& rfs)
{
	if (rfs.data == nullptr)
	{
		data = nullptr;
		size = 0;
		return *this;
	}
	if (&rfs == this)
	{
		return *this;
	}
	this->~Array();
	size = rfs.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = rfs.data[i];
	}
	return *this;
}
const int& Array::operator[](int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
}
//inline int& Array::getSet(int index) const
//{
//	cout << "Const vala " << endl;
//	if (isValidIndex(index))
//	{
//		return data[index];
//	}
//	//at(2) = 5;//In the statement this->data[4] = 7;, this is a pointer to a 
//	//const Array object. This means that the object itself is const, but it doesn't necessarily mean
//	//that its members are also const.
//
//	//In C++, when you have a const object, you're saying that you won't modify the
//	//object itself through that pointer, but you can still modify its non - const members.
//	//this->data[4] = 7;
//	exit(0);
//}

//Array::Array (const Array& ref):Array()
//{
//	if (ref.data != nullptr)
//	{
//		capacity = ref.capacity;
//		data = new int[capacity];
//		for (int i = 0; i < ref.capacity; i++)
//		{
//			data[i] = ref.data[i];
//		}
//	}
//}