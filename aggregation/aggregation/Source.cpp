#include <iostream>
#include "Instructor.h"
#include "TextBook.h"
#include "Course.h"
using namespace std;
int main()
{
    Course c1("Introducting to computing", "Starting with c++", "Tony Gaddis", "Allah ditaha", "Ghazali", "Ahamad", "0311-0524867");
    cout << "-------------------------------------------------------------\n";
    Course c2;
    cout << "-------------------------------------------------------------\n";
    c2 = c1;
    cout << "-------------------------------------------------------------\n";
    c2.display();
    cout << "-------------------------------------------------------------\n";
}
