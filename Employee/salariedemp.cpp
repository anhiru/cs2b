//
//  salariedemp.cpp
//  Employee
//
//  Created by Andrew Tran on 11/12/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "salariedemp.h"
#include "employee.h"
#include <iostream>
using namespace std;

void salariedEmp::giveRaise(double amount) {
    salary += amount;
    netPay += amount;
}






salariedEmp::salariedEmp() {
    salary = 0;
    netPay = 0;
}






salariedEmp::salariedEmp(const string& newName,
                         const string& newSSN,
                         double newWeeklySalary)
: employee(newName, newSSN) {
    salary = newWeeklySalary;
    netPay = salary;
}






void salariedEmp::printCheck() const {
    cout << "Pay " << name << " the sum of " << netPay << " dollars." << endl;
    cout << "Check Stub: " << endl;
    cout << "Employee number: " << ssn << endl;
    cout << "This is a salaried employee.  Regular pay: "
    << salary << endl;
}
