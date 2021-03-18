public class TryCatchTest {

    public static void main (String[] args) {

        int[] arr = new int[3];
        
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }

        try {
            
            for (int i = 0; i < arr.length + 1; i++) {
                System.out.println(arr[i]);
            }

            throw new IllegalArgumentException("Prova throw");      // Il corpo del try non viene eseguito fino a qui perché viene prima rilevato l'altro errore.
                                                                    // Per eseguire questo throw, commentare il ciclo for

        } catch (ArrayIndexOutOfBoundsException error) {
            System.out.println("Istruzioni catch 1 ...");
        } catch (IllegalArgumentException error) {
            System.out.println(error.getMessage());                 // Se viene eseguito il throw permette di stampare il messaggio di quest'ultimo
            System.out.println("Istruzioni catch 2 ...");
        } 
        


    }
}