//
//  demon.h
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef DEMON_H
#define DEMON_H
#include "creature.h"
using namespace std;


namespace cs_creature {

    class Demon: public Creature {
    public:
        Demon();
        Demon(int newStrength, int newHitpoints);
        string getSpecies() const;
        int getDamage() const;
    };

}


#endif /* demon_h */
