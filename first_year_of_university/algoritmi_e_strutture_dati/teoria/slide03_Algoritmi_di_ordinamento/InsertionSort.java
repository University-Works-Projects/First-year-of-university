/*
    - Si cerca (sorrendo l'array) il valore minimo e lo si scambia con l'elemento in testa
    Esempio:
    
        5  6  3  7  3  6

        3  6  5  7  3  6
        3  3  5  7  6  6 
        3  3  5  7  6  6 
        3  3  5  6  7  6 
        3  3  5  6  6  7    stop

*/

import java.util.Scanner;

public class InsertionSort {

    public static void selectionSort (int[] in_array) {
        for (int i = 0; i < in_array.length; i++) {
            for (int k = i + 1; k < in_array.length; k++) {
                if (in_array[i] > in_array[k]) {
                    int tmp = in_array[i];          // tmp = i
                    in_array[i] = in_array[k];  // i = k
                    in_array[k] = tmp;          // k = tmp
                }
            }

            // Stampa dell'array
            for (int j = 0; j < in_array.length; j++) {
                System.out.print (in_array[j]);
            }
        }
    }
    
    public static void insertionSort (int[] in_array) {
        System.out.println ("Array in input:");
        for (int j = 0; j < in_array.length; j++) {
            System.out.print (in_array[j]);
        }
        System.out.println ("");
        
        for (int i = 0; i < in_array.length; i++) {
            int tmp = i;
            for (int k = i; k < in_array.length; k++) {
                if (in_array[i] > in_array[k]) {
                    tmp = in_array[i];          // tmp = i
                    in_array[i] = in_array[k];  // i = k
                    in_array[k] = tmp;          // k = tmp
                }
            }

            // Stampa dell'array
            for (int j = 0; j < in_array.length; j++) {
                System.out.print (in_array[j]);
            }
            System.out.println ("  -  Scambio di: " + in_array[i] + " con: " + tmp);

        }
    }

    public static void main (String[] args) {
        Scanner UserInput = new Scanner(System.in);

        System.out.print("Inserire la lungezza dell'array: ");
        int length = UserInput.nextInt ();
        int[] array = new int[length];

        System.out.println ("");
        System.out.println("Inserire gli elementi dell'array: ");
        for (int i = 0; i < array.length; i++) {
            array[i] = UserInput.nextInt ();
        }

        System.out.println ("");
        selectionSort (array);
        
    }
}
