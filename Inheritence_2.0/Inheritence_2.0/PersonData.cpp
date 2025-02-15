#include <iostream>
#include "PersonData.h"
//#include "Instructor.h"
using namespace std;

int PersonData::strlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void  PersonData::strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null terminator to the destination string
}
PersonData::PersonData()
{
    cout << "PERSON data default constructor called\n";
    lastName = new char[2];
    strcpy(lastName, "");
    firstName = new char[2];
    strcpy(firstName, "");
    address = new char[2];
    strcpy(address, "");
    city = new char[2];
    strcpy(city, "");
    state = new char[2];
    strcpy(state, "");
    zipCode = 0;
    phone = new char[2];
    strcpy(phone, "");
}
PersonData::PersonData(const char* lastN, const char* firstN, const char* ad,
    const char* cit, const char* st, int zip, const char* ph)
{
    cout << "PERSON data default constructor called\n";
    lastName = new char[strlen(lastN) + 1];
    strcpy(lastName, lastN);
    firstName = new char[strlen(firstN) + 1];
    strcpy(firstName, firstN);
    address = new char[strlen(ad) + 1];
    strcpy(address, ad);
    city = new char[strlen(cit) + 1];
    strcpy(city, cit);
    state = new char[strlen(st) + 1];
    strcpy(state, st);
    zipCode = zip;
    phone = new char[strlen(ph) + 1];
    strcpy(phone,ph);
}
PersonData::~PersonData()
{
    cout << "PersonData Destructor is called\n";
    if (lastName != nullptr)
    {
        delete[]  lastName;
        lastName = nullptr;
    }
    if (firstName != nullptr)
    {
        delete[] firstName;
        firstName = nullptr;
    }
    if (address != nullptr)
    {
        delete[] address;
        address = nullptr;
    }
    if (city != nullptr)
    {
        delete[] city;
        city = nullptr;
    }
    if (state != nullptr)
    {
        delete[] state;
        state = nullptr;
    }
    if (phone != nullptr)
    {
        delete[] phone;
        phone = nullptr;
    }
}
const char* PersonData::getAddress() const
{
    return address;
}
const char* PersonData::getLastName() const
{
    return lastName;
}
const char* PersonData::getFirstName() const
{
    return firstName;
}
const char* PersonData::getCity() const
{
    return city;
}
const char* PersonData::getState() const
{
    return state;
}
const char* PersonData::getPhone() const
{
    return phone;
}
int PersonData::getZip() const
{
    return zipCode;
}
PersonData::PersonData(const PersonData& rhs)
{
    cout << "Person data default constructor called\n";
    lastName = new char[strlen(rhs.lastName) + 1];
    strcpy(lastName, rhs.lastName);
    firstName = new char[strlen(rhs.firstName) + 1];
    strcpy(firstName, rhs.firstName);
    address = new char[strlen(rhs.address) + 1];
    strcpy(address, rhs.address);
    city = new char[strlen(rhs.city) + 1];
    strcpy(city, rhs.city);
    state = new char[strlen(rhs.state) + 1];
    strcpy(state, rhs.state);
    zipCode = rhs.zipCode;
    phone = new char[strlen(rhs.phone) + 1];
    strcpy(phone, rhs.phone);
}
const PersonData& PersonData:: operator = (const PersonData&rhs)
{
    if (this != &rhs)
    {
        if (lastName != nullptr)
        {
            delete[]  lastName;
                lastName = nullptr;
        }
        if (firstName != nullptr)
        {
            delete[] firstName;
                firstName = nullptr;
        }
        if (address != nullptr)
        {
            delete[] address;
            address = nullptr;
        }
        if (city != nullptr)
        {
            delete[] city;
            city = nullptr;
        }
        if (state != nullptr)
        {
            delete[] state;
            state = nullptr;
        }
        if (phone != nullptr)
        {
            delete[] phone;
            phone = nullptr;
        }
        lastName = new char[strlen(rhs.lastName) + 1];
        strcpy(lastName, rhs.lastName);
        firstName = new char[strlen(rhs.firstName) + 1];
        strcpy(firstName, rhs.firstName);
        address = new char[strlen(rhs.address) + 1];
        strcpy(address, rhs.address);
        city = new char[strlen(rhs.city) + 1];
        strcpy(city, rhs.city);
        state = new char[strlen(rhs.state) + 1];
        strcpy(state, rhs.state);
        zipCode = rhs.zipCode;
        phone = new char[strlen(rhs.phone) + 1];
        strcpy(phone, rhs.phone);
    }
    return *this;
}


void PersonData::setAddress(const char* ad)
{
    strcpy(address, ad);
}
void PersonData::setLastName(const char* lt)
{
    strcpy(lastName, lt);
}
void PersonData::setFirstName(const char* ft)
{
    strcpy(firstName,ft);
}
void PersonData::setCity(const char*ct)
{
    strcpy(city, ct);
}
void PersonData::setState(const char* st)
{
    strcpy(state, st);
}
void PersonData::setPhone(const char* ph)
{
    strcpy(phone,ph);
}
void PersonData::setZip(int a)
{
    zipCode = a;
}
void PersonData::display()
{
    cout << "The name of Person is : " <<getFirstName() << " " << getLastName() << endl;
    cout << "Address is " << getAddress() << endl;
    cout << "City is   " << getCity() << "  :  " << "State is   " << getState() << endl;
    cout << "zip code is :   " << getZip() << " : " << "Phone is :   " << getPhone() << endl;
}