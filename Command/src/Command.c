//
// Created by Elena on 2020/1/9.
//
#include "../inc/Command.h"
#include "stdio.h"
#include "malloc.h"
/**
 * Target
 */
/** default method -------------------------*/
public static Size getSize(Target *self){
    return self->size;
}
public static void setSize(Target *self,Size size){
    self->size = size;
}
public static Visibility getVisibility(Target *self){
    return self->visibility;
}
public static void setVisibility(Target *self,Visibility *visibility){
    self->visibility = visibility;
}
public static void printStatus(Target *self){
    printf("%s [size = %s] [visibility = %s]",
    self->toString(self),self->getSize(self),self->getVisibility(self));
}
Target* (*newTarget)(void){
    Target *self = malloc(sizeof(Target));
    self.setSize = setSize;
    self.getSize = getSize;
    self.setVisibility = setVisibility;
    self.getVisibility = getVisibility;
    self.printStatus = printStatus;
    return self;
}
void (*delTarget)(Target *self){
    if (NULL != self){
        free(self);
    }
}

/** super --------------------*/
static void initSuper(Target super){
    super.setSize = setSize;
    super.getSize = getSize;
    super.setVisibility = setVisibility;
    super.getVisibility = getVisibility;
    super.printStatus = printStatus;
}

/**
 * Goblin
 */
@Override
public String toString() {
    return "Goblin";
}
Goblin *newGoblin(void){
    Goblin *self = malloc(sizeof(Goblin));
    initSuper(&self->super);
    self->super.toString = toString;
    return self;
}
void delGoblin(Goblin *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

