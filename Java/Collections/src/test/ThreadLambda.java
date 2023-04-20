package test;

public class ThreadLambda {
    public static void main(String[] args) {
        new Thread(() -> {
            for (int i = 0; i < 20; i++) {
                System.out.print("a");
            }
            Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
        }).start();

        new Thread(() -> {
            print20("b");
//            try {
//                Thread.sleep(500);
//            } catch (InterruptedException e) {
//                throw new RuntimeException(e);
//            }
        }).start();

        print20("c");
    }

    public static <T> void print20(T value) {
        for (int i = 0; i < 20; i++) {
            System.out.print(value);
        }
    }
}
