package es3;

public class Benzina extends Motore {
    public Benzina (int in_cilindrata, int in_numCilindri){
        super(in_cilindrata, in_numCilindri);
    }
    public int potenzaMetano () {
        return (int)( (this.cilindrata / this.numCilindri) * 0.1);
    }
}
