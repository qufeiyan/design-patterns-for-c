//
// Created by Elena on 2020/1/9.
//

#include "../LinkedList/LinkedList.h"

#ifndef COMMAND_COMMAND_H
#define COMMAND_COMMAND_H

#endif //COMMAND_COMMAND_H
#ifndef OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private
#define protected
#endif

typedef enum Size{
    SMAll,
    NORMAL
}Size;

typedef enum Visibility{
    VISIBLE,
    INVISIBLE
}Visibility;

/**
 * Base class for spell target
 */
class Target Target;
public abstract class Target{
    private Size size;
    private Visibility visibility;
    public Size (*getSize)(Target *self);
    public void (*setSize)(Target *self,Size size);
    public void (*setVisibility)(Target *self,Visibility visibility);
    public Visibility (*getVisibility)(Target *self);
    public abstract char*(*toString)(Target *self);
    public void (*printStatus)(Target *self);
}Target;
//Target* (*newTarget)(void);
//void (*delTarget)(Target *self);
/**
 * Goblin is the target of the spells.
 */
#define extends_Target
public class Goblin extends_Target{
    Target super;
}Goblin;
Goblin *newGoblin(void);
void delGoblin(Goblin *self);

/**
 * Interface for Commands.
 */
class Command Command;
public abstract class Command{
    public abstract void (*execute)(Command *super,Target *target);
    public abstract void (*undo)(Command *super);
    public abstract void (*redo)(Command *super);
    public abstract char* (*toString)();
}Command;

/**
 * InvisibilitySpell is a concrete command.
 */
#define extends_Command
public class InvisibilitySpell extends_Command{
    private Command super;
    private Target *target;
}InvisibilitySpell;
InvisibilitySpell *newInvisibilitySpell(void);
void delInvisibility(InvisibilitySpell *self);

/**
 * ShrinkSpell is a concrete command.
 */
public class ShrinkSpell extends_Command{
    private Command super;
    private Size oldSize;
    private Target *target;
}ShrinkSpell;
ShrinkSpell *newShrinkSpell(void);
void delShrinkSpell(ShrinkSpell *self);

/**
 * Wizard is the invoker of the commands.
 */
class Wizard Wizard;
public class Wizard {
    private LinkedList *undoStack;
    private LinkedList *redoStack;
    public void (*castSpell)(Wizard *self,Command *command,Target* target);
    public void (*undoLastSpell)(Wizard *self);
    public void (*redoLastSpell)(Wizard *self);
    public char *(*toString)();
}Wizard;
Wizard *newWizard(void);
void delWizard(Wizard *self);

