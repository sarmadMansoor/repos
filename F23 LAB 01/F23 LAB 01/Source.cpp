#include <iostream>
using namespace std;



//Question number 1 
int getStringLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}
char* getVowelsFreeString(const char* const str)
{
    int j = 0;
    char* result = new char[getStringLength(str) + 1];
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
            && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U')
        {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';
    return result;
}

bool isDigit(char num)
{
    if (num >= '0' && num <= '9')
    {
        return true;
    }
    return false;
}

bool isInt(const char* arr)
{
    if (*arr == '-')
    {
        arr = arr + 1;
    }
    while (*arr != '\0')
    {
        if (!isDigit(*arr))
        {
            return false;
        }
        arr = arr + 1;
    }
    return true;
}

int charToInt(const char* str)
{
    int result = 0;
    bool isNeg = false;
    if (*str == '-')
    {
        isNeg = true;
        str++;
    }
    while (*str != '\0')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (isNeg)
    {
        result = result * -1;
        return result;
    }
    return result;
}

int inputNum()
{
    const int size = 50;
    char input[size];
    bool status = false;
    int num;

    while (!status)
    {
        cout << "Enter Number: ";
        cin.getline(input, size);

        if (isInt(input))
        {
            num = charToInt(input);
            status = true;
        }
        else
        {
            cout << "Not a valid integral value." << endl;
        }
    }
    return num;
}




//Question number 3 
void copyArray(char* destination, const char* source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void reSize(char* & arr, int* size)
{
    char* newArr = new char[*size * 2];
    copyArray(newArr, arr);
    delete[] arr;
    arr = newArr;
    newArr = nullptr;
    *size *= 2;
}




char* inputString()
{
    int size = 10;
    char* str = new char[size];
    int i = 0;
    char c;

    while (cin.get(c) && c != '\n')
    {
        str[i] = c;
        i++;

        if (i == size)
        {
            reSize(str, &size);
        }
    }
    str[i] = '\0';
    return str;
}




int main()
{

    /*char* arr = inputString();
    cout << arr;*/
         int num = inputNum();
    cout << "The Number is: " << num << '\n';
    return 0;

    /*const int num = 9;
    int arr[num];*/
  /*  const char* myStr = "";
    char* noVowels = getVowelsFreeString(myStr);

    std::cout << noVowels << std::endl;

    delete[] noVowels;*/
}