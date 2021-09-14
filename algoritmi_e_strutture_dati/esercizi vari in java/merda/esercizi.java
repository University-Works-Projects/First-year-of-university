import java.util.Scanner;
import java.lang.Math.*;

public class Es3{

public static void main(String []args){
    
    Scanner UserInput = new Scanner(System.in);
     	
    double area, circonferenza;
     	
    System.out.println("Inserire la misura del raggio: ");
     	
    int raggio = UserInput.nextInt();
    area = Math.PI * raggio * raggio;
    circonferenza = 2 * Math.PI * raggio;
        
    System.out.println("La superficie dell'area è di: " + area + "\nLa lunghezza della circonferenza è di: " + circonferenza);
        
    // RISOLVERE: come stampare il carattere "è"
    }
	
}

public class Es4{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	int raggio;
     	double area, circonferenza;

     	System.out.println("Inserire due valori booleani (scrivendo 'true'/'false'): ");
     	boolean x = UserInput.nextBoolean();
     	boolean y = UserInput.nextBoolean();
     	
     	System.out.println("NOT (x OR y) : " + ! (x || y));
     	System.out.println("(NOT x) AND (NOT y) : " + (!x && !y));  // x! e NON !(x)
     	System.out.println("NOT (x AND y) : " + ! (x && y));
     	System.out.println("(NOT x) OR (NOT y) : " + (!x || !y));
     	
     }
}

public class Es5{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);

     	System.out.println("Inserire due numeri: ");
     	float x = UserInput.nextFloat();
     	float y = UserInput.nextFloat();
     	
     	System.out.println(x == y ? "0 i due numeri sono uguali" : "1 i due numeri sono diversi ");

     }
}

public class Es6{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);

     	System.out.println("Inserire un numero: ");
     	double x = UserInput.nextDouble();
     	
     	System.out.println(x < 0 ? (int)x : 3 * x + 2);

     }
}

public class Es2p1{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.println("Insert a string: ");
     	String str = UserInput.nextLine();
     	
     	UserInput.nextLine(); /* Comando necessario per fa si chè il comando successivo di nextLine 
     	possa leggere permettere all'utente di inserire la stringa, senza che quest'ultimo comando
     	venga skippato brutalmente. Ciò accade perchè il comando "INVIO" per confermare il comando 
     	di input preccedente rimane nel buffer, e tramite un nextLine "a vuoto" e viene subito letto dal 
     	comando nextline senza dar tempo all'utente di inserire qualocsa, legge dunque una stringa vuota.
     	*/
     	
     	System.out.println("Insert an index: ");
     	int index = UserInput.nextInt();
     	
     	int index_position = str.length();

     	
     	System.out.println((0 < index && index < index_position - 1) ? "" + str.charAt(index) : str.toLowerCase() + str.toUpperCase());
     	/* Essendo una strinda un oggetto di una classe e non una varibile primititva non si puù fare un
     	cast per stampare la lettera corrispondente all'indice inserito, bisogna dunque fare questo
     	"trucchetto" che consiste nell'inserire una stringa vuota e poi il carattere corrispondente
     	al valore dell'indice.
     	
     	FUN FUCT: funziona anche senza     	
     	*/ 

     }
}

public class Es2p2{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.println("Insert a string: ");
     	String str = UserInput.nextLine();
     	
     	String trimStr = str.trim();
     	
     	int i = str.indexOf(trimStr); /* Cerca la prima occorrrenza, ovvero la stringa str, dentro la 
     	stringa trimStr. Esempio str:= "   lol  kek  " --> trimStr:= "lol  kek", e con questo comando
     	và a cercare l'indice dell'inizio della frase inserita dll'utente. Provare per capire meglio.
     	*/
     	
      	//System.out.println(i);
    	
     	System.out.println("Result: <" + str.substring(i) + ">"); /* Grazie all'istruzione substring(i)
     	si stampa tutto quello che viene dopo l'indice i, in questo caso dalla prima lettera (DELLA 
     	VARIABILE str E NON trimStr, per questo motivo rimangono gli spazi finali) in poi.    	
     	*/

     }
}

public class Es2p3{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.println("Insert a string: ");
     	String str = UserInput.nextLine();
     	
     	String trimStr = str.trim();
     	
     	int i = str.indexOf(trimStr); 
     	
     	System.out.println("Result: <" + str.substring(0, i + trimStr.length()) + "$>");	
     	 

     }
}                                                     

public class Es2p4{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.println("Insert a number: ");
     	double x = UserInput.nextDouble();
     	
     	double y = Math.sqrt(x);
     	int z = (int)y;
     	
     	System.out.println(y == z ?  x + " e' un quadrato perfetto, infatti radq(" + x + ") = "  + (int)y : x + " non e' un quadrato perfetto, infatti radq(" + x + ") = " + y);

     }
}

/*   VERSIONE PIU SINTETICA

public class Es2p4{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.println("Insert a number: ");
     	double x = UserInput.nextDouble();
     	
     	System.out.println(Math.sqrt(x) == (int)Math.sqrt(x) ?  x + " e' un quadrato perfetto, infatti radq(" + x + ") = "  + (int)Math.sqrt(x) : x + " non e' un quadrato perfetto, infatti radq(" + x + ") = " + Math.sqrt(x));

     }
}


*/

public class Es2p5{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.println("Insert a number (Example: 43,568): ");
     	double x = UserInput.nextDouble();
     	
     	System.out.println("Insert a byte: ");
     	byte b = UserInput.nextByte();
     	
     	System.out.println(Math.round(x * Math.pow(10,b)) / Math.pow(10,b) );

     }
}

public class Es2p6{

     public static void main(String []args){
        
     	Scanner UserInput = new Scanner(System.in);
     	
     	System.out.println("Insert two numbers: ");
     	double x = UserInput.nextDouble();
     	double y = UserInput.nextDouble();
     	
     	
     	// Droppa un intero
     	System.out.println( ((0 <= x) && (x <= y)) ? (int)(Math.random() * (y - x)) + x : "ERROR" ); 
     	// Droppa un double
     	System.out.println( ((0 <= x) && (x <= y)) ? (Math.random() * (y - x)) + x : "ERROR" );

     }
}
