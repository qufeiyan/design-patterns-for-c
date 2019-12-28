//
// Created by Elena on 2019/12/28.
//

#ifndef BUILDER_BUILDER_H
#define BUILDER_BUILDER_H

#endif //BUILDER_BUILDER_H

#define class typedef struct
#define interface typedef struct

#define private
#define public

typedef enum boolean{
    false = 0,
    true
}boolean;

class Burger{
    private int size;
    private boolean cheese;
    private boolean pepperoni;
    private boolean lettuce;
    private boolean tomato;

}Burger;

class BurgerBuilder BurgerBuilder;
Burger *CreateBurger(BurgerBuilder *builder);
void deleteBurger(Burger *self);

class BurgerBuilder{
    public int size;
    public boolean cheese;
    public boolean pepperoni;
    public boolean lettuce;
    public boolean tomato;

    BurgerBuilder* (*addPepperoni)(BurgerBuilder *self);
    BurgerBuilder* (*addLettuce)(BurgerBuilder *self);
    BurgerBuilder* (*addCheese)(BurgerBuilder *self);
    BurgerBuilder* (*addTomato)(BurgerBuilder *self);
    Burger* (*build)(BurgerBuilder *self);
}BurgerBuilder;

BurgerBuilder *createBurgerBuilder(int size);
void deleteBurgerBuilder(BurgerBuilder *self);



