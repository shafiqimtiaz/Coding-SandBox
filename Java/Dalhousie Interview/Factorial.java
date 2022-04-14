import java.util.*;

public class Factorial {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please enter a number");
        int n = input.nextInt();

        System.out.print("Iterative Factorial of " + n + " is " + iterativefactorial(n));
        System.out.println();
        System.out.print("Recursive Factorial of " + n + " is " + recursivefactorial(n));

        input.close();
    }

    static int recursivefactorial(int n) {
        if (n == 0)
            return 1;
        return (n * recursivefactorial(n - 1));
    }

    static int iterativefactorial(int n) {
        int fact = 1;
        for (int i = 2; i <= n; i++)
            fact *= i;
        return fact;
    }

}
