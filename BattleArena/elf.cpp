//
//  elf.cpp
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "elf.h"
#include "creature.h"
#include <iostream>
using namespace std;


namespace cs_creature {

    Elf::Elf() {}






    Elf::Elf(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints) {}






    string Elf::getSpecies() const {
        return "Elf";
    }


    
    
    
    
    int Elf::getDamage() const {
        int damage = Creature::getDamage();
        
        // cout << "The " << getSpecies() << " attacks for " << damage
        // << " points!" << endl;
        
        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage
            << " additional damage points!" << endl;
            damage *= 2;
        }
        
        return damage;
    }

}
