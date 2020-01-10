#include <stdio.h>
#include "inc/Command.h"

int main() {
    printf("Hello, World!\n");

    Wizard *wizard = newWizard();
    Target *goblin = (Target *)newGoblin();

    goblin->printStatus(goblin);

    Command *shrinkSpell = (Command*)newShrinkSpell();
    Command *invisibilitySpell = (Command*)newInvisibilitySpell();
    wizard->castSpell(wizard,shrinkSpell,goblin);
    goblin->printStatus(goblin);

    wizard->castSpell(wizard,invisibilitySpell,goblin);
    goblin->printStatus(goblin);

    wizard->undoLastSpell(wizard);
    goblin->printStatus(goblin);

    wizard->undoLastSpell(wizard);
    goblin->printStatus(goblin);

    wizard->redoLastSpell(wizard);
    goblin->printStatus(goblin);

    wizard->redoLastSpell(wizard);
    goblin->printStatus(goblin);

    delGoblin(goblin);
    delShrinkSpell(shrinkSpell);
    delInvisibility(invisibilitySpell);
    delWizard(wizard);
    return 0;
}
