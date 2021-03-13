/*
	This program takes two words and print them in randomize order (chars including)
*/

import java.util.Scanner;
import java.lang.Math.*;

public class Due_parole_rimescolate{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.print("Enter two words: ");
		String first_word = UserInput.nextLine(); 
		String second_word = UserInput.nextLine();
		
		String union = first_word + second_word;
		String randomized_word = "";
		
		for (int length_randomized_word = first_word.length() + second_word.length(); length_randomized_word > 0 ; length_randomized_word--){
			int randomize_seed = (int)(Math.random() * (length_randomized_word));
			randomized_word += union.charAt(randomize_seed);
			union = union.substring(0, randomize_seed) + union.substring(randomize_seed + 1, union.length());	
		}
		System.out.println(randomized_word);
		
		System.out.println(union);
		  	
     }
}

/*
	This program simulates the roll of a dice (il lancio di un dado),
	allowing you (permettendoti) to choose the dice's faces,
	how many time roll it and print the average of the dice roll values.
*/

public class Es1LancioDelDado{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	double dice_result;
     	float average = 0;
     	
     	System.out.println("This program simulate the roll of a dice");
     	System.out.println("Insert the number of dice's face: ");    	
     	int dice_faces = UserInput.nextInt();
     	
     	System.out.println("How many times the dice must be rolled? : ");
     	int roll_times = UserInput.nextInt(), roll_times_copy = roll_times;
     	
     	System.out.println("The results of the rolls are...");    	
     	while (roll_times > 0){
     		dice_result = 1 + Math.random() * (dice_faces); // Il range del valore del dado è [1, dice_faces]
     		System.out.println((int)dice_result); 
     		average += (int)dice_result;
     		roll_times--;
     	}
     	System.out.println("The average is: " + average / roll_times_copy);
     	System.out.println("Thanks for playing dude!");

     }
}

/*
	This program takes two words and print them in column
	Example:  "lol" "ciao"
	l c
	o i
	l a
	o
	
	I think that this program can be optimized..
*/

public class Stampa_in_colonna_due_parole{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.print("Insert two words: ");
		String first_word = UserInput.nextLine(); 
		String second_word = UserInput.nextLine();
     	
		String combined_words = "";
     	
     	int limit = first_word.length() < second_word.length() ? first_word.length() : second_word.length();
     	int i = 0;
     	
     	for (i = 0; i < limit; i++){
     		System.out.print(first_word.charAt(i) + " ");
     		System.out.println(second_word.charAt(i));
     	}
     	
		if (first_word.length() > second_word.length()){
			for (i = 0; i < first_word.length(); i++){
				System.out.println(first_word.charAt(i));
			}
		} else if (second_word.length() > first_word.length()){
			for (i = i; i < second_word.length(); i++){
				System.out.println("  " + second_word.charAt(i));
			}			
     	}
     	
     	
     }
}

/*
	Generation of primes numbers.
*/

public class Generazione_Numeri_Primi{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.print("Enter a limit: ");
     	int limit = UserInput.nextInt();
		
     	int n = 2, c = 1;

     	while (limit > 0){
     		
     		if (n > c && n % c != 0){ // 5 % 3 = 2
     			c++;
     			//System.out.println("a");
     		}
     		else if (n % c == 0 && n > c){ // 4 % 2 = 0
     			//System.out.println("b");
     			c = 2;
     			n++;
     		}
     		else if (c == n && n % c == 0){
     			System.out.println("Numero primo: " + n);
     			c = 1;
     			n++;
     			limit--;
     		}
     		//System.out.print(" counter: " + c + " n = " + n + "    ");
     		
     	}	

     	
     }
}