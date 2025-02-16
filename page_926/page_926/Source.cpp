#include <iostream>
using namespace std;
class NumDays
{
	int hrs;
	double days;
public:
	NumDays():hrs(0), days (0)
	{
		cout << "NumDays dafault constructor called\n";
	}
	NumDays(int d)
	{
		cout << "NumDays Overloaded constructor called\n";
		days =d;
		hrs = d * 8;
		
	}
	void setHrs(int h)
	{
		if (h >= 0)
		{
			hrs = h;
			days = hrs / 8.0;
		}
	}
	int getHrs() const
	{
		return hrs;
	}
	double getDays() const
	{
		return days;
	}
	NumDays operator + (const NumDays& rhs) const 
	{
		NumDays temp;
		temp.setHrs(getHrs() + rhs.getHrs());
		return temp;
	}
	NumDays operator - (const NumDays& rhs) const 
	{
		NumDays temp;
		temp.setHrs(getHrs() - rhs.getHrs());
		return temp;
	}
	//pre
	NumDays& operator++()
	{
		setHrs(getHrs() + 1);
		return *this;

	}
	//post
	NumDays operator ++ (int a)
	{
		NumDays temp;
		temp.setHrs(getHrs());
		setHrs(getHrs() + 1);
		return temp;
	}
	//pre
	NumDays& operator--()
	{
		setHrs(getHrs() - 1);
		return *this;

	}
	NumDays operator -- (int a)
	{
		NumDays temp;
		temp.setHrs(getHrs());
		setHrs(getHrs() - 1);
		return temp;
	}
	~NumDays()
	{
		cout << "destructor called\n";
	}
};
class TimeOff
{
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays maxTaken;
	NumDays maxUnpaid;
	NumDays unpaidTaken;
	char* name;
	int idNo;
	int strlen(const char* str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			length++;
		}
		return length;
	}
	void  strcpy(char* dest, const char* src)
	{
		int i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0'; // Add null terminator to the destination string
	}
public:

	TimeOff():maxSickDays(),sickTaken(),maxVacation(),
		maxTaken(),maxUnpaid(),unpaidTaken()
	{
		cout << "Time default constructor called\n";
		name = nullptr;
		idNo = 0;
	}
	TimeOff(const char * n,int id,int msd,int st,int mv,int mt,int mup,int upt) :maxSickDays(msd), sickTaken(st), maxVacation(mv),
		maxTaken(mt), maxUnpaid(mup), unpaidTaken(upt)
	{
		cout << "Time overloaded constructor called\n";
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		idNo = id;
	}
	void  setMaxSickDays(NumDays a)
	{
		maxSickDays = a;
	}
	void  setSickTaken(NumDays a)
	{
		sickTaken = a;
	}
	void  setMaxVacation(NumDays a)
	{
		maxVacation = a;
	}
	void  setMaxTaken(NumDays a)
	{
		maxTaken = a;
	}
	void  setMaxUnpaid(NumDays a)
	{
		maxUnpaid = a;
	}
	void  setUnpaidTaken(NumDays a)
	{
		unpaidTaken = a;
	}
	void setName(const char* n)
	{
		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	void setID(int id)
	{
		idNo = id;
	}
	
	~TimeOff()
	{
		cout << "time destructor called\n";
		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}
	}
};
class A
{
	int a=5;
public:
	A()
	{

	}
	virtual void f()
	{
		cout << "A f()\n";
	}

};
class B :public A
{
	int b=1;
	void f()
	{
		cout << "b F ()\n";
	}
public:
	B()
	{

	}
	void f(int )
	{
		cout << "b F ()\n";
	}
};
int main()
{
	A a;
	int* p = (int* ) &a; 
	cout << (int)p << " : "<<(int)&a << endl;
	*p = 3;
	cout << *p << endl;
	p = (int*) (&a);
	cout << *p << endl;
	/*A* p = (A*) new B();
	p->f();*/
}