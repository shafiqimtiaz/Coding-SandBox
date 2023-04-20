package example;

// The task class for printing number from 1 to n for a given n
public class PrintNum implements Runnable {
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
