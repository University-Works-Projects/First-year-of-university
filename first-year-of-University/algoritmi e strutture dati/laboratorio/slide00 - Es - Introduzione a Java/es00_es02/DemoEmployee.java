/**
  * Creare una classe Persona con le variabili di istanza: nome (stringa) e data
  * di nascita (vedi java.time e java.util.Date). 
  * Creare una sottoclasse Impiegato che ha le seguenti variabili di istanza:
  * nome e data di nascita (ereditati) e stipendio. 
  * Definire costruttori e metodi set e get per le variabili di istanza, per
  * entrambe le classi Persona e Impiegato. 
  * Costruire una sottoclasse di Impiegato, chiamata Stagista, che contiene due
  * variabili di istanza entrambe di tipo intero: numeroPresenze, che registra
  * il numero di ore di presenza, e numeroIdentificativoStage.
  * Definire costruttore e metodi set e get per le variabili di istanza. 
  * Implementare una classe ImpiegatiDemo e nel metodo main() creare tre oggetti
  * di tipo Impiegato, di cui almeno uno stagista, e memorizzarli in un array. 
  * Aggiungere un metodo cercaGiovane che prende in input un vettore di
  * impiegati e ritorna l’impiegato più giovane. Invocare il metodo sul vettore
  * precedente e stampare le informazioni relative all’impiegato trovato.
  */

package es00_es02;

import java.time.LocalDate;

public class DemoEmployee {

    public static String findYoungerEmployee (Employee[] in_employees) {
        if (in_employees.length <= 0) return null;
        Employee winner = in_employees[0];                  // The winner is set to the first employee
        for (int i = 1; i < in_employees.length; i++) {     // i = 1 cuz in_employees[0] is the winner
            if (in_employees[i].getDateOfBirth ().compareTo (winner.getDateOfBirth) > 0) winner = in_employees[i];
        }
        return winner;
    }

    public static void main (String[] args) {
        Employee[] tmp = {
                new Employee1 ("Name 1", LocalDate.of(1970, 01, 10), 1300),
                new Employee2 ("Name 2", LocalDate.of(1971, 02, 12), 1400),
                new Intern1   ("Name 3", LocalDate.of(1972, 03, 13), 800, 1)
            };
        }
        System.out.println(findYoungerEmployee(tmp).toString());
    }
}