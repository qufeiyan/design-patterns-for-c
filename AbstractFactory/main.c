#include <stdio.h>

#include "inc\AbstractFactory.h"

int main() {

    /** Iron door */
    DoorFactory *doorFactory = (DoorFactory *)createIronDoorFactory();
    Door *door = doorFactory->makeDoor();
    DoorFittingExpert *expert = doorFactory->makeDoorFittingExpert();
    door->getDescription();
    expert->getDescription();
    /** wooden door */
 /*   DoorFactory *doorFactory1 = (DoorFactory *)createWoodenDoorFactory();
    Door *door1 = doorFactory1->makeDoor();
    DoorFittingExpert *expert1 = doorFactory1->makeDoorFittingExpert();
    door->getDescription();
    expert1->getDescription();
*/
    return 0;
}
