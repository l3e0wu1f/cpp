/* Do Programming Project 3 on page 740: Redo Practice Program 1 from Chapter 11.
 * Modify the definition of the class Money shown in display 11.8 so that all of the following are added:
 * Overloded operators for <, <=, >, >=, and the Money percent member function.
 *
 * Author: Josh Lewis
 * Version: 3/4/2018
 * Application File
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include "JoshLewisMoney.h"
using namespace std;

int main()
{
    Money amount;
    ifstream inStream;
    ofstream outStream;
    
    inStream.open("infile.dat");
    if(inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    outStream.open("outfile.dat");
    if(outStream.fail())
    {
        cout << "Output file opening failed.";
        exit(1);
    }
    
    inStream >> amount;
    outStream << amount << " copied from the file infile.dat.\n";
    cout << amount << " copied from the file infile.dat.\n";
    
    inStream.close();
    outStream.close();
    
    return 0;
}
