package com.ooptest;

abstract class Animal {
    private String name;
    private int legs;
    private String colour;

    public Animal(String name, int legs, String colour) {
        this.name = name;
        this.legs = legs;
        this.colour = colour;
    }

    abstract void makeSound();

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getLegs() {
        return legs;
    }

    public void setLegs(int legs) {
        this.legs = legs;
    }

    public String getColour() {
        return colour;
    }

    public void setColour(String colour) {
        this.colour = colour;
    }
}
