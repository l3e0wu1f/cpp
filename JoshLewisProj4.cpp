/* Do Programming Project 3 on page 740: Redo Programming Project 9 from Chapter 11.
 * Define ADT class in separate files so that it can be compiled separately.
 * Put the main function in its own file separate from the ADT files.
 * 
 * Author: Josh Lewis
 * Version: 3/2/2018
 * Application File
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "JLp4interface.h" // custom header with ADT
using namespace std;

int main()
{
    // Some simple string operation tests
    string initial[] = {"Moe", "Larry", "Curly"};
    StringSet threeStooges(initial, 3);
    
    // Output initial set
    cout << "Initial set: \n";
    threeStooges.output();
    cout << endl;
    
    // Remove an item from set
    cout << "Remove Curly: \n";
    threeStooges.removeString("Curly");
    threeStooges.output();
    cout << endl;
    
    // Add an item to set
    cout << "Add Shemp: \n";
    threeStooges.addString("Shemp");
    threeStooges.output();
    cout << endl;
    cout << "Size of set is: \n";
    threeStooges.arraySize();
    cout << endl;
    
    // Create 2 additional sets for intersection & union comparisons
    string initial2[] = {"one", "two", "three", "four"};
    string initial3[] = {"two", "five", "three"};
    StringSet set2(initial2, 4);
    StringSet set3(initial3, 3);
    cout << endl;
    cout << "Set 2: \n";
    set2.output();
    cout << endl;
    cout << "Set 3: \n";
    set3.output();
    cout << endl;
    
    // Intersection
    cout << "Intersection of sets 2 and 3: \n";
    StringSet set4 = set2 * set3;
    set4.output();
    cout << endl;
    
    // Union
    cout << "Union of original set and previous set: \n";
    StringSet set5 = threeStooges + set4;
    set5.output();
    cout << endl;
    
    // Clear
    cout << "Clearing set 4.\n";
    set4.clearSet();
    cout << "Cleared set output: \n";
    set4.output();
    
    return 0;
}
