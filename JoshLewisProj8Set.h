// This is the interface file of Project 8: A template-based class that implements a set of items.
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 4/25/2018

#ifndef JoshLewisProj8Set_h
#define JoshLewisProj8Set_h

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>

class Set

{
    
private:
    
    /* vector to store set elements */
    
    vector<T> mElems;
    
public:
    
    /* function to add new set item */
    
    int addItem(T item);
    
    /* function to remove item from the set */
    
    int removeItem(T item);
    
    /* returns number of items in the set */
    
    int numItems();
    
    /* returns true, if given item is in set */
    
    bool IsMember(T item);
    
    /* returns array of elements includes all set elements */
    
    T* getArrayOfSetItems();
    
};

template<class T>

int Set<T>::addItem(T item)

{
    
    if (find(mElems.begin(), mElems.end(), item) == mElems.end())
        
    {
        
        cout << "Item is added to set.\n";
        
        mElems.push_back(item);
        
        return 0;
        
    }
    
    cout << "Item is already exists.\n";
    
    return -1;
    
}

template<class T>

int Set<T>::removeItem(T item)

{
    
    if (find(mElems.begin(), mElems.end(), item) != mElems.end())
        
    {
        
        cout << "Item is removed from set.\n";
        
        mElems.erase(remove(mElems.begin(), mElems.end(), item), mElems.end());
        
        return 0;
        
    }
    
    cout << "Item is not found in set.\n";
    
    return -1;
    
}

template<class T>

int Set<T>::numItems()

{
    
    return mElems.size();
    
}

template<class T>

bool Set<T>::IsMember(T item)

{
    
    if (find(mElems.begin(), mElems.end(), item) != mElems.end())
        
    {
        
        cout << "Given item is member of set.\n";
        
        return true;
        
    }
    
    cout << "Given item is not a member of set.\n";
    
    return false;
    
}

template<class T>

T * Set<T>::getArrayOfSetItems()

{
    
    T *array = new T[mElems.size()];
    
    for (int i=0; i<mElems.size(); ++i)
        
    {
        
        array[i] = mElems[i];
        
    }
    
    return array;
    
}

#endif
