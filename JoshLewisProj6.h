/* Shape Project from Page 884.
 *
 * Author: Josh Lewis
 * Version: 4/4/2018
 * Interface File
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#ifndef JOSHLEWISPROJ6_H
#define JOSHLEWISPROJ6_H

class Shape {
public:
    Shape();
    Shape(string name);
    string getName();
    void setName(string newName);
    virtual double getArea() = 0;
private:
    string name;
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle();
    Circle(int theRadius);
    void setRadius(int newRadius);
    double getRadius();
    virtual double getArea();
};

class Rectangle : public Shape {
private:
    int width;
    int height;
public:
    Rectangle();
    Rectangle(int theHeight, int theWidth);
    void setHeight(int newHeight);
    void setWidth(int newWidth);
    int getHeight();
    int getWidth();
    virtual double getArea();
};

#endif
