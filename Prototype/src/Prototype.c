//
// Created by Elena on 2019/12/28.
//
#include "malloc.h"
#include "string.h"
#include "../inc/Prototype.h"

#ifndef NULL
#define NULL (void *)0
#endif

/** Beast @virtual Function----------------*/
public static boolean equals(Beast *this,void *obj){
    Beast *cObj = obj;
    if(obj == NULL)
        return false;
    if (cObj->super.clone == this->super.clone) {return true;}
    return false;
}

/** ElfBeast @override----------------*/
public static void* copyElf(void *this){
    return newELFBeast1((ElfBeast*)this);
}

public static boolean equalsElf(Beast *this,void *obj){
    if(!equals(this,obj))
        return false;
    ElfBeast *other = (ElfBeast*) obj;
    ElfBeast *cthis = (ElfBeast *)this;
    if (cthis->helpType == NULL){
        if (other->helpType != NULL){
            return false;
        }
    } else if (strcmp(cthis->helpType,other->helpType) != 0){
        return false;
    }
    return true;
}

public static char *toStringElf(Beast *this){
    ElfBeast *elfBeast = (ElfBeast*)this;
    static char str[20] = "ElfBeast";
    return strcat(str,elfBeast->helpType);
}

/** ElfBeast @constructor && @destructor----------------*/
ElfBeast *newElfBeast0(char* helpType){
    ElfBeast *this = malloc(sizeof(ElfBeast));
    this->helpType = helpType;
    this->super.super.clone = copyElf;
    this->super.equals = equalsElf;
    this->super.toString = toStringElf;
    return this;
}
ElfBeast *newELFBeast1(ElfBeast *elfBeast){
    ElfBeast *this = malloc(sizeof(ElfBeast));
    this->helpType = elfBeast->helpType;
    this->super.super.clone = elfBeast->super.super.clone;
    this->super.equals = elfBeast->super.equals;
    this->super.toString = elfBeast->super.toString;
    return this;
}
void delElfBeast(ElfBeast *this){
    if(this)
        free(this);
}

/** OrcBeast @override----------------*/
public void *copyOrc(void *this){
    return newOrcBeast1((OrcBeast*)this);
}

public boolean equalsOrc(Beast * this,void *obj){
    if(!equals(this,obj))
        return false;
    OrcBeast *other = (OrcBeast*) obj;
    OrcBeast *cthis = (OrcBeast*) this;
    if (cthis->weapon == NULL){
        if (other->weapon != NULL){
            return false;
        }
    } else if (strcmp(cthis->weapon,other->weapon) != 0){
        return false;
    }
    return true;
}

public static char* toStringOrc(Beast* this){
    OrcBeast *orcBeast = (OrcBeast*)this;
    static char str[20] = "OrcBeast";
    return strcat(str,orcBeast->weapon);
}
/** OrcBeast @constructor && @destructor----------------*/
OrcBeast *newOrcBeast0(char* weapon){
    OrcBeast *this = malloc(sizeof(OrcBeast));
    this->weapon = weapon;
    this->super.super.clone = copyOrc;
    this->super.equals = equalsOrc;
    this->super.toString = toStringOrc;
    return this;
}
OrcBeast *newOrcBeast1(OrcBeast* orcBeast){
    OrcBeast *this = malloc(sizeof(OrcBeast));
    this->weapon = orcBeast->weapon;
    this->super.super.clone = orcBeast->super.super.clone;
    this->super.equals = orcBeast->super.equals;
    this->super.toString = orcBeast->super.toString;
    return this;
}
void delOrcBeast(OrcBeast *this){
    if(this)
        free(this);
}


public Beast *createBeast(HeroFactory *this){
    return this->beast->super.clone(this->beast);
}
HeroFactory *newHeroFactory(Beast *beast){
    HeroFactory *this = malloc(sizeof(HeroFactory));
    this->beast = beast;
    this->createBeast = createBeast;
}
void delHeroFactory(HeroFactory *this){
    if (this)
        free(this);
}