#ifndef PERSON_DATA_CLASS
#define PERSON_DATA_CLASS

class PersonData
{
	char* lastName;
	char* firstName;
	char* address;
	char* city;
	char* state;
	int zipCode;
	char* phone;
	int strlen(const char* str);
	void strcpy(char* dest, const char* src);
public:
	PersonData();
	PersonData(const PersonData&);
	const PersonData& operator = (const PersonData&);
	PersonData(const char* lastN, const char* firstN, const char* ad,
		const char* cit, const char* st, int zip, const char* ph);
	~PersonData();
	void display();
	const char* getAddress() const;
	const char* getLastName()const;
	const char* getFirstName() const;
	const char* getCity() const;
	const char* getState() const;
	const char* getPhone() const;
	int getZip() const;

	void setAddress(const char*);
	void setLastName(const char*);
	void setFirstName(const char*);
	void setCity(const char*);
	void setState(const char*);
	void setPhone(const char*);
	void setZip(int);

};
#endif
