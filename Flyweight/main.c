#include <stdio.h>
#include "inc\Flyweight.h"

int main() {
    printf("Hello, World!\n");

    AlchemistShop *alchemistShop = newAlchemistShop();
    alchemistShop->enumerate(alchemistShop);

    delAlchemistShop(alchemistShop);
    return 0;
}
