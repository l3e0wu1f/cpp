/* Do Programming Project 3 on page 740: Redo Practice Program 1 from Chapter 11.
 * Modify the definition of the class Money shown in display 11.8 so that all of the following are added:
 * Overloded operators for <, <=, >, >=, and the Money percent member function.
 *
 * Author: Josh Lewis
 * Version: 3/4/2018
 * Implementation File
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include "JoshLewisMoney.h"
using namespace std;




Money::Money()
{
    allCents = 0;
}

Money::Money(long dollars)
{
    allCents = dollars * 100;
}

Money::Money(long dollars, int cents)
{
    if(dollars * cents < 0) // If one is negative, and the other is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars * 100 + cents;
}

double getValue() const
{
    return allCents / 100.0;
}

friend Money operator +(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

friend Money operator -(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}

friend Money operator -(const Money &amount1)
{
    Money temp;
    temp.allCents = -amount.allCents;
    return temp;
}

friend bool operator ==(const Money &amount1, const Money &amount2)
{
    return (amount1.allCents == amount2.allCents);
}

friend bool operator <(const Money &amount1, const Money &amount2)
{
    return (amount1.allCents < amount2.allCents);
}

friend bool operator <=(const Money &amount1, const Money &amount2)
{
    return (amount1.allCents <= amount2.allCents);
}

friend bool operator >(const Money &amount1, const Money &amount2)
{
    return (amount1.allCents > amount2.allCents);
}

friend bool operator >=(const Money &amount1, const Money &amount2)
{
    return (amount1.allCents >= amount2.allCents);
}

Money::Money percent(int percentFigure) const
{
    long totalCents = (long) round(allCents * (percentFigure / 100.0));
    long dollars = totalCents / 100;
    int cents = totalCents % 100;
    return Money(dollars, cents);
}

istream& operator >>(istream& ins, Money& amount)
{
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative; // set to true if input is negative
    
    ins >> oneChar;
    if(oneChar == '-')
    {
        negative = true;
        ins >> oneChar; // read '$'
    }
    else
    {
        negative = false;
    }
    // If input is legal, then oneChar == '$'
    
    ins >> dollars >> decimalPoint >> digit1 >> digit2;
    
    if(oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error: illegl form for money input.\n";
        exit(1);
    }
    
    cents = digitToInt(digit1) * 10 + digitToInt(digit2);
    
    amount.allCents = dollars * 100 + cents;
    if(negative)
    {
        amount.allCents = -amount.allCents;
    }
    return ins;
}

int digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

ostream& operator <<(ostream& outs, const Money& amount)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;
    
    if(amount.allCents < 0)
    {
        outs << "-$" << dollars << '.';
    }
    else
    {
        outs << "$" << dollars << '.';
    }
    
    if(cents < 10)
    {
        outs << '0';
    }
    outs << cents;
    
    return outs;
}
