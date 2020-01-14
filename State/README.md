##　Also known as
Objects for States

## Intent
Allow an object to alter its behavior when its internal state changes. The object 
will appear to change its class.

In plain words
> It lets you change the behavior of a class when the state changes.

Wikipedia says
> The state pattern is a behavioral software design that implements a state machine in 
> an object-oriented way. With the state pattern, a state machine is implemented by 
> implementing each individual state as a derived class of the state pattern interface,
> and implementing state transitions by invoking methods defined by the pattern's 
> superclass.


> The state pattern can be interpreted as a strategy pattern which is able to switch the
> current strategy through invocations of methods defined in the pattern's interface. 


**Programmatic example**

Let's take an example of .

```c

```



## Class diagram




## Applicability
Use the State pattern in either of the following cases

* An object's behavior depends on its states, and it must change its behavior at 
run-time depending on that state
* Operations have large, multipart conditional statements that depend on the 
object's state. This state is usually represented by one or more enumerated constant. 
Often, several operations will contain this same conditional structure. The State 
pattern puts each branch of the conditional in a separate class. This lets you treat
the object's state as an object in its own right that can vary independently from other
objects.

## Real world examples


