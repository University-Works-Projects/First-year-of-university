package es4;

import java.time.LocalDate;

public abstract class Animal {
    private int legs;                // Numero di zampe
    private String[] verse;          // Verso dell'animale
    protected String[] name;
    protected int years;

    public Animal (int in_years){
        this.years = in_years;
    }
    
}
