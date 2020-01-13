/**
 *
 *  @file    Stack.h
 *  @author  qufeiyan
 *  @brief   implemention of Stack.
 *  @date    2019/1/13
 *
 */
/* Define to prevent recursive inclusion ---------------------------------------------------*/
#ifndef __STACK_H
#define __STACK_H
#ifdef __cplusplus
extern "C" {
#endif
/* Includes --------------------------------------------------------------------------------*/
#include "List/inc/ArrayList.h"
/* Define ----------------------------------------------------------------------------------*/
#ifndef NULL
#define NULL (void *)0
#endif

#ifndef OBJECT_ORIENTED_SUPPORT
#define OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private
#define protected
#endif

#ifndef BOOL
#define BOOL
typedef enum boolean{
    false,
    true
}boolean;
#endif


/**
 *  The {@code Stack} class represents a last-in-first-out
 * (LIFO) stack of objects. It extends class {@code ArrayList} with five
 * operations that allow a array list to be treated as a stack. The usual
 * {@code push} and {@code pop} operations are provided, as well as a method
 * to {@code peek} at the top item on the stack, a method to test for whether
 * the stack {@code isEmpty}, and a method to {@code search} the stack for an
 * item and discover how far it is from the top.
 * <p>
 * When a stack is first created, it contains no items.
 */
class Stack Stack;

public class Stack {
    ArrayList *super;
    public dataType (*push)(Stack *self,dataType item);
    public dataType (*pop)(Stack *self);
    public dataType (*peek)(Stack *self);
    public boolean (*isEmpty)(Stack *self);
    public int (*search)(Stack *self,dataType data);
}Stack;
Stack *newStack(void);
void *delStack(Stack *);






#ifdef __cplusplus
}
#endif
#endif
/*************************************** END OF FILE ****************************************/


