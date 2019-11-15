//
//  a6_2.cpp
//  a6_2
//
//  Created by Andrew Tran on 10/30/19.
//  CS 2B, Dave Harden.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "mystring.h"
#include <iostream>
#include <cctype>
using namespace std;
using namespace cs_mystring;

/*

 This program tests the recursive function: isAPalindrome.

 The program will test this method using a MyString object that will be
 initialized and assigned to a user-inputted value.

 The user may choose to terminate the program at any time by typing "quit"
 and pressing the return (or enter) button.

 */

bool isAPalindrome(MyString str, int start, int end);


int main() {
    MyString testString;

    cout << "Enter a string: ";
    testString.read(cin, '\n');

    while (testString != "quit") {
        if (isAPalindrome(testString, 0, testString.length() - 1)) {
            cout << testString << " is a palindrome." << endl;
        } else {
            cout << testString << " is not a palindrome." << endl;
        }

        cout << "Enter a string: ";
        testString.read(cin, '\n');
    }
}





// This bool recursive function takes in a single MyString argument and
// two arguments that are bounds on array indices.
// The function will examine the part of the MyString argument between the
// two bounds (including the bounds) and will return true if this part of
// the argument is a palindrome, and false otherwise.
// Punctation, whitespace, and capitalization are ignored.

bool isAPalindrome(MyString str, int start, int end) {

    if (start == end) {
        return true;
    } else if (ispunct(str[start]) || isspace(str[start])) {
        return isAPalindrome(str, start + 1, end);
    } else if (ispunct(str[end]) || isspace(str[end])) {
        return isAPalindrome(str, start, end - 1);
    } else if (toupper(str[start]) != toupper(str[end])) {
        return false;
    } else if (start < end) {
        return isAPalindrome(str, start + 1, end - 1);
    } else {
        return true;
    }

}

/*

 Enter a string: Able was I, ere I saw Elba
 Able was I, ere I saw Elba is a palindrome.
 Enter a string: peanut butter
 peanut butter is not a palindrome.
 Enter a string: quit

 */
