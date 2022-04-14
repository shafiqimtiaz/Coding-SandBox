import java.util.*;

class CheckPin {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please enter your four digit pin");

        int checkPin = 1234;

        while (true) {

            String pin = input.nextLine();

            try {
                int inputPin = Integer.parseInt(pin);
                if (pin.length() != 4) {
                    System.out.println("Please enter 4 digits only");
                } else {
                    if (inputPin == checkPin) {
                        System.out.println("ACCESS GRANTED");
                        break;
                    } else {
                        System.out.println("ACCESS DENIED, please enter correct PIN");
                    }
                }
            } catch (NumberFormatException e) {
                System.out.println("Please enter an integer");
            }
        }

        input.close();

    }
}