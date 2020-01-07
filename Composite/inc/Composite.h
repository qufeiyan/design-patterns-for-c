#ifndef __COMPOSITE_H
#define __COMPOSITE_H
#endif

#include "ArrayList.h"

#ifndef OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private

#endif

#ifdef boolean
typedef enum boolean{
    false,
    true
}boolean;
#endif
/**
 * Composite interface.
 */
class LetterComposite LetterComposite;
abstract class LetterComposite{
    private ArrayList *children;
    void (*add)(LetterComposite *self,LetterComposite *letter);
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
public class Letter extends_LetterComposite{
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
}Sentence;
Sentence *newSentence(ArrayList *words);
void delSentence(Sentence *self);

/**
 * Word
 */
class Word extends_LetterComposite{
    LetterComposite super;
}Word;
//Word * newWord(ArrayList *letters);
Word * newWord1(char letters[],int size);
void delWord(Word *self);