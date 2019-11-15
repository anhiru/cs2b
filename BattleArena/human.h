//
//  human.h
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef HUMAN_H
#define HUMAN_H
#include "creature.h"
using namespace std;


namespace cs_creature {
    
    class Human: public Creature {
    public:
        Human();
        Human(int newStrength, int newHitpoints);
        string getSpecies() const;
        // int getDamage() const;
    };

}

#endif /* human_h */
