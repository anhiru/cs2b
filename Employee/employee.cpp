//
//  employee.cpp
//  Employee
//
//  Created by Andrew Tran on 11/12/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "employee.h"
#include <string>
using namespace std;

employee::employee() {
    netPay = 0;
}






employee::employee(const string& newName, const string& newSSN) {
    name = newName;
    ssn = newSSN;
    netPay = 0;
}






void employee::changeName(const string& newName) {
    name = newName;
}






void employee::changeSSN(const string& newSSN) {
    ssn = newSSN;
}






string employee::getName() const {
    return name;
}






string employee::getSSN() const {
    return ssn;
}
