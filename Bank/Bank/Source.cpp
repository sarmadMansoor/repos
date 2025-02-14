#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <string>
using namespace std;
SavingsAccount f()
{
	SavingsAccount s1, s2;
	if (2 % 3 == 0)
	{
		return s1;
	}
	else
	{
		return s2;
	}
}
class Quiz
{
public:
    int a;
    Quiz(int i = 1)
    {
        a = i;
        cout << "\nQuiz()" << a ;
    }
    Quiz(const Quiz& ref)
    {
        a = ref.a;
        cout << "\nQuiz (const Quiz &)" << a ;
    }
    ~Quiz()
    {
        cout << "\n~Quiz()"<<a;
    }
};

Quiz f(Quiz a, Quiz b, Quiz&  c)
{
    static Quiz y(23);
    Quiz x(24);
    return x;
}

void g()
{
    static Quiz z(100);
}

void wow(Quiz& s)
{
   
}

 /*Quiz g1(10);
 static Quiz g2(11);
Quiz g3(12);*/
class B
{
    int a;
    static const int b = 1;
public:
    B()
    {
        
    }
};
void merge(int* arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e-mid;
    int* left = new int[len1];
    int* right = new int[len2];
    int mainIndex = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mainIndex++];
    }
    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (left[index1] > right[index2])
            arr[mainIndex++] = right[index2++];
        else
            arr[mainIndex++] = left[index1++];
    }

    while (index1 < len1)
    {
        arr[mainIndex++] = left[index1++];
    }

    while (index2 < len2)
    {
        arr[mainIndex++] = right[index2++];
    }
}
void mergeSort(int* arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr,mid+1,e);
    merge(arr, s, e);
}
#include <iostream>

int getPascalNumber(int r, int c)
{
    if (c == 0 || c == r)
    {
        return 1;
    }
    return getPascalNumber(r - 1, c - 1) + getPascalNumber(r - 1, c);
}

int main()
{
    int row = 5, column = 2;
    std::cout << "Pascal's Triangle value at row " << row << " and column " << column
        << " is: " << getPascalNumber(row, column) << std::endl;
    return 0; 

    /*int a[7] = { 3,2,4,5,1,0,6 };
    mergeSort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }*/
    /*Quiz r,s(2), t(3);
    f(r, s, t);
    wow(r);
    f(r, s, t);*/
	
}