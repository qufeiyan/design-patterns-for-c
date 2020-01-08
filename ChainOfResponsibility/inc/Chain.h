#ifndef __CHAIN_H
#define __CHAIN_H
#endif

#ifndef OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private
#define protected
#endif

typedef enum boolean{
    false,
    true
}boolean;

class Request Request;
/**
 * RequestHandler.
 */
class RequestHandler RequestHandler;
public abstract class RequestHandler {
    private RequestHandler *next;
    public void (*RequestHandler)(RequestHandler *next);
    public void (*handleRequest)(Request *req);
    protected void (*printHandling)(Request *req);
    public abstract char *(*toString)();
}RequestHandler;

/**
 * OrcKing makes requests that are handled by the chain.
 */
public class OrcKing{
    private RequestHandler *chain;

}OrcKing;


/**
 * RequestType enumeration.
 */
public typedef enum RequestType {

    DEFEND_CASTLE,
    TORTURE_PRISONER,
    COLLECT_TAX
}RequestType;

/**
 * Request.
 */
public class Request {

    /**
     * The type of this request, used by each item in the chain to see if they should or can handle
     * this particular request.
     */
    private const RequestType requestType;

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



