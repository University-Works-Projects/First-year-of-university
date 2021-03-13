package es4;

public class Cat extends Animal{
    public Cat (int in_legs, String[] in_verse, String[] in_name, int in_dateOfBirth){
        this.legs = in_legs;
        this.verse = in_verse;
        this.name = in_name;
        super (in_dateOfBirth);
    }
}
