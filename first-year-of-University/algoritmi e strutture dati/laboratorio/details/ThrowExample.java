/*
    N.B: Il messaggio del comando throw non è tanto un output del programma per l'utente, ma più
    un messaggio del programma per il programmatore con delle informazioni sull'eccezzione generata

 */

import java.util.Scanner;
import java.lang.Math.*;

public class ThrowExample {

    // Calcola la radice quadrata di x, se è positivo 
    public static double sqrt (double x) {
        // Cancia un'eccezione se il parametro attuale è illegale 
        if (x < 0)
            throw new IllegalArgumentException("sqrt: " + x);
        return Math.sqrt(x);
    }
    
    public static void main (String [] args) {
     	Scanner UserInput = new Scanner(System.in);
        double x = 0; 
        do { 
            System.out.print ("Scrivi un intero (0 per finire): ");
            x = UserInput.nextInt(); 
            if (x != 0) {
                System.out.println("Risultato di sqrt(" + x + "):");
                System.out.println(sqrt(x)); 
            } 
        } while (x != 0); 
    } 
}
