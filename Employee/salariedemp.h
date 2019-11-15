//
//  salariedemp.h
//  Employee
//
//  Created by Andrew Tran on 11/12/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef SALARIEDEMP_H
#define SALARIEDEMP_H
#include "employee.h"
#include <string>
using namespace std;

class salariedEmp : public employee {
public:
    salariedEmp();
    salariedEmp(const string& newName, const string& newSSN,
                double newWeeklySalary);
    void printCheck() const;
    void giveRaise(double amount);
private:
    double salary;
};

#endif /* salariedemp_h */
