Memento
---------
## Also known as
Token

## Intent
Without violating encapsulation, capture and externalize
an object's internal state so that the object can be restored
to this state later.

In plain words
> Memento pattern is about capturing and storing the current
> state of an object in a manner that it can be restored
> later on in a smooth manner.

Wikipedia says
> The memento pattern is a software design pattern that 
> provides the ability to restore an object to its previous
> state (undo via rollback).

Usually useful when you need to provide some sort of undo
functionality.




## Class diagram
![alt text]()

## Applicability
Use the Memento pattern when

* a snapshot of an object's state must be saved so that
it can be restored to that state later, and
* a direct interface to obtaining the state would expose
implementation details and break the object's encapsulation

## Real world examples

* [java.util.Date](http://docs.oracle.com/javase/8/docs/api/java/util/Date.html)

## Credits

* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)