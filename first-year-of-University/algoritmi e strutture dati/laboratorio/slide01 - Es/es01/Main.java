/*  EXERCISES TEXT
    Scrivere un algoritmo che, dato in input una lista concatenata monodirezionale,
    restituisce il k-esimo elemento a partire dalla fine.
    Ad esempio, se k = 1 l'algoritmo deve restituire l'ultimo elemento;
    Se k = 2 il penultimo, e così via.
*/

package es01;
// FIXARE LIBRERIE
import essentials.Node;
import essentials.ListFunctions;

public class Main {

    public int backPosition (Node in_headNode, int in_index) {
        int winnerPosition = listLength (in_headNode) - in_index + 1;   // Valore che rappresenza la n-ultima posizone dell'elemento cercato tramite in_index
        int counter = 0;
        while (in_headNode != null && counter != winnerPosition) {
            counter++;
            in_headNode = in_headNode.getNextNode();
        }
        return in_headNode.getIntValue();
    }
    
    public static void main (String[] args) {

    }
}
