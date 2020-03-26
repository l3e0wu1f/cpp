//
//  JoshLewisProj9.cpp
//
//
//  Created by Josh Lewis on 12/6//17.
//
//

#include <iostream>
using namespace std;

int str_length(char s[], int start);
// Recursive version of strlen.
// It returns the length of the substring from s[start] to
// the char before '\0',
// inclusive. When str_length(s,0) is called,
// the length of s is returned.

int sum(int n);
// Recursive version to calculate the sum of
// 1 + 2 + .... + n

int main() {
    char choice;
    
    do{
        // test str_length function
        char sentence[80];
        cout << "Enter a sentence: ";
        cin.getline(sentence, 80);
        cout << "There are " << str_length(sentence,0) << " characters in the sentence, including white spaces." << endl;
        
        //test sum function
        int n;
        cout << "Enter a number: ";
        cin >> n;
        cout << "The sum of 1 + 2 + ... + " << n << " is: " << sum(n) << "." << endl;
        
        cout << "Do you want to have another run? Y/N: ";
        cin >> choice;
        while(choice != Y && choice != y && choice != N && choice != n){
            cout << "Not a valid entry. Please type Y to continue or N to quit: ";
            cin >> choice;
        }
    } while(choice == 'Y' || choice == 'y');
    

    cout << "Goodbye!";
    
    return 0;
}

int str_length(char s[], int start){
    if(s[start] == '\0') // start is the index of '\0'
        return 0;
    return 1 + str_length(s, start+1);
}

int sum(int n){
    if(n != 0)
        return n + sum(n - 1);
    return 0;
}
