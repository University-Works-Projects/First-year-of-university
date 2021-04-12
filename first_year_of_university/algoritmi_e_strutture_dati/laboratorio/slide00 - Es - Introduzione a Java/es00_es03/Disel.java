package es00_es03;

public class Disel extends Motore {
    public Disel (int in_cilindrata, int in_numCilindri){
        super(in_cilindrata, in_numCilindri);
    }
    public int potenzaMetano () {
        return (int)( (this.cilindrata / this.numCilindri) * 0.2);
    }
}
