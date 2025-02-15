#include"Array.h"

void Array::copyArray(Array* source, int* destination)
{
    for (int i = 0; i < source->size; i++)
    {
        destination[i] = source->data[i];
    }
}

Array::Array(int count, ...)
{
    va_list list;
    va_start(list, count);
    va_arg(list, int);
    va_end(list);
}

//Array::Array(int n)
//{
//    size = n;
//    data = new int[n];
//}

Array::Array(const Array& ref)
{
    size = ref.size;
    copyArray(this, ref.data);
}

Array::~Array()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }
}

int& Array::operator[](int index)
{
    return data[index];
}

const int& Array::operator[](int index) const
{
    return data[index];
}

int Array::getSize() const
{
    return size;
}

void Array::reSize(int cap)
{
    if (cap <= 0)
    {
        this->~Array();
        return;
    }
    int* temp = new int[cap];
    if (cap)
    {
        copyArray(this, temp);
    }
    this->~Array();
    data = temp;
    size = cap;
}