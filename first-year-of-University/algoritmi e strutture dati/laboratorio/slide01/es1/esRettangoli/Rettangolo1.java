package es1.esRettangoli;

public class Rettangolo1 {
    private float side, height;                             // lato lato ed altezza

    public Rettangolo1(float in_side, float in_height){
        this.side = in_side;
        this.height = in_height;
    }

    public float perimeter(){
        return (this.side * 2 + this.height * 2);
    }

    public float area(){
        return ((this.side * this.height) / 2);
    }
}