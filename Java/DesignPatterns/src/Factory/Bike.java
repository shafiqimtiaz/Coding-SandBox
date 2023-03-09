package Factory;

public class Bike implements Vehicle {
    @Override
    public void build() {
        System.out.println("Build Bike");
    }
}
