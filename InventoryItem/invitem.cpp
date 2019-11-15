//
//  invitem.cpp
//  InventoryItem
//
//  Created by Andrew Tran on 10/19/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
#include "invitem.h"
using namespace std;

// default constructor
InventoryItem::InventoryItem() {
    description = new char[1];
    strcpy(description, "");
    units = 0;
}






// input constructor
InventoryItem::InventoryItem(const char* inDesc) {
    description = new char[strlen(inDesc) + 1];
    strcpy(description, inDesc);
    units = 0;
}






// copy constructor (1 of the big-3 member functions)
InventoryItem::InventoryItem(const InventoryItem& right) {
    units = right.units;
    description = new char[strlen(right.description) + 1];
    strcpy(description, right.description);
}






// destructor (1 of the big-3 member functions)
InventoryItem::~InventoryItem() {
    delete [] description;
}






// overloading assingment operator (1 of the big-3 member functions)
InventoryItem InventoryItem::operator=(const InventoryItem& right) {
    if (this != &right) {
        setInfo(right.description, right.units);
    }
    return *this;
}






void InventoryItem::setInfo(const char *inDesc, int inUnits) {
    delete [] description;
    description = new char[strlen(inDesc) + 1];
    strcpy(description, inDesc);
    units = inUnits;
}






void InventoryItem::setUnits(int inUnits) {
    units = inUnits;
}






// overloading output operator
ostream& operator<<(ostream& out, const InventoryItem& printMe) {
    out << printMe.units << " " << printMe.description;
    return out;
}






// overloading input operator
istream& operator>>(istream& in, InventoryItem& target) {
    while (isspace(in.peek())){
        in.ignore();
    }

    char temp[InventoryItem::MAX_INPUT_SIZE + 1];
    in.getline(temp, InventoryItem::MAX_INPUT_SIZE, ':');
    delete [] target.description;
    target.description = new char[strlen(temp) + 1];
    strcpy(target.description, temp);
    in >> target.units;

    return in;
}






char InventoryItem::operator[](int index) const {
    assert(index >= 0 && index < strlen(description));
    return description[index];
}






char& InventoryItem::operator[](int index) {
    assert(index >= 0 && index < strlen(description));
    return description[index];
}
