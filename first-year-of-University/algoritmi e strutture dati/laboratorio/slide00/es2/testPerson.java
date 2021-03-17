/* Exercise test

    Implementare in Java una classe Persona, caratterizzata da:
    nome, cognome e cittadinanza, dove la cittadinanza può essere scelta tra:
    ‘Italiana’, ‘EU’, ‘ExtraEU’.

    • La cittadinanza deve essere implementata tramite l’enumerazione Cittadinanza.
    • La classe Persona implementa due metodi
    • costruttore
    • getInfo(): ritorna una stringa di informazioni, ad es:
        “Mi chiamo Mario Rossi e ho cittadinanza EU”
    
*/

import Person.Person1;

public class  testPerson{
    public static void main (String[] args){
        Person1 p1 = new Person1("Ezio Stracchini");
        Person1 p2 = new Person1("Beppe Stupro");
    
        System.out.println(p1.getInfo());
        System.out.println(p2.getInfo());
    }
}