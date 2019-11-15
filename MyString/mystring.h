//
//  mystring.h
//  MyString
//
//  CS 2B, Dave Harden.
//  Created by Andrew Tran on 10/16/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

/*

 The MyString class can be used to construct strings as well as
 read, print, and access characters. In addition, the MyString object
 possesses the ability to make a full deep-copy of itself when copied.
 All of the expected operators are provided, including stream extraction,
 stream insertion, relational operators, and concatenation operators.
 The following functions are available:

 MyString();
 post: The calling object has been created such that the instance variable str
    is initialized to an empty string.

 MyString(const char* inString);
 post: The calling object has been created such that the instance variable str
    is initialized to an empty string.

 friend ostream& operator<<(ostream& out, const MyString& output);
 post: Returns the ostream object with formatted output.

 friend istream& operator>>(ostream& out, const MyString& output);
 pre: Each entered word is less than 128 characters long.
 post: Returns the istream object with formatted input.

 void read(istream& in, char delim);
 pre: Each entered line is less than 128 characters long.
 post: Placed everything up to but not including the delimiting charcter
 into the calling object, and the delimiting character has been
 consumed and discarded.

 ~MyString();
 post: The variable on the heap that str was pointing to has been deallocated.

 MyString(const MyString& right);
 post: A copy of the calling object's str has been made
    (instead of using the default memberwise copy).

 MyString operator=(const MyString& right);
 post: Returns the calling object. The str of the calling object
    has been assigned the value corresponding to the str in right.

 MyString operator+=(const MyString& right);
 post: Returns the calling object. The str of the callinig object
    has been concatenated with the value corresponding to the str in right.

 friend MyString operator+(const MyString& left, const MyString& right);
 pre: Both strings are a total of less than 128 characters long.
 post: Returns the concatenation of two MyString objects.

 friend bool operator<(const MyString& left, const MyString& right);
 post: Returns True if left is lexicographically smaller than right.
    Returns False otherwise.

 friend bool operator<=(const MyString& left, const MyString& right);
 post: Returns True if left is lexicographically smaller than or
    equivalent to right. Returns False otherwise.

 friend bool operator>(const MyString& left, const MyString& right);
 post: Returns True if left is lexicographically larger than right.
    Returns False otherwise.

 friend bool operator>=(const MyString& left, const MyString& right);
 post: Returns True if left is lexicographically larger than or
    equivalent to right. Returns False otherwise.

 friend bool operator==(const MyString& left, const MyString& right);
 post: Returns True if left is lexicographically equivalent to right.
    Returns False otherwise.

 friend bool operator!=(const MyString& left, const MyString& right);
 post: Returns True if left is not lexicographically equivalent to right.
    Returns False otherwise.

 char operator[](int index) const;
 post: Returns the VALUE of str at the requested index. 

 char& operator[](int index);
 post: Returns the REFERENCE of str at the requested index.

 int length() const;
 post: Returns the number of characters in str.

 */

namespace cs_mystring {

    class MyString {
    public:
        static const int MAX_INPUT_SIZE = 127;
        MyString();
        MyString(const char* inString);
        friend ostream& operator<<(ostream& out, const MyString& output);
        friend istream& operator>>(istream& in, MyString& input);
        void read(istream& in, char delim);
        ~MyString();
        MyString(const MyString& right);
        MyString operator=(const MyString& right);
        MyString operator+=(const MyString& right);
        friend MyString operator+(const MyString& left, const MyString& right);
        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const MyString& right);
        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const MyString& right);
        char operator[](int index) const;
        char& operator[](int index);
        int length() const;
    private:
        char* str;
    };
}

#endif /* mystring_h */
