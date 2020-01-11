#include "../inc/Party.h"
#include "malloc.h"

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
            member->partyAction(action);
        }
    }
}
public static void addMember(Party *super,PartyMember *member){
    PartyImpl *self = (PartyImpl*)super;
    self->members->append(self->members,member);
    member->joinedParty(self);
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
    printf("%s joins the party\n",super);
}
void partyAction(PartyMember *super,Action action);
void act1(PartyMember *super,Action action);