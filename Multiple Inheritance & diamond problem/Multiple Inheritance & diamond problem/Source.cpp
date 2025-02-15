#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class A
{
	int aInt;
public:
	A():aInt(0)
	{
		cout << "A,s Default Constructor is called!!\n";
	}
	A(int a) :aInt(a)
	{
		cout << "A,s Overloaded Constructor is called!!\n";
	}
	virtual void display()
	{
		cout << "the Value of A,s member variable is : " << getA() << endl;
	}
	int getA()
	{
		return aInt;
	}
	void setA(int a)
	{
		aInt = a;
	}
	virtual const A& operator = (const A& rhs)
	{
		cout << "A,s = operator is called\n";
		aInt = rhs.aInt;
		return *this;
	}
	 virtual void f()
	{
		cout << "a" << endl;
	}
	~A() 
	{
		cout << "A,s  Destructor is called!!\n";
	}
};


class B : virtual  public A
{
	int BInt;
public:
	 void f()
	{
		cout << "b" << endl;
	}
	B() :BInt(0), A(0)
	{
		cout << "B,s Default Constructor is called!!\n";
	}
	B(int a) :BInt(a),A(1122)
	{
		cout << "B,s Overloaded Constructor is called!!\n";
	}
	void display()
	{
		A::display();
		cout << "the Value of B,s member variable is : " << getB() << endl;
	}
	int getB()
	{
		return BInt;
	}
	void setB(int a)
	{
		BInt = a;
	}
	const B& operator = (const B& rhs)
	{
		A::operator=(rhs);
		cout << "B,s = operator is called\n";
		BInt = rhs.BInt;
		return *this;
	}
	~B()
	{
		cout << "B, s  Destructor is called!!\n";
	}
};


class C : virtual public A
{
	int CInt;
public:
	void f()
	{
		cout << "c" << endl;
	}
	C() :CInt(0), A(0)
	{
		cout << "C,s Default Constructor is called!!\n";
	}
	C(int a) :CInt(a), A(15)
	{
		cout << "C,s Overloaded Constructor is called!!\n";
	}
	void display()
	{
		A::display();
		cout << "the Value of C,s member variable is : " << getC() << endl;
	}
	int getC()
	{
		return CInt;
	}
	void setC(int a)
	{
		CInt = a;
	}
	const C& operator = (const C& rhs)
	{
		A::operator=(rhs);
		cout << "C,s = operator is called\n";
		CInt = rhs.CInt;
		return *this;
	}
	~C()
	{
		cout << "C,s  Destructor is called!!\n";
	}
};



class D :public B,public C
{
	int DInt;
public:
	void f()
	{
		cout << "d" << endl;
	}
	D() :DInt(),B(),C()
	{
		cout << "D,s Default Constructor is called!!\n";
	}
	D(int b, int c, int d) :B(b),C(c),DInt(d)
	{
		cout << "D,s Overloaded Constructor is called!!\n";
	}
	void display()
	{
		B::display();
		C::display();
		cout << "the Value of D,s member variable is : " << getD() << endl;
	}
	int getD()
	{
		return DInt;
	}
	void setD(int a)
	{
		DInt = a;
	}
	const D& operator = (const D& rhs)
	{
		B::operator=(rhs);
		C::operator=(rhs);
		cout<< "D,s = operator is called\n";
		DInt = rhs.DInt;
		return *this;
	}
	~D()
	{
		cout << "D,s  Destructor is called!!\n";
	}
};

















class Shape
{
protected:
	int border;
public:
	Shape(int a) :border(a)
	{
		cout << "Shape Overloaded constructor is called\n";
	}
	virtual ~Shape()
	{
		cout << "Shape destructor is called\n";
	}
	virtual void displayArea()
	{
	}
	Shape (const Shape & rhs):border(rhs.border)
	{
		cout << "Shape Copy Constructor is Called\n";
	}
	const Shape& operator =(const Shape& rhs)
	{
		cout << "Shape =operator is called\n";
		border = rhs.border;
		return *this;
	}
};

class Rectangle :public Shape
{
	double length, width;
public:
	Rectangle(int l, int w, int b) :length(l), width(w), Shape(b)
	{
		cout << "Rectangle  Overloaded construtor is called\n";
	}
	void displayArea()
	{
		cout << "Rectangle's area is : " << length * width << endl;
	}
	~Rectangle()
	{
		cout << "Rectangle destructor is called \n";
	}
	Rectangle(const Rectangle& rhs) :length(rhs.length), width(rhs.width), Shape(rhs)
	{
		cout << "Copy constructor is called" << endl;
	}
	const Rectangle& operator =(const Rectangle&rhs)
	{
		Shape::operator=(rhs);
		length = rhs.length;
		width = rhs.width;
		return *this;
	} 
	bool isSquare()
	{
		if (length == width)
			return true;
		else
			return false;
	}

};
class Triangle :public Shape
{
	double s1, s2, s3;
public:
	Triangle(double t1, double t2, double t3, int bdr) :s1(t1), s2(t2), s3(t3), Shape(bdr)
	{
		cout << "Triangle Overloaded constructor is called \n";
	}
	void displayArea()
	{
		double s = (s1 + s2 + s3) / 2;
		double area = sqrt(s * (s - s1) * (s - s2) * (s - s3));
		cout << "Triangle's area is  :  " << fixed << setprecision(2) << area << endl;
	}
	~Triangle()
	{
		cout << "Triangle destructor is called \n";
	}
	Triangle(const Triangle& rhs) :s1(rhs.s1), s2(rhs.s2), s3(rhs.s3), Shape(rhs)
	{
		cout << "TRIANGLE COPY CONSTRUCTOR IS CALLED\n";
	}
	const Triangle& operator =(const Triangle& rhs)
	{
		Shape ::operator=(rhs);
		s1 = rhs.s1;
		s2 = rhs.s2;
		s3 = rhs.s3;

		return *this;
	}
	bool isEquileteral()
	{
		if ((s1 == s2) && (s2 == s3))
			return true;
		else
			return false;
	}
};

class Canvas
{
	Shape* p;
public:
	Canvas(Shape* rhs) :p(rhs)
	{
		cout << "Canvas overloaded constructor is called\n";
	}
	Canvas(const Canvas& rhs)
	{
		cout << "Canvas Copy Constructor is called\n" << endl;
		Rectangle * temp = dynamic_cast<Rectangle*>(rhs.p);
		if (temp != nullptr)
		{
			p = new Rectangle(*temp);
		}
		Triangle* temp1 = dynamic_cast<Triangle*>(rhs.p);
		if (temp1 != nullptr)
		{
			p = new Triangle(*temp1);
		}
	}
	void display()
	{
		p->displayArea();
	}
	~Canvas()
	{
		cout << "Canvas Destructor is called\n";
		if (p != nullptr)
		{
			delete p;
			p = nullptr;
		}
	}
	const Canvas& operator = (const Canvas& rhs)
	{
		cout << "Canvas assigment operator is called\n";
		if (this == &rhs)
		{
			cout << "Canvas Self Assigment \n";
		}
		else
		{
			if (p != nullptr)
			{
				delete p;
				p = nullptr;
			}
			Rectangle* rp = dynamic_cast<Rectangle*> (rhs.p);
			if (rp != nullptr)
			{
				p = new Rectangle(*rp);
			}
			Triangle * tp= dynamic_cast<Triangle*> (rhs.p);
			if (tp != nullptr)
			{
				p = new Triangle(*tp);
			}

		}
		return *this;
	
	}
};
int main()
{
	/*D d1(1,2,3);
	cout << "---------------------------------------------\n";
	D d;
	cout << "---------------------------------------------\n";
	d = d1;
	cout << "---------------------------------------------\n";
	d.display();
	cout << "---------------------------------------------\n";
	d1.display();
	cout << "---------------------------------------------\n";*/

	/*A* p = new D(1, 2, 3);
	cout << "---------------------------------------------\n";
	p->f();*/
	//p->display();
	//A* p1 = new D(11, 22, 33);
	//cout << "---------------------------------------------\n"; 
	//*p1 = *p;
	//cout << "---------------------------------------------\n"; 
	//p1->display();
	//cout << "---------------------------------------------\n"; 

	/*Triangle t1(3, 4, 5, 4);
	cout << "---------------------------------------------\n";
	t1.displayArea();
	cout << "---------------------------------------------\n";


	Rectangle r1(10, 20, 3);
	cout << "---------------------------------------------\n";
	r1.displayArea();
	cout << "---------------------------------------------\n";*/


	int val;
	cout << "Enter 1 to create a Rectangle, Enter 2 to create a Triangle: ";
	cin >> val;
	Shape* rp = nullptr;
	if (val == 1)
	{
		int length, width,bdr;
		cout << "Enter the value of length and width and bdr: ";
		cin >> length >> width>>bdr;
		rp = new Rectangle(length, width, bdr);
	}
	else if (val == 2)
	{
		int s1,s2,s3, bdr;
		cout << "Enter the value of s1 & s2 & s3 & bdr: ";
		cin >> s1 >> s2 >> s3>>bdr;
		rp = new Triangle(s1, s2,s3, bdr);
	}

	


	rp->displayArea();


	//we want to call derived class specific function from 
	// base class pointer 



	//Solution 1
	/*if (typeid(*rp) == typeid(Rectangle))
	{
		Rectangle* p;
		p = static_cast<Rectangle*>(rp);
		bool flag=p->isSquare();
		if (flag)
		{
			cout << "it is a square\n";
		}
		else
		{
			cout << "it is not a square";
		}
	}


	if (typeid(*rp) == typeid(Triangle))
	{
		Triangle * p;
		p = static_cast<Triangle*>(rp);
		bool flag = p->isEquileteral();
		if (flag)
		{
			cout << "it is a equileteral Triangle\n";
		}
		else
		{
			cout << "it is not a equileteral Triangle";
		}
	}*/


	Rectangle* p = nullptr;
	p=dynamic_cast<Rectangle*>(rp);
	if (p != nullptr)
	{
		if ((p->isSquare()))
			cout << "it is a square\n";
		else
			cout << "it is a not square\n";
	}

	Triangle* p1 = nullptr;
	p1 = dynamic_cast<Triangle*>(rp);//behavior of dynamic_cast is explain in lecture 24 by ahmd Ghazali
	if (p1 != nullptr)
	{
		if ((p1->isEquileteral()))
			cout << "it is a equileteral Triangle\n";
		else
			cout << "it is a not  equileteral Triangle\n";
	}
	cout << "-------------------------------------------------------------------------\n";

	Canvas c1(rp);
	c1.display();

	cout << "-------------------------------------------------------------------------\n";
	Canvas c2(c1);
	cout << "-------------------------------------------------------------------------\n";
	c2 = c1;
	cout << "-------------------------------------------------------------------------\n";
}