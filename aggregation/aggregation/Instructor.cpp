#include <iostream>
#include "Instructor.h"
using namespace std;

int Instructor::strlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void  Instructor::strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null terminator to the destination string
}


Instructor::Instructor()
{
    cout << "Instructor Default Constructor is called\n";
    lastName = new char[2];
    strcpy(lastName, "");
    firstName = new char[2];
    strcpy(firstName, "");
    officeNumber = new char[2];
    strcpy(officeNumber, "");
}
Instructor::Instructor(const char* ln, const char* fn, const char* on)
{
    cout << "Instructor Overloaded Constructor is called\n";
    lastName = new char[strlen(ln) + 1];
    strcpy(lastName, ln);
    firstName = new char[strlen(fn) + 1];
    strcpy(firstName, fn);
    officeNumber = new char[strlen(on) + 1];
    strcpy(officeNumber, on);
}
Instructor::Instructor(const Instructor& rhs)
{
    cout << "Instructor copy constructor is called\n";
    lastName = new char[strlen(rhs.lastName) + 1];
    strcpy(lastName, rhs.lastName);
    firstName = new char[strlen(rhs.firstName) + 1];
    strcpy(firstName, rhs.firstName);
    officeNumber = new char[strlen(rhs.officeNumber) + 1];
    strcpy(officeNumber, rhs.officeNumber);
}
const Instructor& Instructor:: operator = (const Instructor& rhs)
{
    cout << "Instructor = operator is called\n";
    if (this != &rhs)
    {
        if (lastName != nullptr)
        {
            delete[] lastName;
            lastName = nullptr;
        }
        if (firstName != nullptr)
        {
            delete[] firstName;
            firstName = nullptr;
        }
        if (officeNumber != nullptr)
        {
            delete[] officeNumber;
            officeNumber = nullptr;
        }
        lastName = new char[strlen(rhs.lastName) + 1];
        strcpy(lastName, rhs.lastName);
        firstName = new char[strlen(rhs.firstName) + 1];
        strcpy(firstName, rhs.firstName);
        officeNumber = new char[strlen(rhs.officeNumber) + 1];
        strcpy(officeNumber, rhs.officeNumber);
    }
    return *this;
}
void  Instructor::display()
{
    cout << "Name of your Instructor is " << firstName << " " << lastName << endl;
    cout << "Phone no is " << officeNumber << endl;
}
Instructor:: ~Instructor()
{
    cout << "Instructor Destructor is called\n";
    if (lastName != nullptr)
    {
        delete[] lastName;
        lastName = nullptr;
    }
    if (firstName != nullptr)
    {
        delete[] firstName;
        firstName = nullptr;
    }
    if (officeNumber != nullptr)
    {
        delete[] officeNumber;
        officeNumber = nullptr;
    }

}
void Instructor::setLastName(const char* ln)
{
    strcpy(lastName, ln);
}
void  Instructor::setFirstName(const char* ln)
{
    strcpy(firstName, ln);
}
void  Instructor::setOfficeNo(const char* ln)
{
    strcpy(officeNumber, ln);
}
const char* Instructor::getLastName() const
{
    return lastName;
}
const char* Instructor::getFirstName() const
{
    return firstName;
}
const char* Instructor::getOfficeNumber() const
{
    return officeNumber;
}