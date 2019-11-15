//
//  human.cpp
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "human.h"
#include "creature.h"
#include <iostream>
using namespace std;


namespace cs_creature {

    Human::Human() {}






    Human::Human(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints) {}






    string Human::getSpecies() const {
        return "Human";
    }






    /*
     int Human::getDamage() const {
     int damage = Creature::getDamage();

     // cout << "The " << getSpecies() << " attacks for " << damage
     << " points!" << endl;

     return damage;
     }
     */

}
