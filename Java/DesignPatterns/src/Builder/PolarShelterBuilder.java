package Builder;

public class PolarShelterBuilder extends ShelterBuilder {
    public void buildRoof() { // Build the different parts of the Shelter
        shelterProduct.setRoof("ice dome");
    }

    public void buildStructure() { // The construction of the Shelter parts
        shelterProduct.setStructure("ice blocks"); // depends on the type of Shelter being built
    }

    public void buildFloor() { // The construction process in a real-life
        shelterProduct.setFloor("caribou skin"); // example may be more complex.
    }
}

