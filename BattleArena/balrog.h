//
//  balrog.h
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef BALROG_H
#define BALROG_H
#include "demon.h"
#include "creature.h"
#include <string>
using namespace std;


namespace cs_creature {

    class Balrog: public Demon {
    public:
        Balrog();
        Balrog(int newStrength, int newHitpoints);
        string getSpecies() const;
        int getDamage() const;
    };

}

#endif /* balrog_h */
