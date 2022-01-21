public class Main {
    public static void main(String[] args) {

        Account shafiqAccount = new Account(); //("12345", 0.00, "Shafiq Imtiaz", "shafiqimtiaz@gmail.com", "(514) 5744-436");
        System.out.println(shafiqAccount.getEmail());

        shafiqAccount.withdrawal(100.0);
        shafiqAccount.deposit(50.0);
        shafiqAccount.withdrawal(100.0);
        shafiqAccount.deposit(51.0);
        shafiqAccount.withdrawal(100.0);

        Account ilhamAccount = new Account("Ilham Morsalin",  "ilhammorsalin@gmail.com", "018-328-74436");
        System.out.println("New Account for "+ilhamAccount.getName()+" with Account number "+ilhamAccount.getNumber());
    }
}
