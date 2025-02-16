#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include <iomanip>
using namespace std;
class HUM
{
	int num;
public:
	virtual void f()
	{
		cout << "HUM ka f ho\n";
	}
	virtual void g()
	{
		cout << "HUM ka g ho\n";
	}
	virtual void m()
	{
		cout << "HUM ka m ho\n";
	}
};
class TUM
{
	int num;
public:
	virtual int x(int i)
	{
		cout << "TUM ka x ho\n";
		return 1;
	}
	virtual void y()
	{
		cout << "TUM ka y ho\n";
	}
};
/*
* TUM obj;
	HUM* p = (HUM*)&obj;
	p->m(); test karo
*/


//multiple inheritance + polymerphism
class num
{
	int a, b;
public:
	num()
	{
		cout << "num ctor\n";
	}
	virtual void f()
	{
		cout << "num ka F\n";
	}
	void numF()
	{
	}
	~num()
	{
		cout << "num dtor\n";
	}
};
class mum:public num
{
	int  k;
public:
	void f()
	{
		cout << "mum ka F\n";
	}
	mum()
	{
		cout << "mum ctor\n";
	}
	void mumF() {};
	~mum()
	{
		cout << "mum dtor\n";
	}
};
class kum
{
	int f, k;
public:
	kum()
	{
		cout << "kum ctor\n";
	}
	void kumF() {};
	~kum()
	{
		cout << "kum dtor\n";
	}
};
class sum :public mum,public num,public kum
{
	int o;
public:
	sum()
	{
		cout << "sum ctor\n";
	}
	void sumF() {};
	~sum()
	{
		cout << "sum dtor\n";
	}
};
class X1
{
	int x;
public:
	X1()
	{
		cout << "X1's ctor\n";
	}
	X1(int a):x(a)
	{
		cout << x << "\t";
		cout << "X1's ctor\n";
	}
	/*virtual void f()
	{
		cout << "A's F\n";
	}*/
	virtual ~X1()
	{
		cout << "X1's Dtor\n";
	}
};
class A1: virtual public X1
{
	int a;
public:
	A1(int p):X1(12),a(p)
	{
		cout << a << "\t";
		cout << "A1's ctor\n";
	}
	/*virtual void f()
	{
		cout << "A's F\n";
	}*/
	 ~A1()
	{
		cout << "A1's Dtor\n";
	}
};
class B1 :virtual public X1
{
	int b;
public:
	B1(int a):X1(10),b(a)
	{
		cout << b << "\t";

		cout << "B1's ctor\n";
	}
	/*virtual void f()
	{
		cout << "A's F\n";
	}*/
	~B1()
	{
		cout << "B1's Dtor\n";
	}
};
class C1:public A1,public B1
{
	int c;
public:
	C1(int m):A1(1),B1(2),X1(3),c(m)
	{
		cout << c << "\t";
		cout << "C1's ctor\n";
	}
	/*virtual void f()
	{
		cout << "A's F\n";
	}*/
	~C1()
	{
		cout << "C1's Dtor\n";
	}
};
class M;
class T
{
	friend class M;
public :
	virtual void f()
	{
		cout << "T ka F\n";
	}
};
class H:public T
{
public:
	void f()
	{
		cout << "H ka F\n";
	}
};
class M
{
public:
	void k()
	{
		T* p = new T;
		p->f();
	}
};
class base
{
public:

	virtual void fun()
	{
		cout << "base ka fun\n";
	}
	/*virtual void f() = 0;
	virtual ~base() = 0;*/
};
//void base::f()
//{
//	cout << "base ka f\n";
//}
//base::~base()
//{
//	cout << "~base \n";
//}
class derive:private base
{
public:
	void fun()
	{
		cout << "derive ka fun\n";
		base* p = new derive;
		//p->fun();
	}
	/*derive  * f() 
	{
		cout << "base ka f\n";
		return this;
	}*/
	/*base * g()
	{
		return f();
	}*/

	//virtual void f() {};
	//virtual ~derive() {};

};
class P
{
public :
	P()
	{
		cout << "p ka ctor\n";
		f();
	}
	virtual void f()
	{
		cout << " p ka f\n";
	}
};
class Q:public P
{
public:
	Q()
	{
		cout << "Q ka ctor\n";
		f();
	}
	void f()
	{
		cout << "Q ka f \n";
	}
	/*virtual void g()
	{
		cout << "Q ka g";
	}
	virtual void f() override
	{
		cout << "Q ka f\n";
	}*/
};
class R:public Q
{
public:
	R()
	{
		f();
		cout << "R ka ctor \n";
	}
};
//class halo
//{
//
//};
class shape
{
public:
	shape()
	{

	}
	shape(shape& rfs)
	{

	}
	virtual shape* clone()  = 0;
};
class circle:public shape 
{
	int* num;
public :
	circle()
	{
		num = new int[5];
	}
	circle(circle& rfs):shape(rfs)
	{
		num = new int[5];
	}
	virtual shape* clone() 
	{
		return new circle(*this);
	}
};
class Fred {
	shape* p_;
public:
	Fred(shape* p)
	{
		cout << "Default ctor\n";
		p_ = p;
	}
	~Fred()
	{
		if (p_ != nullptr)
		{
			delete p_;
			p_ = nullptr;
		}
	}
	Fred(const Fred& rfs) :p_(rfs.p_->clone())
	{
		cout << "Cpy Fred ctor\n";
	}
	Fred& operator =(const Fred& rfs)
	{
		if (this != &rfs)
		{
			delete p_;
			p_ = rfs.p_->clone();
		}
		return *this;
	}
};


class Sajjad
{
public:
	Sajjad()
	{
		cout << "Sajjad Ctor\n";
	}
	virtual ~Sajjad() = 0;
	Sajjad(const Sajjad & )
	{
		cout << "Sajjad copy Ctor\n";
	} 
	Sajjad(const  Sajjad&& )
	{
		cout << "Sajjad && Ctor\n";
	}
	void operator = (const Sajjad&)
	{
		cout << "Sajjad operator = is called\n";

	}
	void operator = ( Sajjad&& )
	{
		cout << "Sajjad operator && is called\n";

	}
	virtual void  f()
	{
		cout << "S sajjad f\n";
	}
};
//Sajjad::~Sajjad()
//{
//
//}
class Sarmad:public Sajjad
{
	int a;
public:
	 void  f() override
	{
		cout << "Sarmad sajjad f\n";
	}
	void f(int)
	{
		 cout << "Sarmad sajjad f\n";
	}
	Sarmad()
	{
		cout << "Sarmad Ctor \n";
	}
	Sarmad(const Sarmad & a):Sajjad(move(a))
	{
		cout << "Sarmad copy Ctor \n";
	}
	Sarmad(const  Sarmad &&)
	{
		cout << "Sarmad move copy  Ctor \n";
	}
	void operator = (const Sarmad  & )
	{
		cout << "operator = is called  \n";
	}
	void operator = (const Sarmad&& a)
	{
		Sajjad::operator=(a);
		cout << " Sarmad operator = && is called  \n";
	}
	/*~Sarmad()
	{
		cout << "Sarmad Dtor \n";
	}*/
};


//#include <iostream>
//
//class B;  // Forward declaration of class B
//
//class A {
//public:
//	virtual void display() {
//		std::cout << "Inside A::display\n";
//	}
//	friend void B::show();  // B::show is a friend of A
//};
//
//class B 
//{
//public:
//	 void show() 
//	 {
//		cout << "B ka show\n";
//		 // Can access private members of A because B::show is a friend of A
//	}
//};
//
//class C : public A {
//public:
//	void display() override {
//		std::cout << "Inside C::display\n";
//	}
//	//void show(A& a) {
//	//	cout << "C vala show\n";
//	//	a.display();  // Can access private members of A because B::show is a friend of A
//	//}
//};
//class A;
//class C
//{
//public:
//	void Cx()
//	{
//		cout << "C ka CX \n";
//	}
//	C()
//	{
//
//	}
//	/*C(A p)
//	{
//		cout << " c ctor ka a vala\n";
//	}*/
//};
//class A
//{
//	/*A & p;*/
//public:
//	//friend void C::Cx();
//	A()
//	{
//		cout << "A ka ctor\n";
//	}
//	A(C p)
//	{
//		cout << "A ka c Vala C ctor ctor \n";
//	}
//	void f()
//	{
//		cout << "A ka f\n";
//		//k();
//	}
//	void f() const
//	{
//		cout << "A ka f const \n";
//		//k();
//	}
//	virtual void k()
//	{
//		cout << "K A ka Sarmad 5\n";
//	}
//};
//class B:public A
//{
//public:
//	void k()
//	{
//		cout << "K ka f \n";
//	}
//};
	



//class D:public C
//{
//public:
//	virtual void Dx()
//	{
//		cout << "D ka DX \n";
//	}
//};
class guest
{
public:
	guest()
	{
		cout << "Guest ctor\n";
	}
	~guest()
	{
		cout << "~Guest dtor\n";
	}
	guest(const guest & a)
	{
		cout << "Guest  copy ctor\n";
	}
	guest( guest && a)
	{
		cout << "Guest  move ctor\n";
	}
	void operator =(const guest& a)
	{
		cout << "guest operator = is called\n";
	}
	void operator =( guest &&    a)
	{
		cout << "guest operator move = is called\n";
	}
};
class host
{
	guest a;
public:
	host()
	{
		cout << "host ctor\n";
	}
	~host()
	{
		cout << "~host dtor\n";
	}
	host(const host & m):a(m.a)
	{
		cout << " host copy ctor\n";
	}
	host(host&& m):a(move(m.a))
	{
		cout << "host  move ctor\n";
	}
	/*void operator =(const host & m)
	{
		a = m.a;
		cout << "host operator = is called\n";
	}*/
	void operator =( const host && m)
	{
		a = move(m.a);
		cout << "host operator move = is called\n";
	}
};
class host1:public guest
{
public:
	host1()
	{
		cout << "host ctor\n";
	}
	~host1()
	{
		cout << "~host dtor\n";
	}
	host1(const host1& m):guest(m)
	{
		cout << " host copy ctor\n";
	}
	host1(host1&& m) :guest(move(m))
	{
		cout << "host  move ctor\n";
	}
	/*void operator =(const host1 & m)
	{
		a = m.a;
		cout << "host1 operator = is called\n";
	}*/
	void operator =(const host1&& m)
	{
		guest::operator=(m);
		cout << "host1 operator move = is called\n";
	}
};
class A
{
	int a;
public:
	A(int n) :a(n)
	{
		cout << "A's ctor\n";
	}
	virtual void f()
	{
		cout << "A's F\n";
	}
	 ~A()
	{
		cout << "A's Dtor\n";
	}
};
class B
{
	int b;
public:
	B(int k = 0) 
	{
		cout << "B's ctor\n";
	}
	virtual void f()
	{
		cout << "B's F\n";
	}
	 ~B()
	{
		cout << "B's Dtor\n";
	}
};
class C : public A ,public B
{
	int c;
public:
	C(int f) :A(1), c(f),B(0)
	{
		cout << "C's ctor\n";
	}
	virtual void f()
	{
		cout << "C's F\n";
	}
	 ~C()
	{
		cout << "C's Dtor\n";
	}
};
//class D :public B, public C
//{
//	int d;
//public:
//	D(int f) :A(f), B(f), C(f)
//	{
//		cout << "D's ctor\n";
//	}
//	virtual ~D()
//	{
//		cout << "D's Dtor\n";
//	}
//	/*virtual void f()
//	{
//		cout << "D's F\n";
//	}*/
//};
class Public
{
public:
	int a; int b;
};
class	Quiz
{
public:
	int a;
	Quiz(int i = 1)
	{ 
		a = i;
		cout << "\nQuiz() " << a;
	}
	Quiz(const Quiz& ref)
	{
		a = ref.a;
		cout << "\nQuiz(const Quiz & ) " << a;
	}
	~Quiz()
	{
		cout << "\n~Quiz() " << a;
	}

};
Quiz f(Quiz a, Quiz b, Quiz& c)
{
	static Quiz y(23);
	Quiz x(24);
	return x;
}
void g()
{
	static Quiz z(100);
}

void wow(Quiz& s)
{

}
//Quiz g1(10);
//static Quiz g2(11);
//Quiz g3(12);
struct Tom
{
	int mem = 4;
	Tom(int x = 1)
	{
		cout << "\nTom()" << mem;
		mem = x;
	}
	Tom(const Tom& ref)
	{
		cout << "\nTom(Tom &) " << mem;
	}
	~Tom()
	{
		cout << "\n~Tom()" << mem;
	}
	void print()
	{
		cout << "\nmem = " << mem;
	}
	Tom add(Tom t)
	{
		Tom s;
		s.mem = mem + t.mem;
		return s;
	}
	Tom multiply(Tom t)
	{
		Tom s;
		s.mem = mem * t.mem;
		return s;
	}
	Tom sub(const Tom& t)
	{
		Tom s;
		s.mem = mem - t.mem;
		return s;
	}
};
struct Quiz1
{
	int a;
	Quiz1()
	{
		cout << "\nDef Ctor";
	}
	Quiz1(const Quiz1&)
	{
		cout << "\nconst Quiz1 & ";
	}
	Quiz1( Quiz1 &)
	{
		cout << "\nQuiz1 & ";
	}
};
void Fquiz1(Quiz1)
{
	cout << "\nf(Quiz)1";
}
void Fquiz1(Quiz1 & )
{
	cout << "\nf(Quiz & )1";
}
struct Butter
{
	virtual void letsApplyButter()
	{
		cout << "\nButter Applied";
	}
	virtual void letsApplyButterNTimes(int n)
	{
		for (int i = 1; i <= n; i++)
			letsApplyButter();
	}
	virtual void letsWorkAndButter()
	{
		letsApplyButter();
		cout << "\nNow Work";
	}
	virtual void letsWorkOnly() final
	{
		cout << "\nWr do Work Honestly and pray to GOD for good results";
	}
	virtual void g()
	{
		cout << "\nButter vala g";
	}
	virtual void f()
	{
		cout << "\nButter vala f";
		g();
	}
};
class ButteringCounter :public Butter
{
	int bCount = 0;
public:
	virtual void g()
	{
		cout << "\nButteringCounter vala g";
	}
	void letsApplyButter() override
	{
		bCount = bCount + 1;
		Butter::letsApplyButter();
	}
	void letsApplyButterNTimes(int n)override
	{
		bCount = bCount + 1;
		Butter::letsApplyButterNTimes(n);
	}
	void letsWorkAndButter() override
	{
		bCount = bCount + 1;
		Butter::letsWorkAndButter();
	}
	int getButteringCount()
	{
		return bCount;
	}
	void m()
	{
		Butter::f();
	}
};
class Set5
{
public:
	int* arr;
	Set5()
	{
	}
	void setElements()
	{
		arr = new int[5];
		for (int i = 0; i < 5; i++)
		{
			cout << "enter elements: " << endl;
			cin >> arr[i];
		}
	}
	Set5(const Set5& obj)
	{
		arr = new int[5];
		for (int i = 0; i < 5; i++)
			arr[i] = obj.arr[i];
	}
	void operator ++()
	{
		for (int i = 0; i < 5; i++)
		{
			arr[i] = arr[i]++;
		}
	}
	void display()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Value: " << arr[i] << endl;
			cout << "Address: " << &arr[i] << endl;
		}
	}
};
class A123
{
	int i, j;

public:
	A123(int a)
	{
		cout << "def dtor\n";
	}
	A123(int a, int b) {};
	A123() {};
};
class Singeletion
{
	static String * p;
	Singeletion()
	{

	}
	Singeletion(const Singeletion& a)
	{

	}
	~Singeletion()
	{

	}
public:
	static String* create()
	{
		if (p == nullptr)
		{
			p = new String{};
		}
		return p;
	}
	static void remove()
	{
		if (p != nullptr)
		{
			delete p;
			p = nullptr;
		}
	}
};
	


class sir
{
public:
	virtual void f()
	{
		cout << "Sir ka f\n";
	}
};
class student:private sir
{public:
	void f(int, int)
	{
		cout << "Student ka int int \n";
	}
private :

	void f()
	{
		cout << "student ka f\n";
	}
};
class hum
{

};
struct chlo
{
	virtual void f()
	{

	}
};
struct chlo1:public chlo
{
	virtual void f()
	{

	}
};
struct chlo2:public  chlo1
{

};
int main()
{
	cout << sizeof(chlo2) << endl;
	/*student a;
	sir* p = (sir*)&a;
	p->f();*/
	/*String * p = Singeletion::create();
	p->display();*/
	//A123 x[3] = { A123(12),A123(30) };
	/*Set5 s1;
	s1.setElements();
	Set5 s2(s1);
	++s1;
	cout << "Display values of s1: " << endl;
	s1.display();
	cout << "Display values of s2: " << endl;
	s2.display();*/

//	ButteringCounter b;
//	b.letsApplyButterNTimes(2);
//	cout << b.getButteringCount() << endl;
	//Fquiz1(Quiz1());
	
	//Tom t1(5), t2;
	//cout << "\n-----------\n";
	//t1.add(5);
	//cout << "\n-----------\n";
	//t1.sub(12).print();
	//cout << "\n-----------\n";
	//t1.add(t1).print();
	//cout << "\n-----------\n";
	//cout << "\n-----------\n";

	////Tom t3(t1.multiply(t2));

	//cout << "\n-----------\n";
	//cout << "\n-----------\n";



	/*Quiz r, s(2), t(3);
	cout << "\n-----------\n";

	f(r, s, t);
	cout << "\n-----------\n";
	wow(r);
	cout << "\n-----------\n";

	static Quiz l{5000};
	cout << "\n-----------\n";

	f(r, s, t);*/

	/*Public j = { 1,2 };
	ofstream ofs("quiz1.txt", ios::out);
	char a = 26;
	ofs << "28		8302 9 20 78     292 202 20 10 10 9 17 9\n 11 30     9 783487";
	ofs.close();
	ifstream ifs("quiz1.txt", ios::in);
	int prevNum=0;
	while (ifs>> prevNum)
	{
		
	}
	ifs.clear();
	ifs.seekg(0, ios::beg);
	int  cnt = 0,  num = -1;
	while (ifs >> num)
	{
		if (num == prevNum)
		{
			cnt = cnt + 1;
		}
	}
	ifs.close();
	cout << "The last number is "<<prevNum<<" which exist in the file "<<cnt<<" time.";*/
	//cout << cnt;
	//C a{ 2 };

	////A* p1=&a;
	//B* p2=&a;
	//C* p3=&a;

	/*B o1{};
	A* p = (A*)&o1;
	p->f();*/
	/*const  host a;
	 host b;
	 b = move(a);*/


	 /*int kum = 1;
	 int&& num = move(kum);*/
	 //int&& num = kum;//syntax error

	/*string a{"S"};
	a += 65;
	cout << a;*/
	/*String a{"34.445"};
	int num= long long int (a);
	cout << long long int(a) << endl;;
	cout << num;*/
	//a += 65;
	//int num=a;
	//cout << num << endl;
	/*int& a = *(new int);
	a = 0;
	cout << a << endl;;
	delete &a;*/
	/*A a{};
	a.f();*/
	/*C c{};
	a = c;*/
	/*B b;
	A* p = &b;
	delete p;*/

	/*string str;
	ifstream myfile("file.txt", ios::in);
	if (myfile.fail())
	{
		cout << "File does not exist code here" << endl;
	}
	else
	{
		int i = 0; int wrd = 0;
		while (!myfile.eof())
		{
			getline(myfile, str, '*');
			cout << "ifs.eof()  is:  " << myfile.eof() << endl;

			i = 0;
			while (str[i] != '\0')
			{
				if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
					wrd++;
				i++;
			}
		}
		cout << "Number of words: " << wrd << endl;
	}
	return 0;*/
	//Sarmad a{};
	//A a;
	//B b;
	//C c;
	//b.show();  // prints "Inside A::display"
	//b.show();  // prints "Inside C::display" because A::display is virtual

	//Dog a{};



	//Sarmad a{};
	//Sajjad * p=&a;
	//p->f();
	////Sarmad b{};
	//cout << "----------------------\n";

	//a = move(b);
	//const Sarmad b{};
	//Sarmad  a{move (b)};//move  chalay ga 
	//cout << "----------------------\n";

	/*
	Sarmad {};
	cout << "----------------------\n";
	Sarmad b{};
	cout << "----------------------\n";*/


	//			i		const Sarmad b{};
	//Sarmad  a{ move(b)};//copy chalay ga if i dont write const in copy constructor 
	//cout << "----------------------\n";

	//a = move(b);
	//cout << "----------------------\n";

	/*D d(10);
	d.f();*/
	/*Fred f(new circle);
	Fred f1(f);
	Fred f2(new circle);
	f1 = f2;*/
	/*R p;
	int b;
	int&& a = b;*/

	/*derive p;
	p.fun();*/
	//Q q;//
	//P* p = (P*)&q;
	//cout << &q << endl << p << endl;
	//p->f();
	//base p;
	//derive d;
	/*derive p;
	p.fun();*/
	/*num* p = new num;
	p->f();*/
	//M o;
	//o.k();
	/*sum obj;
	kum* p = &obj;*/
	//C1 a{ 1 };
	//B1 f;
	//X1* p = &a;
	//cout << "--------------------------------\n";

	//CASE NO 1
//i

	/*A* p = new D;
	cout << "--------------------------------\n";

	p->f();
	delete p;*/
	
//ii
	//object slicing
	/*D d1;
	A p = d1;
	p.f();*/

	//CASE NO 2

	/*TUM obj;
	HUM* p = (HUM*)&obj;
	p->m();*/

	//CASE NO 3
	/*mum* p = new sum{};
	p->mumF();*/
	/*int a;
	cout << typeid(a).name();*/
}