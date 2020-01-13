/**
 *
 *  @file    ArrayList.h
 *  @author  qufeiyan
 *  @brief   implemention of ArrayList.
 *  @date    2019/12/4
 *
 */
/* Define to prevent recursive inclusion ---------------------------------------------------*/
#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H
#ifdef __cplusplus
extern "C" {
#endif
/* Includes --------------------------------------------------------------------------------*/

/* Define ----------------------------------------------------------------------------------*/
#ifndef NULL
#define NULL (void *)0
#endif

#ifdef bool
#undef bool
#endif

#define Use_Array_Float 0
#define Use_Array_Int 0
#define Use_Array_Ref 1
#define Use_Array_Char 0

#if Use_Array_Float
typedef float dataType;
#elif Use_Array_Int
typedef int dataType;
#elif Use_Array_Ref
typedef void* dataType;
#endif

#ifndef BOOL
#define BOOL
typedef enum boolean {
    false = 0,
    true
} boolean;
#endif

typedef struct ArrayList {
    int capacity;
    int size;
    dataType *array; //The array buffer into which the elements of the ArrayList are stored.
    boolean (*isEmpty)(struct ArrayList *obj);

    boolean (*contains)(struct ArrayList *obj, dataType data);

    int (*indexOf)(struct ArrayList *obj, dataType data);

    int (*indexOfRange)(struct ArrayList *obj, dataType data, int start, int end);

    int (*lastIndexOf)(struct ArrayList *obj, dataType data);

    int (*lastIndexOfRange)(struct ArrayList *obj, dataType data, int start, int end);

    void (*add)(struct ArrayList *obj, int index, dataType data);

    boolean (*remove)(struct ArrayList *obj, dataType data);

    void (*fastRemove)(struct ArrayList *obj, int index);

    boolean (*removeAll)(struct ArrayList *obj);

    dataType (*set)(struct ArrayList *obj, int index, dataType data);

    dataType (*get)(struct ArrayList *obj, int index);

    boolean (*append)(struct ArrayList *obj, dataType data);

    dataType *(*toArray)(struct ArrayList *obj);

    dataType *(*grow)(struct ArrayList *obj, int minCapacity);

    void (*trimToSize)(struct ArrayList *obj);

    void (*forEach)(struct ArrayList *obj,void(*)());

    struct ArrayList *(*clone)(struct ArrayList *obj);
} ArrayList;

ArrayList *createArrayList(int capacity);

void deleteArrayList(ArrayList *obj);

#ifdef __cplusplus
}
#endif
#endif
/*************************************** END OF FILE ****************************************/
