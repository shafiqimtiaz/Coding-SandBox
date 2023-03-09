package Factory;

public class FactoryApp {
    public static void main(String[] args) {
        new CarFactory().createVehicle().build();
        new BikeFactory().createVehicle().build();
    }
}
