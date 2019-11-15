//
//  creature.h
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef CREATURE_H
#define CREATURE_H
#include <string>
using namespace std;

namespace cs_creature {

    class Creature {
    public:
        Creature();
        Creature(int newStrength, int newHitpoints);
        int getStrength() const;
        int getHitpoints() const;
        void setStrength(const int& newStrength);
        void setHitpoints(const int& newHitpoints);
        virtual string getSpecies() const = 0;
        virtual int getDamage() const;
    private:
        int strength;
        int hitpoints;
    };
    
}

#endif /* creature_h */
