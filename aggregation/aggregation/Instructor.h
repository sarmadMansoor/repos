#ifndef INSTRUCTOR_CLASS
#define INSTRUCTOR_CLASS

class Instructor
{
    char* lastName;
    char* firstName;
    char* officeNumber;
    int strlen(const char* str);
    void strcpy(char* dest, const char* src);

public:
    Instructor();
    Instructor(const char* ln, const char* fn, const char* on);
    Instructor(const Instructor& rhs);
    const Instructor& operator = (const Instructor& rhs);
    void display();
    ~Instructor();
    void setLastName(const char* ln);
    void setFirstName(const char* ln);
    void setOfficeNo(const char* ln);
    const char* getLastName() const;
    const char* getFirstName() const;
    const char* getOfficeNumber() const;
};
#endif
