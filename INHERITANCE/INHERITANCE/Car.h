#ifndef CAR_CLASS
#define CAR_CLASS
#include "Vehicle.h"
class Car :public Vehicle
{
	int capacity;
public:
	Car();
	Car(int,int ,int);
	~Car();
	void setCapacity(int);
	int getCapacity() const;
	Car(const Car&);
	const Car& operator=(const Car& );
	void display() const;
	void h()
	{
		cout << "hhh" << endl;
	}
};

#endif 
