//
//  JoshLewisProj5.cpp
//
//
//  Created by Josh Lewis on 10/16/17.
//
//

// Day of the Week Calendar Program

#include <iostream>
using namespace std;

void testMenu();
// postcondition: the test menu is displayed for choice

bool isLeapYear(int year);

int getCenturyValue(int year);

int getYearValue(int year);

int getMonthValue(int month, int year);

string dayOfWeek(int month, int day, int year);
// precondition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// postcondition: the name of the day of week is returned; 1, then MONDAY is returned and so on.

int main() {
    
    int choice;
    int day, month, year;
    char slash = '/';
    
    do {
        testMenu();
        
        cout << "Please choose from menu: ";
        cin >> choice;
        switch(choice){
            case 1: // check if a given year is leap year
                cout << "Please enter a year: ";
                cin >> year;
                if(isLeapYear(year))
                    cout << "Year " << year << "is a leap year" << endl;
                else
                    cout << "Year " << year << "is NOT a leap year" << endl;
                break;
            case 2: // calculate the century value of a given year
                cout << "Please enter a year: ";
                cin >> year;
                cout << "The century value is: " << getCenturyValue(year) << endl;
                break;
            case 3: // calculate the year value in a given year
                cout << "Please enter a year: ";
                cin >> year;
                cout << "The year value is: " << getYearValue(year) << endl;
                break;
            case 4: // calculate the month value of a given month in a given year
                cout << "Please enter a month and year (M/YYYY): ";
                cin >> month >> slash >> year;
                cout << "The month is: " << getMonthValue(month, year) << endl;
                break;
            case 5: // calculate the day of week of a given date
                cout << "Please enter a month, day, and year (M/DD/YYYY): ";
                cin >> month >> slash >> day >> slash >> year;
                cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
                break;
            case 6: // print out the name of a given day of week
                cout << "Please enter a number for the day of the week (0 for Sunday, 1 for Monday, etc): ";
                cin >> day;
                cout << "The day of the week is: " << dayOfWeek(day) << endl;
                break;
            case 7:
                cout << "Have you tested all functions yet? If not, please re-run the program.\n";
                break;
            default:
                cout << "Sorry, that is not a valid option. Please choose from menu and try again.\n";
                break;
        }
    } while (choice != 7);
    
    return 0;
}

// Displays test menu
void testMenu(){
    cout << "    *************************************" << endl;
    cout << "    *           Test Menu               *" << endl;
    cout << "    * 1. isLeapYear                     *" << endl;
    cout << "    * 2. getCenturyValue                *" << endl;
    cout << "    * 3. getYearValue                   *" << endl;
    cout << "    * 4. getMonthValue                  *" << endl;
    cout << "    * 5. dayOfWeek(month, day, year)    *" << endl;
    cout << "    * 6. dayOfWeek(day)                 *" << endl;
    cout << "    * 7. Quit                           *" << endl;
    cout << "    *************************************" << endl;
}

// Determines whether or not it's Leap Year
bool isLeapYear(int& year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

// Calculates Century
int getCenturyValue(int& year){
    int century = year / 100;
    int remainder = century % 4;
    return (3 - remainder) * 2;
}

// Calculates year value past century
int getYearValue(int& year){
    int decade = ((year / 10) % 10) + (year % 10);
    return decade + (decade / 4);
}

// Returns name of month based on input
int getMonthValue(int& month, int& year){
    switch(month){
        case 1: // January
            if (isLeapYear(year) == true)
                return 6;
            else
                return 0;
            break;
        case 2: // February
            if (isLeapYear(year) == true)
                return 2;
            else
                return 0;
            break;
        case 3: // March
            return 3;
            break;
        case 4: // April
            return 6;
            break;
        case 5: // May
            return 1;
            break;
        case 6: // June
            return 4;
            break;
        case 7: // July
            return 6;
            break;
        case 8: // August
            return 2;
            break;
        case 9: // September
            return 5;
            break;
        case 10: // October
            return 0;
            break;
        case 11: // November
            return 3;
            break;
        case 12: // December
            return 5;
            break;
    }
}

// Displays day of week based on date input
string dayOfWeek(int month, int& day, int year){
    cout << "Please enter day of the month: ";
    cin >> day;
    int sum = day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year);
    switch(sum % 7){
        case 0:
            return "Sunday";
            break;
        case 1:
            return "Monday";
            break;
        case 2:
            return "Tuesday";
            break;
        case 3:
            return "Wednesday";
            break;
        case 4:
            return "Thursday";
            break;
        case 5:
            return "Friday";
            break;
        case 6:
            return "Saturday";
            break;
        default:
            return "Not a valid entry";
            break;
    }
}
