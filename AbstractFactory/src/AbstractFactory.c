#include "../inc/AbstractFactory.h"
#include "malloc.h"
#include "stdio.h"

/** WoodenDoor override.  */
public static inline void getDescriptionForWoodenDoor(void){
    printf("I am a wooden door\n");
}

/**
 * @brief Constructor && Destructor for woodenDoor
 */
WoodenDoor *createWoodenDoor(void){
    WoodenDoor *obj =  malloc(sizeof(struct WoodenDoor));
    obj->base.getDescription = getDescriptionForWoodenDoor;
    return obj;
}

void deleteWoodenDoor(WoodenDoor *obj){
    if (obj != NULL){
        free(obj);
    }
}

/** IronDoor override */
public static inline void getDescriptionForIronDoor(void){
    printf("I am a iron door\n");
}

/**
 * @brief Constructor && Destructor for IronDoor.
 * @return
 */
IronDoor *createIronDoor(void){
    IronDoor *obj = malloc(sizeof(IronDoor));
    obj->base.getDescription = getDescriptionForIronDoor;
    return obj;
}

void deleteIronDoor(IronDoor *obj){
    if (NULL != obj)
        free(obj);
}

/** welder override */
public static inline void getDescriptionForWelder(void){
    printf("I can only fit iron doors\n");
}

/**
 * @brief Constructor && Destructor for Welder.
 * @return
 */
Welder *createWelder(void){
    Welder *obj = malloc(sizeof(Welder));
    obj->base.getDescription = getDescriptionForWelder;
    return obj;
}

void deleteWelder(Welder *obj){
    if (NULL != obj)
        free(obj);
}

/** Carpenter override */
public static inline void getDescriptionForCarpenter(){
    printf("I can only fit wooden doors\n");
};

/**
 * @brief Constructor && Destructor for Carpenter.
 */
Carpenter *createCarpenter(void){
    Carpenter *obj = malloc(sizeof(Carpenter));
    obj->base.getDescription = getDescriptionForCarpenter;
    return obj;
}

void deleteCarpenter(Carpenter *obj){
    if (NULL != obj)
        free(obj);
}

/** WoodenDoorFactory override */
public static inline Door* makeDoorForWoodenFactory(){
    return (Door *)createWoodenDoor();
}

public static inline DoorFittingExpert* makeDoorFittingExpertForWoodenFactory(){
    return (DoorFittingExpert *)createCarpenter();
}

/**
 * @brief Constructor && Destructor for WoodenDoorFactory.
 */
WoodenDoorFactory *createWoodenDoorFactory(){
    WoodenDoorFactory *obj = malloc(sizeof(WoodenDoorFactory));
  //  obj->base = malloc(sizeof(DoorFactory));
    obj->base.makeDoor = makeDoorForWoodenFactory;
    obj->base.makeDoorFittingExpert = makeDoorFittingExpertForWoodenFactory;
    return obj;
}

void deleteWoodenDoorFactory(WoodenDoorFactory *obj){
    if (NULL != obj)
        free(obj);
}

/** IronDoorFactory override */
public static inline Door* makeDoorForIronDoorFactory(){
    return (Door *)createIronDoor();
}

public static inline DoorFittingExpert *makeDoorFittingExpertForIronDoorFactory(){
    return (DoorFittingExpert *)createWelder();
}

/**
 * @brief Constructor && Destructor for IronDoorFactory.
 */
IronDoorFactory *createIronDoorFactory(){
    IronDoorFactory *obj = (IronDoorFactory *)malloc(sizeof(IronDoorFactory));
   // obj->base = (DoorFactory*)malloc(sizeof(DoorFactory));
    obj->base.makeDoor = makeDoorForIronDoorFactory;
    obj->base.makeDoorFittingExpert = makeDoorFittingExpertForIronDoorFactory;
    return obj;
}

void deleteIronDoorFactory(IronDoorFactory *obj){
    if (NULL != obj)
        free(obj);
}

