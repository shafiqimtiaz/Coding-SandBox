package example;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class FairLock {
    public static void main(String[] argv) {
        Lock fork1 = new ReentrantLock(false);
        Lock fork2 = new ReentrantLock(true);
        Lock fork3 = new ReentrantLock(true);
        Lock fork4 = new ReentrantLock();
        Lock fork5 = new ReentrantLock(true);
        /*from ww w  .  ja  va2s  . c o m*/
        Philosopher p1 = new Philosopher(fork1, fork2, "P1");
        Philosopher p2 = new Philosopher(fork2, fork3, "P2");
        Philosopher p3 = new Philosopher(fork3, fork4, "P3");
        Philosopher p4 = new Philosopher(fork4, fork5, "P4");
        Philosopher p5 = new Philosopher(fork5, fork1, "P5");

        p1.eat();
        p1.think();

        p2.eat();
        p2.think();

        p3.eat();
        p3.think();

        p4.eat();
        p4.think();

        p5.eat();
        p5.think();


        p1.eat();
        p2.eat();
        p3.eat();
        p4.eat();
        p5.eat();

        p1.think();
        p2.think();
        p3.think();
        p4.think();
        p5.think();

    }
}

class Philosopher {
    private Lock leftFork;
    private Lock rightFork;
    private String name; // Philosopher's name

    public Philosopher(Lock leftFork, Lock rightFork, String name) {
        this.leftFork = leftFork;
        this.rightFork = rightFork;
        this.name = name;
    }

    public void think() {
        System.out.println(name + " is thinking...");
    }

    public void eat() {
        // Try to get the left fork
        if (leftFork.tryLock()) {
            try {
                // try to get the right fork
                if (rightFork.tryLock()) {
                    try {
                        try {
                            // Got both forks. Eat now
                            Thread.sleep(1000);
                            System.out.println(name + " is eating...");

                            Thread.sleep(1000);
                        } catch (InterruptedException e) {
                            // TODO Auto-generated catch block
                            e.printStackTrace();
                        }
                    } finally {
                        // release the right fork
                        rightFork.unlock();
                    }
                }
            } finally {
                // release the left fork
                leftFork.unlock();
            }
        }
    }
}
