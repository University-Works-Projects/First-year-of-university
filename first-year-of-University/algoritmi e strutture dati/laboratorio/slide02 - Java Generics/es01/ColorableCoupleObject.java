package es01;

public class ColorableCoupleObject <A extends MixedCouple, B extends MixedCouple> {
    protected A var1;
    protected B var2;

    public CoupleObject (A in_var1, B in_var2) {
        this.var1 = in_var1;
        this.var2 = in_var2;
    }

    public setColor (Colors in_color) {
        this.var1 = Colors.in_color;
        this.var2 = Colors.in_color;
        
    }


}