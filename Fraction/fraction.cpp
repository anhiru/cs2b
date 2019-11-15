//
//  fraction.cpp
//  Fraction
//
//  Created by Andrew Tran on 10/2/19.
//  CS 2B, Dave Harden
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
#include "fraction.h"
#include <cmath>
using namespace std;

/*

 Class Invariant: a Fraction object has 2 int data members: numerator, which
 represents the parts of a whole, and denominator, which represents how many
 parts make up a whole. Internal operations always result in simplified
 Fractions (i.e. whole numbers and mixed numbers). However, no effort is made
 to prevent the client from dividing by a Fraction that is equal to 0.

*/

namespace cs_fraction {

    Fraction::Fraction(int inNumerator, int inDenominator) {
        assert(inDenominator != 0);
        numerator = inNumerator;
        denominator = inDenominator;
        simplify();
    }






    Fraction operator+(const Fraction& left, const Fraction& right) {
        Fraction answer;

        if (left.denominator == right.denominator) {
            answer.numerator = left.numerator + right.numerator;
            answer.denominator = left.denominator;
        } else {
            answer.numerator = (left.numerator * right.denominator) +
            (right.numerator * left.denominator);
            answer.denominator = left.denominator * right.denominator;
        }

        answer.simplify();
        return answer;
    }






    Fraction operator-(const Fraction& left, const Fraction& right) {
        Fraction answer;

        if (left.denominator == right.denominator) {
            answer.numerator = left.numerator - right.numerator;
            answer.denominator = left.denominator;
        } else {
            answer.numerator = (left.numerator * right.denominator) -
            (right.numerator * left.denominator);
            answer.denominator = left.denominator * right.denominator;
        }

        answer.simplify();
        return answer;
    }






    Fraction operator*(const Fraction& left, const Fraction& right) {
        Fraction answer;

        answer.numerator = left.numerator * right.numerator;
        answer.denominator = left.denominator * right.denominator;

        answer.simplify();
        return answer;
    }






    Fraction operator/(const Fraction& left, const Fraction& right) {
        Fraction answer;

        answer.numerator = left.numerator * right.denominator;
        answer.denominator = left.denominator * right.numerator;

        answer.simplify();
        return answer;
    }






    bool operator<(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator <
                right.numerator * left.denominator);
    }






    bool operator<=(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator <=
                right.numerator * left.denominator);
    }






    bool operator>(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator >
                right.numerator * left.denominator);
    }






    bool operator>=(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator >=
                right.numerator * left.denominator);
    }






    bool operator==(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator ==
                right.numerator * left.denominator);
    }






    bool operator!=(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator !=
                right.numerator * left.denominator);
    }






    ostream& operator<<(ostream& out, const Fraction& output) {

        if (output.denominator == 1){
            out << output.numerator;
        } else if (abs(output.numerator) < output.denominator){
            out << output.numerator << '/' << output.denominator;
        } else {
            out << output.numerator/output.denominator << '+'
            << abs(output.numerator % output.denominator) << '/'
            << output.denominator;
        }

        return out;
    }






    istream& operator>>(istream& in, Fraction& input) {
        int wholeNum = 0;

        // first, read the fraction as a mixed number

        in >> input.numerator;
        if (in.peek() == '+') {
            wholeNum = input.numerator;
            in.ignore();
            in >> input.numerator;
        }

        if (in.peek() == '/') {
            in.ignore();
            in >> input.denominator;
        } else {
            input.denominator = 1;
        }

        // second, convert the mixed number to an improper fraction if needed

        if (wholeNum >= 0) {  // positive fraction
            input.numerator = wholeNum * input.denominator + input.numerator;
        } else {  // negative fraction
            input.numerator = -(abs(wholeNum) * input.denominator
                                + input.numerator);
        }
        input.simplify();

        return in;
    }






    Fraction Fraction::operator++() {
        numerator += denominator;
        return *this;
    }






    Fraction Fraction::operator++(int) {
        Fraction temp(numerator, denominator);
        numerator += denominator;
        return temp;
    }






    Fraction Fraction::operator--() {
        numerator -= denominator;
        return *this;
    }






    Fraction Fraction::operator--(int) {
        Fraction temp(numerator, denominator);
        numerator -= denominator;
        return temp;
    }






    Fraction Fraction::operator+=(const Fraction& right) {
        *this = *this + right;
        return *this;
    }






    Fraction Fraction::operator-=(const Fraction& right) {
        *this = *this - right;
        return *this;
    }






    Fraction Fraction::operator*=(const Fraction& right) {
        *this = *this * right;
        return *this;
    }






    Fraction Fraction::operator/=(const Fraction& right) {
        *this = *this / right;
        return *this;
    }






    // This private void member function reduces a fraction to its
    // lowest terms, or "simplest form."
    // This function also ensures that the denominator is never negative.

    void Fraction::simplify() {
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int gcf = 1;
        for (int i = 2; i <= abs(numerator) && i <= abs(denominator); i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcf = i;
            }
        }
        numerator /= gcf;
        denominator /= gcf;
    }

}

/*

 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10
 Fraction [3] = -4
 Fraction [4] = 0
 Fraction [5] = 4+2/3
 Fraction [6] = 0

 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6
 Read Fraction = 5
 Read Fraction = -8
 Read Fraction = 1+2/5
 Read Fraction = -16+2/3
 Read Fraction = 1+1/4
 Read Fraction = 2
 Read Fraction = -4+1/4
 Read Fraction = -10+5/6

 ----- Testing relational operators between Fractions
 Comparing 1/2 to -1/2
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing -1/2 to 1/2
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing 1/2 to 1/10
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing 1/10 to 0
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing 0 to 0
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false

 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing -3 to 1/4
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true

 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4

 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6

 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2

 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3

 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3

*/
