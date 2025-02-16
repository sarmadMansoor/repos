#ifndef POINT_CLASS
#define POINT_CLASS

class Point
{
	int x;
	int y;
public:
	Point();
	Point(int);
	Point(int, int);
	void display();
	Point(const Point&);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	const Point& operator = (const Point&);
	~Point();
	//friend ostream& operator << (ostream&, const Point&);
};
#endif 