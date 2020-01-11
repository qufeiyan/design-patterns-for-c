#include "Item.h"

/** member method -----------------*/
static inline char *toString(Item *self){
    return self->name;
}

static inline ItemType getType(Item *self){
    return self->type;
}

static inline void setType(Item *self,ItemType type){
    self->type = type;
}

Item *newItem(ItemType type,char* name){
    Item *self = malloc(sizeof(Item));
    self->toString = toString;
    self->getType = getType;
    self->setType = setType;
    self->setType(self,type);
    self->name = name;
    return self;
}

void delItem(Item *self){
    if(NULL != self){
        free(self);
    }
}