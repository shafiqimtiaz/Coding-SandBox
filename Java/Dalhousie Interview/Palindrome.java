import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        System.out.print("Enter number: ");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();

        System.out.println(process(num));
        input.close();
    }

    static int process(int num) {
        int reverse = getRev(num);
        int sum = reverse + num;
        if (check(sum)) {
            return sum;
        } else {
            return getRev(sum) + sum;
        }
    }

    static boolean check(int num) {
        int reverse = getRev(num);
        return reverse == num;
    }

    static int getRev(int num) {
        int reverse = 0;
        // run loop until num becomes 0
        while (num != 0) {
            // get last digit from num
            int digit = num % 10;
            reverse = reverse * 10 + digit;
            // remove the last digit from num
            num /= 10;
        }
        return reverse;
    }
}
