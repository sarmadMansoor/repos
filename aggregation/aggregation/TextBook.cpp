#include <iostream>
using namespace std;
#include "Textbook.h"
int TextBook::strlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void  TextBook::strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null terminator to the destination string
}

TextBook::TextBook()
{
    cout << "Textbook Default Constructor is called\n";
    title = new char[2];
    strcpy(title, "");
    author = new char[2];
    strcpy(author, "");
    publisher = new char[2];
    strcpy(publisher, "");
}
TextBook::TextBook(const char* tl, const char* au, const char* pb)
{
    cout << "Textbook Overloaded Constructor is called\n";
    title = new char[strlen(tl) + 1];
    strcpy(title, tl);
    author = new char[strlen(au) + 1];
    strcpy(author, au);
    publisher = new char[strlen(pb) + 1];
    strcpy(publisher, pb);
}
TextBook::TextBook(const TextBook& rhs)
{
    cout << "TextBook copy constructor is called\n";
    title = new char[strlen(rhs.title) + 1];
    strcpy(title, rhs.title);
    author = new char[strlen(rhs.author) + 1];
    strcpy(author, rhs.author);
    publisher = new char[strlen(rhs.publisher) + 1];
    strcpy(publisher, rhs.publisher);
}
const TextBook& TextBook:: operator = (const TextBook& rhs)
{
    cout << "TextBook = operator is called\n";
    if (this != &rhs)
    {
        if (author != nullptr)
        {
            delete[] author;
            author = nullptr;
        }
        if (title != nullptr)
        {
            delete[] title;
            title = nullptr;
        }
        if (publisher != nullptr)
        {
            delete[] publisher;
            publisher = nullptr;
        }
        title = new char[strlen(rhs.title) + 1];
        strcpy(title, rhs.title);
        author = new char[strlen(rhs.author) + 1];
        strcpy(author, rhs.author);
        publisher = new char[strlen(rhs.publisher) + 1];
        strcpy(publisher, rhs.publisher);
    }
    return *this;
}
void  TextBook::display()
{
    cout << "The title of book is  " << title << endl;
    cout<<"Name of auther is : " << author << endl;
    cout << "Publisher is :  " << publisher << endl;
}
TextBook:: ~TextBook()
{
    cout << "Textbook Destructor is called\n";

    if (author != nullptr)
    {
        delete[] author;
        author = nullptr;
    }
    if (title != nullptr)
    {
        delete[] title;
        title = nullptr;
    }
    if (publisher != nullptr)
    {
        delete[] publisher;
        publisher = nullptr;
    }

}
void TextBook :: setAuthor(const char* ln)
{
    strcpy(author, ln);
}
void  TextBook::setTitle(const char* ln)
{
    strcpy(title, ln);
}
void  TextBook::setPublisher(const char* ln)
{
    strcpy(publisher, ln);
}
const char* TextBook::getAuthor() const
{
    return author;
}
const char* TextBook::getTitle() const
{
    return title;
}
const char* TextBook::getPublisher() const
{
    return publisher;
}