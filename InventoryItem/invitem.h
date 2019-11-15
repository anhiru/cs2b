//
//  invitem.h
//  InventoryItem
//
//  Created by Andrew Tran on 10/19/19.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef INVITEM_H
#define INVITEM_H
#include <iostream>
using namespace std;

class InventoryItem {
public:
    static const int MAX_INPUT_SIZE = 127;
    InventoryItem();
    InventoryItem(const char* inDesc);
    InventoryItem(const InventoryItem& right);
    ~InventoryItem();
    InventoryItem operator=(const InventoryItem& right);
    void setInfo(const char* inDesc, int inUnits);
    void setUnits(int inUnits);
    friend ostream& operator<<(ostream& out, const InventoryItem& source);
    friend istream& operator>>(istream& in, InventoryItem& target);
    char operator[](int index) const;
    char& operator[](int index);
private:
    char* description;
    int units;
};

#endif /* invitem_h */
