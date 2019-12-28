//
// Created by Elena on 2019/12/28.
//
#include "../inc/Builder.h"
#include "malloc.h"
#include "stdio.h"

/* Burger constructor && destructor --------*/
Burger *CreateBurger(BurgerBuilder *builder){
    Burger *self = malloc(sizeof(Burger));
    self->size = builder->size;
    self->cheese = builder->cheese;
    self->lettuce = builder->lettuce;
    self->pepperoni = builder->pepperoni;
    self->tomato = builder->tomato;
    printf("burger create succeed\n size is %d\n"
           "cheese is %d\n lettuce is %d\n tomato is %d\n pepperoni is %d\n",
           self->size,self->cheese,self->lettuce,self->tomato,self->pepperoni);
    return self;
}
void deleteBurger(Burger *self){
    free(self);
}


/** public method. */
public static BurgerBuilder* addPepperoni(BurgerBuilder *self){
    self->pepperoni = true;
    return self;
}

public static BurgerBuilder* addLettuce(BurgerBuilder *self){
    self->lettuce = true;
    return self;
}

public static BurgerBuilder* addCheese(BurgerBuilder *self){
    self->cheese = true;
    return self;
}

public static BurgerBuilder* addTomato(BurgerBuilder *self){
    self->tomato = true;
    return self;
}

public static Burger* build(BurgerBuilder *self){
    return CreateBurger(self);
}

/** BurgerBuilder constructor && destructor ----------------*/
BurgerBuilder *createBurgerBuilder(int size){
    BurgerBuilder *self = malloc(sizeof(BurgerBuilder));
    self->size = size;
    self->cheese = false;
    self->pepperoni = false;
    self->lettuce = false;
    self->tomato = false;
    self->addCheese = addCheese;
    self->addLettuce = addLettuce;
    self->addPepperoni = addPepperoni;
    self->addTomato = addTomato;
    self->build = build;
    return self;
}

void deleteBurgerBuilder(BurgerBuilder *self){
    free(self);
}



