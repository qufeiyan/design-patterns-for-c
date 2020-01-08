#include <stdio.h>
#include "inc\Flyweight.h"
#include "malloc.h"

//#define Potion int
//static void delPotion1(Potion *potion){
//    static Potion *temp = NULL; //used to prevent repeated release.
//    printf("temp is %d\n",temp);
//    if (potion != NULL){
//        if (temp == NULL) {
//            free(potion);
//            printf("potion is %d released\n ",potion);
//            temp = potion;
//            potion = NULL;
//        }else if (temp == potion){
//            //.nothing to do.
//        }else if (temp != NULL && temp != potion){
//            free(potion);
//            printf("potion is %d released\n ",potion);
//            temp = potion;
//            potion = NULL;
//        }
//    }
//}

int main() {
    printf("Hello, World!\n");

    PotionFactory *factory = newPotionFactory();
    AlchemistShop *alchemistShop = newAlchemistShop(factory);
    alchemistShop->enumerate(alchemistShop);

    delPotionFactory(factory);
    delAlchemistShop(alchemistShop);

//    int *a = malloc(sizeof(int));
//    int *b = a;
//    int *c = a;
//
//    int *A = malloc(sizeof(int));
//    int *B = A;
//
//    delPotion1(a);
//    delPotion1(b);
//    delPotion1(c);
//    delPotion1(A);
//    delPotion1(B);
//    delPotion1(b);
    return 0;
}
