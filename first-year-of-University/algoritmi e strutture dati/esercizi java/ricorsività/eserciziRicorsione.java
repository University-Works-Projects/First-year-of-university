//import java.util.Scanner;

public class eserciziRicorsione {

    // Es 1
    // Calcolo di n!
    public static int factorial (int n){
        //if (n < 0) return 0;              // Si assume n > 0
        if (n == 0) return 1;
        else return (n * factorial(--n));
    }

    // Es 2
    // Somma degli elementi di un array
    public static int sommaElementiArray (int[] in_a, int in_length){
        if (in_length == 1) return in_a[in_length];
        else return (in_a[in_length] + sommaElementiArray(in_a, --in_length));
    }

    // Es 3
    // Inversione degli elementi di un array, SI ASSUME i < j
    public static int[] reverseArray (int[] in_a, int i, int j){
        if (j < i || j == i) return in_a;
        else {
            int tmp = in_a[i];
            in_a[i] = in_a[j];
            in_a[j] = tmp;
            return reverseArray(in_a, ++i, --j);
        }
    }

    public static void printArrayElements(int[] in_a){
        for (int i = 0; i < in_a.length; i++){
            System.out.println(in_a[i]);
        }
    }

    // ------------------------------------------------------------------------------------------

    public static void main(String []args){

        // Es 1
        //System.out.println(factorial(5));

        /* Es 2
        int length = 6;
        int[] a = new int[length];        
        for (int i = 0; i < length; i++) a[i] = i;              // a[0] = 0 ; a[1] = 1 ; ... a[5] = 5        
        System.out.println(sommaElementiArray(a, --length));    // Si passa length -1 perchè altrimenti la funzione tenterebbe di accedere a in_a[6] causando errore
        */

        // Es 3
        int length = 6;
        int[] a = new int[length];        
        for (int i = 0; i < length; i++) a[i] = i;
        printArrayElements(a);
        System.out.println("aaaa");
        printArrayElements(reverseArray(a,0, --length));
        



    }

}
