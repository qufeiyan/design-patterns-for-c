#include <stdio.h>
#include "stdlib.h"

#include "string.h"
#include "inc/Memento.h"
#include "Stack/Stack.h"

int main() {

    Stack *states = newStack();
    Star *star = newStar(SUN, 10000000, 500000);
    printf("%s\n",star->toString(star));

    states->push(states,star->getMemento(star));
    star->timePasses(star);
    printf("%s\n",star->toString(star));

    states->push(states,star->getMemento(star));
    star->timePasses(star);
    printf("%s\n",star->toString(star));

    states->push(states,star->getMemento(star));
    star->timePasses(star);
    printf("%s\n",star->toString(star));

    while (states->super->size > 0){
        star->setMemento(star,states->pop(states));
        printf("%s\n",star->toString(star));
    }


    delStar(star);
    states->super->forEach(states->super,delStarMementoInternal);
    delStack(states);

    return 0;
}
