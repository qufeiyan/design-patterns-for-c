//
// Created by Elena on 2020/1/12.
//

#include "../inc/Memento.h"
#include "stdlib.h"
#include "stdio.h"

static char* typeTitle(StarType type){
    switch (type){
        case SUN:
            return "sun";
        case RED_GIANT:
            return "red giant";
        case WHITE_DWARF:
            return "white dwarf";
        case SUPERNOVA:
            return "supernova";
        case DEAD:
            return "dead star";
        case UNDEFINED:
            return "";
    }
}

public static void timePasses(Star *self){
    self->ageYears *= 2;
    self->massTons *= 8;
    switch (self->type){
        case RED_GIANT:
            self->type = WHITE_DWARF;
            break;
        case SUN:
            self->type = RED_GIANT;
            break;
        case SUPERNOVA:
            self->type = DEAD;
            break;
        case WHITE_DWARF:
            self->type = SUPERNOVA;
            break;
        case DEAD:
            self->ageYears *= 2;
            self->massTons = 0;
            break;
        default:
            break;
    }
}
static StarMemento* getMemento(Star *self){
    StarMementoInternal *state = newStarMementoInternal();
    state->setAgeYears(state,self->ageYears);
    state->setMassTons(state,self->massTons);
    state->setType(state,self->type);
    return (StarMemento *)state;
}
static void setMemento(Star *self,StarMemento *memento){
    StarMementoInternal *state = (StarMementoInternal*)memento;
    self->type = state->getType(state);
    self->ageYears = state->getAgeYears(state);
    self->massTons = state->getMassTons(state);
}
public static char* toString(Star *self){
    static char buffer[40];
    sprintf(buffer,"%s age: %d years mass: %d tons",
            typeTitle(self->type),self->ageYears,self->massTons);
    return buffer;
}
Star *newStar(StarType starType, int starAge, int starMass){
    Star *self = malloc(sizeof(Star));
    self->type = starType;
    self->ageYears = starAge;
    self->massTons = starMass;
    self->getMemento = getMemento;
    self->setMemento = setMemento;
    self->timePasses = timePasses;
    self->toString = toString;
    return self;
}
void delStar(Star *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * StarMemento implementation.
 */
/** definition ---*/
public static StarType getType(StarMementoInternal *self){
    return self->type;
}
public static void setType(StarMementoInternal *self,StarType type){
    self->type = type;
}
public static int getAgeYears(StarMementoInternal *self){
    return self->ageYears;
}
public static void setAgeYears(StarMementoInternal *self, int ageYears){
    self->ageYears = ageYears;
}
public static int getMassTons(StarMementoInternal *self){
    return self->massTons;
}
public static void setMassTons(StarMementoInternal *self, int massTons){
    self->massTons = massTons;
}

StarMementoInternal* newStarMementoInternal(void){
    StarMementoInternal *self = malloc(sizeof(StarMementoInternal));
    self->setType = setType;
    self->getType = getType;
    self->setAgeYears = setAgeYears;
    self->getAgeYears = getAgeYears;
    self->setMassTons = setMassTons;
    self->getMassTons = getMassTons;
    return self;
}
void delStarMementoInternal(StarMementoInternal *self){
    if (NULL != self){
        free(self);
    }
}

