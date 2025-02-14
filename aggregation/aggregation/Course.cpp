#include <iostream>
#include "Course.h"
using namespace std;
int Course::strlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void Course::strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null terminator to the destination string
}
Course::Course() :book(), teacher()
{
    cout << "Course Default Constructor is called \n";
    name = new char[2];
    strcpy(name, "");
}
Course::Course(const char* n, const char* tl, const char* au,
    const char* pb, const char* ln, const char* fn,
    const char* on) :book(tl, au, pb), teacher(ln, fn, on)
{
    cout << "Course Overloaded Constructor is called\n";
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
Course::~Course()
{
    cout << "Course Destructor is called\n";
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}
void Course::display()
{
    cout << "The Course Name is " << name << endl;
    book.display();
    teacher.display();
}
const Course& Course::operator = (const Course& rhs)
{
    cout << "Course = operator is called\n";
    if (this != &rhs)
    {
        if (name != nullptr)
        {
            delete[] name;
            name = nullptr;
        }
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        book = rhs.book;//call Textbook = operator 
        teacher = rhs.teacher;//call Instructor = operator
    }
    return *this;
}
Course::Course(const Course& rhs) :name(rhs.name), book(rhs.book), teacher(rhs.teacher)
{
    cout << "Course Copy Constructor is called \n";
}
