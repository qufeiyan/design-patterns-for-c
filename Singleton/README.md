💍 Singleton
----------------
## Intent
Ensure a class only have one instance, and provide a
global point of access to it.

## Explanation
Real word example

> There can only be one ivory where the wizards study their magic.
> The same enchanted ivory tower is always used by the wizards. Ivory tower
> here is singleton.

In plain words

> Ensure that only one object of a particular class is ever created.

Wikipedia says

> In software engineering, the singleton pattern is a software design pattern that
> restricts the instantiation of a class to one object. This is useful when exactly 
> one object is needs to coordinate actions across the system.

**Programmatic Example**




## Class diagram
![alt text](Singleton.png "Singleton pattern class diagram")

## Applicability
Use the Singleton pattern when

* There must be exactly one instance of a class, and it must be accessible to clients
from a well-known access point 
* When the sole instance should be extensible by subclassing, and Clients should be
able to use an extended instance without modifying their code

## Typical Use Case
* The logging class
* Managing a connection to a database 
* File manager

## Real world example
* [java.lang.Runtime#getRuntime()](http://docs.oracle.com/javase/8/docs/api/java/lang/Runtime.html#getRuntime%28%29)
* [java.awt.Desktop#getDesktop()](http://docs.oracle.com/javase/8/docs/api/java/awt/Desktop.html#getDesktop--)
* [java.lang.System#getSecurityManager()](http://docs.oracle.com/javase/8/docs/api/java/lang/System.html#getSecurityManager--)

## Consequences
* Violates Single Responsibility Principle (SRP) by controlling their own creation and lifecycle.
* Encourages using a global shared instance which prevents an object and resources used by their 
object from being deallocated.
* Creates tightly coupled code. The clients of the Singleton become difficult to test.
* Makes it almost impossible to subclass a Singleton.

## Credits
*  [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Dsign-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)

