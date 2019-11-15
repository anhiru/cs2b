//
//  mystring.cpp
//  MyString
//
//  CS 2B, Dave Harden.
//  Created by Andrew Tran on 10/16/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cassert>
#include "mystring.h"
using namespace std;

/*

 Class Invariant: a MyString object has 1 char* data member: str, which is
 a c-string implemented as a dynamic array. A MyString object declared without
 a parameter will be initialized to an empty c-string.

 */

namespace cs_mystring {

    // CONSTRUCTORS, INSERTION, AND EXTRACTION

    MyString::MyString() {
        str = new char[1];
        strcpy(str, "");
    }






    MyString::MyString(const char* inString) {
        str = new char[strlen(inString) + 1];
        strcpy(str, inString);
    }






    ostream& operator<<(ostream& out, const MyString& output) {
        out << output.str;

        return out;
    }






    istream& operator>>(istream& in, MyString& input) {
        while (isspace(in.peek())) {
            in.ignore();
        }

        char temp[MyString::MAX_INPUT_SIZE + 1];
        in >> temp;
        delete input.str;
        input.str = new char[strlen(temp) + 1];
        strcpy(input.str, temp);

        return in;
    }






    void MyString::read(istream& in, char delim) {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE, delim);
        delete str;
        str = new char[strlen(temp) + 1];
        strcpy(str, temp);
    }






    // THE BIG-3 (DESTRUCTOR, COPY CONSTRUCTOR, AND ASSIGNMENT OPERATOR)

    MyString::~MyString() {
        delete [] str;
    }






    MyString::MyString(const MyString& right) {
        str = new char[strlen(right.str) + 1];
        strcpy(str, right.str);
    }






    MyString MyString::operator=(const MyString& right) {
        if (this != &right) {
            delete str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }

        return *this;
    }






    // CONCATENATION OPERATORS

    MyString MyString::operator+=(const MyString& right) {
        *this = *this + right;

        return *this;
    }






    MyString operator+(const MyString& left, const MyString& right) {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        strcpy(temp, left.str);
        strcat(temp, right.str);

        return MyString(temp);
    }






    // RELATIONAL OPERATORS

    bool operator<(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) < 0);
    }






    bool operator<=(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) <= 0);
    }






    bool operator>(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) > 0);
    }






    bool operator>=(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) >= 0);
    }






    bool operator==(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) == 0);
    }






    bool operator!=(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) != 0);
    }






    // SQUARE BRACKETS OPERATOR

    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(str));

        return str[index];
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(str));
        
        return str[index];
    }






    // MEMBER FUNCTIONS

    int MyString::length() const {
        return strlen(str);
    }

}

/*

 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z

 ----- Now reading MyStrings from file

 ----- first, word by word
 Read string = The
 Read string = first
 Read string = time
 Read string = we
 Read string = will
 Read string = read
 Read string = individual
 Read string = words,
 Read string = next
 Read string = we
 Read string = read
 Read string = whole
 Read string = lines

 ----- now, line by line
 Read string = The  first  time  we  will
 Read string =     read individual words, next
 Read string = we read whole lines

 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

 ----- Testing relational operators between MyStrings
 Comparing app to apple
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing apple to
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing  to Banana
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing Banana to Banana
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false

 ----- Testing relations between MyStrings and char *
 Comparing he to hello
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing why to wackity
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true

 ----- Testing concatentation on MyStrings
 outrageous + milk = outrageousmilk
 milk +  = milk
 + cow = cow
 cow + bell = cowbell

 ----- Testing concatentation between MyString and char *
 abcde + XYZ = abcdeXYZ
 XYZ + abcde = XYZabcde

 ----- Testing shorthand concat/assign on MyStrings
 who += what = whowhatandwhowhat
 what += WHEN = whatWHENandwhatWHEN
 WHEN += Where = WHENWhereandWHENWhere
 Where += why = WherewhyandWherewhy

 ----- Testing shorthand concat/assign using char *
 I love  += programming = I love programming

 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is BinkyBoo
 val is winky
 after assign,  val is BinkyBoo

 */
