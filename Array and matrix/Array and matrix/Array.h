#ifndef MY_ARRAY
#define MY_ARRAY
#include <iostream>
#include <fstream>
using namespace std;
class Array
{
	friend ostream& operator << (ostream& rfs, Array& r);

private:
	//const int num;
	int* data;
	int size;
	bool isValidIndex(int) const;
	void initailize();
public:
	//Array(int = 0);
	Array(int cnt, ...);
	~Array();
	Array(const Array&);
	int getSize() const;
	//void insert(int );
	//int& getSet(int );
	void reSize(int);
	//void display() const ;
	int& operator[](int index);
	const int& operator[](int index) const;
	Array& operator =(const Array& rfs);

};
#endif 
