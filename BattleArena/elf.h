//
//  elf.h
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#ifndef ELF_H
#define ELF_H
#include "creature.h"
#include <string>
using namespace std;


namespace cs_creature {

    class Elf: public Creature {
    public:
        Elf();
        Elf(int newStrength, int newHitpoints);
        string getSpecies() const;
        int getDamage() const;
    };

}

#endif /* elf_h */
