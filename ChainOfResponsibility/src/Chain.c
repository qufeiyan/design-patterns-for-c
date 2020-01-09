#include "..\inc\Chain.h"
#include "malloc.h"
#include "stdio.h"

#ifndef NULL
#define NULL (void *)0
#endif

/**
 * Request
 */
//. member method.
/**
  * Get a description of the request.
  *
  * @return A human readable description of the request
  */
public static const char* getRequestDescription(Request *self) {
    return self->requestDescription;
}


/**
 * Get the type of this request, used by each person in the chain of command to see if they should
 * or can handle this particular request.
 *
 * @return The request type
 */
public static RequestType getRequestType(Request *self) {
    return self->requestType;
}


/**
 * Mark the request as handled.
 */
public static void markHandled(Request *self) {
    self->handled = true;
}

/**
  * Indicates if this request is handled or not.
  *
  * @return <tt>true</tt> when the request is handled, <tt>false</tt> if not
  */
public static boolean isHandled(Request *self) {
    return self->handled;
}

public static char* toString(Request* self) {
    return (char *)self->getRequestDescription(self);
}


/**
 * @param requestType
 * @param requestDescription
 * @return
 */
Request *newRequest(const RequestType requestType,
                    const char* requestDescription){
    Request *self = malloc(sizeof(Request));
    self->requestType = requestType;
    self->requestDescription = requestDescription;
    self->toString = toString;
    self->getRequestDescription = getRequestDescription;
    self->getRequestType = getRequestType;
    self->isHandled = isHandled;
    self->markHandled = markHandled;
    return self;
}
void delRequest(Request *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}


/**
 * RequestHandler.
 */
/** default member method ------------------*/

/**
 * Request handler.
 */
public static void handleRequest(RequestHandler *self,Request *req) {
    if (self->next != NULL) {
        self->next->handleRequest(self->next,req);
    }
}

protected static void printHandling(RequestHandler *self,Request *req) {
    printf("%s handling request \" %s \" \n", self->toString(self), req->toString(req));
}

/** default -----------------------*/
public static void setNextHandler(RequestHandler *self,RequestHandler *next){
    self->next = next;
}

/**
 * OrcCommander.
 */
/** @Override -----------------*/
public static void handleRequest1(RequestHandler *self,Request *req){
    if (DEFEND_CASTLE == req->getRequestType(req)){
        self->printHandling(self,req);
        req->markHandled(req);
    } else{
        handleRequest(self,req); //. iteration
    }
}
public static char* toString1(RequestHandler *self){
    return "Orc commander";
}
/** Constructor && Destructor */
OrcCommander *newOrcCommander(RequestHandler *handler){
    OrcCommander *self = malloc(sizeof(OrcCommander));
    self->super.handleRequest = handleRequest1;
    self->super.toString = toString1;
    self->super.setNextHandler = setNextHandler;
    self->super.printHandling = printHandling;
    self->super.setNextHandler((RequestHandler*)self,handler);
    return self;
}

void delOrcCommander(OrcCommander *self){
    if (NULL != self){
        free(self);
    }
}

/**
 * OrcOfficer
 */
/** @Override -----------------*/
public static void handleRequest2(RequestHandler *self,Request *req){
    if (TORTURE_PRISONER == req->getRequestType(req)){
        self->printHandling(self,req);
        req->markHandled(req);
    } else{
        handleRequest(self,req);
    }
}
public static char* toString2(RequestHandler *self){
    return "Orc officer";
}
/** Constructor && Destructor */
OrcOfficer *newOrcOfficer(RequestHandler *handler){
    OrcOfficer *self = malloc(sizeof(OrcOfficer));
    self->super.handleRequest = handleRequest2;
    self->super.toString = toString2;
    self->super.setNextHandler = setNextHandler;
    self->super.printHandling = printHandling;
    self->super.setNextHandler((RequestHandler*)self,handler);
    return self;
}

void delOrcOfficer(OrcOfficer *self){
    if (NULL != self){
        free(self);
    }
}

/**
 * OrcSoldier
 */
/** @Override -----------------*/
public static void handleRequest3(RequestHandler *self,Request *req){
    if (COLLECT_TAX == req->getRequestType(req)){
        self->printHandling(self,req);
        req->markHandled(req);
    } else{
        handleRequest(self,req);
    }
}
public static char* toString3(RequestHandler *self){
    return "Orc soldier";
}
/** Constructor && Destructor */
OrcSoldier *newOrcSoldier(RequestHandler *handler){
    OrcSoldier *self = malloc(sizeof(OrcSoldier));
    self->super.handleRequest = handleRequest3;
    self->super.toString = toString3;
    self->super.setNextHandler = setNextHandler;
    self->super.printHandling = printHandling;
    self->super.setNextHandler((RequestHandler*)self,handler);
    return self;
}

void delOrcSoldier(OrcSoldier *self){
    if (NULL != self){
        free(self);
    }
}

/**
 * OrcKing makes requests that are handled by the chain.
 */
private static void buildChain(OrcKing *self){
    self->soldier = (RequestHandler*)newOrcSoldier(NULL);
    self->officer = (RequestHandler*)newOrcOfficer(self->soldier);
    self->commander = (RequestHandler*)newOrcCommander(self->officer);
    self->chain = self->commander;
}

private static void breakChain(OrcKing *self){
    if (self != NULL){
        if (self->chain != NULL){
            typeof(self->chain) next = self->chain;
            typeof(self->chain) temp = self->chain;
            while (next != NULL){
                temp = temp->next;
                free(next);
                next = temp;
            }
        }
    }
}

public static void makeRequest(OrcKing *self,Request *req){
    self->chain->handleRequest(self->chain,req);
}
/** Constructor -----------------*/
public OrcKing *newOrcKing(void){
    OrcKing *self = malloc(sizeof(OrcKing));
    self->buildChain = buildChain;
    self->breakChain = breakChain;
    self->makeRequest = makeRequest;
    self->buildChain(self);
    return self;
}
public void delOrcKing(OrcKing *self){
    if (NULL != self){
        self->breakChain(self);
        free(self);
    }
}