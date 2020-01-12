Mediator
-------------

## Intent 
Define an object that encapsulates how a set of objects interact.
Mediator promotes loose coupling by keeping objects from referring 
to each other explicitly, and it lets you vary their interaction 
independently.

`用一个中介者对象封装一系列的对象交互，中介者使各对象不需要显示地相互作用，从而使耦合松散，而且可以独立地改变它们之间的交互。`

In plain words
> Mediator pattern adds a third party object (called mediator) to 
> control the interaction between two objects (called colleagues).
> It helps reduce the coupling between the classes communicating 
> with each other. Because now they don't need to have the knowledge
> of each other's implementation.

Wikipedia says
> In software engineering, the mediator pattern defines an object 
> that encapsulates how a set of objects interact. This pattern is 
> considered to be a behavioral pattern due to the way it can alter
> the program's running behavior.

**Programmatic Example**
Here is the simplest example.
首先定義中介者接口
```c
/**
 * Party interface
 */
public interface Party{
    void (*addMember)(Party *super,PartyMember *member);
    void (*act)(Party *super,PartyMember *actor,Action action);
}Party;
```
實現中介者接口的具體中介類
```c
/**
 * Party implementation
 */
class PartyImpl PartyImpl;
#define implements_Party
public class PartyImpl implements_Party{
    Party super;
    private ArrayList *members;
}PartImpl;
PartyImpl *newPartyImpl(void);
void delPartyImpl(PartImpl *self);

/** definition ---------------*/
/** @Override -------------*/
public static void act(Party *super,PartyMember *actor,Action action){
    PartyImpl *self = (PartyImpl*)super;
    PartyMember *member;
    for(int i = 0;i < self->members->size;++i){
        member = self->members->get(self->members,i);
        if (!(member == actor)){
            member->partyAction(member,action);
        }
    }
}
public static void addMember(Party *super,PartyMember *member){
    PartyImpl *self = (PartyImpl*)super;
    self->members->append(self->members,member);
    member->joinedParty(member,super);
}

PartyImpl *newPartyImpl(void){
    PartImpl *self = malloc(sizeof(PartImpl));
    self->super.act = act;
    self->super.addMember = addMember;
    self->members = createArrayList(10);
    return self;
}
void delPartyImpl(PartImpl *self){
    if (self != NULL){
        if (self->members != NULL){
            deleteArrayList(self->members);
            self->members = NULL;
        }
        free(self);
        self = NULL;
    }
}
```
需要解耦的對象接口
```c
/**
 * Interface for party members interacting with {@link Party}.
 */
interface Party Party;
interface PartyMember PartyMember;
public interface PartyMember{
    void (*joinedParty)(PartyMember *super,Party *party);
    void (*partyAction)(PartyMember *super,Action action);
    void (*act)(PartyMember *super,Action action);
}PartyMember;
```
實現上一接口的抽象基類
```c
/**
 * Abstract base class for party members.
 */
#define implements_PartyMember
public abstract class PartyMemberBase implements_PartyMember {
    PartyMember super;
    protected Party *party;
    char* (*toString)();
}PartyMemberBase;

/** method definition -----------------------*/
/**
 *  Abstract base class for party members.
 */
/** @Override -------------*/
public static void joinedParty(PartyMember *super,Party *party){
    PartyMemberBase *self = (PartyMemberBase*)super;
    printf("%s joins the party\n",self->toString());
    self->party = party;
}
public static void partyAction(PartyMember *super,Action action){
    PartyMemberBase *self = (PartyMemberBase*)super;
    printf("%s %s\n",self->toString(),actionDescription(action));
}
public static void act1(PartyMember *super,Action action){
    PartyMemberBase * self = (PartyMemberBase*)super;
    if (self->party != NULL){
        printf("%s %s\n",self->toString(),actionTitle(action));
        self->party->act(self->party,super,action);
    }
}

static void initSuper(PartyMemberBase *super){
    super->super.act = act1;
    super->super.partyAction = partyAction;
    super->super.joinedParty = joinedParty;
}
```
具體的通过中介交互的各方類定義
```c
/**
 * Rogue party member.
 */
#define extends_PartyMemberBase
public class Rogue extends_PartyMemberBase {
    PartyMemberBase super;
}Rogue;
Rogue *newRogue(void);
void delRogue(Rogue *self);

/**
 * Wizard party member.
 */
public class Wizard extends_PartyMemberBase{
    PartyMemberBase super;
}Wizard;
Wizard *newWizard(void);
void delWizard(Wizard *self);

/**
 * Hunter party member.
 */
public class Hunter extends_PartyMemberBase{
    PartyMemberBase super;
}Hunter;
Hunter *newHunter(void);
void delHunter(Hunter *self);

/**
 * Hobbit party member.
 */
public class Hobbit extends_PartyMemberBase{
    PartyMemberBase super;
}Hobbit;
Hobbit *newHobbit(void);
void delHobbit(Hobbit *self);

/** definition ------------*/
/**
 * Rogue
 */
/** @Override ------------ */
public char* toString(){
    return "Rogue";
}

Rogue *newRogue(void){
    Rogue *self = malloc(sizeof(Rogue));
    initSuper(&self->super);
    self->super.toString = toString;
    return self;
}
void delRogue(Rogue *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * Wizard
 */
/** @Override --------------*/
public static char *toString1(){
    return "Wizard";
}
Wizard *newWizard(void){
    Wizard *self = malloc(sizeof(Wizard));
    self->super.toString = toString1;
    initSuper(&self->super);
    return self;
}
void delWizard(Wizard *self){
    if (NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * Hunter
 */
/** @Override ------------*/
public static char* toString2(){
    return "Hunter";
}
Hunter *newHunter(void){
    Hunter *self = malloc(sizeof(Hunter));
    self->super.toString = toString2;
    initSuper(&self->super);
    return self;
}
void delHunter(Hunter *self){
    if(NULL != self){
        free(self);
        self = NULL;
    }
}

/**
 * Hobbit
 */
/** @Override -------------*/
public static char* toString3(){
    return "Hobbit";
}
Hobbit *newHobbit(void){
    Hobbit *self = malloc(sizeof(Hobbit));
    self->super.toString = toString3;
    initSuper(&self->super);
    return self;
}
void delHobbit(Hobbit *self){
    if(NULL != self){
        free(self);
        self = NULL;
    }
}
```
使用時，可以這樣
```c
// create party and members
Party *party = (Party*)newPartyImpl();
PartyMember *hobbit = (PartyMember*)newHobbit();
PartyMember *wizard = (PartyMember*)newWizard();
PartyMember *rogue = (PartyMember*)newRogue();
PartyMember *hunter = (PartyMember*)newHunter();

// add party members
party->addMember(party,hobbit);
party->addMember(party,wizard);
party->addMember(party,rogue);
party->addMember(party,hunter);

// perform actions -> the other party members
// are notified by the party
hobbit->act(hobbit,ENEMY);
wizard->act(wizard,TALE);
rogue->act(rogue,GOLD);
hunter->act(hunter,HUNT);

delHobbit((Hobbit*)hobbit);
delHunter((Hunter*)hunter);
delRogue((Rogue*)rogue);
delWizard((Wizard*)wizard);

delPartyImpl((PartyImpl *)party);
```
運行結果為
~~~~
Hobbit joins the party
Wizard joins the party
Rogue joins the party
Hunter joins the party
Hobbit spotted enemies
Wizard runs for cover
Rogue runs for cover
Hunter runs for cover
Wizard tells a tale
Hobbit comes to listen
Rogue comes to listen
Hunter comes to listen
Rogue found gold
Hobbit takes his share of the gold
Wizard takes his share of the gold
Hunter takes his share of the gold
Hunter hunted a rabbit
Hobbit arrives for dinner
Wizard arrives for dinner
Rogue arrives for dinner
~~~~

## Class diagram
![lo2GnS.png](https://s2.ax1x.com/2020/01/12/lo2GnS.png)

## Applicability
Use the Mediator pattern when

* a set of objects communicate in well-defined but complex
ways. The resulting interdependencies are unstructured
and difficult to understand
* reusing an object is difficult because it refers to and 
communicates with many other objects
* a behavior that's distributed between several classes
should be customizable without a lot of subclassing

## Real world example

* All scheduleXXX() methods of [java.util.Timer](http://docs.oracle.com/javase/8/docs/api/java/util/Timer.html)
* [java.lang.reflect.Method#invoke()](http://docs.oracle.com/javase/8/docs/api/java/lang/reflect/Method.html#invoke-java.lang.Object-java.lang.Object...-)

## Credits

* [Design Patterns: Elements of Reusable Object-Oriented Software](http://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)


