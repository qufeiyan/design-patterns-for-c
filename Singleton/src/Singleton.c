#include "..\inc\Singleton.h"
#include "malloc.h"
#include "stdio.h"
#include "string.h"

/** @override-----------------------------*/
static inline boolean isHuman(Hero *this){
    printf("I am alien\n");
    return false;
}

static inline boolean isMarried(Hero *this){
    printf("I am married\n");
    return true;
}

/**----------*/
static inline void fly(Superman *this){
    printf("I can fly\n");
}

/** @constuctor && @destructor------------*/
static Superman *newSuperman(void){
    Superman* this = malloc(sizeof(Superman));
    this->super.gender = "male";
    this->super.isHuman = isHuman;
    this->super.isMarried = isMarried;
    this->fly = fly;
    this->super.superPower = "fly";
    return this;
}



/** @override-----------------------------*/
static inline boolean isHuman1(Hero *this){
    printf("I am Human\n");
    return true;
}

static inline boolean isMarried1(Hero *this){
    printf("I am not married\n");
    return false;
}

/**----------*/
static inline void kill(Batman *this){
    printf("I always kill\n");
}

/** @constuctor && @destructor------------*/
static Batman *newBatman(void){
    Batman* this = malloc(sizeof(Batman));
    this->super.gender = "male";
    this->super.isHuman = isHuman1;
    this->super.isMarried = isMarried1;
    this->kill = kill;
    this->super.superPower = "kill";
    return this;
}


Hero *getHero(char* gender,char* superPower){
    static Hero *hero = NULL;
    printf("hero addr is %04x\n",hero);
    if(NULL != hero){
        return hero;
    }else{
        if (strcmp(gender,"male") == 0 && strcmp(superPower,"kill")){
            return hero = (Hero*)newSuperman();
            printf("call here\n");
        }else{
            return hero = (Hero*)newBatman();
        }
    }
}







