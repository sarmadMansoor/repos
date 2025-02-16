#ifndef MY_ARRAY
#define MY_ARRAY
class Array
{
private:
	//const int num;
	static const int num ;
	int* data;
	int size;
	bool isValidIndex(int) const ;
	void initailize();
public:
	//Array(int = 0);
	Array(int cnt, ...);
	~Array();
	Array(const Array&);
	int getSize() const;
	//void insert(int );
	//int& getSet(int );
	void reSize(int );
	//void display() const ;
	int& getSet(int);
	const int& getSet(int) const ;
};
#endif 
