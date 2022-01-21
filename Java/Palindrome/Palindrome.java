import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        System.out.print("Enter number: ");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();

        if (isPalindrome(num)) {
            System.out.println(num + " is Palindrome");
        } else System.out.println("Not Palindrome");
    }

    static boolean isPalindrome(int num) {
        int lastDigit, reverse = 0, match;

        match = num;
        while (num > 0) {
            lastDigit = num % 10;
            reverse = (reverse * 10) + lastDigit;
            num /= 10;
        }

        if (reverse == match) {
            return true;
        } else {
            return false;
        }
    }
}
