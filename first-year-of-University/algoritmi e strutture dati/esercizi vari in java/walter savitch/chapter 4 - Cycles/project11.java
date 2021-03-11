/**
 * Execution example:
 * Input: 4
 * Output:
 * *
 * **
 * ***
 * ****
 * ***
 * **
 * *
*/

import java.util.Scanner;

public class project11 {

    public static void main (String[] args){

        Scanner UserInput = new Scanner(System.in);
        System.out.println("Enter the height of the pyramid: ");
        int height = UserInput.nextInt();

        for (int i = 0; i < height; i++){
            for (int j = i; j > 0; j--){
                System.out.print("*");
            }
            System.out.print("\n");
        }
        for (int i = height; i > 0; i--){
            for (int j = i; j > 0; j--){
                System.out.print("*");
            }
            System.out.print("\n");
        }


    }

}