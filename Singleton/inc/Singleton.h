#ifndef __SINGLETON_H
#define __SINGLETON_H
#endif

#ifndef OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private

#endif

typedef enum boolean{
    false,
    true
}boolean;

abstract class Hero Hero;
abstract class Hero{
    char *gender;
    char *superPower;
    boolean (*isHuman)(Hero *);
    boolean (*isMarried)(Hero *);
}Hero;

#define extends_Hero
class Superman Superman;
class Superman extends_Hero{
    Hero super;
    void (*fly)(Superman *);
}Superman;

class Batman Batman;
class Batman extends_Hero{
    Hero super;
    void (*kill)(Batman *);
}Batman;

Hero *getHero(char* gender,char* superPower);