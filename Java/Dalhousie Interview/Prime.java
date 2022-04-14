import javax.sound.sampled.BooleanControl;

import java.util.*;

public class Prime {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please enter a number");

        while (true) {

            int num = input.nextInt();

            if (num < 1)
                break;

            if (isPrime(num)) {
                System.out.println(num + " is a prime number");
            } else {
                System.out.println(num + " is not a prime number");
            }
        }

        System.out.println("EXIT");
        input.close();
    }

    public static boolean isPrime(int num) {

        if (num < 1)
            return false;

        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

}
