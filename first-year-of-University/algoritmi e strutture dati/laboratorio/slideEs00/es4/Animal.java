package es4;

public abstract class Animal {
    private int legs;                // Numero di zampe
    private String[] verse;          // Verso dell'animale
    protected String[] name;
    protected int dateOfBirth;

    public Animal (int in_dateOfBirth){
        this.dateOfBirth = in_dateOfBirth;
    }
    
}
