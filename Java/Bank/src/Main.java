public class Main {
    public static void main(String[] args) {

//        Account shafiqAccount = new Account(); //("12345", 0.00, "Shafiq Imtiaz", "shafiqimtiaz@gmail.com", "(514) 5744-436");
//        System.out.println(shafiqAccount.getEmail());
//
//        shafiqAccount.withdrawal(100.0);
//        shafiqAccount.deposit(50.0);
//        shafiqAccount.withdrawal(100.0);
//        shafiqAccount.deposit(51.0);
//        shafiqAccount.withdrawal(100.0);
//
//        Account ilhamAccount = new Account("Ilham Morsalin",  "ilhammorsalin@gmail.com", "018-328-74436");
//        System.out.println("New src.Account for "+ilhamAccount.getName()+" with src.Account number "+ilhamAccount.getNumber());

        VipPerson abbu = new VipPerson();
        System.out.println(abbu.getName());

        VipPerson ammu = new VipPerson("Matluba Akther", 1000.00, "matluba@gmail.com");
        System.out.println(ammu.getName() + " - " + ammu.getLimit() + " - " + ammu.getEmail());
    }
}
