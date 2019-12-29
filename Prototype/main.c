#include <stdio.h>
#include <malloc.h>
#include "inc/Prototype.h"

int main() {
//    printf("Hello, World!\n");
//    int x = 10000;
//    int * a = NULL;
//    printf("a is %d\n",a);
//    while(x --) {
//        int *aa = malloc(sizeof(int));
//        *aa = 0;
//        printf("aa is %d\n *aa is %d\n", aa, *aa);
//        free(aa);
//        printf("aa is %d\n *aa is %d\n", aa, *aa);
//    }

    Beast *b = (Beast*)newElfBeast0("protecting");
    HeroFactory *factory = (HeroFactory *)newHeroFactoryImpl(b);
    Beast *beast = factory->createBeast(factory);

    printf("b is equals %d\n",b->equals(b,beast));
    printf("%s\n",beast->toString(beast));


    Beast *ocb = (Beast*)newOrcBeast0("laser");
    factory = (HeroFactory*)newHeroFactoryImpl(ocb);
    Beast *ocbeast = factory->createBeast(factory);
    printf("b is equals %d\n",ocb->equals(ocb,beast));
    printf("%s\n",ocbeast->toString(ocbeast));
    return 0;
}

