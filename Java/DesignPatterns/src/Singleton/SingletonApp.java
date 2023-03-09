package Singleton;

public class SingletonApp {

    public static void main(String[] args) {
        Singleton singleton1 = Singleton.getInstance();
        System.out.println(singleton1.getInfo());

        Singleton singleton2 = Singleton.getInstance();
        singleton2.setInfo("Hello World");

        System.out.println(singleton1.getInfo());
        System.out.println(singleton2.getInfo());
    }
}
