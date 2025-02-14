#include"Matrix.h"

void Matrix::copyMatrix(Matrix& source, Matrix dest)
{
	for (int i = 0; i < dest.rows && i < source.rows; i++)
	{
		for (int j = 0; j < dest.cols && j < source.cols; j++)
		{
			source.data[i][j] = dest.data[i][j];
		}
	}
}
Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	data = nullptr;
}

Matrix::Matrix(int r, int c) :Matrix()
{
	if (r <= 0 || c <= 0)
	{
		return;
	}
	rows = r;
	cols = c;
	data = new Array * [r];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new Array(cols);
	}
}

Matrix::Matrix(const Matrix& ref)
{
	rows = ref.rows;
	cols = ref.cols;
	reSize(rows, cols);
	copyMatrix(*this, ref);
}

Matrix::~Matrix()
{
	rows = 0;
	cols = 0;
	for (int i = 0; i < cols; i++)
	{
		delete data[i];
	}
	delete data;
	data = nullptr;
}

Array& Matrix::operator[](int index)
{
	return *data[index];
}

const Array& Matrix::operator[](int index) const
{
	return *data[index];
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getCols() const
{
	return cols;
}

void Matrix::display() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << (*data[i])[j]<<"   ";
		}
		cout << endl;
	}
}

Matrix Matrix::transpose() const
{
	Matrix transpose{ cols,rows };
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			transpose.data[i][j] = data[j][i];
		}
	}
	return transpose;
}

//Matrix Matrix::add(const Matrix& mat2) const
//{
//	if ((rows != mat2.rows) && (cols != mat2.cols))
//	{
//		cout << "Addition not possible";
//		exit(0);
//	}
//	Matrix add{ cols,rows };
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			add.data[i][j] = mat2.data[i][j] + data[i][j];
//		}
//	}
//	return add;
//}

//Matrix Matrix::multiply(const Matrix& mat2) const
//{
//	if (cols != mat2.rows)
//	{
//		cout << "Multiplication not possible";
//		exit(0);
//	}
//	Matrix resultantMatrix{ rows,mat2.cols };
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < mat2.cols; j++)
//		{
//			resultantMatrix.data[i][j] = 0;
//			for (int k = 0; k < cols; k++)
//			{
//				resultantMatrix.data[i][j] += data[i][k] * mat2.data[k][j];
//			}
//		}
//	}
//	return resultantMatrix;
//}

void Matrix::reSize(int r, int c)
{
	if (r <= 0 || c <= 0)
	{
		return;
	}
	Matrix temp{ r,c };
	copyMatrix(temp, *this);
	this->~Matrix();
	data = temp.data;
	temp.data = nullptr;
	rows = r;
	cols = c;
}
