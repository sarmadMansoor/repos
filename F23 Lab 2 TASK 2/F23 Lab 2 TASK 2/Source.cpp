#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cTime>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

struct Token
{
    int tokenNumber;
    Date tokenDate;
    Time tokenTime;
};

struct ServiceCounter
{
    int counterNumber;
    Token list[100];
    int tokensCount;
};

void printDate(Date date)
{
    cout << "Date: " << date.day << ":" << date.month << ":" << date.year << '\n';
}
void printTime(Time time)
{
    cout << "Time: ";
    bool PM_Status = false;
    if (time.hours > 12)
    {
        cout << time.hours - 12;
        PM_Status = true;
    }
    cout << ":" << time.minutes << ":" << time.seconds ;
    PM_Status == true ? cout << " PM\n" : cout << " AM\n";
}
//
Token generateToken()
{
    static int uniqueTokenIntializer = 1;

    Token newToken;
    newToken.tokenNumber = uniqueTokenIntializer++;


    time_t t = time(0);
    tm curTime = *localtime(&t);
    newToken.tokenDate.day = curTime.tm_mday;
    newToken.tokenDate.month = curTime.tm_mon + 1;
    newToken.tokenDate.year = curTime.tm_year + 1900;


    newToken.tokenTime.hours = curTime.tm_hour;
    newToken.tokenTime.minutes = curTime.tm_min;
    newToken.tokenTime.seconds = curTime.tm_sec;

    return newToken;
}
void printToken(Token token)
{
    cout << "Token # : " << token.tokenNumber << endl;
    printTime(token.tokenTime);
    printDate(token.tokenDate);
}
void initializeServiceCounter(ServiceCounter& counter)
{
    static int uniqueCounterNumber = 1;
    counter.counterNumber = uniqueCounterNumber++;
    counter.tokensCount = 0;
}
void assignToken(ServiceCounter& rfs, Token token)
{
    if (rfs.tokensCount < 100)
    {
        rfs.list[rfs.tokensCount] = token;
        rfs.tokensCount++;
    }
}
void serviceToken(ServiceCounter& counter)
{
    if (counter.tokensCount > 0)
    {
        for (int i = 0; i < counter.tokensCount - 1; ++i)
        {
            counter.list[i] = counter.list[i + 1];
        }
        counter.tokensCount--;
    }
}
void printTokensAtServiceCounter(ServiceCounter counter)
{
    cout << "*** Token Queue Waiting For Service @ Counter #" << counter.counterNumber << " ***" << endl;

    if (counter.tokensCount > 0)
    {
        for (int i = 0; i < counter.tokensCount; ++i)
        {
            printToken(counter.list[i]);
        }
    }
    else
    {
        cout << "--> Queue is Empty <---" << endl;
    }
}
//long long int convertToBinary(int num)
//{
//    long long int reverseBinaryValue = 1;
//    while (num > 0)
//    {
//        int rem = num % 2;
//        num = num / 2;
//        reverseBinaryValue = reverseBinaryValue * 10 + rem;
//    }
//    long long int binaryValue =0;
//
//
//}



class Polynomial
{
    int* coeffs;
    int degree;
public:
    Polynomial()
    {
        coeffs = nullptr;
        degree = 0;
    }
    Polynomial(int d,int * arr):Polynomial()
    {
        if (d <= 0)
            return;
        degree = d;
        coeffs = new int[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coeffs[i] = arr[degree-i];
        }
    }
    void print()
    {
        for (int i = 0; i < degree; i++)
        {
            int num = coeffs[degree - i];
            if (num == 0)
                num;
            else if (i != degree)
                cout << num << "x^" << degree - i << " + ";
        }
        cout << coeffs[0] << endl;
       /* for (int i = 0; i <= degree; i++)
        {
            int num = coeffs[degree - i];
            if (num == 0)
                num;
            else if (i != degree)
                cout << num << "x^" << degree - i << " + ";
            else
                cout << num << endl;
        }*/
    }
    ~Polynomial()
    {
        if (coeffs != nullptr)
        {
            delete[] coeffs;
            coeffs = nullptr;
            degree = 0;
        }
    }
    Polynomial& operator = (const Polynomial& rfs)
    {
        if (this == &rfs)
            return *this;
        this->~Polynomial();
        if (rfs.coeffs == nullptr)
            return *this;
        degree = rfs.degree;
        coeffs = new int[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coeffs[i] = rfs.coeffs[i];
        }
        return  *this;
    }
    Polynomial(const Polynomial& rfs)
    {
        *this = rfs;
    }
    Polynomial operator + (const Polynomial& rfs)
    {
        Polynomial sum{};
        Polynomial min{};
        if (degree > rfs.degree)
        {
            sum = *this;
            min = rfs;
        }
        else
        {
            sum = rfs;
            min = *this;
        }
        for (int i = 0;( i <= degree) && (i <= rfs.degree); i++)
        {
            sum.coeffs[i] += min.coeffs[i];
        }
        return sum;
    }
    Polynomial operator - (const Polynomial& rfs)
    {
        Polynomial subtract{};
        Polynomial min{};
        if (degree > rfs.degree)
        {
            subtract = *this;
            min = rfs;
        }
        else
        {
            subtract = rfs;
            min = *this;
        }
        for (int i = 0; (i <= degree) && (i <= rfs.degree); i++)
        {
            subtract.coeffs[i] -= min.coeffs[i];
        }
        return subtract;
    }
};
int main()
{
   int a[6] = { 6,5,0,3,2,1 };
   Polynomial a1{ 5,a };

   int a2[4] = {2,0,0,0};
   Polynomial a3{ 3,a2 };
   a3.print();

 // (a1 - a3).print();







   /* int n = 2;
   int  sum = 0;
   for (int i = 1; i < n; i++)
   {
       for (int j = 1; j < i * i; j++)
       {
           if (j % i == 0)
           {
               for (int k = 0; k < j; k++)
                   sum++;
           }
       }
   }

   cout << sum << endl;*/
    /*Token x = generateToken();
    Token y= generateToken();
    printToken(x);

    printToken(y);




    cout << "\n-------------------------------------------------\n";

    ServiceCounter a, b;
    initializeServiceCounter(a);
    initializeServiceCounter(b);

    assignToken(a, generateToken());
    assignToken(b, generateToken());
    assignToken(a, generateToken());
    assignToken(a, generateToken());

    assignToken(b, generateToken());
    assignToken(b, generateToken());

    assignToken(b, generateToken());
    assignToken(b, generateToken());

    assignToken(b, generateToken());
    assignToken(a, generateToken());

    printTokensAtServiceCounter(a);

    cout << "\n-------------------------------------------------\n";

    serviceToken(a);
    printTokensAtServiceCounter(a);

    cout << "\n-------------------------------------------------\n";

    serviceToken(a);
    serviceToken(a);

    serviceToken(a);
    printTokensAtServiceCounter(a);
    cout << "\n-------------------------------------------------\n";


    serviceToken(b);
    printTokensAtServiceCounter(b);*/


}



//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//#include <ctime> 
//
//struct Time
//{
//    int hours;
//    int minutes;
//    int seconds;
//};
//
//Time getTimeDifference(Time rfs)
//{
//    Time currentTime;
//    time_t t = time(0);
//    tm curTime = *localtime(&t);
//    currentTime.hours = curTime.tm_hour;
//    currentTime.minutes = curTime.tm_min;
//    currentTime.seconds = curTime.tm_sec;
//
//    long long int currentTotalSec= currentTime.hours * 3600 + currentTime.minutes * 60 + currentTime.seconds;
//    long long int rfsTotalSec = rfs.hours * 3600 + rfs.minutes * 60 + rfs.seconds;
//    long long int timeDifferenceInSec = currentTotalSec - rfsTotalSec;
//
//
//   timeDifferenceInSec < 0 ? timeDifferenceInSec *= -1 : timeDifferenceInSec;
//
//    Time timeDiffernce;
//    timeDiffernce.hours = timeDifferenceInSec / 3600;
//    timeDiffernce.minutes = (timeDifferenceInSec % 3600) / 60;
//    timeDiffernce.seconds = timeDifferenceInSec % 60;
//
//    return timeDiffernce;
//
//}
//
//
//int main()
//{
//    Time t1 = { 20, 15, 50 };
//    Time diffTime = getTimeDifference(t1);
//    cout << diffTime.hours << " : " << diffTime.minutes << " : " << diffTime.seconds << endl;
//
//    return 0;
//}
