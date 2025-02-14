//#ifndef BIG_NUMBER_H
//#define  BIG_NUMBER_H
//enum Comparsion { EQUAL, SMALL,LARGE };
//class BigNumber
//{
//	char* number;
//	int numberLength;
//	int getLength(const char * num);
//	void copyCharArray(const char* source);
//	bool isSame(BigNumber str) const ;
//	bool isEmpty() const ;
//	bool isCallingGreater(BigNumber s2) const ;
//public:
//	BigNumber(const char*);
//	BigNumber(const BigNumber&);
//	~BigNumber();
//	void setNumber(const char* num);
//	void print() const ;
//	BigNumber subtract(const BigNumber& other) const;
//	BigNumber multiply(const BigNumber& other) const;
//	BigNumber add(const BigNumber & ) const ;
//	Comparsion compare(const BigNumber &) const ;
//};
//#endif // !1
//
//
//
#ifndef BIG_NUMBER_H
#define  BIG_NUMBER_H
enum Comparsion { EQUAL, SMALL, LARGE };
class BigNumber
{
	char* number;
	int numberLength;
	int getLength(const char* num);
	void copyCharArray(const char* source);
	bool isSame(BigNumber str) const;
	bool isEmpty() const;
	bool isCallingGreater(BigNumber s2) const;
public:
	BigNumber(const char*);
	BigNumber(const BigNumber&);
	~BigNumber();
	void setNumber(const char* num);
	void print() const;
	BigNumber subtract(const BigNumber& other) const;
	BigNumber multiply(const BigNumber& other) const;
	BigNumber add(const BigNumber&) const;
	Comparsion compare(const BigNumber&) const;
};
#endif // ! BIG_NUMBER_H
