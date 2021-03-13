import java.util.Scanner;
import java.lang.Math.*;

public class project6_v1 {

    public final PIN = 5;

    public static boolean correctNumbers (int[] in_originalNumber) {
        for (int i = 0; i < in_originalNumber; i++) {
            if (in_originalNumber > 9 || in_originalNumber < 0) return false;
        }
        return true;
    }

    public static boolean isCorrect (int[] in_userPIN, int[] in_correctPIN) {
        for (int i = 0; i < in_userPIN.length; i++) {
            if (in_userPIN[i] != in_correctPIN[i]) return false;
        }
        return true;
    }

    public static void main (String[] args){
     	Scanner UserInput = new Scanner(System.in);
        
        // Take original PIN

        int[] originalPIN = new int[PIN];
        
        while (true) {                                                                      // ------------------------------------
            System.out.println("Enter correct PIN (5 digits): ");
           
            for (int i = 0; i < originalPIN.length; i++) originalPIN[i] = UserInput.nextInt();    // Taking original PIN
            if (originalPIN.length == PIN && correctNumbers (originalPIN)) break;
            System.out.println("invalid PIN. Try again (5 numbers)");
        }                                                                                   // ------------------------------------

        System.out.println("");
        System.out.println("**********************************");
        System.out.println("");



        // Numbers and coding numbers

        int[] codingNumbers = new int[10];                      // Array per i numeri codificati

        for (int i = 0; i < codingNumbers.length, i++) {
            codingNumbers[i] = (int)(Math.random() * 10);       // Array for coding numbers
        }

        System.out.println("PIN: 0 1 2 3 4 5 6 7 8 9");         // PIN: 0 1 2 3 4 5 6 7 8 9
        System.out.print("NUM: ");

        for (int i = 0; i < codingNumbers.length; i++) {        // NUM: x x x x x x x x x x
            System.out.print(codingNumbers[i] + " ");
        }



        // Make correct PIN

        int[] correctPIN = new int[PIN];
        for (int i = 0; < originalPIN.length; i++) {
            correctPIN[i] = codingNumbers[originalPIN[i]];      // ***
            // ***
            // originalPIN: 13452
            //
            //      position: 0 1 2 3 4 5 6 7 8 9
            // codingNumbers: 3 2 5 1 7 8 0 6 9 4
            //
            // correctPIN[x] = codingNumbers[ originalPIN[x] ]
        }



        // Take user input PIN while it's not correct

        int[] userPIN = new int[PIN];

        System.out.println("Enter your PIN:");

        while (true) {
            for (int i = 0; i < userPIN.length; i++) {
                userPIN[i] = UserInput.nextInt();
            }

            if (isCorrect (userPIN, codingNumbers, originalPIN)) break;
            System.out.println("Invalid PIN, try again");
        }
        
    }

    
    
}