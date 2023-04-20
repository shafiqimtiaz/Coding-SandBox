package example;

// The task for printing a specified character in specified times
public class PrintChar implements Runnable {
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
