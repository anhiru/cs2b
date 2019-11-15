//
//  demon.cpp
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "demon.h"
#include "creature.h"
#include <iostream>
using namespace std;


namespace cs_creature {

    Demon::Demon() {}






    Demon::Demon(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints) {}






    string Demon::getSpecies() const {
        return "Demon";
    }






    int Demon::getDamage() const {
        int damage = Creature::getDamage();

        // cout << " attacks for " << damage << " points!" << endl;

        if (rand() % 4 == 0) {
            damage += 50;
            cout << "Demonic attack inflicts 50 additional damage points!"
            << endl;
        }

        return damage;
    }

}
