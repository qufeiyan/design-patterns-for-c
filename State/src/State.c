#include "../inc/State.h"
#include "stdio.h"
#include "malloc.h"

#ifndef NULL
#define NULL (void *)0
#endif
// 任一时刻只存在单一状态对象。
static State* getState(Mammoth *self, StateName name){
    static State* state[2] = {NULL};
    State *peceful = newPeacefulState(self);
    State *angry = newAngryState(self);
    switch (name){
        case PEACEFUL:
            state[0] = angry
    }
}

/**
 * Mammoth
 */
/** member method ---------------------*/
public static void timePasses(Mammoth *self){
//    if (self->state )
    State *nextState =
}

private static void changeStateTo(Mammoth *self,State newState){
    self->state = newState;
    self->state.onEnterState(&self->state);
}

public char* toString(){
    return "The mammoth";
}

public static void observe(Mammoth *self){
    self->state.observe(&self->state);
}

Mammoth *newMammoth(void){
    Mammoth *self = malloc(sizeof(Mammoth));
    self->timePasses = timePasses;
    self->observe = observe;
    self->changeStateTo = changeStateTo;
    self->toString = toString;
    return self;
}
void delMammoth(Mammoth *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * PeacefulState
 */
/** definition ----------------------*/
public static void observe1(PeacefulState *self){
    printf("%s is calm and peaceful!\n",self->mammoth->toString());
}

public static void onEnterState1(PeacefulState *self){
    printf("%s calms down.\n",self->mammoth->toString());
}


PeacefulState *newPeacefulState(Mammoth *mammoth){
    PeacefulState *self = malloc(sizeof(PeacefulState));
    self->super.observe = observe1;
    self->super.onEnterState = onEnterState1;
    self->mammoth = mammoth;
    return self;
}
void delPeacefulState(PeacefulState* self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * AngryState
 */
/** definition ----------------------*/
public static void observe2(AngryState *self){
    printf("%s is furious!\n",self->mammoth->toString());
}

public static void onEnterState2(AngryState *self){
    printf("%s gets angry!\n",self->mammoth->toString());
}

AngryState *newAngryState(Mammoth *mammoth){
    AngryState *self = malloc(sizeof(AngryState));
    self->super.onEnterState = onEnterState2;
    self->super.observe = observe2;
    self->mammoth = mammoth;
    return self;
}

void delAngryState(AngryState *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}