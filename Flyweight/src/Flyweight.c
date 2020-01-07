#include "..\inc\Flyweight.h"

#include "stdio.h"
#include "stdlib.h"

/**
 * HealingPotion
 */
/** @Override -----------*/
public static void drink(Potion *self){
    printf("You feel healed. (Potion = %d)",self);
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
    printf("You feel blessed. (Potion = %d)",self);
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
    printf("You become invisible. (Potion = %d)",self);
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
    printf("Urgh! This is poisonous. (Potion = %d)",self);
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
public static void drink4(StrengthPotion *self) {
    printf("You feel strong. (Potion= %d)", self);
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
            delHealingPotion((HealingPotion*)potion);
            break;
        case HOLY_WATER:
            delHolyWaterPotion((HolyWaterPotion*)potion);
            break;
        case INVISIBILITY:
            delInvisibilityPotion((InvisibilityPotion *)potion);
            break;
        case POISON:
            delPoisonPotion((PoisonPotion*)potion);
            break;
        case STRENGTH:
            delStrengthPotion((StrengthPotion*)potion);
            break;
        default:
            break;
    }
}

public PotionFactory *newPotionFactory(void){
    PotionFactory *self = malloc(sizeof(PotionFactory));
    self->potions = createHashMap();
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

static void delPotion1(Potion *potion){
    if (potion != NULL){
        free(potion);
    }
}

/** @brief member method for AlchemistShop--------------*/
public static void enumerate(AlchemistShop *self){
    printf("Enumerating top shelf potions\n");
    self->topShelf->forEach(self->topShelf,Potion_drink);
    printf("Enumerating bottom shelf potions\n");
    self->bottomShelf->forEach(self->bottomShelf,Potion_drink);
}

AlchemistShop *newAlchemistShop(void){
    AlchemistShop *self = malloc(sizeof(AlchemistShop));
    self->topShelf = createArrayList(10);
    self->bottomShelf = createArrayList(10);
    self->enumerate = enumerate;


    return self;
}
void delALchemistShop(AlchemistShop *self){
    if (self != NULL){
        self->topShelf->forEach(self->topShelf,delPotion1);
        self->bottomShelf->forEach(self->bottomShelf,delPotion1);
        deleteArrayList(self->topShelf);
        deleteArrayList(self->bottomShelf);
        free(self);
    }
}