//
//  creature.cpp
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "creature.h"
#include <iostream>
using namespace std;


namespace cs_creature {

    Creature::Creature() {
        setStrength(10);
        setHitpoints(10);
    }






    Creature::Creature(int newStrength, int newHitpoints) {
        setStrength(newStrength);
        setHitpoints(newHitpoints);
    }






    int Creature::getStrength() const {
        return strength;
    }






    int Creature::getHitpoints() const {
        return hitpoints;
    }






    void Creature::setStrength(const int& newStrength) {
        strength = newStrength;
    }






    void Creature::setHitpoints(const int& newHitpoints) {
        hitpoints = newHitpoints;
    }






    int Creature::getDamage() const {
        int damage = (rand() % strength) + 1;


        cout << "The " << getSpecies() << " attacks for " << damage
        << " points!" << endl;


        return damage;
    }

}
