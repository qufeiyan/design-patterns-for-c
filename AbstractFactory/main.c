#include <stdio.h>

#include "inc\AbstractFactory.h"

#include "malloc.h"

int main() {

    /** Iron door */
    DoorFactory *doorFactory = (DoorFactory *)createIronDoorFactory();
    Door *door = doorFactory->makeDoor();
    DoorFittingExpert *expert = doorFactory->makeDoorFittingExpert();
    door->getDescription();
    expert->getDescription();
    /** wooden door */
    DoorFactory *doorFactory1 = (DoorFactory *)createWoodenDoorFactory();
    Door *door1 = doorFactory1->makeDoor();
    DoorFittingExpert *expert1 = doorFactory1->makeDoorFittingExpert();
    door1->getDescription();
    expert1->getDescription();

/*
    typedef struct parent{
        int data;
        float fdata;
    }parent;

    typedef struct child{
        parent super;
    }child;

    typedef struct derived{
        parent* super;
    }derived;

    child d;
    derived de;

    printf("sizeof(child) is %d\n", sizeof(child));
    printf("sizeof(parent) is %d\n", sizeof(parent));
    printf("&child is %d\n", &d);
    printf("&child.super is %d\n",&d.super);

    printf("sizeof(derived) is %d\n", sizeof(derived));
    printf("&derived is %d\n", &de.super);
    printf("&derived.super is %d\n",&de.super);

    child *c = malloc(sizeof(child));
    derived *deri = malloc(sizeof(derived));
    deri->super = malloc(sizeof(parent));

    printf("&deri is %d\n",&deri);  */
    return 0;
}
