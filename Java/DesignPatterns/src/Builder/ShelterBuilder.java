package Builder;

/**
 * Abstract Builder class of the Builder pattern
 */
public abstract class ShelterBuilder {
    /**
     * Product to be constructed by the builder
     */
    protected Shelter shelterProduct;

    /**
     * Get the constructed Shelter from the Builder
     */
    public Shelter getShelter() {
        return shelterProduct;
    }

    /**
     * Create a new unspecified Shelter that
     * will be eventually build by calling the
     * following abstract methods in a concrete
     * class derived from the Shelter class
     */
    public void createNewShelter() {
        shelterProduct = new Shelter();
    }

    abstract void buildRoof();

    abstract void buildStructure();

    abstract void buildFloor();
}

