//
//  hourlyemp.cpp
//  Employee
//
//  Created by Andrew Tran on 11/12/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "hourlyemp.h"
#include "employee.h"
#include <iostream>
using namespace std;

void hourlyEmp::setHours(double newHours) {
    hours = newHours;
    netPay = payRate * hours;
}






void hourlyEmp::giveRaise(double amount) {
    payRate += amount;
    netPay = payRate * hours;
}






double hourlyEmp::getHours() const {
    return hours;
}






void hourlyEmp::printCheck() const {
    cout << "Pay " << name << " the sum of " << netPay << " dollars." << endl;
    cout << "Check Stub: " << endl;
    cout << "Employee number: " << ssn << endl;
    cout << "This is an hourly employee.  Hours worked: " << hours
    << endl;
    cout << "Rate: " << payRate << "    Pay: " << netPay << endl;
}






hourlyEmp::hourlyEmp() {
    payRate = 0;
    hours = 0;
}






hourlyEmp::hourlyEmp(const string& newName, const string& newSSN,
                     double newPayRate, double newHours)
: employee(newName, newSSN) {
    payRate = newPayRate;
    hours = newHours;
    netPay = hours * payRate;
}
