#ifndef TEST_CLASS
#define TEST_CLASS
class Test
{
	int val;
	int* p;
public:
	Test();
	Test(int, int);
	Test(const Test&);
	void setVal(int);
	void setP(int);
	int getVal() const;

	int	getP() const;
	void display();
	int & setV(int a)
	{
		val = a;
		return val;
	}
	Test operator + (const Test&) const;
	Test operator - (const Test& ) const;
	Test& operator += (const Test&) ;;//(t1+=t2)+=t3 can be done by using & in return type
	Test& operator -= (const Test&);
	bool  operator ==(const Test& ) const;
	bool  operator !=(const Test& ) const;
	//Pre Increament 
	Test& operator++();
	//Post Increament 
	Test operator++(int);
	const Test & operator  = (const Test& );
	Test operator - ();

	//friend Test operator + (int, const Test&);
	~Test();
};
#endif 

