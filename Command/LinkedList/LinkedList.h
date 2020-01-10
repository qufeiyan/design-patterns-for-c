/**
   ******************************************************************************
   *
   * @file    linkedList.h   
   * @author  qufeiyan
  
   * @date    16-Novemble-2019
   
   * @brief   implement  doubly linked list  
   *
   ******************************************************************************
   */

#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include "stdlib.h"  

#ifndef BOOL
typedef enum boolean{
    false,
    true
}boolean;
#endif
#define Use_Ref_Data 1
#ifndef DataType
#if Use_Ref_Data
#define DataType void*
#else
#define DataType float
#endif
#endif

// #define NULL (void*)0

/*  Doubly Linked List  */

typedef struct Node{
	DataType val;
	struct Node *prev;
	struct Node *next;
}Node,*pNode;

typedef struct LinkedList{
	pNode root;
	pNode tail; 
	volatile int size;
	DataType (*get)(struct LinkedList *obj,int index); 
	pNode (*getNode)(struct LinkedList *obj,int index); 
	void (*addAtHead)(struct LinkedList *obj,DataType val);
	void (*addAtTail)(struct LinkedList *obj,DataType val);
	void (*addAtIndex)(struct LinkedList *obj,int index,DataType val);
	DataType (*deleteAtIndex)(struct LinkedList *obj,int index);
	boolean (*isEmpty)(struct LinkedList *obj);

}LinkedList;



/** All nodes in the list are 0-index. */
LinkedList *createList(void);

void freeList(LinkedList *obj);


#endif
 
