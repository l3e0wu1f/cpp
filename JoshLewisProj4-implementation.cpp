/* Do Programming Project 3 on page 740: Redo Programming Project 9 from Chapter 11.
 * Define ADT class in separate files so that it can be compiled separately.
 * Put the main function in its own file separate from the ADT files.
 *
 * Author: Josh Lewis
 * Version: 3/2/2018
 * Implementation File
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "JLp4interface.h"
using namespace std;

StringSet::StringSet()
{
}

StringSet::StringSet(const string initial[], int size)
{
    int i;
    for(i = 0; i < size; i++) {
        data.push_back(initial[i]);
    }
}

// Outputs all strings
void StringSet::output()
{
    for(int i = 0; i < data.size(); i++) {
        cout << " " << data[i];
    }
}

// Erases all entries in set
void StringSet::clearSet()
{
    data.clear(); // Removes all elements from vector
}

// Number of entries in set
int StringSet::arraySize()
{
    int count;
    for(int i = 0; i < data.size(); i++){
        count++;
    }
    return count;
}

// Searches vector for target string. Index is returned if found, else -1 is returned.
int StringSet::search(const string s)
{
    for(int i = 0; i < data.size(); i++) {
        
        if(data[i] == s) {
            return i;
        }
        else {
            return -1;
        }
    }
}

// Adds new entry to StringSet
bool StringSet::addString(const string s)
{
    int i = search(s);
    if(i >= 0) {
        return false; // because s is already in the set
    }
    else {
        data.push_back(s);
        return true;
    }
}

// Removes an entry from StringSet
bool StringSet::removeString(const string s)
{
    int i = search(s);
    if(i >= 0) {
        vector<string> temp;
        for(int j = 0; j < data.size(); j++) { // Copy all non-target items to delete
            if(data[j] != s) {
                temp.push_back(data[j]);
            }
        }
        data.clear(); // Clears original vector
        for(int k = 0; k < temp.size(); k++) {
            data.push_back(temp[k]);
        }
        return true;
    }
    else {
        return false;
    }
}

// Intersect current set with other set
StringSet operator *(const StringSet &set1, const StringSet &set2)
{
    StringSet temp;
    
    for(int i = 0; i < set1.data.size(); i++) {
        for(int j = 0; j < set2.data.size(); j++) {
            if(set1.data[i] == set2.data[j]) {
                temp.addString(set1.data[i]);
            }
        }
    }
    return temp;
}

// Union of current set with other set
StringSet operator +(const StringSet &set1, const StringSet &set2)
{
    StringSet temp;
    
    for(int i = 0; i < set1.data.size(); i++) { // Adds everything from set1
        temp.addString(set1.data[i]);
    }
    for(int i = 0; i < set2.data.size(); i++) { // Adds everything from set2
        temp.addString(set2.data[i]);
    }
    return temp;
}
