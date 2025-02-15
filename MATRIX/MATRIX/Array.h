#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<stdarg.h>
using namespace std;

class Array
{
	int size;
	int* data;
	void copyArray(Array*, int*);
public:
	Array(int, ...);
	//Array(int);
	Array(const Array&);
	~Array();
	int& operator[](int);
	const int& operator[](int) const;
	int getSize() const;
	void reSize(int);
};

#endif // !ARRAY_H