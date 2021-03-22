package es00_es02;

import java.time.LocalDate;

public interface Intern extends Employee {
    private int workHours;
    private LocalDate internNumeber;

    public void setPresence (int in_workHours) {
        this.workHours = in_workHours;
    }
    
    public void setInternNumer(int in_internNumber) {
        this.setInternNumer = in_internNumber;
    }

    public int getPresence () {
        return this.workHours;
    }

    public getPresence () {
        return this.workHours;
    }

    @Override
    public String toString () {
        return super.toString() + "\nHours of work: " + this.work + "\nIntern number: " + this.internNumeber;
    }


}