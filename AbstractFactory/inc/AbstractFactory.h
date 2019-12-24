#ifndef __ABSTRACT_FACTORY_H
#define __ABSTRACT_FACTORY_H

#include "stdio.h"



#define Class typedef struct
#define private
#define public

#define interface typedef struct


interface IDoor{
    public void (*getDescription)(void);
}Door;

#define implements_IDoor
Class WoodenDoor implements_IDoor{
    Door base;
}WoodenDoor;

WoodenDoor *createWoodenDoor(void);
void deleteWoodenDoor(WoodenDoor *obj);

Class IronDoor implements_IDoor{
    Door base;
}IronDoor;

IronDoor *createIronDoor(void);
void deleteIronDoor(IronDoor *obj);

//. Then we have some fitting exkperts for each door type

interface IDoorFittingExpert{
    public void (*getDescription)(void);
}DoorFittingExpert;

#define implements_IDoorFittingExpert
Class Welder implements_IDoorFittingExpert{
    DoorFittingExpert base;
}Welder;

Welder *createWelder(void);
void deleteWelder(Welder *obj);


Class Carpenter implements_IDoorFittingExpert{
    DoorFittingExpert base;
}Carpenter;

Carpenter *createCarpenter(void);
void deleteCarpenter(Carpenter *obj);


//. Now we have our abstract factory that woulde let us make family of related objects i.e.
//. wooden door factory would create a wooden door and wooden door fitting expert and iro door
//. factory would create an iron door and iron door fitting expert.

interface IDoorFactory{
    public Door *(*makeDoor)(void);
    public DoorFittingExpert *(*makeDoorFittingExpert)(void);
}DoorFactory;

#define implements_IDoorFactory
Class WoodenDoorFactory implements_IDoorFactory{
    DoorFactory base;
}WoodenDoorFactory;
WoodenDoorFactory *createWoodenDoorFactory(void);
void deleteWoodenDoorFactory(WoodenDoorFactory *obj);

Class IronDoorFactory implements_IDoorFactory{
    DoorFactory base;
}IronDoorFactory;

IronDoorFactory *createIronDoorFactory(void);
void deleteIronDoorFactory(IronDoorFactory *obj);



#endif