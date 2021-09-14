package es01;

import javax.sound.sampled.spi.MixerProvider;

public class ColorableMixedCouple <A extends MixedCouple, B extends MixedCouple> extends MixedCouple <A, B> {

    public ColorableMixedCouple (A in_var1, B in_var2) {
        super (in_var1, ni_var2);
    }

    public setColor (Colors in_color) {
        this.var1.setColor (in_color);      // Si assume che setColor sia impleentato in A e B
        this.var2.setColor (in_color);      // Si assume che setColor sia impleentato in A e B
    }


}