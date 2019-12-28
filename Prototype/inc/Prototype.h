//
// Created by Elena on 2019/12/28.
//

#ifndef PROTOTYPE_PROTOTYPE_H
#define PROTOTYPE_PROTOTYPE_H

#endif //PROTOTYPE_PROTOTYPE_H

#define class typedef struct
#define interface typedef struct
#define public
#define private

interface Prototype Prototype;

interface Prototype{
    void *(*copy)(Prototype*);
}Prototype;


