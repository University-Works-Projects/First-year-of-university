import java.util.Scanner;

public class Es4 {

    public class Contatore {
            protected int counter;
            Contatore(){ counter = 0; }
            public int valoreContatore(){
                return counter;
            }
            public void incrementaContatore() {
                counter++;
            }
            public void decrementaContatore() {
                counter--;
            }
    }
}

public class Gnomo {
    //  Variabili d'istanza
    public String nome;                         // Stringa contenente il nome;
    public int anni;
    public Gnomo amicoGnomo;
    private boolean magico = false;             // private --> variabile modificabile solo tramite i metodi di QUESTA classe
    protected double altezza = 2.5;
    public static final int ALTEZZA_MAX = 3; // static --> Variabile "globale" della vlasse ; final --> Non modificabile dopo la prima ssegnazione (const in C)

    // Costruttori
    Gnomo (String in_nome, int in_anni, Gnomo amico, double in_altezza){
        nome = in_nome;
        anni = in_anni;
        amicoGnomo = amico;
        altezza = in_altezza;
    }
    // Costruttore di default
    Gnomo(){
        nome = "Theragkh";
        anni = 189;
        amicoGnomo = null;
        altezza = 2.3;
    }

    // Metodi
    public static void makeKing(Gnomo in_gn){
        in_gn.nome = "Re " + h.ottieniNomeReale();
        in_gn.magico = true;    // Si ricorda che solo la classe Gnomo può far riferimento a questo campo
    }
    public void diventaRe(){
        nome = "Re " + h.ottieniNomeReale();
        magico = true;
    }
    public boolean essereMagico() { return magico; }
    public void setAltezza(int in_nuovaAltezza) { altezza = in_nuovaAltezza; }
    public String ottieniNome () { return "Suca"; }
    public String ottieniNomeReale() { return nome; }
    public void rinominaGnomo(String s) { nome = s; }

}

public class DayTripper {
    public enum Giorno {LUN,MAR,MER,GIO,VEN,SAB,DOM};   // Il tipo di variabile enum consente a GIorno di assumere solo i valori inseriti tra le graffe.
    public static void main(String[] args){
        Giorno g = Giorno.LUN;
        System.out.println("All'inizio g è " + g);
        g = Giorno.MER;
        System.out.println("Poi è " + g);
        Giorno t = Giorno.valueOf("MER");
        System.out.println("Significa che g e t coincidono: " + (g == t));        
    }
}
