#ifndef SET_CLASS
#define SET_CLASS
#include "Array.h"
class Set
{
	Array data;
	int noOfElement;
	int findIndex(int val) const;
	//bool linearSearch(int ) const ;
	bool isS2SubSetOfCallObj(Set s2) const;
	bool isCallObjSubSet(Set s2) const;
	bool isImproperSubSet(Set s2) const;
	int commonElement(const Set& s2) const;
	void printSubset(Array& subset) const ;
public:
	Set(int cap =0);
	//Set(int cnt, ...);
	void insert(int element);
	void remove(int element);
	void print() const ;
	int getCardinality()const;
	bool isMember(int val) const;
	int isSubSet(Set s2) const;
	void reSize(int newCapacity);
	Set calcUnion(const Set& s2) const;
	Set calcIntersection(const Set& s2) const;
	Set calcDifference(const Set& s2) const;
	Set calcSymmetricDifference(const Set& s2) const;
	void displayPowerSet() const;
};
#endif