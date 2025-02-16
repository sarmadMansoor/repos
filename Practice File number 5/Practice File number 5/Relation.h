#ifndef RELATION_H
#define RELATION_H
#include "Set.h"
#include "OrderedPair.h"
class Relation
{
	Set setA;
	OrderedPair* orderedPairList;
	int capacity;
	int noOfOrderedPair;
	bool isPresent(const OrderedPair & ) const;
	bool isValidPair(const OrderedPair&) const;
	int giveIndexOfRecord(const OrderedPair&) const;
	void resize();
public:
	Relation(Set);
	void insert(const OrderedPair & ref);
	~Relation();
	void print() const;
	int getCardinality() const;
	void remove(const OrderedPair& ref);
	bool compare(const Relation&) const;
	bool isReflexive() const;
	bool isIrreflexive() const;
	bool isSymmetric() const;
	bool isTransitive() const;
	Relation(const Relation& rfs);

};
#endif


