#pragma once

#include "../OOPSupport.h"
#include "../Iterator.h"
#include "TreasureChest.h"

/**
 * TreasureChestItemIterator
 */
class TreasureChestItemIterator TreasureChestItemIterator;
#define implements_Iterator
class TreasureChestItemIterator implements_Iterator{
    private Iterator super;
    private TreasureChest *chest;
    private int idx;
    private ItemType type;
    private int (*findNextIdx)(TreasureChestItemIterator *self);
}TreasureChestItemIterator;

TreasureChestItemIterator *newTreasureChestItemIterator(TreasureChest *chest,ItemType type);
void delTreasureChestItemIterator(TreasureChestItemIterator *self);