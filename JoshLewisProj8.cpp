// This is the program file of Project 8: A template-based class that implements a set of items.
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 4/25/2018

#include <iostream>
#include "JoshLewisProj8Set.h"


class A

{
    
    A *a;
    
public:
    
    A()
    
    {
        
        a = this;
        
    }
    
    
    bool operator==(const A &obj)
    
    {
        
        if (&obj == a)
            
        {
            
            return true;
            
        }
        
        return false;
        
    }
    
    
    bool operator!=(const A &obj)
    
    {
        
        if (&obj != a)
            
        {
            
            return true;
            
        }
        
        return false;
        
    }
    
};

/*
 
 * Driver program to test the set Class.
 
 */

int main()

{
    
    A a;
    
    A b;
    
    /* Set of Integers */
    
    Set<int> set1;
    
    /* Set of Objects */
    
    Set<A> set2;
    
    /* Adding objects to set */
    
    set2.addItem(a);
    
    set2.addItem(b);
    
    /* Adding items */
    
    set1.addItem(5);
    
    set1.addItem(6);
    
    set1.addItem(1);
    
    set1.addItem(1);
    
    set1.addItem(10);
    
    set1.addItem(12);
    
    /* Remove items */
    
    set1.removeItem(6);
    
    /* Checking members whether members of set or not */
    
    set1.IsMember(6);
    
    set1.IsMember(5);
    
    int * array = set1.getArrayOfSetItems();
    
    delete array;
    
    return 0;
    
}
