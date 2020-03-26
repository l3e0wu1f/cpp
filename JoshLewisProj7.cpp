// This is the program file of project 7: A 24-Hour Clock Converter
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 4/11/2018

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class TimeFormatMistake: public exception {
    virtual const char* what() const throw()
    {
        return "Time is invalid";
    }
};

void getTimes(string str, int &hours, int &minutes) {
    if(str.length() != 5) {
        throw TimeFormatMistake();
    }
    if(str[0] < '0' || str[0] > '9') {
        throw TimeFormatMistake();
    }
    if(str[1] < '0' || str[1] > '9') {
        throw TimeFormatMistake();
    }
    if(str[2] != ':') {
        throw TimeFormatMistake();
    }
    if(str[3] < '0' || str[3] > '9') {
        throw TimeFormatMistake();
    }
    if(str[4] < '0' || str[4] > '9') {
        throw TimeFormatMistake();
    }
    hours = (10 * (str[0]-'0')) + (str[1] - '0');
    minutes = (10 * (str[3]-'0')) + (str[4] - '0');
    if((hours < 0 || hours > 24) || (minutes < 0 || minutes > 59)) {
        throw TimeFormatMistake();
    }
}

int main() {
    string str;
    string period;
    int hours, mins;
    while(true) {
        cout << "Enter time in 24-hour notation: ";
        cin >> str;
        try {
            getTimes(str, hours, mins);
            if(hours >= 12 && hours < 24) {
                period = "PM";
            } else {
                period = "AM";
            }
            hours %= 12;
            if(hours == 0) {
                hours = 12;
            }
            cout << "That is the same as " << hours << ":" << setfill('0') << setw(2) << mins << " " << period << endl;
        } catch (exception& e) {
            cout << "There is no such time as " << str << endl;
        }
        cout << "Again? (y/n)";
        cin >> str;
        if(str != "y" && str != "Y") {
            cout << "Goodbye!";
            break;
        }
    }
    return 0;
}
