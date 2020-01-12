#include <stdio.h>
#include "stdlib.h"

#include "string.h"
#include "inc/Memento.h"

int main() {

    Star *star = newStar();
    printf("%s",star->toString(star));
    

    return 0;
}
