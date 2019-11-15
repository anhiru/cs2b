//
//  balrog.cpp
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include "balrog.h"
#include "demon.h"
#include "creature.h"
#include <iostream>
using namespace std;


namespace cs_creature {

    Balrog::Balrog() {}






    Balrog::Balrog(int newStrength, int newHitpoints)
    : Demon(newStrength, newHitpoints) {}






    string Balrog::getSpecies() const {
        return "Balrog";
    }






    int Balrog::getDamage() const {
        // cout << "The " << getSpecies();

        int damage = Demon::getDamage();
        int damage2 = (rand() % Demon::getStrength()) + 1;

        cout << "Balrog speed attack inflicts " << damage2
        << " additional damage points!" << endl;

        damage += damage2;

        return damage;
    }

}
