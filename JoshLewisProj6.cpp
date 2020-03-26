// This is the program file of project 6
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 4/4/2018

#include <iostream>
#include <string>
#include <cstdlib>
#include "JoshLewisProj6.h"

using namespace std;

int main() {
    Circle c(2);
    cout << c.getName() << " has radius " << c.getRadius() << " and area " << c.getArea() << endl;
    
    Rectangle r(3,4);
    cout << r.getName() << " has width " << r.getWidth() << ", a height of " << r.getHeight() <<
    ", and an area of " << r.getArea() << "." << endl;
    
    return 0;
}
