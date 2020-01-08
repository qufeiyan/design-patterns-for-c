#include "..\inc\Flyweight.h"

#include "stdio.h"
#include "stdlib.h"

/**
 * HealingPotion
 */
/** @Override -----------*/
public static void drink(Potion *self){
    printf("You feel healed. (Potion = %d)\n",self);
}
/** @Constructor && @Destructor -----------------*/
public HealingPotion *newHealingPotion(){
    HealingPotion *self = malloc(sizeof(HealingPotion));
    self->super.drink = drink;
    return self;
}
public void delHealingPotion(HealingPotion *self){
    if (NULL != self){
        free(self);
    }
}

/**
 * HolyWaterPotion
 */
/** @Override ------------*/
public static void drink1(Potion *self){
    printf("You feel blessed. (Potion = %d)\n",self);
}
/** @Constructor && @Destructor -----------------*/
public HolyWaterPotion *newHolyWaterPotion(){
    HolyWaterPotion *self = malloc(sizeof(HolyWaterPotion));
    self->super.drink = drink1;
    return self;
}
public void delHolyWaterPotion(HolyWaterPotion *self){
    if (NULL != self)
        free(self);
}
/**
 * InvisibilityPotion
 */
/** @Override ------------*/
public static void drink2(Potion *self){
    printf("You become invisible. (Potion = %d)\n",self);
}
/** @Constructor && @Destructor -----------------*/
public InvisibilityPotion *newInvisibilityPotion(){
    InvisibilityPotion *self = malloc(sizeof(InvisibilityPotion));
    self->super.drink = drink2;
    return self;
}
public void delInvisibilityPotion(InvisibilityPotion *self){
    if (NULL != self){
        free(self);
    }
}

/**
 * HolyWaterPotion
 */
/** @Override ------------*/
public static void drink3(Potion *self){
    printf("Urgh! This is poisonous. (Potion = %d)\n",self);
}
/** @Constructor && @Destructor -----------------*/
public PoisonPotion *newPoisonPotion(){
    PoisonPotion *self = malloc(sizeof(PoisonPotion));
    self->super.drink = drink3;
    return self;
}
public void delPoisonPotion(PoisonPotion *self){
    if (NULL != self){
        free(self);
    }
}

/**
 * StrengthPotion.
 */
/** @Override -------------*/
public static void drink4(Potion *self) {
    printf("You feel strong. (Potion= %d)\n", self);
}
public StrengthPotion *newStrengthPotion(){\
    StrengthPotion* self = malloc(sizeof(StrengthPotion));
    self->super.drink = drink4;
    return self;
}
public void delStrengthPotion(StrengthPotion* self){
    if (NULL != self){
        free(self);
    }
}
/**
 * PotionFactory
 */
/** @brief member method for PotionFactory---------------*/
public Potion *createPotion(PotionFactory *self,PotionType type){
    Potion *potion = self->potions->get(self->potions,type);
    if (potion == NULL){
        switch (type){
            case HEALING:
                potion = (Potion*)newHealingPotion();
                self->potions->put(self->potions,type,potion);
                break;
            case HOLY_WATER:
                potion = (Potion*)newHolyWaterPotion();
                self->potions->put(self->potions,type, potion);
                break;
            case INVISIBILITY:
                potion = (Potion*)newInvisibilityPotion();
                self->potions->put(self->potions,type,potion);
                break;
            case POISON:
                potion = (Potion*)newPoisonPotion();
                self->potions->put(self->potions,type,potion);
                break;
            case STRENGTH:
                potion = (Potion*)newStrengthPotion();
                self->potions->put(self->potions,type,potion);
                break;
            default:
                break;
        }
    }
    return potion;
}

/** --------*/
public static void delPotion(PotionType type,Potion *potion){
    switch(type){
        case HEALING:
            if (NULL != potion) {
                delHealingPotion((HealingPotion *) potion);
                potion = NULL;
            }
            break;
        case HOLY_WATER:
            if (NULL != potion) {
                delHolyWaterPotion((HolyWaterPotion*)potion);
                potion = NULL;
            }
            break;
        case INVISIBILITY:
            if (NULL != potion) {
                delInvisibilityPotion((InvisibilityPotion *)potion);
                potion = NULL;
            }
            break;
        case POISON:
            if (NULL != potion) {
                delPoisonPotion((PoisonPotion*)potion);
                potion = NULL;
            }
            break;
        case STRENGTH:
            if (NULL != potion) {
                delStrengthPotion((StrengthPotion*)potion);
                potion = NULL;
            }
            break;
        default:
            break;
    }
}

public PotionFactory *newPotionFactory(void){
    PotionFactory *self = malloc(sizeof(PotionFactory));
    self->potions = createHashMap();
    self->createPotion = createPotion;
    return self;
}
public void delPotionFactory(PotionFactory *self){
    if (self != NULL){
        if (self->potions != NULL){
            self->potions->forEach(self->potions,delPotion);
            freeHashMap(self->potions);
        }
        free(self);
    }
}

/**
 * AlChemistShop
 */
static void Potion_drink(Potion *potion){
    potion->drink(potion);
}
    //. 仅对重复对象引用相邻的情况有用。
//static void delPotion1(Potion *potion){
//    static Potion *temp = NULL; //used to prevent repeated release.
//    if (potion != NULL){
//        if (temp == NULL) {
//            free(potion);
//            temp = potion;
//            potion = NULL;
//        }else if (temp == potion){
//            //.nothing to do.
//        }else if (temp != NULL && temp != potion){
//            free(potion);
//            temp = potion;
//            potion = NULL;
//        }
//    }
//}

/** @brief member method for AlchemistShop--------------*/
public static void enumerate(AlchemistShop *self){
    printf("Enumerating top shelf potions\n");
    self->topShelf->forEach(self->topShelf,Potion_drink);
    printf("Enumerating bottom shelf potions\n");
    self->bottomShelf->forEach(self->bottomShelf,Potion_drink);
}
public const ArrayList *getTopShelf(AlchemistShop *self){
    return self->topShelf->clone(self->topShelf);
}

public const ArrayList *getBottomShelf(AlchemistShop *self){
    return self->bottomShelf->clone(self->bottomShelf);
}

AlchemistShop *newAlchemistShop(PotionFactory *factory){
    AlchemistShop *self = malloc(sizeof(AlchemistShop));
    self->topShelf = createArrayList(10);
    self->bottomShelf = createArrayList(10);
    self->enumerate = enumerate;
    self->getBottomShelf = getBottomShelf;
    self->getTopShelf = getTopShelf;

    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,INVISIBILITY));
    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,INVISIBILITY));
    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,STRENGTH));
    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,HEALING));
    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,INVISIBILITY));
    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,STRENGTH));
    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,HEALING));
    self->topShelf->append(self->topShelf,
            factory->createPotion(factory,HEALING));

    self->bottomShelf->append(self->bottomShelf,
            factory->createPotion(factory,POISON));
    self->bottomShelf->append(self->bottomShelf,
            factory->createPotion(factory,POISON));
    self->bottomShelf->append(self->bottomShelf,
            factory->createPotion(factory,POISON));
    self->bottomShelf->append(self->bottomShelf,
            factory->createPotion(factory,HOLY_WATER));
    self->bottomShelf->append(self->bottomShelf,
            factory->createPotion(factory,HOLY_WATER));

    //delPotionFactory(factory);

    self->factory = factory;
    return self;
}
void delAlchemistShop(AlchemistShop *self){
    if (self != NULL){
//        self->topShelf->forEach(self->topShelf,delPotion1); //. 对象在factory中释放。shop只负责释放list。
//        self->bottomShelf->forEach(self->bottomShelf,delPotion1);
        deleteArrayList(self->topShelf);
        deleteArrayList(self->bottomShelf);
        free(self);
    }
}