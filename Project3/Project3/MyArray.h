#ifndef MY_ARRAY
#define MT_ARRAY
#include <iostream>
using namespace std;
template <class T>
class MyArray
{
private:
	T* aptr;
	int arraySize;
	void subscriptError();
public:
	MyArray(int);
	MyArray(const MyArray&);
	~MyArray();
	void display()const;
	int size()const
	{
		return arraySize;
	}
	//const MyArray<T>& operator = (const MyArray<T>& rhs)
	T & operator[](const int&);
};

 template <class T>
 void MyArray<T>::display() const 
 {
	 for (int i = 0; i < arraySize; i++)
	 {
		 cout << aptr[i] << "\t";// << endl;
	 }
	 cout << endl;
 }
template<class T>
T& MyArray<T>::operator[](const int& sub)
{
	if (sub < 0 || sub >= arraySize)
		subscriptError();
	return aptr[sub]; 
}

template<class T>
MyArray<T>::MyArray(const MyArray& obj)
{
	arraySize = obj.arraySize;
	aptr = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		*(aptr + i) = *(obj.aptr + count); 
	}
}

template<class T>
MyArray<T>::MyArray(int s)
{
	arraySize =s;
	aptr = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		*(aptr + i) = 0;//complex step first it create a Point which contain 0 , 0 by 1 parameter constructor
		//then it call assigment of point 
	}
}


template<class T>
void MyArray<T>::subscriptError()
{
	cout << "ERROR: Subscript out of range\n";
	exit(0);
}

template <class T>
MyArray<T>::~MyArray()
{
	if (aptr != nullptr)
	{
		delete[] aptr;
		aptr = nullptr;
	}
}
//template<class T>
//const MyArray<T>& MyArray::operator = (const MyArray<T>& rhs)
//{
//	if (this == &rhs)
//	{
//		return *this;
//	}
//	else
//	{
//		if (aptr != nullptr)
//		{
//			delete[] aptr;
//			aptr = nullptr;
//		}
//		arrrySize = rhs.arraySize;
//		aptr = new T [arrrySize];
//		for (int i = 0; i < arraySize; i++)
//		{
//			aptr[i] = 0;
//		}
//		return *this;
//	}
//}

/*\
* 
* const int & MyArray::operator [] (const int i )
* {
*		retunrn aptr[i];
* }
*/



#endif 