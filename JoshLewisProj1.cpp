//
//  JoshLewisProj1.cpp
//
//
//  Created by Josh Lewis on 1/27/18.
//
//

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void revString(char* front, char* rear);
// Reverses string by swapping values between two pointers
// Tests for both odd and even strings

string *addEntry(string *dynamicArray, int& size, string newEntry);

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);

void print(string *dynamicArray, int size);

int main()
{
    // Chooses one odd and one even string to reverse
    char odd[] = "Vader";
    char even[] = "Yoda";
    
    cout << "Before reversal, the odd string is: " << odd << endl;
    cout << "Before reversal, the even string is: " << even << endl;
    
    revString(odd, odd + strlen(odd) - 1);
    
    revString(even, even + strlen(even) - 1);
    
    cout << "After reversal, the odd string is: " << odd << endl;
    cout << "After reversal, the even string is: " << even << endl;

    // Creates array and enters some names
    int size = 5;
    string *names = new string[size];
    names[0] = "Luke";
    names[1] = "Leia";
    names[2] = "Han";
    names[3] = "C3PO";
    names[4] = "R2D2";
    
    cout << "Initial list of names: \n";
    print(names,size);
    
    // Add some additional entries
    names = addEntry(names,size,"Jabba");
    names = addEntry(names,size,"Greedo");
    names = addEntry(names,size,"Palpatine");
    cout << "The list with some added villains is now: \n";
    print(names,size);
    
    // Delete some entries
    names = deleteEntry(names,size,"Greedo");
    names = deleteEntry(names,size,"Jabba");
    cout << "After defeating two villains, the cast of characters remains: \n";
    print(names,size);
    
    //Delete entire array
    delete [] names;
    
    return 0;
}

void revString(char* front, char* rear)
{
    char temp;
    while(front < rear)
    {
        temp = *front;
        *front = *rear;
        *rear = temp;
        front++;
        rear--;
    }
}

string *addEntry(string *dynamicArray, int& size, string newEntry)
{
    // Create new dynamic array 1 element longer than dynamicArray
    // Copy all elements from dynamicArray into new array
    // Add new entry onto end of new array
    // Increment size, delete dynamicArray, and return new array
    
    string *newArray = new string[size + 1];
    for(int i = 0; i < size; i++)
        newArray[i] = dynamicArray[i];
    newArray[size] = newEntry;
    size++;
    delete [] dynamicArray;
    return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    // Search dynamicArray for entryToDelete
    // If not found, request to be ignored & dynamicArray returned
    // If found, create new dynamic array 1 element smaller than dynamicArray
    // Copy all elements except entryToDelete into new array
    // Delete dynamicArray, decrement size, and return new array
    
    string *result = dynamicArray;
    int index_of_entry = -1;
    for(int i = 0; i < size; i++)
    {
        if(dynamicArray[i] == entryToDelete){
            index_of_entry = i;
            break;
        }
    }
    if(index_of_entry == -1)
        return result;
    else
    {
        result = new string[size - 1];
        int index_new_array = 0;
        for(int i = 0; i < size; i++)
            if(i != index_of_entry)
            {
                result[index_new_array] = dynamicArray[i];
                index_new_array++;
            }
            else
            {
                // i == index_of_entry
            }
        size--;
        delete [] dynamicArray;
    }
    return result;
}

void print(string *dynamicArray, int size)
{
    for(int i = 0; i < size; i++)
        cout << i << ": " << dynamicArray[i] << endl;
    cout << endl;
}
