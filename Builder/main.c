#include <stdio.h>
#include "inc/Builder.h"


int main() {

    BurgerBuilder *builder = createBurgerBuilder(43);

    Burger *burger = builder->addPepperoni(builder)
            ->addTomato(builder)->addCheese(builder)
            ->addLettuce(builder)->build(builder);
    return 0;
}
