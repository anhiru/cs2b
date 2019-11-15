//
//  fraction.h
//  Fraction
//
//  Created by Andrew Tran on 10/2/19.
//  CS 2B, Dave Harden
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef FRACTION_H
#define FRACTION_H
using namespace std;

/*

 The Fraction class can be used to create and handle objects that store a
 fraction.  In its simplest form, a Fraction is just two integer values:
 a numerator and a denominator. Fractions can be negative, may be improper,
 and can be whole numbers (denominator of 1).
 The following functions are available:

 Fraction(int inNumerator=0, int inDenominator=1);
 post: The calling object has been created and initialized so that the
    numerator is inNumerator and the denominator is inDenominator. If no
    parameters were provided, the numerator will default to 0 and the
    denominator will default to 1.

 friend Fraction operator+(const Fraction& left, const Fraction& right);
 post: Returns the sum of two Fraction objects.

 friend Fraction operator-(const Fraction& left, const Fraction& right);
 post: Returns the difference of two Fraction objects.

 friend Fraction operator*(const Fraction& left, const Fraction& right);
 post: Returns the product of two Fraction objects.

 friend Fraction operator/(const Fraction& left, const Fraction& right);
 pre: right is a nonzero Fraction.
 post: Returns the quotient of two Fraction objects.

 friend bool operator<(const Fraction& left, const Fraction& right);
 post: Returns True if left is a smaller Fraction than right. Returns False
    otherwise.

 friend bool operator<=(const Fraction& left, const Fraction& right);
 post: Returns True if left is a smaller Fraction than or equivalent to right.
    Returns False otherwise.

 friend bool operator>(const Fraction& left, const Fraction& right);
 post: Returns True if left is a larger Fraction than right. Returns False
    otherwise.

 friend bool operator>=(const Fraction& left, const Fraction& right);
 post: Returns True if left is a larger Fraction than or equivalent to right.
    Returns False otherwise.

 friend bool operator==(const Fraction& left, const Fraction& right);
 post: Returns True if left is an equivalent Fraction to right. Returns False
    otherwise.

 friend bool operator!=(const Fraction& left, const Fraction& right);
 post: Returns True if left is not an equivalent Fraction to right. Returns
    False otherwise.

 friend ostream& operator<<(ostream& out, const Fraction& output);
 post: Returns the ostream object with formatted output. Negative Fractions
    will be printed with a leading minus sign. Improper fractions will be
    printed as mixed numbers.

 friend istream& operator>>(istream& out, Fraction& input);
 pre: There are no spaces or formatting errors in input.
 post: Returns the istream object with formatted input.

 Fraction operator++();
 post: Add 1, then return the modified Fraction object.

 Fraction operator++(int);
 post: Add 1, then return the unmodified version of the Fraction object.

 Fraction operator--();
 post: Subtract 1, then return the modified Fraction object.

 Fraction operator--(int);
 post: Subtract 1, then return the unmodified version of the Fraction object.

 Fraction operator+=(const Fraction& right);
 pre: The calling object is a Fraction.
 post: Return the sum of the calling object and right.

 Fraction operator-=(const Fraction& right);
 pre: The calling object is a Fraction.
 post: Return the difference of the calling object and right.

 Fraction operator*=(const Fraction& right);
 pre: The calling object is a Fraction.
 post: Return the product of the calling object and right.

 Fraction operator/=(const Fraction& right);
 pre: The calling object is a Fraction.
 post: Return the quotient of the calling object and right.

*/

namespace cs_fraction {

    class Fraction {
    public:
        Fraction(int inNumerator=0, int inDenominator=1);
        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);
        friend ostream& operator<<(ostream& out, const Fraction& output);
        friend istream& operator>>(istream& out, Fraction& input);
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        Fraction operator+=(const Fraction& right);
        Fraction operator-=(const Fraction& right);
        Fraction operator*=(const Fraction& right);
        Fraction operator/=(const Fraction& right);
    private:
        void simplify();
        int numerator;
        int denominator;
    };

}

#endif
