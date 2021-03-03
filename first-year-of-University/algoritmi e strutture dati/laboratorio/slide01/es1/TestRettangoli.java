/*

    An example of using the java classes

*/

import esRettangoli.Rettangolo1;
import esRettangoli.Rettangolo2;

public class TestRettangoli {
    public static void main(String[] args) {
        Rettangolo1 r1 = new Rettangolo1(20, 50);
        Rettangolo2 r2 = new Rettangolo2(80, 10);

        System.out.println("Area r1: " + r1.area());
        System.out.println("Perimetro r2: " + r2.perimeter());
    }
}