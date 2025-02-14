#include <iostream>
#include <fstream>
#include <exception>
#include "Array.h"
#include "String.h"
//ofstream& operator << (ofstream& ofs, const String& s2)
//{
//
//	ofs << s2.getSize();
//	ofs << "\n";
//	ofs << s2.data;
//	ofs << '\n';
//	return ofs;
//}
struct Student
{
	float rollNo;
	int NOE;
	int* list;
};
struct h
{
	String name;
};
struct Stud
{
	int rollNo=1;
	int gpa=2;
	int cpga=3;
};
using namespace std;


#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
//#include "IndexOutOfBound.h"
#include "String.h"
using namespace std;

//struct  A
//{
//	A()
//	{
//		cout << "A's CTOR\n";
//	}
//	~A()
//	{
//		cout << "A's DTOR\n";
//	}
//};
////
//double divide(int n, int d)
//{
//	A a;
//	if (d == 0)
//	{
//		throw string {"Divide function receive 0 in denomerater\n"};
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
//		divide(12, 0);
//		//A c();
//		cout << "Divide function do not throw an Error\n";
//	}
//	catch (string& a)
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
//	catch (string& a)
//	{
//		//a += "The f() function is also effected by throw\n";
//		throw;
//	}
//	cout << "\nNOW I M IN F() \n";
//}

class A
{
public:
	A()
	{
		cout << "A,s D ctor";
	}
	~A()
	{
		cout << "A,s dtor";
	}
};

int main()
{ 
	String rollNumber = "BSEF22M012";
	//cout << sizeof(rollNumber) << endl;
	int sizeOfRoll = rollNumber.getLength() + 1;;
	ofstream ofs("binary.txt", ios::binary);
	if (ofs.fail())
	{
		cout << "system donot found the file\n";
	}
	else
	{
		ofs.write((char* )&sizeOfRoll,sizeof(int));
		ofs.write((char*)&rollNumber[0], rollNumber.getLength()+1);
	}
	ofs.close();
	ifstream ifs("binary.txt", ios::binary);
	String roll;
	int size;
	ifs.read((char*)&size,sizeof(int));
	roll.reSize(size);
	ifs.read((char*)&roll[0], rollNumber.getLength()+1);
	ifs.close();
	//cout << size << endl;
	cout << roll << endl;


	//cout << roll << endl;
	//f();
	//Stud a, b, c,d;
	//c.cpga = 1;
	//c.gpa = 1;
	//c.rollNo = 1;
	//ofstream ofs("hum.txt", ios::binary);
	//ofs.write((char*)&a, sizeof(a));
	//ofs.write((char*)&b, sizeof(b));
	//ofs.write((char*)&c, sizeof(c));
	//ofs.write((char*)&d, sizeof(d));
	//ofs.close();


	/*ifstream ifs("hum.txt", ios::binary);
	ifs.seekg(sizeof(a) * 2, ios::beg);
	Stud demo;
	ifs.read((char*)&demo, sizeof(demo));
	ifs.close();
	cout << demo.cpga << endl;
	cout << demo.gpa << endl;
	cout << demo.rollNo << endl;*/








	/*Student a = { 12,2,(new int [2] {1,2}) };
	String n = { "khaflglifglgflih" };
	ofstream ofs("chee.txt", ios::binary);
	streambuf* p = cout.rdbuf();
	cout.rdbuf(ofs.rdbuf());
	int size = n.getLength() + 1;
	cout.write((char*)&size, sizeof(int));
	cout.write(&n[0],size );
	ofs.close();*/

//	
//	String l;
//	char* name;
//	ifstream ifs("chee.txt", ios::binary);
//	streambuf* k = cin.rdbuf(ifs.rdbuf());
//	int size1;
//	cin.read((char*)&size1, sizeof(int));
//	//name = new char[size1];
////	cout << size1 << endl;
//	l.reSize(size1);
//	cin.read(&l[0], size1);
//	ifs.close();
//
//	cout.rdbuf(p);
//	cin.rdbuf(k);
//	cout << l;



	/*String a{ "Sarmad MaNSOOR AHAMD CHEEMA PUNJABI LAYYAH" };
	ofstream ofs("halog.txt", ios::binary);
	ofs.write(&a[0], a.getLength()+1);
	ofs.close();
	String p;
	p.reSize(a.getLength());
	ifstream ifs("halog.txt", ios::binary);
	ifs.read(&p[0], a.getLength() + 1);
	ifs.close();*/





	//cout << p;



	//ifstream ifs("test.txt", ios::binary);


	//ofstream ofs("japan.txt", ios::binary);

	//ofs << ifs.rdbuf();// test sy sara data japan vali file py write kar raha ha
	//ifs.close();
	//ifs.close();


	/*String a = { "Cheema gajkakdnkajbdabdadibi" };
	ofstream ofs("anas.txt");
	ofs << a;
	ofs.close();

	String k;
	ifstream ifs("anas.txt");
	ifs >>k;
	ifs.close();
	cout << k;*/
	/*const char a[10] = "Sarmad";
	ofstream ofs("cheema.txt", ios::binary);
	ofs.write(a, sizeof(a));
	ofs.close();*/


	//streambuf* p = cout.rdbuf();
	//int num1 = 45;
	//ofstream ofs("young.txt", ios::binary);
	//cout.rdbuf(ofs.rdbuf());
	//cout << num1;
	////ofs.write((char*)&num1, 4);
	//ofs.close();

	//int num=0;
	//ifstream ifs("young.txt", ios::binary);

	//ifs.read((char*)num, 4);
	//ifs.close();
	//cout.rdbuf(p);
	//cout << num;
	//h hal = {"S"};
	//String *p= &(hal.name.display());

	//int num1 = 8134;
	//ofstream ofs("chowk.txt", ios::binary);
	//ofs.write((char*)&num1, sizeof(int));
	//ofs.close();

	//int num;
	//ifstream ifs("chowk.txt", ios::binary);
	//cout << ifs.tellg() << endl;
	//ifs.read((char*)&num, sizeof(int));
	//cout << ifs.peek() << endl;
	//cout << "eof bit is : " << ifs.eof() << endl;
	//cout << "fail bit is : " << ifs.fail() << endl;

	//ifs.read((char*)&num, sizeof(int));
	////ifs.seekg(0, ios::end);
	//cout << ifs.tellg() << endl;
	//cout << "eof bit is : " << ifs.eof() << endl;
	//cout << "fail bit is : " << ifs.fail() << endl;
	//ifs.close();
	//Student a = { 12,2,(new int [2] {1,2}) };
	//h n = { "Sarmad" };
	//cout << a.list;
	//String name = "Sramad";
	//ofstream ofs("hallo.txt", ios::binary);

	///*ofs.write((char*)&a.rollNo, sizeof(float));
	//ofs.write((char*)&a.NOE, sizeof(int));
	//ofs.write((char*)&a.list,4*2);*/
	//ofs.write((char*)&name, name.getLength());
	//ofs.close();

	////h k;
	////Student m;
	//String k;
	//ifstream ifs("hallo.txt", ios::binary);
	//ifs.read((char*)&k, name.getLength());
	//ifs.read((char*)&m.rollNo, sizeof(float));
	//ifs.read((char*)&m.NOE, sizeof(int));
	//ifs.read((char*)&m.list, 4*2);
	//ifs.close();

	
	/*cout << m.rollNo << endl;
	cout << m.NOE << endl;
	cout << m.list[0] << endl;
	cout << m.list[1] << endl;*/
	//cout << m.list[0] << endl;
	//int* list = new int [2] {1, 2};
	//ofstream ofs("data.txt", ios::binary);
	//ofs.write((char*)list, 4 * 2);
	//ofs.close();


	//int* temp = new int[2];
	//ifstream ifs("data.txt", ios::binary);
	//ifs.read((char*)temp, 4 * 2);
	//ifs.close();


	//cout << temp[0] << endl;
	//cout << temp[1] << endl;


	//delete list;
	//list = 0;
	//delete temp;
	//temp = 0;
	/*ofstream ofs("test1.txt", ios::out);
	ofs << 45;
	


	ofstream ofs1("test2.txt", ios::out);



	ofs1 << ofs;
	ofs.close();
	ofs1.close();*/


	///*String n = { "sa" };
	//cout << sizeof(n);*/
	///*ofstream ofs("test.txt", ios::binary);
	//int num = 65;
	//ofs.write((char*)&num, sizeof(int));
	//ofs.close();*/
	//Student a = { 12,"Sarmad",200 };
	//ofstream ofs("Student.txt", ios::binary);
	//int size = a.name.getSize();
	//ofs.write((char*)&a.rollNo, sizeof(float));
	//ofs.write((char*)&size, sizeof(int));
	////ofs.write((char*)&a.rollNo, sizeof(float));
	////ofs.write((char*)&size, sizeof(int));
	//ofs.write((char*)&a.name.,size);
	//ofs.write((char*)&a.rollNo, sizeof(float));

	///*ofs.write((char*)&a, sizeof(Student));*/
	//ofs.close();

	//Student k;
	//ifstream ifs("Student.txt", ios::binary);

	//ifs.read((char*)&k, sizeof(Student));
	///*ifs.read((char*)&k.rollNo, sizeof(float));
	//ifs.read((char*)&k.name, sizeof(String));
	//ifs.read((char*)&k.rollNo, sizeof(float));*/
	//ifs.close();

	//cout << k.rollNo << endl;
	//cout << k.name << endl;
	//cout << k.marks << endl;
}