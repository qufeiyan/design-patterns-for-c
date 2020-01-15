#pragma once

#include "../OOPSupport.h"

/**
 * Interface for the nodes in hierarchy.
 */
class Unit Unit;
class UnitVisitor UnitVisitor;
public abstract class Unit{
    private Unit *children;
    public void (*accept)(UnitVisitor *visitor);
}Unit;

