import java.util.Scanner;
import java.util.Random;

public class esP {
        
    /*  Es 1

        Una punizione comune per gli alunni delle scuole è quella di scrivere moltissime volte la stessa frase.
        Scrivere un programma Java completo che scriva 100 volte la seguente frase: «Non farò mai più spamming ai miei amici».
        Questo programma deve numerare ogni frase e commettere otto differenti errori di stampa apparentemente casuali. 

    */

    

    /*  Es 2

        (Per coloro che conoscono i metodi dell'interfaccia grafica di Java.)
        Definire una classe TestGrafico che controlli la funzionalità della classe CreditCard del
        Frammento di codice 1.5 mediante campi di testo e bottoni. 
    
    */


    /*  Es 3

        II paradosso del compleanno afferma che la probabilità che due persone in una stanza festeggino il
        compleanno nello stesso giorno dell'anno è maggiore di 0,5 se n, il numero di persone presenti nella stanza, è maggiore di 23.
        Questa proprietà, in realtà, non è un paradosso ma molte persone la ritengono sorprendente.
        Si prògetti un programma Java che possa provare questo paradosso con una serie di esperimenti
        su date di compleanno generate a caso, con un numero di persone n = 5,10,15,20,...,100
    
    */

    // ------------------------------------------------------------------------------------------

    public static void main(String []args){
         
        int n = permutazioni(6);
        
        System.out.print(n);
    
    }
}


