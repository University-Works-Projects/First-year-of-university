public class ThrowTest {
    
    static void checkAge (int age) {
        if (age < 18) {
            throw new ArithmeticException ("MESSAGGIO DEL THROW");
        }
        else {
            System.out.println("NESSUN ERRORE");
        }
    }
    
    public static void main(String[] args) {
        
        checkAge(15);                               // Se si esegue SOLO questa istruzione verrà stamapto il messaggio del throw

        /*                                          // Se altrimenti viene eseguito questo blocco try - catch, non verrà stampato
        try {                                       // il messaggio del throw ma verrà eseguito il blocco di istruzioni del relativo catch
            checkAge(15);
        }
        catch (ArithmeticException e) {
            System.out.println("ISTRUZIONI DEL CATCH (MESSAGGIO DEL THROW SURCLASSATO)");
        }
        */
    }
}
