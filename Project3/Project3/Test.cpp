#include <iostream>
#include "Test.h"
using namespace std;
Test::Test()
{
	cout << " TEST default constructor is called!!  " << this << endl;
	val = 0;
	p = new int;
	*p = 0;
}
Test::Test(int num, int num2)
{
	cout << "TEST Overloaded constructor is called!!   " << this << endl;
	val = num;
	p = new int;
	*p = num2;
}
Test::Test(const Test& origin)
{
	cout << "TEST Copy  constructor is called!!   " << this << endl;
	val = origin.val;
	p = new int;
	*p = *(origin.p);
}
void Test::setVal(int num)
{
	val = num;
}
void Test::setP(int num)
{
	p = new int;
	*p = num;
}
int Test::getVal() const
{
	return val;
}
int	Test::getP() const
{
	return *p;
}
void Test::display()
{
	cout << "values are : " << val << " " << *p << endl;
}
Test::~Test()
{
	cout << "TEST destructor is called !!!   " << this << endl;
	if (p != nullptr)
	{
		delete p;
		p = nullptr;
	}
}
Test Test::operator + (const Test& temp) const 
{
	Test sum;
	sum.val = val + temp.val;
	*(sum.p) = *p + *(temp.p);
	return sum; 
}

Test Test::operator - (const Test& temp) const
{
	Test subtract;
	subtract.val = val - subtract.val;
	*(subtract.p) = *p - *(subtract.p);
	return subtract;
}
Test& Test::operator += (const Test& temp) 
{
	val = val + temp.val;
	*p = *p + *(temp.p);
	return *this;
}

Test& Test::operator -= (const Test& temp)
{
	val = val - temp.val;
	*p = *p - *(temp.p);
	return *this;
}
bool Test::operator ==(const Test& rhs) const
{
	if (val == rhs.val && *p == *(rhs.p))
	{
		return true;
	}
	else
	{
		false;
	}
}
bool Test::operator !=(const Test& rhs) const
{
	if (val == rhs.val && *p == *(rhs.p))
	{
		return false;
	}
	else
	{
		true;
	}
}
Test& Test::operator++()
{
	val = val+1;
	*p=*p+1;
	return *this;
}
Test Test::operator++(int)
{
	Test temp(*this);
	val = val + 1;
	*p = *p + 1;
	return temp;
}
 const Test & Test :: operator = (const Test &rhs)
{
	 cout << "Test Assignment operator !!!" << this << endl;
	 if (this == &rhs)
	 {
		 cout << "Self assignment is being done!!\n";
		 return *this;
	 }
	 else
	 {
		 val = rhs.val;
		 if (p != nullptr)
		 {
			 delete p;
			 p = nullptr;
		 }
		 p = new int;
		 *p = *(rhs.p);
		 return *this;
	 }
}
 Test Test::operator - ()
 {
	 Test temp;
	 temp.val = -val;
	 *(temp.p) = -(*p);
	 return temp;
 }
