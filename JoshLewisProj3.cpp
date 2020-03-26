//
//  JoshLewisProj3.cpp
//  
//
//  Created by Josh Lewis on 9/22/17.
//
//

#include <iostream>
using namespace std;

// GAME OF 23

int main() {
    
    int x, total;
    char choice;
    cout << "Let's play a game of \"23\"!\n";
    
do{
    total = 23;
    while (total > 0){
    cout << "Enter the number of sticks you wish to pick: ";
    cin >> x;
    switch(x){
// User picks 1 stick
        case 1:
            total -= x;
            cout << "You picked 1 stick. " << total << " left.\n";
            if (total > 4){
                total -= (4 - x);
                cout << "Computer picked 3 sticks. ";
                cout << total << " left.\n",
                cout << "Your turn. ";
            }
            else if (total >= 2 && total <= 4){
                switch(total){
                    case 2:
                        total -= 1;
                        cout << "Computer picked 1 stick. " << total << " left.\n";
                        break;
                    case 3:
                        total -= 2;
                        cout << "Computer picked 2 sticks. " << total << " left.\n";
                        break;
                    case 4:
                        total -= 3;
                        cout << "Computer picked 3 sticks. " << total << " left.\n";
                        break;
                }
            }
            else if (total == 1){
                total -= 1;
                cout << "Computer picked the last stick. You win!";
                cout << "Do you want to play another game? <Y/N>: ";
                cin >> choice;
                if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                    cout << "That is not a valid answer.";
                    cout << " Do you want to play another game? <Y/N>: ";
                    cin >> choice;
                }
            }
            else{
                cout << "You picked the last stick.\n";
                cout << "Sorry, the computer beat you!\n";
                cout << "Do you want to play another game? <Y/N>: ";
                cin >> choice;
                if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                    cout << "That is not a valid answer.\n";
                    cout << " Do you want to play another game? <Y/N>: ";
                    cin >> choice;
                }
            }
        break;
            
// User picks 2 sticks
        case 2:
            total -= x;
            cout << "You picked 2 sticks. " << total << " left.\n";
            if (total > 4){
                total -= (4 - x);
                cout << "Computer picked 2 sticks. ";
                cout << total << " left.\n",
                cout << "Your turn. ";
            }
            else if (total >= 2 && total <= 4){
                switch(total){
                    case 2:
                        total -= 1;
                        cout << "Computer picked 1 stick. " << total << " left.\n";
                        break;
                    case 3:
                        total -= 2;
                        cout << "Computer picked 2 sticks. " << total << " left.\n";
                        break;
                    case 4:
                        total -= 3;
                        cout << "Computer picked 3 sticks. " << total << " left.\n";
                        break;
                }
            }
            else if (total == 1){
                total -= 1;
                cout << "Computer picked the last stick. You win!\n";
                cout << "Do you want to play another game? <Y/N>: ";
                cin >> choice;
                if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                    cout << "That is not a valid answer.\n";
                    cout << " Do you want to play another game? <Y/N>: ";
                    cin >> choice;
                }
            }
            else{
                cout << "You picked the last stick.\n";
                cout << "Sorry, the computer beat you!\n";
                cout << "Do you want to play another game? <Y/N>: ";
                cin >> choice;
                if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                    cout << "That is not a valid answer.\n";
                    cout << " Do you want to play another game? <Y/N>: ";
                    cin >> choice;
                }
            }
        break;
            
// User picks 3 sticks
        case 3:
            total -= x;
            cout << "You picked 3 sticks. " << total << " left.\n";
                if (total > 4){
                    total -= (4 - x);
                    cout << "Computer picked 1 stick. ";
                    cout << total << " left.\n",
                    cout << "Your turn. ";
                }
                else if (total >= 2 && total <= 4)
                    switch(total){
                        case 2:
                            total -= 1;
                            cout << "Computer picked 1 stick. " << total << " left.\n";
                            break;
                        case 3:
                            total -= 2;
                            cout << "Computer picked 2 sticks. " << total << " left.\n";
                            break;
                        case 4:
                            total -= 3;
                            cout << "Computer picked 3 sticks. " << total << " left.\n";
                            break;
                    }
                else if (total == 1){
                    total -= 1;
                    cout << "Computer picked the last stick. You win!\n";
                    cout << "Do you want to play another game? <Y/N>: ";
                    cin >> choice;
                    if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                        cout << "That is not a valid answer.\n";
                        cout << " Do you want to play another game? <Y/N>: ";
                        cin >> choice;
                    }
                }
                else{
                    cout << "You picked the last stick.\n";
                    cout << "Sorry, the computer beat you!\n";
                    cout << "Do you want to play another game? <Y/N>: ";
                    cin >> choice;
                    if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                        cout << "That is not a valid answer.\n";
                        cout << " Do you want to play another game? <Y/N>: ";
                        cin >> choice;
                    }
                }
        break;
            
        default:
            cout << "Wrong number of sticks. You must choose values of 1, 2, or 3.\n";
            continue;
    }
}
} while(choice == 'Y' || choice == 'y');
    
    return 0;
}
