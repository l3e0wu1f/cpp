/* Do Programming Project 3 on page 740: Redo Programming Project 9 from Chapter 11.
 * Define ADT class in separate files so that it can be compiled separately.
 * Put the main function in its own file separate from the ADT files.
 *
 * Author: Josh Lewis
 * Version: 3/2/2018
 * Interface File
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#ifndef JLP4INTERFACE_H
#define JLP4INTERFACE_H

class StringSet
{
private:
    int search(const string s);
    vector<string> data;
public:
    StringSet();
    StringSet(const string initial[], int size);
    bool addString(string s);
    bool removeString(string s);
    void clearSet();
    int arraySize();
    void output();
    friend StringSet operator *(const StringSet &set1, const StringSet &set2);
    friend StringSet operator +(const StringSet &set1, const StringSet &set2);
    
};

#endif
