//
// Created by Elena on 2020/1/1.
//
#include <stdlib.h>
#include "../inc/Adapter.h"

extern int __cdecl printf(const char * __restrict__ _Format,...);

static void sail(void){
    printf("The fishing boat is sailing\n");
}


FishingBoat *newFishingBoat(void){
    FishingBoat *self = malloc(sizeof(FishingBoat));
    self->sail = sail;
    return self;
}
void delFishingBoat(FishingBoat *self){
    if (NULL != self){
        free(self);
    }
}


/** FishingBoatAdapter @override-----------------*/
public void row(void *obj){
    FishingBoatAdapter *self = obj;
    self->boat->sail();
}
/** FishingBoatAdapter @constructor && @destructor----------------------*/
FishingBoatAdapter *newFishingBoatAdapter(void){
    FishingBoatAdapter *self = malloc(sizeof(FishingBoatAdapter));
    self->boat = newFishingBoat();
    self->super.row = row;
}
void delFishingBoatAdapter(FishingBoatAdapter *self){
    if (NULL != self){
        free(self);
    }
}

/** Captain @method-------------------------------*/
void rowForCaptain(Captain *self){
    self->rowingBoat->row(self->rowingBoat);
}
/** Captain @constructor && @destructor --------------------*/
Captain *newCaptain(RowingBoat *rowingBoat){
    Captain *self= malloc(sizeof(Captain));
    self->rowingBoat = rowingBoat;
    self->row = row;
    return self;
}
void delCaptain(Captain *self){
    if (NULL != self){
        free(self);
    }
}