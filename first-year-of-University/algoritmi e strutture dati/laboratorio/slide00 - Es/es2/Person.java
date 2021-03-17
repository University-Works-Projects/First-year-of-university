package es2;

import java.time.LocalDate;

public interface Person {
    private String name;
    private LocalDate dateOfBirth;

    public Person (String[] in_name, LocalDate in_dateOfBirth) {
        this.name = in_name;
        this.dateOfBirth = in_dateOfBirth;
    }

    public void setName (String in_name) {  
        this.name = in_name;
    }

    public void setDateOfBirth (LocalDate in_dateOfBirth) {  
        this.dateOfBirth = in_dateOfBirth;
    }

    public String getName () {  
        return this.name;
    }

    public LocalDate getDateOfBirth () {
        return this.dateOfBirth;
    }

    @Override
    public String toString () {
        return "Name: " + this.name + "\nDate of birth: " + this.dateOfBirth;
    }

}