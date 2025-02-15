#ifndef COMMISSION_H
#define COMMISSION_H

#include <string> // C++ standard string class
using namespace std;

class CommissionEmployee
{
public:
    CommissionEmployee(const string& first, const string& last, const string& ssn,
        double sales = 0.0, double rate = 0.0);

    void setFirstName(const string& first); 
    string getFirstName() const; 

    void setLastName(const string& last); 
    string getLastName() const; 

    void setSocialSecurityNumber(const string& ssn); 
    string getSocialSecurityNumber() const; 

    void setGrossSales(double sales); 
    double getGrossSales() const; 

    void setCommissionRate(double rate); 
    double getCommissionRate() const; 

    double earnings() const; 
    void print() const; 

private :
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales; // gross weekly sales
    double commissionRate;
};

#endif // COMMISSION_H
