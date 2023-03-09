package Builder;

/**
 * Director of the Builder pattern
 */
public class Explorer {
    /**
     * The Explorer is to use a specific "build plan": the ShelterBuilder
     */
    private ShelterBuilder builder;

    public void setBuilder(ShelterBuilder newShelterBuilder) {
        builder = newShelterBuilder;
    }

    /**
     * The Director assumes that all Shelters have the same parts
     * and each part is built by calling the same method
     * though what these specific methods do may be different.
     */
    public void constructShelter() {
        builder.createNewShelter();
        builder.buildRoof();
        builder.buildStructure();
        builder.buildFloor();
    }

    /**
     * @return gets the Shelter after it has been built
     */
    public Shelter getShelter() {
        return builder.getShelter();
    }
}

