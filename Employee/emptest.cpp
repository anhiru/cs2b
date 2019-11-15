//
//  main.cpp
//  Employee
//
//  Created by Andrew Tran on 11/12/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
#include "hourlyemp.h"
#include "salariedemp.h"
using namespace std;

int main() {

    hourlyEmp arnold("Arnonld Jones","23456664",13,20);
    arnold.setHours(10);
    cout << "Check for " << arnold.getName() << " for "
    << arnold.getHours() << " hours:" << endl;
    arnold.printCheck();

    cout << endl << endl << endl;

    arnold.giveRaise(5);
    cout << "Check for " << arnold.getName() << " for "
    << arnold.getHours() << " hours:" << endl;
    arnold.printCheck();

    cout << endl << endl << endl;

    salariedEmp sally("Sally Wu", "345123456", 1234.45);
    cout << "Check for " << sally.getName() << endl;
    sally.printCheck();

    cout << endl << endl << endl;

    sally.giveRaise(10);
    cout << endl << endl << endl;
    cout << "after a raise of 10, Sally's check:" << endl;
    sally.printCheck();

}

/*

 Check for Arnonld Jones for 10 hours:
 Pay Arnonld Jones the sum of 130 dollars.
 Check Stub:
 Employee number: 23456664
 This is an hourly employee.  Hours worked: 10
 Rate: 13    Pay: 130



 Check for Arnonld Jones for 10 hours:
 Pay Arnonld Jones the sum of 180 dollars.
 Check Stub:
 Employee number: 23456664
 This is an hourly employee.  Hours worked: 10
 Rate: 18    Pay: 180



 Check for Sally Wu
 Pay Sally Wu the sum of 1234.45 dollars.
 Check Stub:
 Employee number: 345123456
 This is a salaried employee.  Regular pay: 1234.45






 after a raise of 10, Sally's check:
 Pay Sally Wu the sum of 1244.45 dollars.
 Check Stub:
 Employee number: 345123456
 This is a salaried employee.  Regular pay: 1244.45

 */
