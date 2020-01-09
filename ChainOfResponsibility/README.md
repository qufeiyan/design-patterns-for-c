🔗 Chain of Responsibility
---
layout: design pattern
title: Chain of responsibility
folder: ChanOfResponsibility
permalink: /design-patterns-for-c
categories: Behavioral
tags:
 - Gang of Four
---

## Intent
Avoid coupling the sender of a request to its receiver by giving more than one 
object a chance to handle the request. Chain the receiving objects and pass the
request along the chain until an object handles it.

>使多个对象都有机会处理请求，从而避免了请求的发送者和接受者之间的耦合关系。
将这些对象连成一条链，并沿着这条链传递该请求，直到有对象处理它为止。

## Explanation
Real world example

> The Orc King gives loud orders to his army. The closest one to react is the 
> commander, then officer and then soldier. The commander, officer and soldier 
> here from a chain of responsibility.

In plain words

> It helps building a chain of objects. Request enters from one end and keeps 
> going from object to object till it finds the suitable handler.

Wikipedia says

> In object-oriented design, the chain-of-responsibility pattern is a design 
> pattern consisting of a source of command objects and a series of processing 
> objects. Each processing object contains logic that defines the types of 
> command objects that it can handle; the rest are passed to the next processing 
> object in the chain.

**Programmatic Example**

Translating our example with orcs from above. First we have the request class
```c
public class Request {

    /**
     * The type of this request, used by each item in the chain to see if they should or can handle
     * this particular request.
     */
    private RequestType requestType;

    /**
     * A description of the request.
     */
    private const char* requestDescription;
    /**
     * Indicates if the request is handled or not. A request can only switch state from unhandled to
     * handled, there's no way to 'unhandle' a request.
     */
    private boolean handled;
    /**
     * Get a description of the request.
     *
     * @return A human readable description of the request
     */
    public char* (*getRequestDescription)();
    /**
     * Get the type of this request, used by each person in the chain of command to see if they should
     * or can handle this particular request.
     *
     * @return The request type
     */
    public RequestType* (*getRequestType)();
    /**
     * Mark the request as handled.
     */
    public void (*markHandled)();
    /**
     * Indicates if this request is handled or not.
     *
     * @return <tt>true</tt> when the request is handled, <tt>false</tt> if not
     */
    public boolean (*isHandled)();
    public char*(*toString)();
}Request;

Request *newRequest(const RequestType requestType,
        const char* requestDescription);
void delRequest(Request *self);

/* definition of Request-------------------------------*/
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
```

Then the request handler hierarchy
```c
/**
 * RequestHandler.
 */
class RequestHandler RequestHandler;
public abstract class RequestHandler {
    private RequestHandler *next;
    public void (*handleRequest)(RequestHandler *self,Request *req);
    protected void (*printHandling)(RequestHandler *self,Request *req);
    private void (*setNextHandler)(RequestHandler *self,RequestHandler *next);
    public abstract char *(*toString)(RequestHandler *self);
}RequestHandler;

/** default member method ------------------*/
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
#define extends_RequestHandler
public class OrcCommander extends_RequestHandler{
    RequestHandler super;
}OrcCommander;
OrcCommander *newOrcCommander(RequestHandler *handler);
void delOrcCommander(OrcCommander *self);

/** definition of OrcCommander---------------------*/
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
 * OrcOfficer.
 */
public class OrcOfficer extends_RequestHandler {
    RequestHandler super;
}OrcOfficer;
OrcOfficer *newOrcOfficer(RequestHandler *handler);
void delOrcOfficer(OrcOfficer *self);
/** definition of OrcOfficer */
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
 * OrcSoldier.
 */
public class OrcSoldier extends_RequestHandler{
    RequestHandler super;
}OrcSoldier;
OrcSoldier *newOrcSoldier(RequestHandler *handler);
void delOrcSoldier(OrcSoldier *self);
/** definition of OrcSoldier */
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
```
Then we have the Orc King who gives the orders and forms the chain
```c
class OrcKing OrcKing;
/**
 * OrcKing makes requests that are handled by the chain.
 */
public class OrcKing{
    private RequestHandler *chain;
    private RequestHandler *commander,*officer,*soldier;
    private void (*buildChain)(OrcKing *self);
    private void (*breakChain)(OrcKing *self);
    public void (*makeRequest)(OrcKing *self,Request *req);
}OrcKing;
OrcKing *newOrcKing(void);
void delOrcKing(OrcKing *self);
/** definition of OrcKing ---------------------------*/
/** member method -----------------------------------*/
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
/** Constructor && Destructor-----------------*/
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
```

Then it is used as follows
```c
OrcKing *king = newOrcKing();
Request *request = newRequest(DEFEND_CASTLE,"defend catsle");
king->makeRequest(king,request);
delRequest(request);

request = newRequest(TORTURE_PRISONER,"torture prisoner");
king->makeRequest(king,request);
delRequest(request);

request = newRequest(COLLECT_TAX,"collect tax");
king->makeRequest(king,request);

delRequest(request);
delOrcKing(king);
```

## Class diagram
![alt text](Chain_of_Responsibility.png "Chain of Responsibility class diagram")

## Applicability
Use Chain of Responsibility when

* more than one object may handle a request, and the handler isn't known a priori.
The handler should be ascertained automatically
* you want to issue a request to one of several objects without specifying the
receiver explicitly
* the set of objects that can handle a request should be specified dynamically

## Real world example
* [java.util.logging.Logger#log()](http://docs.oracle.com/javase/8/docs/api/java/util/logging/

## Credits
* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)
