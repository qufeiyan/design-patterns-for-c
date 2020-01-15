#include "../inc/State.h"
#include "stdio.h"
#include "malloc.h"

#ifndef NULL
#define NULL (void *)0
#endif
//// 任一时刻只存在单一状态对象。
//static void setState(Mammoth *self){
//    static State* state[2] = {NULL};
//    if(state[1] == NULL && state[0] == NULL ){
//        state[0] = newPeacefulState(self);
//        state[1] = newAngryState(self);
//    }
//    switch (self->name){
//        case PEACEFUL:
//            self->state = state[1];
//            self->name = ANGRY;
//            break;
//        case ANGRY:
//            self->state = state[0];
//            self->name = PEACEFUL;
//        default:
//            break;
//    }
//}

/**
 * Mammoth
 */
/** member method ---------------------*/
public static void timePasses(Mammoth *self){
    self->changeStateTo(self);
}

public static void setCurrentState(Mammoth *self,State* state){
    self->currentState = state;
}

private static void changeStateTo(Mammoth *self){
    self->currentState->setNextState(self->currentState);
    self->currentState->onEnterState(self->currentState);
}

public static char* toString(){
    return "The mammoth";
}

public static void observe(Mammoth *self){
    self->currentState->observe(self->currentState);
}

Mammoth *newMammoth(void){
    Mammoth *self = malloc(sizeof(Mammoth));
    //. initialize all state.
    self->PEACEFUL_STATE = (State *)newPeacefulState(self);
    self->ANGRY_STATE = (State*)newAngryState(self);
    //. set initial state.
    self->currentState = self->PEACEFUL_STATE;

    self->timePasses = timePasses;
    self->observe = observe;
    self->changeStateTo = changeStateTo;
    self->toString = toString;
    self->setCurrentState = setCurrentState;
    return self;
}
void delMammoth(Mammoth *self){
    if (NULL != self){

        delAngryState((AngryState *)self->ANGRY_STATE);
        delPeacefulState((PeacefulState *)self->PEACEFUL_STATE);

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

public static void setNextState1(PeacefulState *self){
    self->mammoth->setCurrentState(self->mammoth,self->mammoth->ANGRY_STATE);
}

PeacefulState *newPeacefulState(Mammoth *mammoth){
    PeacefulState *self = malloc(sizeof(PeacefulState));
    self->super.observe = observe1;
    self->super.onEnterState = onEnterState1;
    self->mammoth = mammoth;

    self->super.setNextState = setNextState1;
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

public static void setNextState2(AngryState *self){
    self->mammoth->setCurrentState(self->mammoth,self->mammoth->PEACEFUL_STATE);
}

AngryState *newAngryState(Mammoth *mammoth){
    AngryState *self = malloc(sizeof(AngryState));
    self->super.onEnterState = onEnterState2;
    self->super.observe = observe2;
    self->mammoth = mammoth;
    self->super.setNextState = setNextState2;
    return self;
}

void delAngryState(AngryState *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}