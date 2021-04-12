/** 
 * Scrivere  una  classe  Java  per  gestire  un  conto  corrente,  su  cui  sono  possibili  le  seguenti operazioni:
 * • Aprire conto corrente vuoto (con 0 euro)
 * • Aprire conto corrente con X euro
 * • Versare X euro nel conto
 * • Prelevare X euro dal conto
 * • Stampare un messaggio con il saldo attuale  (nel metodo toString() )
 * Estendere la classe ContoCorrente per poter gestire conti con valute diverse, aggiungendo
 * un campo valuta che può assumere valori “euro”, “dollar”, “pound” (usare Enumeration).
 * Definire il costruttore che prende in input il saldo iniziale e la valuta e sovrascrivere il metodo 
 * toString() per mostrare i dati appropriati.
 * Implementare una classe test in cui sono istanziati tre conti di valute diverse e mostrato il
 * saldo di ognuna.
*/

package es00_es01;

public class TestBankAccount {

    public static void main (String[] args) {
        InternationalBankAccount tmp = new InternationalBankAccount (10, Value.Euro);
        tmp.takeMoney (3);
        System.out.println ("Bank account info: " + tmp.toString());
        
    }

}