public class Farm {
    private Animal animal1;
    public Animal animal2;
    public Animal animal3;

    public Farm(Animal farmAnimal1, Animal farmAnimal2) {
        this.animal1 = farmAnimal1;
        this.animal2 = farmAnimal2;
    }

    public Animal getAnimal1() {
        return animal1;
    }

    public Animal getAnimal2() {
        return animal2;
    }

    public Animal getAnimal3() {
        return animal3;
    }

    public static void main(String[] args) {

        Animal lion = new Animal("Lion");
        Animal cat = new Animal("Cat");

        Farm myFarm = new Farm(lion, cat);

        System.out.println(myFarm.animal1.name);

    }

}
