#ifndef VEHICLE_CLASS
#define VEHICLE_CLASS

class Vehicle
{
	int model;
	int wheels;
public:
	Vehicle();
	Vehicle(int, int);
	~Vehicle();
	void display() const;
	void setModel(int);
	void setWheels(int w);
	int getModel() const ;
	int getWheels() const;
	const Vehicle& operator = (const Vehicle&);
	Vehicle(const Vehicle&);
};

#endif 
