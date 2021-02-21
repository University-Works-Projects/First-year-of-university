import java.util.Scanner;
import java.util.Random;

public class esC {

    /*  Es 1

        Scrivere una breve funzione Java che prenda un array di valori int e determini
        se esiste una coppia di numeri dell'array il cui prodotto è un numero dispari.
    
    */

    public static boolean es1_1 (int[] in_a){
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

    public static boolean es1_2 (int[] in_a){
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

    int[] riempiArray (int[] in_a){
        for (int i = 0; i < length; i++) in_a[i] = i;
        return in_a;
    }

    int[] es1_3 (int[] in_a){
        int tmp1 = 0, tmp2 = 0, tmp3 = 0, limitSx = 0;
        for (int i = 0; i < length; i++){
            tmp1 = limitSx + Math.random() * length; // Il range del valore assegnato a tmp è )limitSx, length(
            tmp2 = limitSx + Math.random() * length;
            while ( tmp1 != tmp2){
                tmp2 = limitSx + Math.random() * length;
            }
            tmp3 = in_a[(int)tmp1];
            in_a[(int)tmp1] = in_a[(int)tmp2];
            in_a[(int)tmp2] = tmp3;
        }
        return in_a;
    }

    /*  Es 4

        Scrivere un breve programma Java che dia in uscita tutte le possibili stringhe
        formate utilizzando una sola volta i caratteri 'c', 'a,', 'r', 'to', 'o', 'n'. 
    
    */

    public static int permutazioni (int n){
        if (n < 0) return 0;
        else if (n == 0) return 1;
        else {
            int res = 1;
            while (n > 0) {
                res *= n;
                n--;
            }
            return res;
        }
    }

    public static int rpermutazioni (int n){
        if (n < 0) return 0;
        else if (n == 0) return 1;
        else return (n * rpermutazioni(n - 1));
    }

    /*  Es 5

        Scrivere un breve programma Java che prenda tutte le righe di ingresso provenienti dal dispositivo
        di input standard e le scriva in ordine inverso sul dispositivo di output standard, nel senso che
        ogni singola riga sia scritta secondo il suo ordine corretto, ma l'ordine delle righe sia invertito.

    */
    
    /*  Es 6

        Scrivere un breve programma Java che prenda due array a e b di lunghezza
        n di numeri di tipo int e restituisca il prodotto scalare di a per b. In altre parole, il
        risultato è un array c di lunghezza n tale che c[i] = a[i\ • b[i], per i - 0,..., n - 1.

    */

    public static int[] es1_6 (int[] in_a, int[] in_b, int in_length){
        int[] c = new int[in_length];   // Dichiarazione di un nuovo array contenente il 
        for (int i = 0; i < in_length; i++) c[i] = a[i] * b[i];
        return c;
    }

    // ------------------------------------------------------------------------------------------

    public static void main(String []args){
         
        int n = permutazioni(6);
        
        System.out.print(n);
    
    }

}

