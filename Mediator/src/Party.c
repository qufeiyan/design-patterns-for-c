#include "../inc/Party.h"
#include "malloc.h"
#include "stdio.h"

static char *actionDescription(Action action){
    switch (action){
        case HUNT:
            return "arrives for dinner";
        case TALE:
            return "comes to listen";
        case GOLD:
            return "takes his share of the gold";
        case ENEMY:
            return "runs for cover";
        case NONE:
            return "";
        default:
            break;
    }
}
static char *actionTitle(Action action){
    switch (action){
        case HUNT:
            return "hunted a rabbit";
        case TALE:
            return "tells a tale";
        case GOLD:
            return "found gold";
        case ENEMY:
            return "spotted enemies";
        case NONE:
            return "";
        default:
            break;
    }
}

/**
 * PartyImpl
 */
/** @Override -------------*/
public static void act(Party *super,PartyMember *actor,Action action){
    PartyImpl *self = (PartyImpl*)super;
    PartyMember *member;
    for(int i = 0;i < self->members->size;++i){
        member = self->members->get(self->members,i);
        if (!(member == actor)){
            member->partyAction(member,action);
        }
    }
}
public static void addMember(Party *super,PartyMember *member){
    PartyImpl *self = (PartyImpl*)super;
    self->members->append(self->members,member);
    member->joinedParty(member,super);
}

PartyImpl *newPartyImpl(void){
    PartImpl *self = malloc(sizeof(PartImpl));
    self->super.act = act;
    self->super.addMember = addMember;
    self->members = createArrayList(10);
    return self;
}
void delPartyImpl(PartImpl *self){
    if (self != NULL){
        if (self->members != NULL){
            deleteArrayList(self->members);
            self->members = NULL;
        }
        free(self);
        self = NULL;
    }
}

/**
 *  Abstract base class for party members.
 */
/** @Override -------------*/
public static void joinedParty(PartyMember *super,Party *party){
    PartyMemberBase *self = (PartyMemberBase*)super;
    printf("%s joins the party\n",self->toString());
    self->party = party;
}
public static void partyAction(PartyMember *super,Action action){
    PartyMemberBase *self = (PartyMemberBase*)super;
    printf("%s %s\n",self->toString(),actionDescription(action));
}
public static void act1(PartyMember *super,Action action){
    PartyMemberBase * self = (PartyMemberBase*)super;
    if (self->party != NULL){
        printf("%s %s\n",self->toString(),actionTitle(action));
        self->party->act(self->party,super,action);
    }
}

static void initSuper(PartyMemberBase *super){
    super->super.act = act1;
    super->super.partyAction = partyAction;
    super->super.joinedParty = joinedParty;
}

/**
 * Rogue
 */
/** @Override ------------ */
public char* toString(){
    return "Rogue";
}

Rogue *newRogue(void){
    Rogue *self = malloc(sizeof(Rogue));
    initSuper(&self->super);
    self->super.toString = toString;
    return self;
}
void delRogue(Rogue *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * Wizard
 */
/** @Override --------------*/
public static char *toString1(){
    return "Wizard";
}
Wizard *newWizard(void){
    Wizard *self = malloc(sizeof(Wizard));
    self->super.toString = toString1;
    initSuper(&self->super);
    return self;
}
void delWizard(Wizard *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * Hunter
 */
/** @Override ------------*/
public static char* toString2(){
    return "Hunter";
}
Hunter *newHunter(void){
    Hunter *self = malloc(sizeof(Hunter));
    self->super.toString = toString2;
    initSuper(&self->super);
    return self;
}
void delHunter(Hunter *self){
    if(NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * Hobbit
 */
/** @Override -------------*/
public static char* toString3(){
    return "Hobbit";
}
Hobbit *newHobbit(void){
    Hobbit *self = malloc(sizeof(Hobbit));
    self->super.toString = toString3;
    initSuper(&self->super);
    return self;
}
void delHobbit(Hobbit *self){
    if(NULL != self){
        free(self);
        self = NULL;
    }
}
