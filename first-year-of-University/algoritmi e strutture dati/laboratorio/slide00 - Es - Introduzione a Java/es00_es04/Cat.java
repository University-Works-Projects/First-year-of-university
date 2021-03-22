package es00_es04;

import java.time.LocalDate;

public class Cat extends Animal{
    public Cat (int in_legs, String[] in_verse, String[] in_name, int in_dateOfBirth){
        this.legs = in_legs;
        this.verse = in_verse;
        this.name = in_name;
        super (in_dateOfBirth);
    }
}
