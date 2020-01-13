/**
 *
 *  @file    ArrayList.c
 *  @author  qufeiyan
 *  @date    2019/1/13
 *  @brief
 *
 */
/* Includes --------------------------------------------------------------------------------*/
#include "Stack.h"
#include "stdlib.h"

/** @addtogroup
 *  @{data structure
 */

/**
 * Stack
 */

/** definition of Stack's method ----------------------------------------*/

/**
 * Pushes an item onto the top of this stack. This has exactly
 * the same effect as :
 * <blockquote><pre>
 * append(ArrayList *,item)</pre></blockquote>
 *
 * @param   item   the item to be pushed onto this stack.
 * @return  the {@code item} argument.
 * @see     ArrayList.h/.c
 */
public static dataType push(Stack *self,dataType item){
    self->super->append(self->super,item);
    return item;
}
/**
 * Removes the object at the top of this stack and returns that
 * object as the value of this function.
 *
 * @return The object at the top of this stack (the last item
 *          of the {@code Vector} object).
 */
public static dataType pop(Stack *self){
    dataType obj;
    int len = self->super->size;
    obj = self->peek(self);
    self->super->fastRemove(self->super,len - 1);
    return obj;
};
/**
 * Looks at the object at the top of this stack without removing it
 * from the stack.
 *
 * @return the object at the top of this stack (the last item
 *          of the {@code ArrayList} object).
 */
public static dataType peek(Stack *self){
    int len = self->super->size;
    if(len != 0){
        return self->super->get(self->super,len - 1);
    }
}
/**
 * Tests if this stack is empty.
 *
 * @return  {@code true} if and only if this stack contains
 *          no items; {@code false} otherwise.
 */
public static boolean isEmpty(Stack *self){
    return self->super->isEmpty(self->super);
}
/**
 * Returns the 1-based position where an object is on this stack.
 * If the object {@code o} occurs as an item in this stack, this
 * method returns the distance from the top of the stack of the
 * occurrence nearest the top of the stack; the topmost item on the
 * stack is considered to be at distance {@code 1}. The {@code equals}
 * method is used to compare {@code o} to the items in this stack.
 *
 * @param   o  the desired object.
 * @return  the 1-based positon from the top of the stack where the object
 *          is located; the return value {@code -1} indicates that the object
 *          is not on the stack.
 */
public static int search(Stack *self,dataType o){
    int i = self->super->lastIndexOf(self->super,o);
    if(i >= 0){
        return self->super->size - i;
    }
    return -1;
}

Stack *newStack(void){
    Stack *self = malloc(sizeof(Stack));
    self->super = createArrayList(10);
    self->isEmpty = isEmpty;
    self->peek = peek;
    self->pop = pop;
    self->push = push;
    self->search = search;
    return self;
}
void *delStack(Stack *self){
    if (NULL != self){
        if (NULL != self->super){
            deleteArrayList(self->super);
            self->super = NULL;
        }
        free(self);
        self = NULL;
    }
}
