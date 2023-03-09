package Factory;

public abstract class VehicleFactory {
    public Vehicle create() {
        Vehicle vehicle = createVehicle();
        vehicle.build();
        return vehicle;
    }

    protected abstract Vehicle createVehicle();
}
