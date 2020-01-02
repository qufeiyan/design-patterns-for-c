#ifndef __COMPOSITE_H
#define __COMPOSITE_H
#endif

#include "ArrayList\inc\ArrayList.h"


#ifndef OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private

#endif

typedef enum boolean{
    false,
    true
}boolean;

/**
 * Composite interface.
 */
class LetterComposite LetterComposite
abstract class LetterComposite{
    private ArrayList *children;
    void (*add)(LetterComposite *letter);
    int (*count)();
    void (*printThisBefore)();
    void (*printThisAfter)();
    /**
     * Print
     */
     void (*print)();
}LetterComposite;

/**
 * Letter
 */
#define extends_LetterComposite
public class Letter extends_LetterComposite(){
    LetterComposite super;
    char character;
}Letter;
Letter *newLetter(char c);
void delLetter(Letter *self);

/**
 * Messenger.
 */
class Messenger{
    LetterComposite *(*messageFromOrcs)();
    LetterComposite *(*messageFromElves)();
}Messenger;
Messenger *newMessenger(void);
void delMessenger(Messenger *self);

/**
 * Sentence
 */
class Sentence extends_LetterComposite{
    LetterComposite super;
}LetterComposite;
Sentence *newSentence(void);
void delSentence(Sentence *self);

clss Word extends_LetterComposite{
    LetterComposite super;
}Word;
Word * newWord();