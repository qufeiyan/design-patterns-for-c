#pragma once

#include "../OOPSupport.h"

typedef enum StateName{
    PEACEFUL,
    ANGRY
}StateName;

/**
 * State interface
 */
public interface State{
    void (*onEnterState)();
    void (*observe)();
}State;
/**
 * Mammoth has internal state that defines its behavior.
 */
public class Mammoth{
    private State state;
    public void (*timePasses)();
    private void (*changeStateTo)();
    public void (*observe)();
    public char* (*toString)();
}Mammoth;
Mammoth *newMammoth(void);
void delMammoth(Mammoth *);

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

/**
 * Angry state.
 */
public class AngryState implements_State{
    private State super;
    private Mammoth *mammoth;
}AngryState;
AngryState *newAngryState(Mammoth *mammoth);
void delAngryState(AngryState*);

