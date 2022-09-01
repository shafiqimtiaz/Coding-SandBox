package com.ooptest;

public class Dog extends Animal {

    private boolean isGoodboi;

    public Dog(String name, int legs, String colour, boolean isGoodboi) {
        super(name, legs, colour);
        this.isGoodboi = isGoodboi;
    }

    public void makeSound() {
        if (this.isGoodboi){
            System.out.format("%s with %d legs and %s color - is Goodboi and says WOOF WOOF",getName(),getLegs(),getColour());
        } else {
            System.out.format("%s with %d legs and %s color - is Amgry and says GRRRRRR",getName(),getLegs(),getColour());
        }
    }
}
