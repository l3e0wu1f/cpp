//
//  JoshLewisProj4.cpp
//
//
//  Created by Josh Lewis on 10/4/17.
//
//

#include <iostream>
using namespace std;

// Temperature at Depth Calculator

void print_introduction();
double celsius_at_depth(double d);
double celsius_to_fahrenheit(double c);
void print_conclusion(double d);

int main() {
    
    double depth;
    char choice;
    
    do {
        print_introduction();
        
        cout << "Enter a depth in KM: ";
        cin >> depth;
        
        print_conclusion(depth);
        
        cout << " Would you like to do it again? (Y/N): ";
        cin >> choice;
        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
            cout << "That is not a valid entry. Would you like to do it again? (Y/N): ";
            cin >> choice;
            continue;
        }
    } while (choice == 'Y' || choice == 'y');
    
    if (choice == 'N' || choice == 'n')
        cout << "Goodbye!";
    
    return 0;
}

// Introduction to calculation
void print_introduction(){
    cout << "Hello! The program will tell you the temperature of the earth at any depth.\n";
}

// Calculates degree Celsius based on depth
double celsius_at_depth(double d){
    return 10 * d + 20;
}

// Calculates degree Fahrenheit given temp in Celsius
double celsius_to_fahrenheit(double c){
    return 1.8 * c + 32;
}

// Conclusion of calculation
void print_conclusion(double d){
    cout << "The temperature of the earth at a depth of " << d << " KM is " << celsius_at_depth(d) << endl;
    cout << "in Celsius, and " << celsius_to_fahrenheit(celsius_at_depth(d)) << " in Fahrenheit.";
}
