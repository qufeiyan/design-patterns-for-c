➿ Iterator
------------------
## Also know as
Cursor

## Intent
Provide a way to access the elements of an aggregate object
sequentially without exposing its underlying representation.

In plain words
> It presents a way to access the elements of an object without
> exposing the underlying presentation.

Wikipedia says
> In object-oriented programming, the iterator pattern is 
> a design pattern in which an iterator is used to traverse
> a container and access the container's elements. The 
> iterator pattern decouples algorithms from containers;
> in some cases, algorithms are necessarily container-specific
> and thus cannot be decoupled.

**Programmatic example**
单个的元素类定义
```c
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
/** definition -----------------*/
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
```
盛放元素的容器类  
```c
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
/** definition ------------------------*/
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
``` 
抽象的迭代器接口
```c
#define DataType void*

public interface Iterator{
    boolean (*hasNext)();
    DataType (*next)();
}Iterator;
```
具体的迭代器实现类
```c
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
/** definition ----------------------------*/
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
```
我们可以这样使用
```c
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
```
运行结果为
~~~~
--------------------------
 Item  Iterator for ItemType RING :
 Ring of shadows
 Ring of armor
 --------------------------
 Item  Iterator for ItemType POTION :
 Potion of courage
 Potion of wisdom
 Potion of blood
 Potion of rust
 Potion of healing
 --------------------------
 Item  Iterator for ItemType WEAPON :
 Sword of silver +1
 Steel halberd
 Dagger of poison
 --------------------------
 Item  Iterator for ItemType ANY :
 Potion of courage
 Ring of shadows
 Potion of wisdom
 Potion of blood
 Sword of silver +1
 Potion of rust
 Potion of healing
 Ring of armor
 Steel halberd
 Dagger of poison
~~~~

## Class diagram
![Iterator.png](https://i.loli.net/2020/01/11/rfcxIuHp4TtNlCF.png)

## Applicability
Use the Iterator pattern

* to access an aggregate object's contents without exposing
its internal representation
* to support multiple traversals of aggregate objects
* to provide a uniform interface for traversing different 
aggregate structures

## Real world examples

* [java.util.Iterator](http://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html)
* [java.util.Enumeration](http://docs.oracle.com/javase/8/docs/api/java/util/Enumeration.html)

## Credits

* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)

 
