#include <stdio.h>
#include "inc/Adapter.h"

int main() {
    printf("Hello, World!\n");


    Captain *cap = newCaptain((RowingBoat*)newFishingBoatAdapter());
    cap->row();
    return 0;
}
