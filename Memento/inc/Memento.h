//
// Created by Elena on 2020/1/12.
//

#ifndef MEMENTO_MEMENTO_H
#define MEMENTO_MEMENTO_H
#endif //MEMENTO_MEMENTO_H

#include "../OOPSupport.h"

typedef enum StarType{
    SUN,
    RED_GIANT,
    WHITE_DWARF,
    SUPERNOVA,
    DEAD,
    UNDEFINED
}StarType;

/**
 * External interface to memento.
 */
public interface StarMemento{

}StarMemento;


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



