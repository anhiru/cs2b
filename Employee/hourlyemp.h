//
//  hourlyemp.h
//  Employee
//
//  Created by Andrew Tran on 11/12/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef HOURLYEMP_H
#define HOURLYEMP_H
#include "employee.h"
#include <string>
using namespace std;

class hourlyEmp: public employee {
public:
    hourlyEmp();
    hourlyEmp(const string& newName, const string& newSSN,
              double newPayRate, double newHours);
    double getHours() const;
    void setHours(double newHours);
    void giveRaise(double amount);
    void printCheck() const;
private:
    double hours;
    double payRate;
};

#endif /* hourlyemp_h */
