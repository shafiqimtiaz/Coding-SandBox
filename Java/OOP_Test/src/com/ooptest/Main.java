package com.ooptest;
public class Main {
    public static void main(String[] args) {
        Car porche = new Car(4,6,"Carrera");
        Car audi = new Car();
        audi.printCar();
        porche.printCar();

        Dog myDog = new Dog("Bompi",4,"brown",true);
        myDog.makeSound();
    }
}