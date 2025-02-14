#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char  a;
	/*ofstream ofs("../x64/c.txt");
	ofs << "a";
	ofs.close();*/


	ifstream ifs("C:/Users/Administrator/source/repos/absolute and realative path/absolute and realative path/A.txt");
	ifs >> a;
	ifs.close();
	cout << a;


}
//
//#include <iostream>
//#include <fstream>
//#include <exception>
//#include <stdexcept>
//#include <initializer_list>
//#include "IndexOutOfBound.h"
//#include "String.h"
//using namespace std;
//
////struct  A
////{
////	A()
////	{
////		cout << "A's CTOR\n";
////	}
////	~A()
////	{
////		cout << "A's DTOR\n";
////	}
////};
////
//double divide1(int n, int d)
//{
//	//A a;
//	if (d == 0)
//	{
//		throw String{ "Divide function receive 0 in denomerater\n" };
//		cout << "\nAfter throw statment\n";
//	}
//	//A b;
//
//	return n / d;
//}
//void  g()
//{
//	try
//	{
//		divide1(12, 0);
//		//A c();
//		cout << "Divide function do not throw an Error\n";
//	}
//	catch (String& a)
//	{
//		//A d{};
//		//a += "The error is also throw by G () function\n";
//		//cout << a;
//		throw;
//	}
//	cout << "\nHELLO FRIENDS I M G()\n";
//}
//void f()
//{
//	try
//	{
//		g();
//	}
//	catch (String& a)
//	{
//		//a += "The f() function is also effected by throw\n";
//		throw;
//	}
//	cout << "\nNOW I M IN F() \n";
//}
//
//double divide(int numerator, int denominator)
//{
//	if (denominator == 0)
//	{
//		cout << "ERROR: Cannot divide by zero.\n";
//		return 0;
//	}
//	else
//		return static_cast<double>(numerator) / denominator;
//}
////int findKey(int* arr, int size, int key)
////{
////	for (int i = 0; i < size; i++)
////	{
////		if (arr[i] == key)
////		{
////			return i;
////		}
////	}
////	return -1;
////}
//
//#include<iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	Animal(int a=0)
//	{
//		
//	}
//	virtual void eat()
//	{
//		cout << "I can eat!" << endl;
//	}
//};
//
//class Mammal : virtual public Animal 
//{
//
//public:
//	virtual void breathe() {
//		cout << "I can breathe!" << endl;
//	}
//	void f()
//	{
//		cout << "Mammal ka f()\n";
//	}
//};
//
//class WingedAnimal : virtual public Animal {
//public:
//	virtual void flap() {
//		cout << "I can flap!" << endl;
//	}
//	void f()
//	{
//		cout << "WingedAnimal ka f()\n";
//	}
//};
//
//// A bat is a winged mammal
//class Bat : public Mammal, public WingedAnimal
//{
//public:
//	Bat():Animal(4)
//	{
//
//	}
//};
//
////class A { }; // No virtual function
////class B : public A { }; // This will fail at runtime
//
////class A
////{
////public:
////	A()
////	{
////
////	}
////	virtual ~A() = 0;
////};
////A::~A()
////{
////
////}
////
////class B :public A
////{
////public:
////	void j()
////	{
////
////	}
////	~B()
////	{
////
////	}
////};
//class Quiz
//{
//public:
//	int a;
//	Quiz(int i = 1)
//	{
//		a = i;
//		cout << "\nQuiz() " << a;
//	}
//	Quiz(const Quiz& ref)
//	{
//		a = ref.a;
//		cout << "\nQuiz (const Quiz &) " << a;
//	}
//	~Quiz()
//	{
//		cout << "\n~Quiz() " << a;
//	}
//};
//Quiz f(Quiz a, Quiz b, Quiz& c)
//{
//	static Quiz y(23);
//	Quiz x(24);
//	return x;
//}
//
////void g()
////{
////	static Quiz z(100);
////}
//
//void wow(Quiz& s)
//{
//}
////Quiz g1(10);
////static Quiz g2(11);
////Quiz  g3(12);
//
//
//struct Tom
//{
//	int mem = 4;
//	Tom(int x = 1)
//	{
//		cout << "\nTom()" << mem;
//		mem = x;
//	}
//
//	Tom(Tom& ref)
//	{
//		cout << "\nTom(&)" << mem;
//		mem = ref.mem;
//	}
//
//	~Tom()
//	{
//		cout << "\n~Tom()" << mem;
//	}
//
//	void print()
//	{
//		cout << "\nmem = " << mem;
//	}
//
//	Tom add(Tom t)
//	{
//		Tom s;
//		s.mem = mem + t.mem;
//		return s;
//	}
//
//	Tom multiply(Tom t)
//	{
//		Tom s;
//		s.mem = mem * t.mem;
//		return s;
//	}
//
//	Tom sub(const Tom& t)
//	{
//		Tom s;
//		s.mem = mem - t.mem;
//		return s;
//	}
//};
//
//#include "B1.h"
//
//class A1
//{
//public:
//	A1()
//	{
//
//	}
//	A1(B1 & a)
//	{
//		cout << "A1(B1 & a)\n";
//	}
//	void operator =(const B1& a)
//	{
//		cout << "void operator =(const B1& a)\n";
//	}
//	operator B1()
//	{
//		B1 a;
//		cout << "A1 ka operator B1()\n";
//		return a;
//	}
//};
//B1::B1()
//{
//	cout << "B1\n";
//}
//B1::operator A1()
//{
//	A1 a;
//	cout << "B1 ka type cast A1\n";
//	return a;
//}
//
//class A
//{
//public:
//	virtual void f()
//	{
//		cout << "f()inA";
//	}
//	virtual void g()
//	{
//		cout << "g()inA";
//	}
//};
//class B :public A
//{
//public:
//	virtual void x()
//	{
//		cout << "x()inB";
//	}
//	virtual void h()
//	{
//		cout << "h()inB";
//	}
//};
//
////extern var;
////why this function runs f() accurately and does`nt get confused in V - tables of class A and class B ?
//int main()
//{
//	/*B obj;
//	A* p = (A*)&obj;
//	p->f();*/
//
//	cout << name << endl;
//
//	try
//	{
//		throw "abs";
//	}
//	catch(int a)
//	{
//
//	}
//	/*B1 b;
//	A1 a;
//	a = b;*/
//
//
//
//
//
//	/*char a = 26;
//	int x = a;
//	cout << x << endl;*/
////	Tom t1(5), t2;
//////	t1.add(5);
////	//t1.sub(12).print();
////	t1.add(t1).print();
//
//	/*static Quiz halao(999999);
//	Quiz r, s(2), t(3);
//	f(r, s, t);
//	wow(r);
//	f(r, s, t);*/
//
//
//	//B a;
//	/*A* a = new B();
//	B* b = dynamic_cast<B*>();*/
//	/*Bat b1;
//	b1.eat();*/
//
//
//	/*try
//	{
//		f();
//	}
//	catch (String &  a)
//	{
//		a.display();
//	}*/
//	//f();
//	//initializer_list<String> a {"a", "b", "c", "d"};
//	//const String* p = a.begin();
//	//while (p != a.end())
//	//{
//	//	cout << *p << endl;
//	//	p++;
//	//}
//	//g();
//	//int num1, num2; // To hold two numbers
//	//double quotient; // To hold the quotient of the numbers
//
//	//// Get two numbers.
//	//cout << "Enter two numbers: ";
//	//cin >> num1 >> num2;
//	//// Divide num1 by num2 and catch any
//	//		// potential exceptions.
//	//try
//	//{
//	//	quotient = divide(num1, num2);
//	//	cout << "The quotient is " << quotient << endl;
//	//}
//	//catch (string exceptionString)
//	//{
//	//	cout << exceptionString;
//	//}
//	//f();
//	//string str;
//	//ifstream myfile("file.txt", ios::in);
//	//if (myfile.fail())
//	//{
//	//	cout << "File does not exist" << endl;
//	//}
//	//else
//	//{
//	//	/*char a = myfile.peek();
//
//	//	cout << myfile.tellg() << endl;
//	//	cout << a << endl;
//	//	myfile.seekg(3, ios::beg);
//	//	myfile.seekg(2, ios::cur);
//	//	 a = myfile.peek();
//	//	 cout << a << endl;
//	//	 cout << myfile.tellg() << endl;*/
//	//	 myfile.seekg(0, ios::end);
//	//	 char  a = myfile.peek();
//	//	 // myfile >> a;
//
//	//	 cout << "myfile eof is : " << myfile.eof() << endl;
//	//	 cout << "myfile fail is : " << myfile.fail() << endl;
//	//	 cout << "myfile hard is : " << myfile.fail() << endl;
//	//	 myfile.seekg(-1, ios::end);
//	//	   a = myfile.peek();
//	//	   cout << a << endl;
//
//	//	/*myfile >> str;
//	//	//cout << str << endl;
//	//	myfile >> str;
//	//	cout << str << endl;*/
//	//}
//	//myfile.close();
//	//return 0;
//
//	/*int begin, end;
//	ifstream myfile("file.txt", ios::in);
//	begin = myfile.tellg();
//	myfile.seekg(0, ios::end);
//	end = myfile.tellg();
//	myfile.close();
//	cout << "size is: " << (end - begin) << " bytes.\n";
//	return 0;*/
//	//int data = 78;
//	//ifstream fin;
//	//fin.open("file.txt", ios::in); // open file
//	//if (fin.fail())
//	//{
//	//	cout << "File is not found \n" << endl;
//	//}
//	//else
//	//{
//	//	while (!fin.eof()) //if not at end of file,
//	//	{
//	//		cout << "entered " << endl;
//	//		cout << data << endl; //print numbers to
//
//	//		fin >> data; //get next number from
//	//		cout << "read " << data << " from file" << endl;
//	//	}
//
//
//	//}
//	//fin.close();
//	////try
//	//{
//	//	//divide(2, 0);
//	//	f();
//	//}
//	//catch (String &  a)
//	//{
//	//	cout << a << endl;
//	//}
//	/*catch (String &a)
//	{
//		cout << a << endl;;
//	}*/
//	//ofstream ofs("oop.txt");
//	//int num = 123;
//	//ofs << 'a';
//	//ofs.close();
//	//ifstream ifs("oop.txt");
//	//char  ch;// = 'R';
//	//cout << "EOF bit is : " << ifs.eof() << endl;
//	//cout << "Hard bit is : " << ifs.fail() << endl;
//	//ifs >> ch;
//	//cout << "\n\n";
//	//cout << ifs.peek() << endl;
//	//cout << "\n\n";
//
//	////while (ifs >> ch)
//	////{
//	////	cout << "EOF bit is : " << ifs.eof() << endl;
//	////	cout << "Hard bit is : " << ifs.fail() << endl;
//	////	//ifs >> ch;
//	////	cout << ch << endl;;
//	////}
//	//cout << "EOF bit is : " << ifs.eof() << endl;
//	//cout << "Hard bit is : " << ifs.fail() << endl;
//	//ifs.close();
//}
