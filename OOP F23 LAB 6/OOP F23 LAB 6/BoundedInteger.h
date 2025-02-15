#ifndef BOUNDEDINTEGER_H
#define BOUNDEDINTEGER_H

class BoundedInteger
{
	int lowerBound;
	int upperBound;
	int value;
	bool isValidBound(int lowerBound, int upperBound) const ;
public:
	BoundedInteger();
	BoundedInteger(int lowerBound, int upperBound);
	BoundedInteger(int lowerBound, int upperBound, int value);
	void setValue(int val);
	int getValue() const ;
	int getLowerBound()const ;
	int getUpperBound()const;
	void increment(int inc = 1);
	void decrement(int dec = 1);
	bool isValidValue(int val) const ;
};

#endif
