#ifndef COURSE_CLASS
#define COURSE_CLASS
#include <iostream>
#include "TextBook.h"
#include "Instructor.h"
using namespace std;
class Course
{
	char* name;
	TextBook  book;
	Instructor teacher;
    int strlen(const char* str);
    void  strcpy(char* dest, const char* src);
public:
    Course();
    Course(const char* n, const char* tl, const char* au,
        const char* pb, const char* ln, const char* fn,
        const char* on);
    ~Course();
    void display();
    const Course& operator = (const Course& rhs);
    Course(const Course& rhs);

};

#endif

