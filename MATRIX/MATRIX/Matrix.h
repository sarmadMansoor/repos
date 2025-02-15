#ifndef MATRIX_CLASS //MATRIX_H
#define MATRIX_CLASS
#include "Array.h"
class Matrix
{
	Array ** data;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int, int);
	~Matrix();
	Array& operator [](int i);
	//Matrix(const Matrix&);
	//int getRows()const;
	//int getCols()const;
	//int& at(int a, int b);
	//const int& at(int a, int b) const;
	void display() const;
	//Matrix transpose() const;
	//Matrix add( const Matrix &) const;
	//Matrix multiply(const Matrix&) const;
	//void reSize(int a,int b);
};
#endif