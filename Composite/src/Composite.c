#include "..\inc\Composite.h"
#include "malloc.h"
#include "stdio.h"
#include "string.h"
#include ".\ArrayList\inc\ArrayList.h"

/** @brief Base Method-----------------*/
public static void add(LetterComposite *self,LetterComposite *letter){
    self->children->add(letter);
}
public int count(LetterComposite *self){
    return self->children->size();
}
public void print(LetterComposite *self){
    self->printThisBefore();
    for (int i = 0; i < self->children->size; ++i) {
        
    }
    self->printThisAfter();
}

/** @override-----------------------------*/
static void printThisBefore1(Letter *self){
    prinf(self->character);
}

/** @constuctor && @destructor------------*/
Letter *newLetter(char c){
    Letter *self = malloc(sizeof(Letter));
    self.character = c;
    self.super.printThisBefore = printThisBefore11;
    return self;
}
void delLetter(Letter *self){
    if (self != NULL){
        free(self);
    }
}

/** @override-----------------------------*/
static LetterComposite *messageFromOrcs(){

}
static LetterComposite *messageFromElves(){

}

/** @constuctor && @destructor------------*/
Messenger *newMessenger(void){
    Messenger *self = malloc(sizeof(Messenger));
    return self;
}
void delMessenger(Messenger *self){
    if (self != NULL){
        free(self);
    }
}

/**
 * Sentence.
 */
Sentence *newSentence(ArrayList *words){
    words.
}
void delSentence(Sentence *self){

}

