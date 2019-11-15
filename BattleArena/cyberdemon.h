//
//  cyberdemon.h
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"
#include "creature.h"
#include <string>
using namespace std;


namespace cs_creature {

    class Cyberdemon: public Demon {
    public:
        Cyberdemon();
        Cyberdemon(int newStrength, int newHitpoints);
        string getSpecies() const;
        // int getDamage() const;
    };

}

#endif /* cyberdemon_h */
