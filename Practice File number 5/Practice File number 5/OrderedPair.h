#ifndef ORDERED_PAIR_H
#define ORDERED_PAIR_H
class OrderedPair
{
	int a;
	int b;
public:
	OrderedPair(int n = 0, int m = 0);
	int getA() const;
	int getB() const;
	void setA(int);
	void setB(int);

};
#endif


