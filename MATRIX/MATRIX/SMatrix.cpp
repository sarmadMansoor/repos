//#include <iostream>
//#include "SMatrix.h"
//using namespace std;
//SMatrix::SMatrix() :mat(), n(0)
//{}
//SMatrix::SMatrix(int a) :mat(a, a), n(a)
//{}
//SMatrix::~SMatrix()
//{
//	mat.~Matrix();
//	n = 0;
//}
//SMatrix::SMatrix(const SMatrix& rhs) :mat(rhs.mat),n(rhs.n)
//{
//}
//int SMatrix::getRows() const
//{
//	return mat.getCols();
//}
//int SMatrix::getCols() const
//{
//	return mat.getCols();
//}
//int& SMatrix::at(int a,int b)
//{
//	return mat.at(a, b);
//}
//const int& SMatrix::at(int a,int b) const
//{
//	return mat.at(a, b);
//}
//void SMatrix::display() const
//{
//	mat.display();
//}
//SMatrix::SMatrix(const Matrix &  rfs):mat(rfs)
//{
//	
//}
//SMatrix SMatrix::transpose() const
//{
//	Matrix t = mat.transpose();
//	return SMatrix (t);
//}
//SMatrix SMatrix::add(const SMatrix& other) const
//{
//	Matrix a = mat.add(other.mat);
//	return SMatrix(a);
//}
//SMatrix SMatrix::multiply(const SMatrix& other) const
//{
//	Matrix a = mat.multiply(other.mat);
//	return SMatrix(a);
//}
//void SMatrix::reSize(int a)
//{
//	mat.reSize(a,a);
//}