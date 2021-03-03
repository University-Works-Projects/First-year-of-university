package es2.Person;

public class Person1 {
    
    private String name;
    private Citizenship citizenship;


    public Person1(String name, Citizenship in_citizenship){
        this.name = name;
        this.citizenship = in_citizenship;
    }

    public Person1(String in_name){
        this.name = in_name;
        this.citizenship = Citizenship.Italiana;
    }

    public String getInfo(){
        return "Name: " + this.name + " ; Citizenship: " + this.citizenship;
    }

}
