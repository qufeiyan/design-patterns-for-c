//
// Created by Elena on 2020/1/9.
//

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
Target* (*newTarget)(void);
void (*delTarget)(Target *self);

/**
 * Interface for Commands.
 */
public abstract class Command{
    public abstract void (*execute)(Target *target);
    public abstract void (*undo)();
    public abstract void (*redo)();
    public abstract char* (*toString)();
}Command;

/**
 * Goblin is the target of the spells.
 */
#define extends_Target
public class Goblin extends_Target{
    Target super;
}Goblin;
Goblin *newGoblin(void);
void delGoblin(Goblin *self);

