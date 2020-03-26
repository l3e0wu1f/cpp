/* Do Programming Project 3 on page 740: Redo Practice Program 1 from Chapter 11.
 * Modify the definition of the class Money shown in display 11.8 so that all of the following are added:
 * Overloded operators for <, <=, >, >=, and the Money percent member function.
 *
 * Author: Josh Lewis
 * Version: 3/4/2018
 * Interface File
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
using namespace std;

#ifndef JOSHLEWISMONEY_H
#define JOSHLEWISMONEY_H

class Money
{
private:
    long allCents;

public:
    Money();
    Money(long dollars);
    Money(long dollars, int cents);
    double getValue() const;
    friend Money operator +(const Money &amount1, const Money &amount2);
    friend Money operator -(const Money &amount1, const Money &amount2);
    friend Money operator -(const Money &amount1);
    friend bool operator ==(const Money &amount1, const Money &amount2);
    friend bool operator <(const Money &amount1, const Money &amount2);
    friend bool operator <=(const Money &amount1, const Money &amount2);
    friend bool operator >(const Money &amount1, const Money &amount2);
    friend bool operator >=(const Money &amount1, const Money &amount2);
    Money percent(int percentFigure) const;
};

#endif
