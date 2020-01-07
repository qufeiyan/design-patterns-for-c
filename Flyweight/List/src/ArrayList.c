/**
 *
 *  @file    ArrayList.c
 *  @author  qufeiyan
 *  @date    2019/12/4
 *  @brief
 *
 */
/* Includes --------------------------------------------------------------------------------*/
#include "../inc/ArrayList.h"

#include "stdlib.h"
#include "string.h"
#include "math.h"

/** @addtogroup
 *  @{
 */

/* Define ----------------------------------------------------------------------------------*/

/**
 * Default initial capacity.
 */
static const int DEFAULT_CAPACITY = 10;

static const int MAX_ARRAY_SIZE = 1024;
/* Macro -----------------------------------------------------------------------------------*/
/* Typedef ---------------------------------------------------------------------------------*/
/* Variables -------------------------------------------------------------------------------*/

/**
 * @brief binary search in a sorted array. it is not used for ArrayList.
 */
static int binarySearch(ArrayList *list, dataType target) {
    int left = 0;
    int right = list->size - 1;
    while (left <= right) {
        int middle = left + ((right - left) >> 1);
#if Use_Array_Float
        float diff = fabs(target - list->get(list, middle));
        if (diff < 0.00000001f) {
            right = middle - 1;
        } else if (diff > 0.00000001f) {
            left = middle + 1;
        } else {
            return middle;
        }
#elif Use_Array_Int
        int diff = target - list->get(list,middle);
        if(diff <  0){
            right = middle - 1;
        }else if(diff > 0){
            left = middle + 1;
        }else{
            return middle;
        }
#endif
    }
    return left;
}


/**
 * @return {@code true} if this list contains no elements
 */
static inline boolean isEmpty(struct ArrayList *obj) {
    return obj->size == 0;
}

static inline boolean contains(struct ArrayList *obj, dataType data) {
    return obj->indexOf(obj, data) >= 0;
}

/**
 * Returns the index of the first occurrence of the specified element
 * in this list, or -1 if this list does not contain the element.
 * More formally, returns the lowest index {@code i} such that
 * {@code Objects.equals(o, get(i))},
 * or -1 if there is no such index.
 */
static inline int indexOf(struct ArrayList *obj, dataType data) {
    return obj->indexOfRange(obj, data, 0, obj->size);
}

static inline int indexOfRange(struct ArrayList *obj, dataType data, int start, int end) {
    dataType *pData = obj->array;
    for (int i = start; i < end; ++i) {
        if (data == pData[i])
            return i;
    }
    return -1;
}

/**
* Increases the capacity to ensure that it can hold at least the
* number of elements specified by the minimum capacity argument.
*        default newCapacity : oldCapacity + (oldCapacity >> 1
* @param minCapacity the desired minimum capacity
*/
static inline dataType *grow(struct ArrayList *obj, int minCapacity) {
    int oldCapacity = obj->capacity;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity - minCapacity < 0)
        newCapacity = minCapacity;
    if (newCapacity - MAX_ARRAY_SIZE > 0)
        newCapacity = MAX_ARRAY_SIZE;
    dataType *oldArray = obj->array;
    dataType *newArray = malloc(newCapacity * sizeof(dataType));
    if (newArray == NULL) return NULL;
    obj->array = newArray;
//    memset(obj->array,0, sizeof(obj->array));
    memcpy(obj->array, oldArray, sizeof(dataType) * obj->size);
    obj->capacity = newCapacity;
    free(oldArray);
    return obj->array;
}
/**
 * Trims the capacity of this {@code ArrayList} instance to be the
 * list's current size.  An application can use this operation to minimize
 * the storage of an {@code ArrayList} instance.
 */
static void trimToSize(struct ArrayList *obj){
    if (obj->size < obj->capacity){
        dataType *oldArray = obj->array;
        dataType *newArray = malloc(obj->size * sizeof(dataType));
        if(newArray == NULL) return;
        memcpy(newArray,oldArray,sizeof(dataType) * obj->size);
        obj->array = newArray;
        obj->capacity = obj->size;
        free(oldArray);
    }
}

/**
 * Inserts the specified element at the specified position in this
 * list. Shifts the element currently at that position (if any) and
 * any subsequent elements to the right (adds one to their indices).
 *
 * @param index index at which the specified element is to be inserted
 * @param data data to be inserted
 */
static inline void add(struct ArrayList *obj, int index, dataType data) {
    if (index > obj->size || index < 0)
        return;
    if (obj->size == obj->capacity) {
        obj->array = grow(obj, obj->size + 1);
    }
    for (int i = obj->size; i > index; --i) {
        obj->array[i] = obj->array[i - 1];
    }
    obj->array[index] = data;
    obj->size++;
}

/**
 * @brief Removes the first occurrence of the specified element from this list
 */
static inline boolean remove(struct ArrayList *obj, dataType data) {
    const dataType *array = obj->array;
    const int size = obj->size;
    int i = 0;
    for (; i < size; ++i) {
#if Use_Array_Int
        if (array[i] == data) break;
#elif Use_Array_Float
        if (fabsf(array[i] - data) < 0.00000001f) break;
#endif
    }
    obj->fastRemove(obj, i);
    return true;
}

static void fastRemove(struct ArrayList *obj, int index) {
    const int newSize = obj->size - 1;
    if (obj == NULL || newSize < index || index < 0) {
        return;
    }
    for (int i = index + 1; i < obj->size; ++i) {
        obj->array[i - 1] = obj->array[i];
    }
    obj->array[newSize] = 0;
    obj->size--;
}

/**
 * Removes all of the elements from this list.  The list will
 * be empty after this call returns.
 */
static inline boolean removeAll(struct ArrayList *obj) {
    if (obj == NULL) return false;
    dataType *array = obj->array;
    for (int i = 0; i < obj->size; ++i) {
        array[i] = 0;
    }
    obj->size = 0;
}

/**
 * Replaces the element at the specified position in this list with
 * the specified element.
 *
 * @param index index of the element to replace
 * @param data data to be stored at the specified position
 * @return the data previously at the specified position
 */
static inline dataType set(struct ArrayList *obj, int index, dataType data) {
    if (index < 0 || index >= obj->size) {
#if Use_Array_Int || Use_Array_Float
        return -1;
#elif Use_Array_Ref
        return NULL;
#endif
    }
    dataType oldValue = obj->array[index];
    obj->array[index] = data;
    return oldValue;
}

/**
 * Returns the data at the specified position in this list.
 *
 * @param  index index of the data to return
 * @return the data at the specified position in this list
 */
static inline dataType get(struct ArrayList *obj, int index) {
    if (index < 0 || index >= obj->size){
#if Use_Array_Int || Use_Array_Float
        return -1;
#elif Use_Array_Ref
        return NULL;
#endif
    }
    return obj->array[index];
}

/**
 * Appends the specified element to the end of this list.
 *
 * @param data data to be appended to this list
 */
static inline boolean append(struct ArrayList *obj, dataType data) {
    obj->add(obj, obj->size, data);
    return true;
}

/**
 * Returns an array containing all of the elements in this list
 * in proper sequence (from first to last element).
 *
 * <p>The returned array will be "safe" in that no references to it are
 * maintained by this list.  (In other words, this method must allocate
 * a new array).  The caller is thus free to modify the returned array.
 *
 * <p>This method acts as bridge between array-based and collection-based
 * APIs.
 *
 * @return an array containing all of the elements in this list in
 *         proper sequence
 */
static inline dataType *toArray(struct ArrayList *obj) {
    dataType *array = (dataType *) malloc(sizeof(dataType) * obj->size);
    memcpy(array, obj->array, obj->size);
    return array;
}

static inline ArrayList *clone(ArrayList *obj) {
    ArrayList *copy = (ArrayList *) createArrayList(obj->capacity);
    memcpy(copy->array, obj->array, obj->size);
    copy->size = obj->size;
    return copy;
}
#if Use_Array_Ref
static inline void forEach(ArrayList *obj,void(*action)()){
    if (action == NULL) return;
    for (int i = 0; i < obj->size; ++i) {
        action(obj->get(obj,i));
    }
}
#else
static inline void forEach(ArrayList *obj,void(*action)()){
    if (action == NULL) return;
    for (int i = 0; i < obj->size; ++i) {
        action(obj->get(obj,i));
    }
}
#endif

/*****************************Constructor and Destructor *********************************/
/**
 * Constructs an empty list with the specified initial capacity.
 *
 * @param  capacity  the initial capacity of the list
 */
ArrayList *createArrayList(int capacity) {
    ArrayList *arrayList = malloc(sizeof(ArrayList));
    if (arrayList == NULL) return NULL;
    arrayList->add = add;
    arrayList->fastRemove = fastRemove;
    arrayList->indexOf = indexOf;
    arrayList->indexOfRange = indexOfRange;
    arrayList->append = append;
    arrayList->contains = contains;
    arrayList->get = get;
    arrayList->set = set;
    arrayList->isEmpty = isEmpty;
    arrayList->clone = clone;
    arrayList->remove = remove;
    arrayList->removeAll = removeAll;
    arrayList->grow = grow;
    arrayList->toArray = toArray;
    arrayList->forEach = forEach;

    if (capacity < DEFAULT_CAPACITY) capacity = DEFAULT_CAPACITY;
    arrayList->array = malloc(sizeof(dataType) * capacity);
    if (arrayList->array == NULL) return NULL;
/*
    for (int i = 0; i < capacity; ++i) {
        arrayList->array[i] = 0;
    }*/
    arrayList->size = 0;
    arrayList->capacity = capacity;
    return arrayList;
}

/**
 * delete a list with the specified capacity.
 *
 * @param  obj  the list to be deleted.
 */
void deleteArrayList(ArrayList *obj) {
    if (obj == NULL) return;
    if (obj->array != NULL) {
        free(obj->array);
        obj->array = NULL;
    }
    free(obj);
    obj = NULL;
}

/*************************************** END OF FILE ****************************************/
