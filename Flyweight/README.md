🍃 Flyweight

## Intent
Use sharing to support large numbers of fine-grained objects efficiently.

## Explanation
Real world example

> Alchemist's shop has shelves full of magic potions. Many of the potions are the same 
> so there is no need to create new object for each of them. Instead one object instance 
> can represent multiple shelf items so memory footprint remains small.

In plain words

> It is used to minimize memory usage or computational expenses by sharing as much as 
> possible with similar objects.

Wikipedia says

> In computer programming, flyweight is a software design pattern. A flyweight is an object 
> that minimizes memory use by sharing as much data as possible with similar objects; it is 
> a way to use objects in large numbers when a simple repeated representation would use an 
> unacceptable amount of memory. often some parts of the object state can be shared, and it 
> is common practice to hold them in external data structures and pass them to the flyweight
> objects temporarily when they are used.

**Programmatic example**

Translating our alchemist shop example from above. First of all we have different potion types

```c

```

Then the actual 




## Class diagram
![alt text](./Flyweight.png "Flyweight pattern class diagram")

## Applicability
The Flyweight pattern's effectiveness depends heavily on how and where it's used.
Apply the Flyweight pattern when all of the following are true

* an application uses a large number of objects 
* storage costs are high because of the sheer quantity of objects most object state 
can be made extrinsic
* many groups of objects may be replaced by relatively few shared objects once extrinsic 
state is removed
* the application doesn't depend on object identity. Since flyweight objects may be shared,
identity tests will return true for conceptually distinct objects.

## Real world example
*  [java.lang.Integer#valueOf(int)](http://docs.oracle.com/javase/8/docs/api/java/lang/Integer.html#valueOf%28int%29) and similarly for Byte, Character and other wrapped types.
 
## Credits

* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)

