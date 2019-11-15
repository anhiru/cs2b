//
//  employee.h
//  Employee
//
//  Created by Andrew Tran on 11/12/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class employee {
public:
    employee();
    employee(const string& newName, const string& newSSN);
    string getName() const;
    string getSSN() const;
    void changeName(const string& newName);
    void changeSSN(const string& newSSN);
protected:
    string name;
    string ssn;
    double netPay;
};

#endif /* employee_h */
