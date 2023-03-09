package Factory;

public class BikeFactory extends VehicleFactory {
    @Override
    protected Vehicle createVehicle() {
        return new Bike();
    }
}
