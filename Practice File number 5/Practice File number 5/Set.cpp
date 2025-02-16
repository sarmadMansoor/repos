#include <iostream>
#include "Set.h"
#include "CMath.h"
#include <stdarg.h>
using namespace std;
Set::Set(int cap):data(cap)
{
	noOfElement = 0;
}
bool Set::isMember(int val) const
{
	bool status = false;
	for (int i = 0; i < noOfElement; i = i + 1)
	{
		if ( data.getSet(i) == val)
		{
			status = true;
		}
	}
	return status;
}	
int Set::getCardinality()const
{
	return noOfElement;
}
void Set::reSize(int newCapacity)
{
	if (data.getSize() == newCapacity)
		return;
	if (newCapacity <data.getSize() && newCapacity<noOfElement)
		noOfElement =  newCapacity;
	data.reSize(newCapacity);
}
void Set::insert(int element)
{
	if (!isMember(element))
	{
		if (noOfElement >= data.getSize())
		{
			if (data.getSize() == 0)
				reSize(2);
			else
				reSize(data.getSize() *2);
			data.getSet(noOfElement) = element;
			noOfElement++;
		}
		else
		{
			data.getSet(noOfElement) = element;
			noOfElement++;
		}
	}
}
void Set::print() const
{
	if (noOfElement == 0) 
	{
		cout << "{ } " << endl;
		return;
	}

	cout << "{ ";
	for (int i = 0; i < noOfElement; i++)
	{
		cout << data.getSet(i);
		if (i < noOfElement - 1) 
		{
			cout << ", ";
		}
	}
	cout << " }" << endl;
}
int Set::findIndex(int val) const
{
	bool status = false;
	for (int i = 0; i < noOfElement; i = i + 1)
	{
		if (data.getSet(i) == val)
		{
			return i;
		}
	}
	return -1;
}
void Set::remove(int element)
{
	if (isMember(element))
	{
		int index = findIndex(element);
		for (int i = index; i < noOfElement-1; i++)
		{
			data.getSet(i) = data.getSet(i + 1);
		}
		noOfElement--;
	}
}
bool Set::isS2SubSetOfCallObj(Set s2) const
{
	if (s2.data.getSize() == 0)
		return true;
	int s2Card = s2.getCardinality();
	int i=0 ,count= 0;
	while (i < s2Card)
	{
		if (isMember(s2.data.getSet(i)))
		{
			count++;
		}
		i++;
	}
	if (count == s2Card)
		return true;
	else
		return false;
}
bool Set::isCallObjSubSet(Set s2) const
{
	if(data.getSize() == 0)
		return true;
	int card = getCardinality();
	int i = 0, count = 0;
	while (i < card)
	{
		if (s2.isMember(data.getSet(i)))
		{
			count++;
		}
		i++;
	}
	if (count == card)
		return true;
	else
		return false;
}
bool Set::isImproperSubSet(Set s2) const
{
	if (data.getSize() == 0 && s2.data.getSize() == 0)
		return true;
	if (getCardinality() != s2.getCardinality())
		return false;
	else
	{
		return isCallObjSubSet(s2);
	}
}
int Set::isSubSet(Set s2) const
{
	if (isImproperSubSet(s2))
		return 2;
	if (isCallObjSubSet(s2))
		return 1;
	if (isS2SubSetOfCallObj(s2))
		return -1;
	else
		return 0;
}
int Set::commonElement(const Set & s2) const
{
	int cnt = 0;
	for (int i = 0; i < getCardinality(); i = i + 1)
	{
		for (int j = 0; j < s2.getCardinality(); j = j + 1)
		{
			if (data.getSet(i) == s2.data.getSet(j))
			{
				cnt = cnt + 1;
			}
		}
	}
	return cnt;
}
Set Set::calcUnion(const Set& s2) const
{
	int common = commonElement(s2);
	Set temp{ getCardinality() + s2.getCardinality() - common };
	int i;
	for (i = 0; i < getCardinality(); i = i + 1)
	{
		temp.data.getSet(i) = data.getSet(i);
		temp.noOfElement++;
	}
	for (int j = 0; j < s2.getCardinality(); j = j + 1)
	{
		if (!isMember(s2.data.getSet(j)))
		{
			temp.data.getSet(i) = s2.data.getSet(j);
			temp.noOfElement++;
			i = i + 1;
		}
	}
	return temp;
}
Set Set::calcIntersection(const Set& s2) const
{
	Set temp{};
	temp.reSize(commonElement(s2));
	int k = 0;
	for (int i = 0; i < getCardinality(); i = i + 1)
	{
		for (int j = 0; j < s2.getCardinality(); j = j + 1)
		{
			if (data.getSet(i) == s2.data.getSet(j))
			{
				temp.data.getSet(k) = data.getSet(i);
				temp.noOfElement++;
				k = k + 1;
			}
		}
	}
	return temp;
}
Set Set::calcDifference(const Set& s2) const
{
	Set temp{ getCardinality() - commonElement(s2) };
	int k = 0;
	for (int i = 0; i < getCardinality(); i++)
	{
		if (!(s2.isMember(data.getSet(i))))
		{
			temp.data.getSet(k) = data.getSet(i);
			k++;
			temp.noOfElement++;
		}
	}
	return temp;
}
Set Set::calcSymmetricDifference(const Set& s2) const
{
	Set Union = calcUnion(s2);
	Set Intersection = calcIntersection(s2);
	Set symmetricDiff = Union.calcDifference(Intersection);
	return symmetricDiff;
}
void Set::printSubset(Array & subset) const
{
	std::cout << "{ ";
	for (int i = 0; i <getCardinality(); i++) {
		if (subset.getSet(i) == 1)
		{
			cout << data.getSet(i) << " ";
		}
	}
	cout << "}\n";
}
void Set::displayPowerSet() const
{
	int totalSubsets = CMath::caluPower(2, getCardinality());
	for (int i = 0; i < totalSubsets; i++) {
		Array subset{ 0 };
		subset.reSize(100);
		int temp = i;
		int j = 0;
		while (temp > 0) {
			subset.getSet(j) = temp % 2;
			temp /= 2;
			j++;
		}
		printSubset( subset);
	}
}
//Set::Set(int cnt, ...):data(cnt)
//{
//	va_list list;
//	va_start(list, cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		int value= va_arg(list, int);
//		if (isMember(value))
//		{
//			data.at(i) = value;
//			noOfElement++;
//
//		}
//	}
//	va_end(list);
//}
