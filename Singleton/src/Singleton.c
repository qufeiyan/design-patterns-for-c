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
    this->super.isHuman = false;
    this->super.isMarried = true;
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
static inline void kill(Superman *this){
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


Hero *(*getHero)(char* gender,char* superPower){
    static Hero *hero = NULL;
    if(NULL != Hero){
        return hero;
    }else{
        if (strcmp(gender,"male") == 0 && strcmp(superPower,"kill")){
            return newSuperman();
        }else{
            return newBatman();
        }
    }
}







