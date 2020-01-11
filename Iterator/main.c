#include <stdio.h>
#include "List/TreasureChest.h"
#include "List/TreasureChestItemIterator.h"

char* itemTypeString(ItemType itemType){
    switch (itemType){
        case ANY:
            return "ANY";
            break;
        case WEAPON:
            return "WEAPON";
            break;
        case RING:
            return "RING";
        case POTION:
            return "POTION";
        default:
            break;
    }
}

private void demonstrateTreasureChestIteratorForType(ItemType itemType){
    printf("--------------------------\n");
    printf("Item  Iterator for ItemType %s :\n",itemTypeString(itemType));

    TreasureChest *treasureChest = newTreasureChest();
    Iterator *itemIterator = treasureChest->iterator(treasureChest,itemType);
    while (itemIterator->hasNext(itemIterator)){
        Item *item = itemIterator->next(itemIterator);
        printf("%s\n",item->toString(item));
    }

    delTreasureChest(treasureChest);
    delTreasureChestItemIterator((TreasureChestItemIterator*)itemIterator);
}


int main() {

    demonstrateTreasureChestIteratorForType(RING);
    demonstrateTreasureChestIteratorForType(POTION);
    demonstrateTreasureChestIteratorForType(WEAPON);
    demonstrateTreasureChestIteratorForType(ANY);
    return 0;
}
