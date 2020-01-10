/**
   ******************************************************************************
   *
   * @file    linkedList.c   
   * @author  qufeiyan
  
   * @date    16-Novemble-2019
   
   * @brief   implement acyclic doubly linked list. 
   *
   ******************************************************************************
   */

#include "LinkedList.h"

#ifndef NULL

#define NULL (void*)0

#endif



static pNode _getNode(struct LinkedList * obj,int index){
	if(index < 0 || index >= obj->size){
		return NULL;
	}
	if(index <= obj->size/2){
		int i = 0;
		pNode pIndex = obj->root;
		while(i++ < index){
			pIndex = pIndex->next; 
		}
		return pIndex;
	}
	
	int j = obj->size - 1;
	pNode pIndex = obj->tail;
	while(j-- > index){
		pIndex = pIndex->prev;	
	} 
	return pIndex;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
 *  index ��0~size-1 
 */ 
static DataType _get(LinkedList * obj,int index){
#if 0
	int temp = 0;
	pNode cur = obj->root;
	while(cur != NULL){
		if(temp == index){
			return cur->val;
		}
		cur = cur->next;
		temp++;
	}
	return -1;
#else
	if(index < 0 || index >= obj->size){
		return -1;
	}else{
		return obj->getNode(obj,index)->val;
	}
#endif
}
/** Add a node of value val before the first element of the linked list. 
 ** After the insertion, the new node will be the first node of the linked list. 
 */
static void _addAtHead(LinkedList * obj,DataType val){
	pNode newNode = (pNode)calloc(1,sizeof(Node)); 
	newNode->val = val;
	if(obj->root != NULL){
		newNode->prev = NULL;
		newNode->next = obj->root;
		obj->root->prev = newNode;
		obj->root = newNode;
	}else{
		newNode->prev = NULL;
		obj->root = newNode;
		obj->tail = obj->root; 
	} 
	obj->size++;
}

 /** Append a node of value val to the last element of the linked list. */
static void _addAtTail(LinkedList * obj,DataType val){
	pNode newNode = (pNode)calloc(1,sizeof(Node));
	newNode->val = val;
	if(obj->tail != NULL){
		newNode->prev = obj->tail;
		newNode->next = NULL;
		obj->tail->next = newNode;
		obj->tail = newNode;
	}else{
		obj->tail = newNode;
		obj->root = obj->tail; 
	}
	obj->size++;
}

/** 
 * Append a node of value val to the last element of the linked list. 
 * If index equals to the length of linked list��the node will be appended
 * to the end of linked list. If index is greater than the length, the node 
 * will not to be inserted.
 */
static void _addAtIndex(LinkedList * obj,int index,DataType val){
	if(index == 0){
		obj->addAtHead(obj,val);
		return;
	}
	if(index == obj->size){
		obj->addAtTail(obj,val);
		return;
	}

	pNode cur = obj->getNode(obj,index);
	
	pNode newNode = calloc(1,sizeof(Node));
	newNode->val = val;
	newNode->prev = cur->prev;
	newNode->next = cur; 
	cur->prev->next = newNode;
	cur->prev = newNode;
	obj->size++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
static DataType _deleteAtIndex(LinkedList *obj,int index){
#if 0
	int temp = 0;
	pNode pre = NULL;
	pNode cur = obj->root;
	if(index == 0){
		pNode old = obj->root;
		obj->root = obj->root->next;
		if(obj->root != NULL){
			obj->root->prev = NULL;
			old->next = NULL; 
		}
		free(old);
		obj->size--;
		return;	
	}	
	if(index == obj->size - 1){
		pNode old = obj->tail;
		obj->tail = obj->tail->prev;
		if(obj->tail){
			obj->tail->next = NULL; 
			old->prev = NULL; 
		} 
		free(old);
		obj->size--;
		return;
	}
	while(cur){
		if(temp == index){
			pNode old = cur;
			if(pre){
				pre->next = cur->next;
			}
			if(cur->next){
				cur->next->prev = pre;
			}
			free(old);
			obj->size--;
			return;
		}
		pre = cur;
		cur = cur->next;
		temp++;
	}
#else
	DataType element;
	if(index == 0){
		pNode old = obj->root;
		obj->root = obj->root->next;
		if(obj->root != NULL){
			obj->root->prev = NULL;
			old->next = NULL; 
		}
		element = old->val;
		free(old);
		obj->size--;
		return element;
	}	
	if(index == obj->size - 1){
		pNode old = obj->tail;
		obj->tail = obj->tail->prev;
		if(obj->tail){
			obj->tail->next = NULL; 
			old->prev = NULL;
		}
		element = old->val;
		free(old);
		obj->size--;
		return element;
	}
	pNode cur = obj->getNode(obj,index);
	element = cur->val;
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	free(cur); 
	obj->size--;
	return element;
#endif	
}

boolean isEmpty(struct LinkedList *obj){
    if (obj != NULL){
        return obj->size == 0;
    }
}


/** delete a linked list. */ 
void freeList(LinkedList *obj)
{
	if(!obj)
		return;
	Node *currentNode = obj->root;
    while (currentNode) {
        Node *tmp = currentNode;
        currentNode = currentNode->next;
        free(tmp);
        tmp = NULL;
    } 
    free(obj);
    obj = NULL;
}

/** new a linked list. */ 
LinkedList *createList(void){
	LinkedList *pList = (LinkedList *)calloc(1,sizeof(LinkedList));
	pList->root = NULL;
	pList->tail = NULL;
	pList->size = 0; 
	
	pList->get = _get;
	pList->getNode = _getNode; 
	pList->addAtHead = _addAtHead;
	pList->addAtIndex = _addAtIndex;
	pList->addAtTail = _addAtTail;
	pList->deleteAtIndex = _deleteAtIndex;
	pList->isEmpty = isEmpty;
    return pList;	
}




