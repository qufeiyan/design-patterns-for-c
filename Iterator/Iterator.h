//
// Created by Elena on 2020/1/10.
//

#pragma once

#include "OOPSupport.h"

#define DataType void*

public interface Iterator{
    boolean (*hasNext)();
    DataType (*next)();
}Iterator;






























