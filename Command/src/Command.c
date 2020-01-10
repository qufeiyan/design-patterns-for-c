//
// Created by Elena on 2020/1/9.
//
#include "../inc/Command.h"
#include "stdio.h"
#include "malloc.h"
/**
 * Target
 */
/** default method -------------------------*/
public static Size getSize(Target *self){
    return self->size;
}
public static void setSize(Target *self,Size size){
    self->size = size;
}
public static Visibility getVisibility(Target *self){
    return self->visibility;
}
public static void setVisibility(Target *self,Visibility visibility){
    self->visibility = visibility;
}
public static void printStatus(Target *self){
    printf("%s [size = %s] [visibility = %s]\n",
    self->toString(self),self->getSize(self) ? "normal" : "small",
    self->getVisibility(self) ? "invisible" : "visible");
}
//Target* newTarget(void){
//    Target *self = malloc(sizeof(Target));
//    self->setSize = setSize;
//    self->getSize = getSize;
//    self->setVisibility = setVisibility;
//    self->getVisibility = getVisibility;
//    self->printStatus = printStatus;
//    return self;
//}
//void delTarget(Target *self){
//    if (NULL != self){
//        free(self);
//    }
//}

/** super --------------------*/
static void initSuper(Target *super){
    super->setSize = setSize;
    super->getSize = getSize;
    super->setVisibility = setVisibility;
    super->getVisibility = getVisibility;
    super->printStatus = printStatus;
}

/**
 * Goblin
 */
/** @Override -------------------------*/
public static char* toString() {
    return "Goblin";
}
Goblin *newGoblin(void){
    Goblin *self = malloc(sizeof(Goblin));
    initSuper(&self->super);
    self->super.toString = toString;
    return self;
}
void delGoblin(Goblin *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * InvisibilitySpell
 */
/** @Override -------------------------*/
public static void execute(Command *super,Target *target){
    target->setVisibility(target,INVISIBLE);
    InvisibilitySpell *self = (InvisibilitySpell*)super;
    self->target = target;
}
public static void undo(Command *super){
    InvisibilitySpell *self = (InvisibilitySpell *)super;
    if (self->target != NULL){
        self->target->setVisibility(self->target,VISIBLE);
    }
}
public static void redo(Command *super){
    InvisibilitySpell *self = (InvisibilitySpell *)super;
    if (self->target != NULL){
        self->target->setVisibility(self->target,INVISIBLE);
    }
}
public static char* toString1() {
    return "Invisibility spell";
}
/** Constructor && Destructor */
InvisibilitySpell *newInvisibilitySpell(void){
    InvisibilitySpell *self = malloc(sizeof(InvisibilitySpell));
    self->super.toString = toString1;
    self->super.execute = execute;
    self->super.redo = redo;
    self->super.undo = undo;
    return self;
}
void delInvisibility(InvisibilitySpell *self){
    if (self != NULL){
        free(self);
    }
}

/**
 * ShrinkSpell
 */
/** @Override -------------------------*/
public static void execute1(Command *super,Target *target){
    ShrinkSpell *self = (ShrinkSpell *)super;
    self->oldSize = target->getSize(target);
    target->setSize(target,SMAll);
    self->target = target;
}
public static void undo1(Command *super){
    ShrinkSpell *self = (ShrinkSpell *)super;
    if (self->oldSize != -1 && self->target != NULL){
        Size temp = self->target->getSize(self->target);
        self->target->setSize(self->target,self->oldSize);
        self->oldSize = temp;
    }
}
public static void redo1(Command *super){
    super->undo(super);
}
public char *toString2(){
    return "Shrink spell";
}
/** Constructor && Destructor -------------*/
ShrinkSpell *newShrinkSpell(void){
    ShrinkSpell *self = malloc(sizeof(ShrinkSpell));
    self->super.toString = toString2;
    self->super.execute = execute1;
    self->super.redo = redo1;
    self->super.undo = undo1;
    return self;
}
void delShrinkSpell(ShrinkSpell *self){
    if (NULL != self){
        free(self);
    }
}

/**
 * Wizard
 */
/** member method ---------------------*/
// Cast spell.
public static void castSpell(Wizard *self,Command *command,Target *target){
    printf("%s casts %s at %s\n",self->toString(),command->toString(),target->toString(target));
    command->execute(command,target);
    self->undoStack->addAtTail(self->undoStack,command);
}
// undo last spell.
public static void undoLastSpell(Wizard *self){
    if (!self->undoStack->isEmpty(self->undoStack)){
        Command *previousSpell = self->undoStack->deleteAtIndex(self->undoStack,self->undoStack->size - 1);
        self->redoStack->addAtTail(self->redoStack,previousSpell);
        printf("%s undoes %s\n",self->toString(),previousSpell->toString());
        previousSpell->undo(previousSpell);
    }
}
// Redo last spell
public static void redoLastSpell(Wizard *self){
    if (!self->redoStack->isEmpty(self->redoStack)){
        Command *previousSpell = self->redoStack->deleteAtIndex(self->redoStack,self->redoStack->size - 1);
        self->undoStack->addAtTail(self->undoStack,previousSpell);
        printf("%s redoes %s\n",self->toString(),previousSpell->toString());
        previousSpell->redo(previousSpell);
    }
}
public static char* toString3(){
    return "Wizard";
}
/** Constructor && Destructor -------------*/
Wizard *newWizard(){
    Wizard *self = malloc(sizeof(Wizard));
    self->undoStack = createList();
    self->redoStack = createList();

    self->redoLastSpell = redoLastSpell;
    self->undoLastSpell = undoLastSpell;
    self->castSpell = castSpell;
    self->toString = toString3;
    return self;
}
void delWizard(Wizard *self){
    if (NULL != self){
        freeList(self->undoStack);
        freeList(self->redoStack);
        free(self);
    }
}
