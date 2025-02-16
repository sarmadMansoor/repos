#include <iostream>
#include "Relation.h"
#include "OrderedPair.h"
using namespace std;
Relation::Relation(Set a):setA(a)
{
	orderedPairList = nullptr;
	capacity = 0;
	noOfOrderedPair = 0;
}
Relation::~Relation()
{
	if (orderedPairList != nullptr)
	{
		delete[] orderedPairList;
		orderedPairList = nullptr;
		capacity = 0;
		noOfOrderedPair = 0;
	}
}
bool Relation::isPresent(const OrderedPair  & ref)  const
{ 
	for (int i = 0; i < noOfOrderedPair; i++)
	{
		if (orderedPairList[i].getA() == ref.getA()&& orderedPairList[i].getB() == ref.getB())
		{
			return true;
		}
	}
	return false;
}
bool Relation:: isValidPair(const OrderedPair& ref) const
{
	for (int i = 0; i < noOfOrderedPair; i++)
	{
		if (!setA.isMember( ref.getA()) || !setA.isMember(ref.getB()))
		{
			return false;
		}
	}
	return true;
}
void Relation::insert(const OrderedPair& ref)
{
	if (isPresent(ref))
		return;
	else if (!isValidPair(ref))
		return;
	resize();
	orderedPairList[noOfOrderedPair].setA(ref.getA());
	orderedPairList[noOfOrderedPair].setB(ref.getB());
	noOfOrderedPair = noOfOrderedPair++;
}
void Relation::resize()
{
	if (noOfOrderedPair == 0)
	{
		orderedPairList = new OrderedPair{};
		return;
	}
	OrderedPair* ptr=nullptr;
	ptr = new OrderedPair[noOfOrderedPair + 1]{};
	for (int i = 0; i < noOfOrderedPair; i++)
	{
		ptr[i] = orderedPairList[i];
	}
	delete[] orderedPairList;
	orderedPairList = ptr;
	capacity=capacity + 1;
}
int Relation::getCardinality() const
{
	return noOfOrderedPair;
}
void Relation::print() const
{
	if (orderedPairList == nullptr)
		return;

	cout << "{";
	for (int i = 0; i < noOfOrderedPair; i++)
	{
		if (i == noOfOrderedPair - 1)
			cout << "(" << orderedPairList[i].getA() << "," << orderedPairList[i].getB() << ")";
		else
			cout << "(" << orderedPairList[i].getA() << "," << orderedPairList[i].getB() << ")" << ",";
	}
	cout << "}";
	

}
int Relation::giveIndexOfRecord(const OrderedPair& ref) const
{
	for (int i = 0; i < noOfOrderedPair; i++)
	{
		if (orderedPairList[i].getA() == ref.getA() && orderedPairList[i].getB() == ref.getB())
		{
			return i;
		}
	}
	return -1;
}
void Relation::remove(const OrderedPair& ref)
{
	if (noOfOrderedPair == 0)
		return;
	if (isPresent(ref))
	{
		int index = giveIndexOfRecord(ref);
		for (int i = index; i < noOfOrderedPair-1; i++)
		{
			orderedPairList[i] = orderedPairList[i + 1];
		}
		noOfOrderedPair = noOfOrderedPair--;
	}
}
bool Relation::compare(const Relation& ref) const
{
	if (setA.isSubSet(ref.setA) != 2)
		return false;
	if (getCardinality() != ref.getCardinality())
		return false;
	for (int i = 0; i < noOfOrderedPair; i++)
	{
		if (!isPresent(ref.orderedPairList[i]))
			return false;
	}
	return true;

}
bool Relation::isReflexive() const
{
	for (int i = 0; i < noOfOrderedPair; i++)
	{
		if (isPresent(OrderedPair(orderedPairList[i].getA(), orderedPairList[i].getA())))
		{
			return true;
		}
	}
	return false;
}
bool Relation::isIrreflexive() const
{
	if (isReflexive())
		return false;
	else
		return true;
}
bool Relation::isSymmetric() const
{
	int num = 0;
	int i = 0;
	for (; i < noOfOrderedPair; i++)
	{
		if (isPresent(OrderedPair(orderedPairList[i].getB(), orderedPairList[i].getA())))
		{
			num = num++;
		}
		else
		{
			return false;
		}
	}
	bool flag = false;
	i == num ? flag = true : flag;
	return flag;
}
Relation::Relation(const Relation& rfs):Relation(rfs.setA)
{
	if (rfs.orderedPairList != nullptr)
	{

	}
}
//bool Relation::isTransitive() const
//{
//	for (int i = 0; i < noOfOrderedPair; i++)
//	{
//
//	}
//}
