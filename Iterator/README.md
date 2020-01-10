➿ Iterator
------------------
## Also know as
Cursor

## Intent
Provide a way to access the elements of an aggregate object
sequentially without exposing its underlying representation.

In plain words
> It presents a way to access the elements of an object without
> exposing the underlying presentation.

Wikipedia says
> In object-oriented programming, the iterator pattern is 
> a design pattern in which an iterator is used to traverse
> a container and access the container's elements. The 
> iterator pattern decouples algorithms from containers;
> in some cases, algorithms are necessarily container-specific
> and thus cannot be decoupled.

Real world example

> An old radio set will be a good example of iterator, where 
> user could start at some channel and then use next or 
> previous buttons to go through the respective channels. 
> Or take an example of MP3 player or a TV set where you 
> could press the next and previous buttons to go through
> the consecutive channels or in other words they all provide
> an interface to iterate through the respective channels, 
> songs or radio stations.

**Programmatic example**

 


## Applicability
Use the Iterator pattern

* to access an aggregate object's contents without exposing
its internal representation
* to support multiple traversals of aggregate objects
* to provide a uniform interface for traversing different 
aggregate structures

## Real world examples

* [java.util.Iterator](http://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html)
* [java.util.Enumeration](http://docs.oracle.com/javase/8/docs/api/java/util/Enumeration.html)

## Credits

* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)


  
