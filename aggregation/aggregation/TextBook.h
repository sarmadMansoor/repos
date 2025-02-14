#ifndef TEXT_BOOK_CLASS
#define TEXT_BOOK_CLASS


class TextBook
{
    char* title;
    char* author;
    char* publisher;
    int strlen(const char* str);
    void strcpy(char* dest, const char* src);
public:
    TextBook();
    TextBook(const char* tl, const char* au, const char* pb);
    TextBook(const TextBook & rhs);
    const TextBook&  operator = (const TextBook& rhs);
    void  display();
     ~TextBook();
    void setAuthor(const char* ln);
    void  setTitle(const char* ln);
    void  setPublisher(const char* ln);
    const char* getAuthor() const;
    const char* getTitle() const;
    const char* getPublisher() const;
};
#endif // !TEXT_BOOK_CLASS
