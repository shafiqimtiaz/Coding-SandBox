package com.ooptest;

public class Car {
    private int doors;
    private int wheels;
    private String model;

    public Car(int doors, int wheels, String model) {
        this.doors = doors;
        this.wheels = wheels;
        this.model = model;
    }

    public Car() {
        this.doors = 0;
        this.wheels = 0;
        this.model = "No Model";
    }

    public void printCar(){
        System.out.println(this.model + " with " + this.doors + " doors and " + this.wheels + " wheels");
    }

    public int getDoors() {
        return doors;
    }

    public void setDoors(int doors) {
        this.doors = doors;
    }

    public int getWheels() {
        return wheels;
    }

    public void setWheels(int wheels) {
        this.wheels = wheels;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }
}
