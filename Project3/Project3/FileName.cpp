#include <iostream>
#include "Test.h"
#include "Point.h"
#include "Circle.h"
#include "MyArray.h"
using namespace std;


ostream& operator << (ostream& out,  Point& rhs)
{
	out << "(" << rhs.getX() << "," << rhs.getY() << ")" << endl;
	return out;
}


void displayValue(Test pt)
{
	pt.display();
}
Test createTest()
{
	Test p(11,22);
	p.display();
	cout << "i m in function " << endl;
	return p;
}
Test operator + ( int num,const Test & rhs)
{
	Test temp;
	temp.setVal(num + rhs.getVal());
	temp.setP(num + rhs.getP());
	return temp;
}

ostream & operator << (ostream& o,const  Test  & rhs)
{
	o <<"Values are : " << rhs.getVal() << '\t' << rhs.getP() << endl;
	return o;
}
istream& operator >> (istream& o, Test& rhs)
{
	cout << "Enter the value of values : ";
	int num1, num2;
	o >> num1;
	o.ignore();
	o >> num2;
	rhs.setVal(num1);
	rhs.setP(num2);
	return o;
}
int main()
{/*
	Test t1(1, 2);
	Test t2;
	t2.display();
	t2 = createTest();
	cout << "in main\n";
	t2.display();*/


	/*Circle c1,c2;
	cout << "-----------------------------in main-------------\n";
	c1 = c2;
	cout << "-----------------------------in main-------------\n";*/

	/*Test t1;
	Test t2(1, 2);
	Test t3(3, 4);
	(t1 += t2);
	cout << t2;*/

	//Test t1(11, 22);
	//Test t2;
	//cin >> t2;
	//t2 = 10 + t1;
	////t2.display();
	//cout << t2;

	/*Point p1(1, 2);
	p1.display();*/

	/*Test t1(1, 2);
	Test t2;
	t2 = -t1;
	t1.display();
	t2.display();*/

	/*Test p1(1, 1);
	Test p= createTest(p1);
	cout << "welcome back !" << endl;*/


	/*Test t1(2, 3);
	Test t2(3, 4);
	Test t3=t1+t2;
	t3.display();*/


	//Test t1;
	////t1.display();
	//t1.display();
	//Test t2 = ++t1;
	//t2.display();
	//cout << "halo" << endl;


	/*Test pt(2, 3);
	displayValue(pt);
	cout << "welcome back!!" << endl;*/



	/*MyArray<int> a1(5);
	a1[2] = 4;
	a1.display();*/

	//cout << "--------------------------------------------------------------\n";
	//MyArray<Point> a2(5);
	////a2[2] = 4;
	//a2.display();

	/*MyArray <Point> a1(4);
	for (int i = 0; i < 4; i++)
	{
		a1[i] = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << a1[i] << endl;
	}*/


	/*Test t( 1, 2);
	cout << "-------------------------------------------\n";
	Test t2(3, 4);
	cout << "-------------------------------------------\n";

	Test t3;
	cout << "-------------------------------------------\n";

	t3 = t + t2;
	cout << "-------------------------------------------\n";*/


	/*int a;
	cin >> a;
	while (cin.good()==0)
	{
		cin.clear();
		cin.ignore();
		cin >> a;
	}*/
	//cout << a << endl;;
	//char num[200];
	/*cin >> num;
	while (cin.good() == 0)
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "enter correct input : ";
		cin >> num;
	}
	cout << num << endl;*/

	/*cin.getline(num,200);
	cout << num;*/


	/*Test t1;
	t1.setV(6);
	t1.display();*/

	cout << 5.0 / 0 << endl;


}