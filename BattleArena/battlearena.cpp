//
//  main.cpp
//  a7
//
//  Created by Andrew Tran on 11/06/19.
//  Dave Harden, CS 2B.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "creature.h"
#include "human.h"
#include "elf.h"
#include "demon.h"
#include "cyberdemon.h"
#include "balrog.h"
using namespace std;
using namespace cs_creature;

void battleArena(Creature& creature1, Creature& creature2);


int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Human h1;
    Elf e1;
    Cyberdemon c1;
    Balrog b1;

    Human h(10, 30);
    Elf e(25, 50);
    Cyberdemon c(30, 70);
    Balrog b(25, 50);


    cout << "default Human strength/hitpoints: " << h1.getStrength()
    << "/" << h1.getHitpoints() << endl;
    cout << "default Elf strength/hitpoints: " << e1.getStrength()
    << "/" << e1.getHitpoints() << endl;
    cout << "default Cyberdemon strength/hitpoints: " << c1.getStrength()
    << "/" << c1.getHitpoints() << endl;
    cout << "default Balrog strength/hitpoints: " << b1.getStrength()
    << "/" << b1.getHitpoints() << endl;
    cout << "non-default Human strength/hitpoints: " << h.getStrength()
    << "/" << h.getHitpoints() << endl;
    cout << "non-default Elf strength/hitpoints: " << e.getStrength()
    << "/" << e.getHitpoints() << endl;
    cout << "non-default Cyberdemon strength/hitpoints: " << c.getStrength()
    << "/" << c.getHitpoints() << endl;
    cout << "non-default Balrog strength/hitpoints: " << b.getStrength()
    << "/" << b.getHitpoints() << endl;
    cout << endl << endl;

    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = c.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = b.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    battleArena(h, e);
    battleArena(h, c);
    battleArena(h, b);
    battleArena(e, c);
    battleArena(e, b);
    battleArena(c, b);
}






void battleArena(Creature& creature1, Creature& creature2) {
    int hpInit1 = creature1.getHitpoints();
    int hpInit2 = creature2.getHitpoints();

    cout << "\nEntering the arena from the left wing...\n Creature 1, "
    << creature1.getSpecies() << ", with " << hpInit1 << " HP and "
    << creature1.getStrength() << " strength." << endl;
    cout << "Entering the arena from the right wing...\n Creature 2, "
    << creature2.getSpecies() << ", with " << hpInit2 << " HP and "
    << creature2.getStrength() << " strength." << endl;
    cout << "\nBATTLE START!" << endl << endl;


    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        creature1.setHitpoints(creature1.getHitpoints()
                               - creature2.getDamage());
        creature2.setHitpoints(creature2.getHitpoints()
                               - creature1.getDamage());

        int hp1 = creature1.getHitpoints();
        int hp2 = creature2.getHitpoints();

        if (hp1 <= 0 && hp2 <= 0) {
            cout << "\nRESULT: Both creatures have fallen. It's a tie!"
            << endl << endl;
        } else if (hp1 > 0 && hp2 <= 0) {
            cout << "\nRESULT: Creature 1, " << creature1.getSpecies()
            << ", emerges victorious!" << endl << endl;
        } else if (hp1 <= 0 && hp2 > 0) {
            cout << "\nRESULT: Creature 2, " << creature2.getSpecies()
            << ", emerges victorious!" << endl << endl;
        } else {
            cout << "\nCreature 1, " << creature1.getSpecies()
            << ", has " << hp1 << " HP left." << endl;
            cout << "Creature 2, " << creature2.getSpecies()
            << ", has " << hp2 << " HP left.\n" << endl;
        }
    }

    creature1.setHitpoints(hpInit1);
    creature2.setHitpoints(hpInit2);
    cout << "Creatures restored to perfect health." << endl << endl << endl;
}

/*

 default Human strength/hitpoints: 10/10
 default Elf strength/hitpoints: 10/10
 default Cyberdemon strength/hitpoints: 10/10
 default Balrog strength/hitpoints: 10/10
 non-default Human strength/hitpoints: 10/30
 non-default Elf strength/hitpoints: 25/50
 non-default Cyberdemon strength/hitpoints: 30/70
 non-default Balrog strength/hitpoints: 25/50


 Examples of Human damage:
 The Human attacks for 7 points!
 Total damage = 7

 The Human attacks for 4 points!
 Total damage = 4

 The Human attacks for 9 points!
 Total damage = 9

 The Human attacks for 3 points!
 Total damage = 3

 The Human attacks for 9 points!
 Total damage = 9

 The Human attacks for 1 points!
 Total damage = 1

 The Human attacks for 10 points!
 Total damage = 10

 The Human attacks for 7 points!
 Total damage = 7

 The Human attacks for 7 points!
 Total damage = 7

 The Human attacks for 4 points!
 Total damage = 4


 Examples of Elf damage:
 The Elf attacks for 22 points!
 Total damage = 22

 The Elf attacks for 20 points!
 Total damage = 20

 The Elf attacks for 19 points!
 Total damage = 19

 The Elf attacks for 11 points!
 Total damage = 11

 The Elf attacks for 17 points!
 Total damage = 17

 The Elf attacks for 16 points!
 Magical attack inflicts 16 additional damage points!
 Total damage = 32

 The Elf attacks for 4 points!
 Magical attack inflicts 4 additional damage points!
 Total damage = 8

 The Elf attacks for 4 points!
 Total damage = 4

 The Elf attacks for 17 points!
 Total damage = 17

 The Elf attacks for 21 points!
 Magical attack inflicts 21 additional damage points!
 Total damage = 42


 Examples of Cyberdemon damage:
 The Cyberdemon attacks for 3 points!
 Total damage = 3

 The Cyberdemon attacks for 23 points!
 Total damage = 23

 The Cyberdemon attacks for 8 points!
 Total damage = 8

 The Cyberdemon attacks for 10 points!
 Total damage = 10

 The Cyberdemon attacks for 9 points!
 Demonic attack inflicts 50 additional damage points!
 Total damage = 59

 The Cyberdemon attacks for 30 points!
 Total damage = 30

 The Cyberdemon attacks for 21 points!
 Total damage = 21

 The Cyberdemon attacks for 16 points!
 Total damage = 16

 The Cyberdemon attacks for 13 points!
 Total damage = 13

 The Cyberdemon attacks for 26 points!
 Total damage = 26


 Examples of Balrog damage:
 The Balrog attacks for 23 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 21 additional damage points!
 Total damage = 94

 The Balrog attacks for 21 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 14 additional damage points!
 Total damage = 85

 The Balrog attacks for 1 points!
 Balrog speed attack inflicts 23 additional damage points!
 Total damage = 24

 The Balrog attacks for 3 points!
 Balrog speed attack inflicts 16 additional damage points!
 Total damage = 19

 The Balrog attacks for 25 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 18 additional damage points!
 Total damage = 93

 The Balrog attacks for 13 points!
 Balrog speed attack inflicts 23 additional damage points!
 Total damage = 36

 The Balrog attacks for 24 points!
 Balrog speed attack inflicts 7 additional damage points!
 Total damage = 31

 The Balrog attacks for 21 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 5 additional damage points!
 Total damage = 76

 The Balrog attacks for 16 points!
 Balrog speed attack inflicts 22 additional damage points!
 Total damage = 38

 The Balrog attacks for 13 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 24 additional damage points!
 Total damage = 87



 Entering the arena from the left wing...
 Creature 1, Human, with 30 HP and 10 strength.
 Entering the arena from the right wing...
 Creature 2, Elf, with 50 HP and 25 strength.

 BATTLE START!

 The Elf attacks for 8 points!
 Magical attack inflicts 8 additional damage points!
 The Human attacks for 10 points!

 Creature 1, Human, has 14 HP left.
 Creature 2, Elf, has 40 HP left.

 The Elf attacks for 10 points!
 Magical attack inflicts 10 additional damage points!
 The Human attacks for 6 points!

 RESULT: Creature 2, Elf, emerges victorious!

 Creatures restored to perfect health.



 Entering the arena from the left wing...
 Creature 1, Human, with 30 HP and 10 strength.
 Entering the arena from the right wing...
 Creature 2, Cyberdemon, with 70 HP and 30 strength.

 BATTLE START!

 The Cyberdemon attacks for 29 points!
 Demonic attack inflicts 50 additional damage points!
 The Human attacks for 3 points!

 RESULT: Creature 2, Cyberdemon, emerges victorious!

 Creatures restored to perfect health.



 Entering the arena from the left wing...
 Creature 1, Human, with 30 HP and 10 strength.
 Entering the arena from the right wing...
 Creature 2, Balrog, with 50 HP and 25 strength.

 BATTLE START!

 The Balrog attacks for 8 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 17 additional damage points!
 The Human attacks for 4 points!

 RESULT: Creature 2, Balrog, emerges victorious!

 Creatures restored to perfect health.



 Entering the arena from the left wing...
 Creature 1, Elf, with 50 HP and 25 strength.
 Entering the arena from the right wing...
 Creature 2, Cyberdemon, with 70 HP and 30 strength.

 BATTLE START!

 The Cyberdemon attacks for 29 points!
 Demonic attack inflicts 50 additional damage points!
 The Elf attacks for 8 points!
 Magical attack inflicts 8 additional damage points!

 RESULT: Creature 2, Cyberdemon, emerges victorious!

 Creatures restored to perfect health.



 Entering the arena from the left wing...
 Creature 1, Elf, with 50 HP and 25 strength.
 Entering the arena from the right wing...
 Creature 2, Balrog, with 50 HP and 25 strength.

 BATTLE START!

 The Balrog attacks for 15 points!
 Balrog speed attack inflicts 19 additional damage points!
 The Elf attacks for 16 points!

 Creature 1, Elf, has 16 HP left.
 Creature 2, Balrog, has 34 HP left.

 The Balrog attacks for 4 points!
 Balrog speed attack inflicts 9 additional damage points!
 The Elf attacks for 22 points!

 Creature 1, Elf, has 3 HP left.
 Creature 2, Balrog, has 12 HP left.

 The Balrog attacks for 7 points!
 Balrog speed attack inflicts 10 additional damage points!
 The Elf attacks for 9 points!

 RESULT: Creature 2, Balrog, emerges victorious!

 Creatures restored to perfect health.



 Entering the arena from the left wing...
 Creature 1, Cyberdemon, with 70 HP and 30 strength.
 Entering the arena from the right wing...
 Creature 2, Balrog, with 50 HP and 25 strength.

 BATTLE START!

 The Balrog attacks for 9 points!
 Balrog speed attack inflicts 9 additional damage points!
 The Cyberdemon attacks for 22 points!

 Creature 1, Cyberdemon, has 52 HP left.
 Creature 2, Balrog, has 28 HP left.

 The Balrog attacks for 12 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 22 additional damage points!
 The Cyberdemon attacks for 7 points!

 RESULT: Creature 2, Balrog, emerges victorious!

 Creatures restored to perfect health.


*/
