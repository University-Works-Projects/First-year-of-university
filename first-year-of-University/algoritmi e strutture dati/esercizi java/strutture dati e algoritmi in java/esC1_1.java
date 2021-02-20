import java.util.Scanner;
import java.util.Random;

public class esC1_1 {

    /*  Es 1

        Scrivere una breve funzione Java che prenda un array di valori int e determini
        se esiste una coppia di numeri dell'array il cui prodotto è un numero dispari.
    
    */

    boolean es1_1 (int[] in_a){
        int length = a.length;
        for (int i = 0; i < length; i++){
            for (int k = 0; k < length; k++){
                if (((in_a[i] * in_a[k]) % 2 != 0) && i != k) return true;
            }
        }
        return false;
    }

    /*  Es 2

        Scrivere un metodo Java che prenda un array di valori int e determini se tutti
        i numeri siano diversi l'uno dall'altro (cioè siano distinti).
    
    */

    boolean es1_2 (int[] in_a){
        for (int i = 0; i < length; i++){
            for (int k = 0; k < length; k++){
                if (in_a[i] == in_a[k] && i != k) return false;
            }
        }
        return true;
    }

    /*  Es 3

        Scrivere un metodo Java che prenda un array contenente l'insieme di tutti i
        numeri interi compresi nell'intervallo 1-n e li disponga in ordine casuale.
        Questo metodo deve fornire in uscita ogni possibile ordinamento dei numeri
        con eguale probabilità. 
    
    */

    final int length = 52;

    int[] es1_3 (int[] in_a){

    }

}