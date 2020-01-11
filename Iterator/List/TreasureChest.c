#include "TreasureChest.h"
#include "TreasureChestItemIterator.h"

/** member method ------------------------*/
public static Iterator* iterator(TreasureChest *self,ItemType itemType){
    return (Iterator*)newTreasureChestItemIterator(self,itemType);
}
public static ArrayList *getItems(TreasureChest *self){
    return self->items->clone(self->items);
}

static void initItems(ArrayList *items){
    items->append(items,newItem(POTION,"Potion of courage"));
    items->append(items,newItem(RING,"Ring of shadows"));
    items->append(items,newItem(POTION,"Potion of wisdom"));
    items->append(items,newItem(POTION,"Potion of blood"));
    items->append(items,newItem(WEAPON,"Sword of silver +1"));
    items->append(items,newItem(POTION,"Potion of rust"));
    items->append(items,newItem(POTION,"Potion of healing"));
    items->append(items,newItem(RING,"Ring of armor"));
    items->append(items,newItem(WEAPON,"Steel halberd"));
    items->append(items,newItem(WEAPON,"Dagger of poison"));
}

static void deInitItems(ArrayList *items){
    if (items != NULL){
        items->forEach(items,delItem);
    }
}
TreasureChest *newTreasureChest(void){
    TreasureChest *self = malloc(sizeof(TreasureChest));
    self->items = createArrayList(10);
    initItems(self->items);
    self->iterator = iterator;
    self->getItems = getItems;
    return self;
}
void delTreasureChest(TreasureChest *self){
    if (NULL != self){
        if (self->items != NULL){
            deInitItems(self->items);
            deleteArrayList(self->items);
        }
        free(self);
    }
}

