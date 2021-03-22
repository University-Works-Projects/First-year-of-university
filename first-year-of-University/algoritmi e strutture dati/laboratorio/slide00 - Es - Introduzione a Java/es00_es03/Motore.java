package es00_es03;

public abstract class Motore {
    public final  int potenza;

    abstract protected float var ();

    public Motore (int in_cilindrata, int in_numCilindri){
        this.potenza = (int)((in_cilindrata / in_numCilindri) * var);
    }

    // Metodi get e set omessi

}

