//
// Created by Elena on 2019/12/28.
//

#ifndef PROTOTYPE_PROTOTYPE_H
#define PROTOTYPE_PROTOTYPE_H

#endif //PROTOTYPE_PROTOTYPE_H

typedef enum boolean{
    false = 0,
    true
}boolean;

#define class typedef struct
#define interface typedef struct
#define public
#define private
#define Abstract
interface Prototype Prototype;

interface Prototype{
    void *(*clone)(void*);
}Prototype;

class Beast Beast;
#define implements_Prototype
Abstract class Beast implements_Prototype{
    Prototype super;
    boolean (*equals)(Beast *this,void *obj);
    char *(*toString)(Beast *);
}Beast;

#define extends_Beast
class ElfBeast extends_Beast{
    Beast super;
    private char* helpType;
}ElfBeast;
ElfBeast *newElfBeast0(char* helpType);
ElfBeast *newELFBeast1(ElfBeast * elfBeast);
void delElfBeast(ElfBeast *this);

class OrcBeast extends_Beast{
    Beast super;
    private char* weapon;
}OrcBeast;
OrcBeast *newOrcBeast0(char *weapon);
OrcBeast *newOrcBeast1(OrcBeast* orcBeast);
void delOrcBeast(OrcBeast *this);

interface HeroFactory HeroFactory;
interface HeroFactory{
    Beast *(*createBeast)(HeroFactory *);
}HeroFactory;

#define implements_HeroFactory
class HeroFactoryImpl HeroFactoryImpl;
class HeroFactoryImpl implements_HeroFactory{
    private Beast *beast;
    public Beast *(*createBeast)(HeroFactory *);
}HeroFactoryImpl;
HeroFactoryImpl *newHeroFactoryImpl(Beast *beast);
void delHeroFactoryImpl(HeroFactoryImpl *factory);