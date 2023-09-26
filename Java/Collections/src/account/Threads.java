package account;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Threads {
    public static void main(String[] args) {
        // Create tasks
        Runnable printA = new PrintChar('a', 100);
        Runnable printB = new PrintChar('b', 100);
        Runnable print100 = new PrintNum(100);

        // Create threads
//        Thread thread1 = new Thread(printA);
//        Thread thread2 = new Thread(printB);
//        Thread thread3 = new Thread(print100);

//        thread2.setPriority(Thread.MAX_PRIORITY);
//        thread3.setPriority(Thread.MIN_PRIORITY);

        // Start threads
//        thread1.start();
//        thread2.start();
//        thread3.start();

        // Create a fixed thread pool with maximum three threads
        ExecutorService executor1 = Executors.newFixedThreadPool(1);
        ExecutorService executor2 = Executors.newCachedThreadPool();

        // Submit runnable tasks to the executor
        executor1.execute(printA);
        executor1.execute(printB);
        executor1.execute(print100);

        //executor2.execute(print100);

        // Shut down the executor
        executor1.shutdown();
        executor2.shutdown();
    }
}

class PrintChar implements Runnable {
    private final char charToPrint; // The character to print
    private final int times; // The times to repeat

    /**
     * Construct a task with specified character and number of
     * times to print the character
     */
    public PrintChar(char c, int t) {
        charToPrint = c;
        times = t;
    }

    @Override
    /** Override the run() method to tell the system
     *  what the task to perform
     */
    public void run() {
        for (int i = 0; i < times; i++) {
            System.out.print(charToPrint);
        }
        System.out.println();
    }
}

class PrintNum implements Runnable {
    private final int lastNum;

    /**
     * Construct a task for printing 1, 2, ... i
     */
    public PrintNum(int n) {
        lastNum = n;
    }

    @Override
    /** Tell the thread how to run */
    public void run() {
        Thread thread4 = new Thread(
                new PrintChar('c', 40));
        thread4.start();
        try {
            for (int i = 1; i <= lastNum; i++) {
                System.out.print(i + " ");
                if (i == 50) thread4.join();
            }
        } catch (InterruptedException ex) {
        }

//        for (int i = 1; i <= lastNum; i++) {
//            System.out.print(i + " ");
////            Thread.yield();
//            try {
//                if (i >= 25) Thread.sleep(10);
//            } catch (InterruptedException ex) {
//                ex.printStackTrace();
//            }
//        }
        System.out.println();
    }
}
