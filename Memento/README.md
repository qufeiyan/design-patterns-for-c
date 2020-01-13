Memento
---------
## Also known as
Token

## Intent
Without violating encapsulation, capture and externalize
an object's internal state so that the object can be restored
to this state later.

``在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可将该对象恢复到原先保存的状态。``

In plain words
> Memento pattern is about capturing and storing the current
> state of an object in a manner that it can be restored
> later on in a smooth manner.

Wikipedia says
> The memento pattern is a software design pattern that 
> provides the ability to restore an object to its previous
> state (undo via rollback).

Usually useful when you need to provide some sort of undo
functionality.

**Programmatic example**
需要备份的类
```c
/**
 * Star uses "mementos" to store and restore state.
 */
class Star Star;
public class Star{
    private StarType type;
    private int ageYears;
    private int massTons;
    public void (*timePasses)(Star *self);
    StarMemento* (*getMemento)(Star *self);
    void (*setMemento)(Star*,StarMemento*);
    char* (*toString)(Star *self);
}Star;
Star *newStar(StarType starType, int starAge, int starMass);
void delStar(Star *);
/** definition ----------------------------*/
public static void timePasses(Star *self){
    self->ageYears *= 2;
    self->massTons *= 8;
    switch (self->type){
        case RED_GIANT:
            self->type = WHITE_DWARF;
            break;
        case SUN:
            self->type = RED_GIANT;
            break;
        case SUPERNOVA:
            self->type = DEAD;
            break;
        case WHITE_DWARF:
            self->type = SUPERNOVA;
            break;
        case DEAD:
            self->ageYears *= 2;
            self->massTons = 0;
            break;
        default:
            break;
    }
}
public static StarMemento* getMemento(Star *self){
    StarMementoInternal *state = newStarMementoInternal();
    state->setAgeYears(state,self->ageYears);
    state->setMassTons(state,self->massTons);
    state->setType(state,self->type);
    return (StarMemento *)state;
}
public static void setMemento(Star *self,StarMemento *memento){
    StarMementoInternal *state = (StarMementoInternal*)memento;
    self->type = state->getType(state);
    self->ageYears = state->getAgeYears(state);
    self->massTons = state->getMassTons(state);
}
public static char* toString(Star *self){
    static char buffer[40];
    sprintf(buffer,"%s age: %d years mass: %d tons",
            typeTitle(self->type),self->ageYears,self->massTons);
    return buffer;
}
Star *newStar(StarType starType, int starAge, int starMass){
    Star *self = malloc(sizeof(Star));
    self->type = starType;
    self->ageYears = starAge;
    self->massTons = starMass;
    self->getMemento = getMemento;
    self->setMemento = setMemento;
    self->timePasses = timePasses;
    self->toString = toString;
    return self;
}
void delStar(Star *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}
```
备忘录类
```c
/**
 * External interface to memento.
 */
public interface StarMemento{

}StarMemento;

/**
 * StarMemento implementation.
 */
#define implements_StarMemento
private class StarMementoInternal StarMementoInternal;
class StarMementoInternal implements_StarMemento{
    private StarType type;
    private int ageYears;
    private int massTons;
    public StarType(*getType)(StarMementoInternal*);
    public void (*setType)(StarMementoInternal*, StarType);
    public void (*setAgeYears)(StarMementoInternal*, int);
    public int (*getAgeYears)(StarMementoInternal*);
    public int (*getMassTons)(StarMementoInternal*);
    public void (*setMassTons)(StarMementoInternal*,int);

}StarMementoInternal;
StarMementoInternal *newStarMementoInternal(void);
void delStarMementoInternal(StarMementoInternal *);
/** definition -----------------------------*/
/**
 * StarMemento implementation.
 */
/** definition ---*/
public static StarType getType(StarMementoInternal *self){
    return self->type;
}
public static void setType(StarMementoInternal *self,StarType type){
    self->type = type;
}
public static int getAgeYears(StarMementoInternal *self){
    return self->ageYears;
}
public static void setAgeYears(StarMementoInternal *self, int ageYears){
    self->ageYears = ageYears;
}
public static int getMassTons(StarMementoInternal *self){
    return self->massTons;
}
public static void setMassTons(StarMementoInternal *self, int massTons){
    self->massTons = massTons;
}

StarMementoInternal* newStarMementoInternal(void){
    StarMementoInternal *self = malloc(sizeof(StarMementoInternal));
    self->setType = setType;
    self->getType = getType;
    self->setAgeYears = setAgeYears;
    self->getAgeYears = getAgeYears;
    self->setMassTons = setMassTons;
    self->getMassTons = getMassTons;
    return self;
}
void delStarMementoInternal(StarMementoInternal *self){
    if (NULL != self){
        free(self);
    }
}
```
备份时，可用容器类保存多个备忘录对象，根据需要恢复状态
```c
Stack *states = newStack();
Star *star = newStar(SUN, 10000000, 500000);
printf("%s\n",star->toString(star));

states->push(states,star->getMemento(star));
star->timePasses(star);
printf("%s\n",star->toString(star));

states->push(states,star->getMemento(star));
star->timePasses(star);
printf("%s\n",star->toString(star));

states->push(states,star->getMemento(star));
star->timePasses(star);
printf("%s\n",star->toString(star));

while (states->super->size > 0){
    star->setMemento(star,states->pop(states));
    printf("%s\n",star->toString(star));
}

// release memory.
delStar(star);
states->super->forEach(states->super,delStarMementoInternal);
delStack(states);
```
运行结果为
~~~~
sun age: 10000000 years mass: 500000 tons
red giant age: 20000000 years mass: 4000000 tons
white dwarf age: 40000000 years mass: 32000000 tons
supernova age: 80000000 years mass: 256000000 tons
white dwarf age: 40000000 years mass: 32000000 tons
red giant age: 20000000 years mass: 4000000 tons
sun age: 10000000 years mass: 500000 tons
~~~~

## Class diagram
![memento.png](https://i.loli.net/2020/01/13/4btIPpso28d7k5N.png)

## Applicability
Use the Memento pattern when

* a snapshot of an object's state must be saved so that
it can be restored to that state later, and
* a direct interface to obtaining the state would expose
implementation details and break the object's encapsulation

## Real world examples

* [java.util.Date](http://docs.oracle.com/javase/8/docs/api/java/util/Date.html)

## Credits

* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)