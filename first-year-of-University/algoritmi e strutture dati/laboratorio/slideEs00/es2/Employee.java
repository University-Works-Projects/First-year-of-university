package es2;

import java.time.LocalDate;

public interface Employee extends Person {
    private float salary;

    public Employee (String[] in_name, LocalDate in_dateOfBirth, float in_salary) {
        super (in_name, in_dateOfBirth);
        this.salary = in_salary;
    }

    public Employee (float in_salary) {
        super ();
        this.salary = in_salary;
    }

    public void setSalary (float in_salary) {
        this.salary = in_salary;
    }

    public float getSalary () {
        return this.salary;
    }

    @Override
    public String toString () {
        return super.toString() + "\nSalary: " + this.salary + "$";
    }

}