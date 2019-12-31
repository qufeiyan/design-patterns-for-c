#include "stdio.h"

#include "stdlib.h"
#include "inc/Singleton.h"

void main(){

    Hero *hero = getHero("male","fly");

    printf("%s\n",hero->isMarried);

}