#pragma once

#include "../OOPSupport.h"
#include "../List/inc/ArrayList.h"

typedef enum Action{
    HUNT,
    TALE,
    GOLD,
    ENEMY,
    NONE
}Action;

/**
 * Interface for party members interacting with {@link Party}.
 */
interface Party Party;
interface PartyMember PartyMember;
public interface PartyMember{
    void (*joinedParty)(PartyMember *super,Party *party);
    void (*partyAction)(PartyMember *super,Action action);
    void (*act)(PartyMember *super,Action action);
}PartyMember;
/**
 * Party interface
 */
public interface Party{
    void (*addMember)(Party *super,PartyMember *member);
    void (*act)(Party *super,PartyMember *actor,Action action);
}Party;

/**
 * Party implementation
 */
class PartyImpl PartyImpl;
#define implements_Party
public class PartyImpl implements_Party{
    Party super;
    private ArrayList *members;
}PartImpl;
PartyImpl *newPartyImpl(void);
void delPartyImpl(PartImpl *self);

/**
 * Abstract base class for party members.
 */
#define implements_PartyMember
public abstract class PartyMemberBase implements_PartyMember {
    PartyMember *super;
    protected Party *party;
}PartyMemberBase;

