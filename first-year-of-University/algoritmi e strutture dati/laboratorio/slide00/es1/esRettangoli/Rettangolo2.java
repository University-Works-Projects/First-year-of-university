package es1.esRettangoli;

public class Rettangolo2 {
    private float  perimeter, area;

    public Rettangolo2(float in_side, float in_height){
        this.perimeter = in_side * 2 + in_height * 2;
        this.area = (in_side * in_height) / 2; 
    }

    public float perimeter(){
        return this.perimeter;
    }
    public float area(){
        return this.area;
    }

}
