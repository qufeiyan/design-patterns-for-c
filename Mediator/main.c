#include <stdio.h>
#include "inc/Party.h"

int main() {
    printf("Hello, World!\n");
    // create party and members
    Party *party = (Party*)newPartyImpl();
    PartyMember *hobbit = (PartyMember*)newHobbit();
    PartyMember *wizard = (PartyMember*)newWizard();
    PartyMember *rogue = (PartyMember*)newRogue();
    PartyMember *hunter = (PartyMember*)newHunter();

    // add party members
    party->addMember(party,hobbit);
    party->addMember(party,wizard);
    party->addMember(party,rogue);
    party->addMember(party,hunter);

    // perform actions -> the other party members
    // are notified by the party
    hobbit->act(hobbit,ENEMY);
    wizard->act(wizard,TALE);
    rogue->act(rogue,GOLD);
    hunter->act(hunter,HUNT);

    delHobbit((Hobbit*)hobbit);
    delHunter((Hunter*)hunter);
    delRogue((Rogue*)rogue);
    delWizard((Wizard*)wizard);

    delPartyImpl((PartyImpl *)party);
    return 0;
}
