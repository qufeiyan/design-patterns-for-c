#pragma once

#include <stdlib.h>
#include "../OOPSupport.h"

typedef enum ItemType{
    ANY,
    WEAPON,
    RING,
    POTION
}ItemType;

class Item Item;
public class Item{
    private ItemType type;
    private char *name;
    public char* (*toString)(Item *self);
    public ItemType (*getType)(Item *self);
    public void (*setType)(Item *self,ItemType type);
}Item;

Item *newItem(ItemType type,char* name);
void delItem(Item *self);
