#ifndef __FLYWEIGHT_H
#define __FLYWEIGHT_H
#endif

#include "../List/inc/ArrayList.h"
#include "../Map/inc/HashMap.h"

#ifndef OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private

#endif


/**
 * Interface for Potions
 */
public interface Potion{
    void (*drink)();
}Potion;

typedef enum PotionType{
    HEALING,
    INVISIBILITY,
    STRENGTH,
    HOLY_WATER,
    POISON
}PotionType;

/**
 * HealingPotion
 */
#define implements_Potion
public class HealingPotion implements_Potion{
    Potion super;
}HealingPotion;
HealingPotion *newHealingPotion(void);
void delHealingPotion(HealingPotion *);
/**
 * HolyWaterPotion
 */
public class HolyWaterPotion implements_Potion{
    Potion super;
}HolyWaterPotion;
HolyWaterPotion *newHolyWaterPotion(void);
void delHolyWaterPotion(HolyWaterPotion*);
/**
 * InvisibilityPotion
 */
public class InvisibilityPotion implements_Potion{
    Potion super;
}InvisibilityPotion;
InvisibilityPotion *newInvisibilityPotion(void);
void delInvisibilityPotion(InvisibilityPotion*);

/**
 * PoisonPotion
 */
public class PoisonPotion implements_Potion{
    Potion super;
}PoisonPotion;
PoisonPotion *newPoisonPotion(void);
void delPoisonPotion(PoisonPotion *);
/**
 * StrengthPotion.
 */
public class StrengthPotion implements_Potion{
    Potion super;
}StrengthPotion;
StrengthPotion *newStrengthPotion(void);
void delStrengthPotion(StrengthPotion*);

/**
 * PotionFactory is the Flyweight in this example. It minimizes memory use by
 * sharing object instances. It holds a map of potion instances and new potions
 * are created only when none of the type already exists.
 */
public class PotionFactory{
    private HashMap *potions;
    Potion (*createPotion)(PotionType type);
}PotionFactory;
public PotionFactory *newPotionFactory(void);
public void delPotionFactory(PotionFactory *self);


/**
 * AlchemistShop holds potions on its shelves.
 * It uses PotionFactory to provide the potions.
 */
public class AlchemistShop{
    private ArrayList *topShelf;
    private ArrayList *bottomShelf;
    public ArrayList *(*getTopShelf)();
    public ArrayList *(*getBottomShelf)();
    public void (*enumerate)();
}AlchemistShop;
AlchemistShop *newAlchemistShop(void);
void delALchemistShop(AlchemistShop *);