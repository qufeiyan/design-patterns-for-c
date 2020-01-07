/**
 * 
 *  @file    HashMap.h
 *  @author  qufeiyan
 *  @brief   provide hash map.
 *  @date    2019/11/27   
 * 
 */
/* Define to prevent recursive inclusion ---------------------------------------------------*/
#ifndef __HASH_MAP_H
#define __HASH_MAP_H
#ifdef __cplusplus
  extern "C" {
#endif
/* Includes --------------------------------------------------------------------------------*/


#define Use_Key_Int 1
#define Use_Key_String 0

#define Use_value_Int 0
#define Use_value_Float 0
#define Use_value_Double 0
#define Use_value_String 0
#define Use_value_Object 1

#if Use_Key_Int
typedef int keyType;
#elif Use_Key_String
typedef void* keyType;
#endif

#if Use_value_Int
typedef int valueType;
#elif Use_value_Float
typedef float valueType;
#elif Use_value_Double
typedef double valueType;
#elif Use_value_String
typedef char* valueType;
#elif Use_value_Object
typedef void* valueType;
#endif




#ifndef BOOLEAN
typedef enum boolean{
    false = 0,
    true
}boolean;
#endif

typedef struct Element{
    int hash;
    keyType key;
    valueType value;
    struct Element *next;
}Element;

typedef struct HashMap{
    Element *pList;
    int size;
    int capacity;
    int threshold;
    float factor;
    boolean autoResize; //auto adjust size.
    boolean (*equal)(keyType key1,keyType key2);
    int (*hashCode)(struct HashMap *obj,keyType key);
    int (*indexFor)(struct HashMap *obj,int hash);
    boolean (*put)(struct HashMap *obj,keyType key,valueType value);
    valueType (*get)(struct HashMap *obj,keyType key);
    boolean (*contains)(struct HashMap *obj,keyType key);    
    boolean (*remove)(struct HashMap *obj,keyType key);
    void (*resize)(struct HashMap *obj,int capacity); //adjust hash map size.
    void (*removeAll)(struct HashMap *obj); //cleal all.
    //. add
    void (*forEach)(struct HashMap *obj,void (*)());
}HashMap;

typedef struct HashMapIterator{
    HashMap *pHashMap;
    Element *current;
    int count;
    int index;
    boolean (*hasNext)(struct HashMapIterator *obj);
    Element *(*nextElement)(struct HashMapIterator *obj);
}HashMapIterator;




HashMap* createHashMap(void);
void freeHashMap(HashMap *obj);
HashMapIterator* createHashMapIterator(HashMap *pHashMap);
void freeHashMapIterator(HashMapIterator *obj);

#ifdef __cplusplus
}
#endif
#endif
/*************************************** END OF FILE ****************************************/
