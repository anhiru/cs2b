//
//  cyberdemon.cpp
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "cyberdemon.h"
#include "demon.h"
#include "creature.h"
#include <iostream>
using namespace std;


namespace cs_creature {

    Cyberdemon::Cyberdemon() {}






    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
    : Demon(newStrength, newHitpoints) {}






    string Cyberdemon::getSpecies() const {
        return "Cyberdemon";
    }






    /*
     int Cyberdemon::getDamage() const {
     // cout << "The " << getSpecies();

     int damage = Demon::getDamage();

     return damage;
     }
     */
    
}
