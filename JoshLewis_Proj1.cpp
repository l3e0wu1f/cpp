//
//  JoshLewisProj1
//  Created by Josh Lewis on 8/20/17.
//
/*  Step 2: No difference is seen in the program's output after comments were added.
    Step 3: Xcode won't run the program when Cout is capitalized. 
            Error says: "Use of undeclared identifier 'Cout'; did you mean 'cout'?" */

#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "This is my first C++ program" << endl;
    system("pause");
}

/* I also get an error "command not found" regarding the system call to pause. After some research, I discovered this is OS-specific, and only works in Windows shells. I'm currently using Xcode 4 on Mac. */

/* Question: Why do we not need to include 'return 0;' at the end of program? Since main() function is declared as an integer, I thought the 'return 0;' was necessary. */
