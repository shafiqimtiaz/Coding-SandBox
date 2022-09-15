package datastructures.Factorial;

public class factorial {

    public static void main(String[] args) {

        double startTime1 = System.nanoTime();
        System.out.println("iterativeFactorial - " + iterativeFactorial(10));
        double stopTime1 = System.nanoTime();
        System.out.println((stopTime1 - startTime1) / 1000000);

        double startTime2 = System.nanoTime();
        System.out.println("recursiveFactorial - " + recursiveFactorial(10));
        double stopTime2 = System.nanoTime();
        System.out.println((stopTime2 - startTime2) / 1000000);
    }

    public static int recursiveFactorial(int num) {
        if (num == 0) {
            return 1;
        }
        return num * recursiveFactorial(num - 1);
    }

    public static int iterativeFactorial(int num) {
        if (num == 0) {
            return 1;
        }
        int fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }
}