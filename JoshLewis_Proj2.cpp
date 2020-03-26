//
//  Created by Josh Lewis on 9/10/17.
//  Copyright © 2017 Josh Lewis. All rights reserved.
//

#include <iostream>
using namespace std;

// Basal Metabolic Rate Calculator

int main(){
    
    int weight, height, age;
    char gender;
    char choice = 'Y';
    
    do {
        cout << "Please enter your weight in pounds: ";
        cin >> weight;
        cout << "Please enter your height in inches: ";
        cin >> height;
        cout << "Please enter your age in years: ";
        cin >> age;
        cout << "Please enter your gender (M/F): ";
        cin >> gender;
        
        // Checks for valid gender entry
        if(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f'){
            cout << "Please re-enter a valid gender selection, M or F: ";
            cin >> gender;
        }
        
        double femBMR = 655 + 4.3 * weight + 4.7 * height - 4.7 * age; // Equation for female BMR
        double maleBMR = 66 + 6.3 * weight + 12.9 * height - 6.8 * age; // Equation for male BMR
        
        // Female output
        if(gender == 'F' || gender == 'f'){
            cout << "The number of daily calories needed for this woman to maintain her weight is: " << femBMR << ".\n";
            cout << "Therefore, " << femBMR / 230 << " chocolate bars should be consumed each day to maintain her current weight.\n";
            cout << "Would you like to repeat the calculation? (Y/N): ";
            cin >> choice;
        }
        // Male output
        if(gender == 'M' || gender == 'm'){
            cout << "The number of daily calories needed for this man to maintain his weight is: " << maleBMR << ".\n";
            cout << "Therefore, " << maleBMR / 230 << " chocolate bars should be consumed each day to maintain his current weight.\n";
            cout << "Would you like to repeat the calculation? (Y/N): ";
            cin >> choice;
        }
    } while (choice == 'Y' || choice == 'y');
    
    return 0;
}
