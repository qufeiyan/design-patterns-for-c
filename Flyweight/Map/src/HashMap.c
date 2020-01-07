/** 
 * 
 *  @file    HashMap.c
 *  @author  qufeiyan
 *  @date    2019/11/27
 *  @brief   
 * 
 */
/* Includes --------------------------------------------------------------------------------*/
#include "../inc/HashMap.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
/* Define ----------------------------------------------------------------------------------*/
#ifndef NULL
    #ifdef __cplusplus
        #define NULL 0
    #else
        #define NULL ((void *)0)
    #endif
#endif

#if Use_Key_Int
#ifndef INT_MIN
#define INT_MIN (-2147483647 - 1)
#endif

#define NULL_Key INT_MIN
#endif

static const int DEFAULT_INITIAL_CAPACITY = 1 << 4; // capacity. buckets.
static const float DEFAULT_LOAD_FACTOR = 0.75f;  //load factor.

/* Macro -----------------------------------------------------------------------------------*/
/* Typedef ---------------------------------------------------------------------------------*/
/* Variables -------------------------------------------------------------------------------*/


/** @addtogroup 
 *  @{
 */
#if Use_Key_String
static inline boolean equal(keyType key1,keyType key2){
    return strcmp((char *)key1,(char *)key2) == 0 ? true : false;
}
#elif Use_Key_Int
static inline boolean equal(keyType key1,keyType key2){
    return key1 == key2 ? true : false;
}
#endif

static inline void resize(HashMap *obj,int newCapacity){
	if (newCapacity < DEFAULT_INITIAL_CAPACITY) return;
    int oldCapacity = obj->capacity;
    Element *newTable = (Element *)malloc(sizeof(struct Element) * newCapacity);

    for (int i = 0; i < newCapacity; ++i) { //. if it is not initialized,an error will be occur during iteration.
#if Use_Key_String
        (newTable + i)->key = NULL;
#elif Use_Key_Int
        (newTable + i)->key = NULL_Key;
#endif
        (newTable + i)->next = NULL;
    }

    Element *oldTable = obj->pList;
    Element* e; //linked list head node.
    if (oldTable != NULL){
        for (int i = 0; i < oldCapacity; ++i) {
          //Element* e; //linked list head node.
#ifndef Use_Key_String
            if ((e = &oldTable[i])->key != NULL){
#elif Use_Key_Int
            if ((e = &oldTable[i])->key != INT_MIN){
#endif
                if (e->next == NULL){ //.if e has none next.
                    newTable[e->hash & (newCapacity - 1)] = *e;
                } else{
                    Element *loHead = NULL, *loTail = NULL;
                    Element *hiHead = NULL, *hiTail = NULL;
                    Element *next;
                    do{
                        next = e->next;
                        if((e->hash & oldCapacity) == 0){
                            if(loTail == NULL){
                                loHead = e;
                            } else{
                                loTail->next = e;
                            }
                            loTail = e;
                        } else{
                            if(hiTail == NULL){
                                hiHead = e;
                            }else{
                                hiTail->next = e;
                            }
                            hiTail = e;
                        }
                    }while ((e = next) != NULL);

                    if (loTail != NULL){
                        loTail->next = NULL;
                        newTable[i] = *loHead;
                    }
                    if (hiTail != NULL){
                        hiTail->next = NULL;
                        newTable[i + oldCapacity] = *hiHead;
                    }
                }
            }
        }
        free(oldTable);
    }
	obj->pList = newTable;
	obj->capacity = newCapacity;
 	obj->threshold = (int)(newCapacity * obj->factor);
}
int num = 0;
static inline boolean put(HashMap *obj,keyType key,valueType value){
    if(obj->autoResize && obj->size >= obj->threshold){ //. resize.
        obj->resize(obj, obj->capacity << 1);
        printf("resize num is %d\n",++num);
        printf("obj->capacity is %d\n",obj->capacity);
    }

    int hash = obj->hashCode(obj,key);
    int index = obj->indexFor(obj,hash);
#if Use_Key_String
    if (obj->pList[index].key == NULL){ //. not exist.
#elif Use_Key_Int
    if (obj->pList[index].key == NULL_Key){ //. not exist.
#endif
        obj->size++;
        obj->pList[index].key = key;
        obj->pList[index].value = value;
        obj->pList[index].hash = hash;
        return true;
    }else{
        Element *current = &obj->pList[index];
        while (current){
            if(obj->equal(key,current->key)){
                obj->pList[index].value = value;    //override exist value.
                return true;
            }
            current = current->next;
        };
        
        Element *pElement = (Element *)malloc(sizeof(struct Element));
        pElement->key = key;
        pElement->value = value;
        pElement->hash= hash;
        pElement->next = obj->pList[index].next;
        obj->pList[index].next = pElement;
        obj->size++;
    }

    return false;
}

static inline valueType get(HashMap *obj,keyType key){
    int hash = obj->hashCode(obj, key);
    int index = obj->indexFor(obj,hash);
    printf("key is %s,index is %d\n",key,index);
	Element *pElement = &obj->pList[index];
	while (pElement != NULL) {
		if (obj->equal(pElement->key, key)) {
			return pElement->value;
		}
		pElement = pElement->next;
	}
#if Use_value_String || Use_value_Object
	return NULL;
#else
    return -1;
#endif
}

static inline boolean contains(HashMap *obj,keyType key){
	int hash = obj->hashCode(obj, key);
	int index = obj->indexFor(obj,hash);
	Element *pElement = &obj->pList[index];
#if Use_Key_String
	if (pElement->key == NULL) {
#elif Use_Key_Int
    if (pElement->key == NULL_Key) {
#endif
		return false;
	}
	else { //. could be optimized.
		while (pElement != NULL) {
			if (obj->equal(pElement->key, key)) {
				return true;
			}
			pElement = pElement->next;
		}
		return false;
	}
}

/**
 *  remove all element.
 */
static inline void removeAll(HashMap *obj){
	for (int i = 0; i < obj->capacity; i++) {
		//release conflict memory.
		Element *pElement = obj->pList[i].next;
		while (pElement != NULL) {
			Element *next = pElement->next;
			free(pElement);
			pElement = next;
		}
		//clear list array.
		obj->pList[i].next = NULL;
#if Use_Key_String
		obj->pList[i].key = NULL;
#elif Use_Key_Int
        obj->pList[i].key = NULL_Key;
#endif
#if Use_value_String || Use_value_Object
        obj->pList[i].value = NULL;
#else
		obj->pList[i].value = 0;
#endif
		obj->pList[i].hash = -1;
	}
	obj->size = 0;
}
#if Use_Key_String
/**
 * @brief ELF hash algorithm. 
 */
static inline int hashCode(HashMap *obj,keyType key){
	char *k = (char *)key;
	unsigned long h = 0;
	while (*k) {
		h = (h << 4) + *k++;
		unsigned long g = h & 0xF0000000L;
		if (g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
    return (h & 0x7FFFFFFF);
}

/**
 * @brief java string hashCode : BKDH hash algorithm. when seed = 31.
 * The hash code for a String object is computed as：
 *      s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
 *  n is the length of the string, and ^ indicates exponentiation.
 *  (The hash value of the empty string is zero.)
 */
static inline int javaHashCode(HashMap *obj,keyType key){
    char *k = (char *)key;
    unsigned long h = 0;
    while(*k){
         h = 31 * h + *k++;
    }
    return (h & 0x7FFFFFFF);
}
#elif Use_Key_Int
static inline int javaHashCode(HashMap *obj,keyType key){
    int k = (int)key;
    return (k & 0x7FFFFFFF);
}
#endif
/**
 * @brief Insertion of disturbance
 */
static inline int hash(HashMap *obj,keyType key){
    int h;
#if Use_Key_String
    return (key == NULL) ? 0 : (h = javaHashCode(obj,key)) ^ (h >> 16);
#elif Use_Key_Int
    return (key == NULL_Key) ? 0 : (h = javaHashCode(obj,key)) ^ (h >> 16);
#endif
}

static inline int indexFor(struct HashMap *obj,int hash){
    return hash & (obj->capacity - 1);
}

static inline boolean removeNode(HashMap *obj,keyType key){
    int hash = obj->hashCode(obj, key);
    int index = indexFor(obj,hash);
	Element *pElement = &obj->pList[index];
#if Use_Key_String
	if (pElement->key == NULL) {
#elif Use_Key_Int
    if (pElement->key == NULL_Key) {
#endif
		return false;
	}
    keyType entryKey = pElement->key;
	boolean result = false;
	if (obj->equal(pElement->key, key)) { //. same with buckets
		obj->size--;
		if (pElement->next != NULL) {
			Element *temp = pElement->next;
			pElement->key = temp->key;
			pElement->value = temp->value;
			pElement->next = temp->next;
			pElement->hash = temp->hash;
			free(temp);
		}
        else {

#if Use_Key_String
            pElement->key = NULL;
#elif Use_Key_Int
            pElement->key = NULL_Key;
#endif
#if Use_value_String || Use_value_Object
            pElement->value = NULL;
#else
            pElement->value = 0; //NULL
#endif
            pElement->hash = -1;
        }
		result = true;
	}
	else {      //.same with list.
		Element *p = pElement;
		pElement = pElement->next;
		while (pElement != NULL) {
			if (obj->equal(pElement->key, key)) {
				obj->size--;
				p->next = pElement->next;
				free(pElement);
				result = true;
				break;
			}
			p = pElement;
			pElement = pElement->next;
		};
	}
	return result;
}

void forEach(struct HashMap *obj,void (*action)()){
    Element *e = NULL;
    for (int i = 0; i < obj->capacity; ++i) {
        e = &obj->pList[i];
        for (; e != NULL ; e = e->next) {
            action(e->key,e->value);
        }
    }
}

HashMap* createHashMap(void){
    HashMap *obj = (HashMap *)malloc(sizeof(struct HashMap));
	obj->size = 0;
	obj->capacity = DEFAULT_INITIAL_CAPACITY;
	obj->factor = DEFAULT_LOAD_FACTOR;
	obj->autoResize = true;
	obj->threshold = (int)(obj->capacity * obj->factor);
    obj->hashCode = hash;
	obj->equal = equal;
	obj->contains = contains;
	obj->get = get;
	obj->put = put;
    obj->remove = removeNode;
	obj->removeAll = removeAll;
	obj->resize = resize;
	obj->indexFor = indexFor;

	obj->forEach = forEach;

	obj->pList = malloc(obj->capacity * sizeof(struct Element));
	Element *p = obj->pList;
	for (int i = 0; i < obj->capacity; i++){
#if Use_Key_Int
	    p[i].key = NULL_Key;
#elif Use_Key_String
		p[i].key = NULL;
#endif

#if Use_value_String || Use_value_Object
        p[i].value = NULL;
#else
        p[i].value = 0;
#endif
		p[i].next = NULL;
	}
	return obj;
}

void freeHashMap(HashMap *obj){
	// remove all elements.
	obj->removeAll(obj);
	// release.
	free(obj->pList);
	obj->pList = NULL;
	free(obj); 
	obj = NULL;
} 

/********************************* Iterator ****************************************/

static inline boolean hasNext(HashMapIterator *obj){
    return obj->count < obj->pHashMap->size ? true : false;
}

static Element* nextElement(HashMapIterator *obj){
	if(obj->hasNext(obj)){
		if(obj->current != NULL && obj->current->next != NULL){
			obj->count++;
			obj->current = obj->current->next;
			return obj->current;
		}
		while (++obj->index < obj->pHashMap->capacity){
			Element *current = &obj->pHashMap->pList[obj->index];
#if Use_Key_String
			if(current->key != NULL){
#elif Use_Key_Int
			if(current->key != NULL_Key){
#endif
				obj->count++;
				obj->current = current;
				break;
			}
		}
	}
	return obj->current;
}


/**
 *  initial status: iterator->current = NULL
 */
HashMapIterator* createHashMapIterator(HashMap *pHashMap){
	HashMapIterator *iterator = (HashMapIterator *)malloc(sizeof(struct HashMapIterator));
    iterator->pHashMap = pHashMap;
	iterator->count = 0;
	iterator->index = -1; //.it is only a index.
	iterator->current = NULL;
	iterator->hasNext = hasNext;
	iterator->nextElement = nextElement;
	return iterator;
}

void freeHashMapIterator(HashMapIterator *obj){
	free(obj);
	obj = NULL;
}

/*************************************** END OF FILE ****************************************/

