#include <iostream>
#include "BigNumber.h"
using namespace std;
template <typename T>
class Stack
{
	T* data;
	int top;
	int size;
	void reSize(int cap)
	{
		T* newData = new T[cap];
		for (int i = 0; i < top; i++)
			newData[i] = data[i];
		delete[] data;
		size = cap;
		data = newData;
	}
public:
	Stack() :data(nullptr), top(0), size(0) {}
	~Stack()
	{
		if (!data)
			return;
		delete[] data;
		size = 0;
		top = 0;
	}
	Stack(const Stack<T>& rfs)
	{
		*this = rfs;
	}
	Stack& operator = (const Stack<T>& rfs)
	{
		if (this == &rfs)
			return *this;
		this->~Stack();
		if (!rfs.data)
			return *this;
		top = rfs.top;
		size = rfs.size;
		data = new T[size];
		for (int i = 0; i < top; i++)
		{
			data[i] = rfs.data[i];
		}
		return *this;
	}
	bool isFull()
	{
		if (top == size)
			return true;
		else 
			return false;
	}
	bool isEmpty()
	{
		if (top == 0)
			return true;
		else
			return false;
	}
	void push(T rfs)
	{
		if (top == size)
			reSize(size==0?1:size*2);
		data[top] = rfs;
		top++;
	}
	T pop()
	{
		if (isEmpty())
			exit(0);
		T val = data[top-1];
		top--;
		if (top > 0 && top == size / 4)
			reSize(size / 2);
		return val;
	}
	T stackTop()
	{
		if (isEmpty())
			exit(0);
		return data[top-1];
	}
};
int main()
{
	//Stack <int> p{};
	//p.push(34);
	//p.push(35);
	//p.push(36);
	//p.push(37);
	//Stack <int > p1{p};
	////p1 = p;
	//cout<<p1.pop();
	/*cout<<p.pop();
	cout<<p.pop();
	cout<<p.pop();
	cout << "-----------------\n";
	cout<<p.pop();
	cout << "-----------------\n";*/
	BigNumber a{ "999" };
	BigNumber b{ "2" };
//	b.setNumber("1");
	a.multiply(b).print();
	//BigNumber num{"3134"};
	//BigNumber num2{ "3254"};
	////BigNumber{ num }.print();
	///*num.add(num2).print();;*/
	//if (num.compare(num2) == EQUAL)
	//	cout << "EQUAL";
	//else if (num.compare(num2) == LARGE)
	//	cout << "LARGE";
	//else
	//	cout << "SMALL";
	//num2.print();
	//cout << num.numberLength;
	/*string g{ "" };
	cout << g[0];*/
	return 0;
}