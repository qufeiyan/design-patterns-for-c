#include "..\inc\Composite.h"
#include "malloc.h"
#include "stdio.h"
#include "string.h"

#define protected
/** @brief Base Method-----------------*/
protected static void printThisBefore0() {
}

protected static void printThisAfter0() {
}

public static void add(LetterComposite *self,LetterComposite *letter){
    self->children->append(self->children,letter);
}
public int count(LetterComposite *self){
    return self->children->size;
}
public void print(LetterComposite *self){
    self->printThisBefore(self);
    for (int i = 0; i < self->count(self); ++i) {
        LetterComposite* children = (self->children->get(self->children,i));
        children->print(children);
    }
    self->printThisAfter(self);
}

static LetterComposite super = {
        .add = add,
        .count = count,
        .print = print,
        .printThisBefore = printThisBefore0,
        .printThisAfter = printThisAfter0
    //    .children =? createArrayList(10)
};

LetterComposite *initLetterComposite(){
    super.children = createArrayList(10);
    return &super;
}


/**
 * Letter
 */
/** @override-----------------------------*/
static void printThisBefore1(Letter *self){
    putchar(self->character);
}

/** @constuctor && @destructor------------*/
Letter *newLetter(char c){
    Letter *self = malloc(sizeof(Letter));
    self->character = c;
    self->super = *initLetterComposite();
    self->super.printThisBefore = printThisBefore1;
    return self;
}
void delLetter(Letter *self){
    if (self != NULL){
        free(self);
    }
}

/**
 * Message
 */
/** @override-----------------------------*/
static LetterComposite *messageFromOrcs(){
    ArrayList *words = createArrayList(20);
//    words->append(words,newWord1(char letters[] = {'W', 'h', 'e', 'r', 'e'},5));
//    words->append(words,newWord1(char letters[] = {'t', 'h', 'e', 'r', 'e'},5));
//    words->append(words,newWord1(char letters[] = {'i', 's'},2));
//    words->append(words,newWord1(char letters[] = {'W', 'h', 'i', 'p'},4));
//    words->append(words,newWord1(char letters[] = {'t', 'h', 'e', 'r', 'e'},5));
//    words->append(words,newWord1(char letters[] = {'i', 's'},2));
//    words->append(words,newWord1(char letters[] = {'a'},1));
//    words->append(words,newWord1(char letters[] = {'W', 'a', 'y'},3));

    words->append(words,newWord1("Where",5));
    words->append(words,newWord1("there",5));
    words->append(words,newWord1("is",2));
    words->append(words,newWord1("whip",4));
    words->append(words,newWord1("there",5));
    words->append(words,newWord1("is",2));
    words->append(words,newWord1("a",1));
    words->append(words,newWord1("way",3));

    LetterComposite *self = (LetterComposite*)newSentence(words);
    deleteArrayList(words);
    return self;
}
static LetterComposite *messageFromElves(){
    ArrayList *words = createArrayList(20);
    words->append(words,newWord1("Much",4));
    words->append(words,newWord1("wind",4));
    words->append(words,newWord1("pours",5));
    words->append(words,newWord1("from",4));
    words->append(words,newWord1("your",4));
    words->append(words,newWord1("mouth",5));
    LetterComposite *self = (LetterComposite*)newSentence(words);
    deleteArrayList(words);
    return self;
}

/** @constuctor && @destructor------------*/
Messenger *newMessenger(void){
    Messenger *self = malloc(sizeof(Messenger));
    self->messageFromElves = messageFromElves;
    self->messageFromOrcs = messageFromOrcs;
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
/** @override */
static void printThisAfter(){
    printf(".");
}
Sentence *newSentence(ArrayList *words){
    Sentence *self = malloc(sizeof(Sentence));
    self->super = *initLetterComposite();
    self->super.printThisAfter = printThisAfter;
    for (int i = 0; i < words->size; ++i) {
        self->super.add(&self->super,(LetterComposite*)words->get(words,i));
    }
    return self;
}
void delSentence(Sentence *self){
    if (NULL != self){
        if (self->super.children != NULL){
            for (int i = 0; i < self->super.children->size; ++i) {
                delWord(self->super.children->get(self->super.children,i));
            }
        }
        free(self);
    }
}

/**
 * Word
 */
/** @override ---------------------*/
static void printThisBefore2(){
    printf(" ");
}

//Word *newWord( ArrayList *letters){
//    Word *self = malloc(sizeof(Word));
//    self->super = super;
//    self->super.printThisBefore = printThisBefore2;
//    for (int i = 0; i < letters->size; ++i) {
//        self->super.add(&self->super,newLetter(letters->get(letters,i)));
//    }
//    return self;
//}

Word * newWord1(char letters[],int size){
    Word *self = malloc(sizeof(Word));
    self->super = *initLetterComposite();
    self->super.printThisBefore = printThisBefore2;
    for (int i = 0; i < size; ++i) {
        self->super.add(&self->super,(LetterComposite*)newLetter(letters[i]));
    }
    return self;
}
void delWord(Word *self){
    if (NULL != self) {
        if (self->super.children != NULL){
            free(self->super.children);
        }
        free(self);
    }
}

