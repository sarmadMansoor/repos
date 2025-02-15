#include <iostream>
#include "Matrix.h"
using namespace std;
Matrix::Matrix()
{
	data = nullptr;
	rows = 0;
	cols = 0;
}
Matrix::Matrix(int a, int b):Matrix()
{
	rows = a;
	cols = b;
	data  = new Array * [rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new Array (cols);
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0;
		}
	}
}
Matrix::~Matrix()
{
	if (data != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete data;
		data = nullptr;
		rows = 0;
		cols = 0;
	}
}
Array& Matrix::operator [](int i)
{
	return *(data[i]);
}
//Matrix::Matrix(const Matrix& rhs):Matrix()
//{
//	if (rhs.data != nullptr)
//	{
//		rows = rhs.rows;
//		cols = rhs.cols;
//		data = new int* [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			data[i] = new int[cols];
//		}
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				data[i][j] = rhs.data[i][j];
//			}
//		}
//	}
//	
//}
//int Matrix::getRows( ) const
//{ 
//	return rows;
//}
//int Matrix::getCols() const
//{
//	return cols;
//}
//int& Matrix:: at(int a, int b)
//{
//	if(a<getRows() && b<getCols())
//		return data[a][b];
//	exit(0);
//}
//const int& Matrix::at(int a, int b) const 
//{
//	if (a < getRows() && b < getCols())
//		return data[a][b];
//	exit(0);
//}
void Matrix::display() const
{
	/*for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << (*this)[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
}
//Matrix Matrix::transpose() const
//{
//	Matrix result(cols, rows);
//
//	for (int i = 0; i < cols; i++)
//	{
//		for (int j = 0; j < rows; j++)
//		{
//			result.at(i,j) = at(j,i);
//		}
//	}
//
//	return result;
//}
//Matrix Matrix::add(const Matrix& other) const
//{
//	if (rows != other.rows || cols != other.cols)
//	{
//		return Matrix();//exit(0)
//	}
//	Matrix result(rows, cols);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			result.data[i][j] = data[i][j] + other.data[i][j];
//		}
//	}
//
//	return result;
//}
//Matrix Matrix::multiply(const Matrix& other) const
//{
//	if (cols != other.rows)
//	{
//		return Matrix();
//	}
//	Matrix result(rows, other.cols);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < other.cols; j++)
//		{
//			for (int k = 0; k < cols; k++)
//			{
//				result.data[i][j] += data[i][k] * other.data[k][j];
//			}
//		}
//	}
//	return result;
//}
//void Matrix::reSize(int a, int b)
//{
//	if (a <= 0 || b <= 0)
//	{
//		return;
//	}
//	int** newData = new int* [a];
//	for (int i = 0; i < a; i++)
//	{
//		newData[i] = new int[b];
//	}
//	for (int i = 0;( i < rows&&i< a); i++)
//	{
//		for (int j = 0;( j < cols&&j< b); j++)
//		{
//			newData[i][j] = at(i,j);
//		}
//	}
//
//	this->~Matrix();
//	rows = a;
//	cols = b;
//	data = newData;
//}