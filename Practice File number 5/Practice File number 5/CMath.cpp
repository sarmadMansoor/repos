#include <iostream>
//#include "String.h"
#include "CMath.h"
using namespace std;
float CMath::caluPower(int base, int exp)
{
	if (base == 0)
		return 0;
	float power = 1;
	int i = 0;
	while (i < exp)
	{
		power = power * base;
		i++;
	}
	return power;
}
int  CMath::GCD(int d, int n)
{
	if (d > n)
	{
		int temp = d;
		d = n;
		n = temp;
	}
	while (n % d != 0)
	{
		int rem = n % d;
		n = d;
		d = rem;
	}
	return d;
}
//String  CMath::toString(long long int num)
//{
//	int len = getLen(num);
//	String p{};
//	long long int temp = num;
//	int i = 0;
//	if (temp < 0)
//	{
//		p.reSize(len + 1);
//		p.at(len) = '-';
//		temp = temp * -1;
//	}
//	else
//	{
//		p.reSize(len);
//	}
//	while (len > 0)
//	{
//		int rem = temp % 10;
//		p.at(i) = numToChar(rem);
//		i++;
//		len--;
//		temp = temp / 10;
//	}
//	num < 0 ? p.at(i + 1) = '\0' : p.at(i) = '\0';
//	p.reverse();
//	return p;
//}
//char CMath::numToChar(int c)
//{
//	return c + '0';
//}
//int CMath::getLen(long long int num)
//{
//	int len = 1;
//	num < 0 ? num = num * -1 : num;
//	while (num >= 10)
//	{
//		num = num / 10;
//		len++;
//	}
//	return len;
//}
//long long int  CMath::toInteger(String s2)
//{
//	long long int num = 0;
//	if (!s2.isEmpty())
//	{
//		num = s2.convertToInteger();
//	}
//	return num;
//}
