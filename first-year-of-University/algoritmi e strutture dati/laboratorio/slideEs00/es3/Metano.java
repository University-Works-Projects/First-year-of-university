package es3;

public class Metano extends Motore {
    public Metano (int in_cilindrata, int in_numCilindri){
        super(in_cilindrata, in_numCilindri);
    }
    public int potenzaMetano () {
        return (int)( ((this.cilindrata * 0.8) / this.numCilindri) * 0.25);
    }
}
