#include "..\inc\Chain.h"
#include "malloc.h"

/**
 * Request
 */
/**
 * @param requestType
 * @param requestDescription
 * @return
 */
Request *newRequest(const RequestType requestType,
                    const char* requestDescription){
    Request *self = malloc(sizeof(Request));
    
}
void delRequest(Request *self);
