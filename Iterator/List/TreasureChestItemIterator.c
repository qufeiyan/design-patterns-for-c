#include "TreasureChestItemIterator.h"


/** Override ------------------------------*/
public static boolean hasNext(TreasureChestItemIterator *self){
    return self->findNextIdx(self) != -1;
}
public static void *next(TreasureChestItemIterator *self){
    self->idx = self->findNextIdx(self);
    if (self->idx != -1){
        ArrayList *items = self->chest->getItems(self->chest);
        Item *item = items->get(items,self->idx);
        deleteArrayList(items);
        return item;
    }
    return NULL;
}
//. private method
private static int findNextIdx(TreasureChestItemIterator *self){
    ArrayList *items = self->chest->getItems(self->chest);
    int tempIdx = self->idx;
    while (true){
        tempIdx++;
        if (tempIdx >= items->size){
            tempIdx = -1;
            break;
        }
        Item *item = items->get(items,tempIdx);
        if (self->type == ANY || item->getType(item) == self->type){
            break;
        }
    }
    deleteArrayList(items);
    return tempIdx;
}

TreasureChestItemIterator *newTreasureChestItemIterator(TreasureChest *chest,ItemType type){
    TreasureChestItemIterator *self = malloc(sizeof(TreasureChestItemIterator));
    self->chest = chest;
    self->type = type;
    self->idx = -1;
    self->findNextIdx = findNextIdx;
    self->super.next = next;
    self->super.hasNext = hasNext;
    return self;
}

void delTreasureChestItemIterator(TreasureChestItemIterator *self){
    if (self != NULL){
        free(self);
        self = NULL;
    }
}



