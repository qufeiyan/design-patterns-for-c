#pragma once

#include "../OOPSupport.h"
#include "../Iterator.h"
#include "Item.h"
#include "inc/ArrayList.h"

/**
 * TreasureChest, the collection class.
 */

class TreasureChest TreasureChest;
public class TreasureChest {
    private ArrayList *items;
    public Iterator *(*iterator)(TreasureChest *self,ItemType itemType);
    public ArrayList *(*getItems)();
} TreasureChest;

TreasureChest *newTreasureChest(void);
void delTreasureChest(TreasureChest *self);