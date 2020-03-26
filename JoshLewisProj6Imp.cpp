// This is the implementation file of project 6
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 4/4/2018

#include <iostream>
#include <string>
#include <cstdlib>
#include "JoshLewisProj6.h"

using namespace std;

// Base class (Shape) implementation

Shape::Shape()
{
    name = "";
}

Shape::Shape(string name)
{
    this -> name = name;
}

string Shape::getName()
{
    return this -> name;
}

void Shape::setName(string newName)
{
    this -> name = newName;
}

// Derived class (Circle) implementation

Circle::Circle() : Shape("Circle"), radius(0)
{ }

Circle::Circle(int theRadius) : Shape("Circle"), radius(theRadius)
{ }

void Circle::setRadius(int newRadius)
{
    this -> radius = newRadius;
}

double Circle::getRadius()
{
    return radius;
}

double Circle::getArea()
{
    return 3.14159 * radius * radius;
}

// Derived class (Rectangle) implementation

Rectangle::Rectangle() : Shape("Rectangle"), height(0), width(0)
{ }

Rectangle::Rectangle(int theHeight, int theWidth) : Shape("Rectangle"), height(theHeight), width(theWidth)
{ }

void Rectangle::setHeight(int newHeight)
{
    this -> height = newHeight;
}

void Rectangle::setWidth(int newWidth)
{
    this -> width = newWidth;
}

int Rectangle::getHeight()
{
    return height;
}

int Rectangle::getWidth()
{
    return width;
}

double Rectangle::getArea()
{
    return static_cast<double>(height) * width;
}
