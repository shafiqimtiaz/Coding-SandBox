import java.util.*;

public class Factorial {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please enter a number");
        int n = input.nextInt();

        System.out.print("Iterative For Factorial of " + n + " is " + iterativeForfactorial(n));
        System.out.println();
        System.out.print("Iterative While Factorial of " + n + " is " + iterativeWhilefactorial(n));
        System.out.println();
        System.out.print("One Line Factorial of " + n + " is " + oneLinefactorial(n));
        System.out.println();
        System.out.print("Recursive Factorial of " + n + " is " + recursivefactorial(n));
        

        input.close();
    }

    static int recursivefactorial(int n) {
        if (n == 0)
            return 1;
        return (n * recursivefactorial(n - 1));
    }

    static int iterativeForfactorial(int n) {
        int fact = 1;
        for (int i = 2; i <= n; i++)
            fact *= i;
        return fact;
    }

    static int iterativeWhilefactorial(int n) {
        if (n == 0)
            return 1;
        int i = n, fact = 1;
        while (n / i != n) {
            fact = fact * i;
            i--;
        }
        return fact;
    }

    static int oneLinefactorial(int n) {
        return (n == 1 || n == 0) ? 1 : n * oneLinefactorial(n - 1);
    }

}
