#include "stdio.h"

#include "stdlib.h"
#include "inc/Singleton.h"

void main(void){

    Hero *hero = getHero("male","fly");
    hero->isHuman(hero);
    hero->isMarried(hero);
    printf("hero is %04x\n",hero);

    Hero *hero1 = getHero("male","fly");
    hero1->isHuman(hero1);
    hero1->isMarried(hero1);
    printf("hero1 is %04x\n", hero1);

    Superman *superman = hero;
    superman->fly(superman);

    return;
}