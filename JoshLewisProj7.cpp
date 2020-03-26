//
//  JoshLewisProj7.cpp
//
//
//  Created by Josh Lewis on 11/9/17.
//
//

#include <iostream>

using namespace std;

void fill_array(int arr[], int size);
// precondition: The arr has actual size that is greater than or equal to size // postcondition: arr[0], ..., arr[size-1] is filled from keyboard

void print_array(int arr[], int size);
// precondition: The arr has actual size that is greater than or equal to size
// postcondition: arr[0], ..., arr[size-1] is printed to screeen with 5 elements per line

int linear_search(int arr[], int size, int key);
// precondition: arr has given size
// postcondition: The index of first occurrence of key in arr is returned. If the key cannot be found in arr, -1 is returned

void select_sort(int arr[], int size);
// precondition: arr has given size
// postcondition: the elements in arr are rearranged from least to largest

void insert_sort(int arr[], int size);
// precondition: arr has given size
// postcondition: the elements in arr are rearranged from least to largest

void bubble_sort(int arr[], int size);
// precondition: arr has given size
// postcondition: the elements in arr are rearranged from least to largest

void menu();
// Menu for user to choose an option for testing

int main() {
    
    int choice;
    int a[9];
    do{ menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: {
                fill_array(a, 9);
                cout << "Enter the key you want to search: ";
                int key;
                cin >> key;
                int index = linear_search(a, 9, key);
                if(index == -1)
                    cout << "The key " << key << " is not in array\n";
                else
                    cout << "The key " << key << " is #" << (index + 1) << " element in array\n";
                    break;
            }
            case 2: {
                fill_array(a, 9);
                select_sort(a, 9);
                cout << "After the Selection sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 3: {
                fill_array(a, 9);
                insert_sort(a, 9);
                cout << "After the Insertion sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 4: {
                fill_array(a, 9);
                bubble_sort(a, 9);
                cout << "After the Bubble sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 5: {
                cout << "Thank you for using the array functions. Goodbye!\n";
                break; }
            default: {
                cout << "Wrong choice. Please choose from menu: ";
                break; }
        }
    } while(choice != 5);

    return 0;
}

void fill_array(int arr[], int size){
    cout << "Enter " << size << " integers: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];
}

void print_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << "\t";
        if(i % 5 == 4)
            cout << "\n";
    }
    cout << "\n";
}

int linear_search(int arr[], int size, int key) // If key is not found in array, it returns -1
{
    for(int i = 0; i < size; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

void select_sort(int arr[], int size){
    for(int position = 0; position < size - 1; position++){ // finds smallest element from position 0 to end of array, then swap with element at position
        int index_of_smallest = position;
        for(int i = position + 1; i < size; i++){
            if(arr[i] < arr[index_of_smallest])
                index_of_smallest = i;
        }
        // index_of_smallest is smallest element among arr[position], ... arr[size-1]
        int temp = arr[position];
        arr[position] = arr[index_of_smallest];
        arr[index_of_smallest] = temp;
    }
}

void insert_sort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1;
        
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void bubble_sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void menu(){
    cout << "**************************\n";
    cout << "*          Menu          *\n";
    cout << "* 1. Test Linear Search  *\n";
    cout << "* 2. Test Select Sort    *\n";
    cout << "* 3. Test Insert Sort    *\n";
    cout << "* 4. Test Bubble Sort    *\n";
    cout << "* 5. Quit                *\n";
    cout << "**************************\n";
}
