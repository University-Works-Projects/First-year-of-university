//import java.util.Scanner;
//import java.lang.Math.*;

/*  Es 1

    Scrivere un algoritmo che dato l'array A[1..n-1], individua
    il valore nell'intervallo 1..n che non compare in A.

    Esemppi:
        A = [1, 3, 4, 5] è una permutazione di 1..5 a cui è stato tolto il numero 2.
        A = [7, 1, 3, 5, 4, 2] è una permutazione di 1..7 a cui è stato tolto il numero 6.

*/

public class esPag41{

    // Non si hanno vincoli sull'utilizzo della ricorsività e sull'iterazione 
    // Si assume l'inserimento di valori consoni all'esercizio evitando la scrittura di codice per input errati.

    // Version 1

    // Pro: Algoritmo adattabile per casistiche che non prevedano array di interi
    // Difetti: Efficiente quanto un tubero in guerra

    /*
    Problema 1: Dato un valore k ed un array a, tornare false se l è in a, true altrimenti.
    Esempi:
        p1 ({1,2,4,5}, 3) = false
        p1 ({1,2,4,5}, 2) = true
    */
    public static boolean isNotIn (int[] in_a, int k){
        for (int i = 0; i < in_a.length; i++){
            if (in_a[i] == k) return false;                                                             
        }
        return true;
    }

    
    public static int es1_v1 (int[] in_a){
        
        if (isNotIn(in_a, in_a.length + 1)) return in_a.length + 1;                                     // max(in_a) = (length + 1 || length) --> controllo il caso length + 1
        for (int i = 1; i <= in_a.length; i++){                                                         // min(in_a) = (1 || 2) --> i = 1 risolve caso min = 1 ; i <= in_a.length caso min = 2
            //System.out.println("i: " + i + " ; isNotIn: " + isNotIn(in_a, i));  // Debug line
            if (isNotIn(in_a, i)) return i;
        }
        return -1;      // Se ritorna -1 qualcosa è andato storto (inserimento di un array errato)
    }

    // Version 2

    // Pro: Molto efficiente in termini di tempo e memoria.
    // Contro: È migliorabile

    public static int es1_v2 (int[] in_a){
        int tot = in_a.length * 2 + 1, sum = 0; // tot = length + (length + 1), ovvero i valori che non vengono aggiunti nel for
        for (int i = 0; i < in_a.length; i++){
            tot += i;                           // tot = Somma di tutti i numeri dell'array compreso il l'elemento mancante
            sum += in_a[i];                     // sum = Somma degli elementi degli array
        }
        return (tot - sum);
    }

    // ------------------------------------------------------------------------------------------

    public static void main(String []args){

        int length = 4;

     	int[] a = new int [length];
        
        a[0] = 2;
        a[1] = 4;
        a[2] = 3;
        a[3] = 1;
        
        System.out.println(es1_v2(a));

    }

}
