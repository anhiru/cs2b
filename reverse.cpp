//
//  a6_1.cpp
//  a6_1
//
//  Created by Andrew Tran on 10/30/19.
//  CS 2B, Dave Harden.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
using namespace std;

/*

 This program tests two recursive functions:
 reverseWithinBounds and reverseCstring.

 The program will test these methods using an array of characters
 and a c-string; both will be intialized without user input.

 Their values will be printed to the console before and after
 each function call.

 */

void reverseWithinBounds(char list[], int start, int end);
void reverseCstring(char* str);


int main() {
    // testing: reverseWithinBounds
    char a[] = { 'A', 'B', 'C', 'D', 'E' };

    cout << "\nBefore function call (reverseWithinBounds):\n";
    for (int i = 0; i < 5; i++) {
        cout << "a[" << i << "] == '" << a[i] << "'" << endl;
    }

    reverseWithinBounds(a, 1, 4);

    cout << "\nAfter function call (reverseWithinBounds):\n";
    for (int i = 0; i < 5; i++) {
        cout << "a[" << i << "] == '" << a[i] << "'" << endl;
    }


    // testing: reverseCstring
    char* testString;
    testString = new char[50];
    strcpy(testString, "The quick brown fox jumped over the lazy dog.");

    cout << "\nBefore function call (reverseCstring):\n" << testString << endl;

    reverseCstring(testString);

    cout << "\nAfter function call (reverseCstring):\n" << testString << endl;
}





// This void recursive function takes in an array of characters and
// two other arguments that are bounds on array indices.
// The function will reverse the order of the entries in the array whose
// indices are between the two bounds (including the bounds).

void reverseWithinBounds(char list[], int start, int end) {
    if (start < end) {
        char temp = list[start];
        list[start] = list[end];
        list[end] = temp;
        reverseWithinBounds(list, start + 1, end - 1);
    }
}





// This void recursive function takes in a c-string and modifies the argument
// so that it is reversed.

void reverseCstring(char* str) {
    reverseWithinBounds(str, 0, strlen(str) - 1);
}

/*

 Before function call (reverseWithinBounds):
 a[0] == 'A'
 a[1] == 'B'
 a[2] == 'C'
 a[3] == 'D'
 a[4] == 'E'

 After function call (reverseWithinBounds):
 a[0] == 'A'
 a[1] == 'E'
 a[2] == 'D'
 a[3] == 'C'
 a[4] == 'B'

 Before function call (reverseCstring):
 The quick brown fox jumped over the lazy dog.

 After function call (reverseCstring):
 .god yzal eht revo depmuj xof nworb kciuq ehT
 Program ended with exit code: 0

 */
