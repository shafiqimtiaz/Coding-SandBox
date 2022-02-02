import java.util.SplittableRandom;

public class VipPerson {
    private String name;
    private double limit;
    private String email;

    public VipPerson(){
        this("Default name", 1000.00, "default@email.com");
    }

    public VipPerson(String name, double limit){
        this(name, limit, "default@email.com");
    }

    public VipPerson(String name, double limit, String email) {
        this.name = name;
        this.limit = limit;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public double getLimit() {
        return limit;
    }

    public String getEmail() {
        return email;
    }
}
