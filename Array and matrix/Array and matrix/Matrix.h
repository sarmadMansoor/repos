#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include"Array.h"
using namespace std;

class Matrix
{
	int rows, cols;
	Array** data;
	void copyMatrix(Matrix&, Matrix);
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	Array& operator[](int index);
	const Array& operator[](int index) const;
	int getRows() const;
	int getCols() const;
	void display() const;
	Matrix transpose() const;
	//Matrix add(const Matrix &) const;
	//Matrix multiply(const Matrix &) const;
	void reSize(int, int);

};
#endif // !MATRIX_H