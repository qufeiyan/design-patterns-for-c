## Also known as
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

## 参与者

* Context(上下文类): 拥有多种状态的对象，上下文类的状态存在多样性，并且在不同的状态下，对象表现出不同的行为。
在上下文类中，维护了一个抽象状态类的实例，表明当前所处之状态。
* State(抽象状态类)：声明一个状态接口，用于封装与在上下文类中的一个特定状态相关的行为，在子类中实现在各种
不同状态对应的方法。不同的子类可能存在不同的实现方法，相同的方法可以写在抽象状态类中。
* ConcreteState(具体状态类): 实现具体状态下的方法，每一个具体状态类对应一个具体的状态。


**Programmatic example**
例如目标对象猛犸有两个情绪状态，生气与平静。其状态可随着时间波动。

猛犸类  即Context
```c
/**
 * Mammoth has internal state that defines its behavior.
 */
public class Mammoth{
    State *PEACEFUL_STATE;
    State *ANGRY_STATE;
    private State *currentState;
    public void (*setCurrentState)();
    public void (*timePasses)();
    private void (*changeStateTo)();
    public void (*observe)();
    public char* (*toString)();
}Mammoth;
Mammoth *newMammoth(void);
void delMammoth(Mammoth *);
/** definition -----------------------*/
/** member method ---------------------*/
public static void timePasses(Mammoth *self){
    self->changeStateTo(self);
}

public static void setCurrentState(Mammoth *self,State* state){
    self->currentState = state;
}

private static void changeStateTo(Mammoth *self){
    self->currentState->setNextState(self->currentState);
    self->currentState->onEnterState(self->currentState);
}

public static char* toString(){
    return "The mammoth";
}

public static void observe(Mammoth *self){
    self->currentState->observe(self->currentState);
}

Mammoth *newMammoth(void){
    Mammoth *self = malloc(sizeof(Mammoth));
    //. initialize all state.
    self->PEACEFUL_STATE = (State *)newPeacefulState(self);
    self->ANGRY_STATE = (State*)newAngryState(self);
    //. set initial state.
    self->currentState = self->PEACEFUL_STATE;

    self->timePasses = timePasses;
    self->observe = observe;
    self->changeStateTo = changeStateTo;
    self->toString = toString;
    self->setCurrentState = setCurrentState;
    return self;
}
void delMammoth(Mammoth *self){
    if (NULL != self){

        delAngryState((AngryState *)self->ANGRY_STATE);
        delPeacefulState((PeacefulState *)self->PEACEFUL_STATE);

        free(self);
        self = NULL;
    }
}
```
State 抽象接口 
```c
/**
 * State interface
 */
public interface State{
    void (*onEnterState)();
    void (*observe)();
    void (*setNextState)();
}State;
```
ConcreteState 具体状态
```c
/**
 * Peaceful state
 */
class PeacefulState PeacefulState;
#define implements_State
public class PeacefulState implements_State{
    private State super;
    private Mammoth *mammoth;
}PeacePeacefulState;
PeacefulState *newPeacefulState(Mammoth *mammoth);
void delPeacefulState(PeacefulState*);
/** definition -------------------------------*/
public static void observe1(PeacefulState *self){
    printf("%s is calm and peaceful!\n",self->mammoth->toString());
}

public static void onEnterState1(PeacefulState *self){
    printf("%s calms down.\n",self->mammoth->toString());
}

public static void setNextState1(PeacefulState *self){
    self->mammoth->setCurrentState(self->mammoth,self->mammoth->ANGRY_STATE);
}

PeacefulState *newPeacefulState(Mammoth *mammoth){
    PeacefulState *self = malloc(sizeof(PeacefulState));
    self->super.observe = observe1;
    self->super.onEnterState = onEnterState1;
    self->mammoth = mammoth;

    self->super.setNextState = setNextState1;
    return self;
}
void delPeacefulState(PeacefulState* self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * Angry state.
 */
public class AngryState implements_State{
    private State super;
    private Mammoth *mammoth;
}AngryState;
AngryState *newAngryState(Mammoth *mammoth);
void delAngryState(AngryState*);

/** definition --------------------------*/
public static void observe2(AngryState *self){
    printf("%s is furious!\n",self->mammoth->toString());
}

public static void onEnterState2(AngryState *self){
    printf("%s gets angry!\n",self->mammoth->toString());
}

public static void setNextState2(AngryState *self){
    self->mammoth->setCurrentState(self->mammoth,self->mammoth->PEACEFUL_STATE);
}

AngryState *newAngryState(Mammoth *mammoth){
    AngryState *self = malloc(sizeof(AngryState));
    self->super.onEnterState = onEnterState2;
    self->super.observe = observe2;
    self->mammoth = mammoth;
    self->super.setNextState = setNextState2;
    return self;
}

void delAngryState(AngryState *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}
```
可以这样使用
```c
Mammoth *mammoth = newMammoth();
mammoth->observe(mammoth);
mammoth->timePasses(mammoth);

mammoth->observe(mammoth);
mammoth->timePasses(mammoth);

mammoth->observe(mammoth);

delMammoth(mammoth);
```

运行结果为
~~~~
The mammoth is calm and peaceful!
The mammoth gets angry!
The mammoth is furious!
The mammoth calms down.
The mammoth is calm and peaceful!
~~~~

完整代码可访问
[state pattern](https://github.com/qufeiyan/design-patterns-for-c/tree/master/State)

## Class diagram
![state.png](https://upload.cc/i1/2020/01/15/eakzGm.png)

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

* [javax.faces.lifecycle.Lifecycle#execute()](http://docs.oracle.com/javaee/7/api/javax/faces/lifecycle/Lifecycle.html#execute-javax.faces.context.FacesContext-) controlled by [FacesServlet](http://docs.oracle.com/javaee/7/api/javax/faces/webapp/FacesServlet.html), the behavior is dependent on current phase of lifecycle.
* [JDiameter - Diameter State Machine](https://github.com/npathai/jdiameter/blob/master/core/jdiameter/api/src/main/java/org/jdiameter/api/app/State.java)

## Credits

* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)


