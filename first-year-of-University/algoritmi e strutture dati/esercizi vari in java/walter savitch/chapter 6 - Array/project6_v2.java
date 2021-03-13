// Same exercise but this time i used array of array
// Questa verisone non è la migliore per via del fatto che utilizzando array multidimensionali
// si perde la riusabilità del codica, in quanto le funzioni devono dipendono da quale "riga"
// dell'array devono andare a scrivere. In poche parole, le funzioni scritte sono specifiche per
// l'array multidimensionale in questione

// Array 0: orginal PIN
// Array 1: coding numbers
// Array 2: converted PIN
// Array 3: input PIN

import java.util.Scanner;
import java.lang.Math.*;

public class project6_v2 {

    static final int PIN = 5;
    static final int nArray = 4;

    public static boolean correctNumbers (int[][] in_originalNumber, int n) {
        for (int i = 0; i < in_originalNumber[n].length; i++) {
            if (in_originalNumber[0][i] > 9 || in_originalNumber[0][i] < 0) return false;
        }
        return true;
    }
    
    public static boolean isCorrect (int[][] in_allArray) {
        for (int i = 0; i < allArrays[3].length; i++) {
            if (in_allArray[3][i] != in_allArray[2][i]) return false;
        }
        return true;
    }
	
	public static void main (String[] args){
     	Scanner UserInput = new Scanner(System.in);

        int[][] allArrays = new int[nArray][PIN];

        // Take array 0
        while (true) {
                System.out.println("Enter correct PIN (5 digits): ");
            
                for (int i = 0; i < allArrays[0].length; i++) allArrays[0][i] = UserInput.nextInt();    // Take array 0
                if (allArrays[0].length == PIN && correctNumbers (allArrays, 0)) break;                 // Controll of the elements of array 0 
                System.out.println("invalid PIN. Try again (5 numbers)");
            }

        System.out.println("");
        System.out.println("**********************************");
        System.out.println("");



        // Numbers and coding numbers

        for (int i = 0; i < allArrays[1].length, i++) {
            allArrays[1][i] = (int)(Math.random() * 10);        // Array for coding numbers
        }

        System.out.println("PIN: 0 1 2 3 4 5 6 7 8 9");         // PIN: 0 1 2 3 4 5 6 7 8 9
        System.out.print("NUM: ");

        for (int i = 0; i < allArrays[1].length; i++) {         // NUM: x x x x x x x x x x
            System.out.print(allArrays[1][i] + " ");
        }

        // Make correct PIN
        int[] correctPIN = new int[PIN];
        for (int i = 0; < allArrays[0].length; i++) {
            allArrays[2][i] = allArrays[1][allArrays[0][i]];      // ***
            // ***
            // originalPIN: 13452
            //
            //      position: 0 1 2 3 4 5 6 7 8 9
            // codingNumbers: 3 2 5 1 7 8 0 6 9 4
            //
            // correctPIN[x] =  codingNumbers[ originalPIN[x] ] -->
            // --> allArrays[2][i] = allArrays[1][ allArrays[0][i] ]
        }



        // Take user input PIN while it's not correct
        System.out.println("Enter your PIN:");

        while (true) {
            for (int i = 0; i < allArrays[3].length; i++) {
                allArrays[3][i] = UserInput.nextInt();
            }

            if (isCorrect (allArrays)) break;
            System.out.println("Invalid PIN, try again");
        }

    } 

    
    
}