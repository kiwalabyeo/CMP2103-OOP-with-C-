// Personal income tax calculator for residents and non-residents.
// Prompts for residence status (0 = resident, 1 = non-resident) and taxable income
// then computes tax according to the schedule in the exercise.

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

static double parse_amount(const string &s)
{
    string t;
    for (char c : s)
        if (isdigit((unsigned char)c) || c == '.' || c == '-')
            t.push_back(c);
    if (t.empty())
        return 0.0;
    return stod(t);
}

long long compute_tax(bool resident, double income)
{
    const double B1 = 2820000.0;
    const double B2 = 4020000.0;
    const double B3 = 4920000.0;
    const double TOP = 120000000.0;

    double tax = 0.0;

    if (resident)
    {
        if (income <= B1)
        {
            tax = 0.0;
        }
        else if (income <= B2)
        {
            tax = (income - B1) * 0.10;
        }
        else if (income <= B3)
        {
            tax = (income - B2) * 0.20 + 120000.0;
        }
        else if (income <= TOP)
        {
            tax = (income - B3) * 0.30 + 300000.0;
        }
        else
        {
            tax = (income - B3) * 0.30 + 300000.0 + (income - TOP) * 0.10;
        }
    }
    else
    {
        if (income <= B2)
        {
            tax = income * 0.10;
        }
        else if (income <= B3)
        {
            tax = (income - B2) * 0.20 + 402000.0;
        }
        else if (income <= TOP)
        {
            tax = (income - B3) * 0.30 + 582000.0;
        }
        else
        {
            tax = (income - B3) * 0.30 + 582000.0 + (income - TOP) * 0.10;
        }
    }

    return (long long)llround(tax);
}

int main()
{
    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    int status;
    if (!(cin >> status))
        return 0;

    cout << "Enter the taxable income: ";
    string income_str;
    if (!(cin >> income_str))
        return 0;

    double income = parse_amount(income_str);
    long long tax = compute_tax(status == 0, income);

    cout << "Tax is " << tax << "." << endl;
    return 0;
}
