package Composite;

import java.util.ArrayList;
import java.util.List;

public class Employee implements IEmployee {
    private final String name;
    private final String dept;
    private final int salary;
    private final List<Employee> subordinates;

    // constructor
    public Employee(String name, String dept, int sal) {
        this.name = name;
        this.dept = dept;
        this.salary = sal;
        subordinates = new ArrayList<>();
    }

    public void add(Employee e) {
        subordinates.add(e);
    }

    public void remove(Employee e) {
        subordinates.remove(e);
    }

    public List<Employee> getSubordinates() {
        return subordinates;
    }

    @Override
    public String getDetails() {
        return ("Employee : [ Name : " + name + ", dept : " + dept + ", salary :" + salary + " ]");
    }
}
