/*
    Scrivere una classe Java per gestire un conto corrente, su cui sono possibili le seguenti operazioni:
        • Aprire conto	corrente	vuoto (con	0	euro)
        • Aprire conto	corrente	con	X	euro
        • Versare X	euro	nel	conto
        • Prelevare X	euro	dal	conto
        • Stampare	un	messaggio	con	il	saldo	attuale		(nel	metodo	toString() )
    Estendere la classe	BankAccount per poter gestire	conti con valutediverse, aggiungendo un	campo valuta che può assumere valori:
        “euro”,	“dollar”,	“pound” (usare	Enumeration).	
    Definire	il	costruttore	che	prende	in	input	il	saldo	iniziale	e	la	valuta	e	sovrascrivere	il	metodo	
    toString()per	mostrare	i	dati	appropriati.
    Implementare	 una	 classe	 test	in	 cui	 sono	istanziati	 tre	 conti	 di	 valute	 diverse	 e	mostrato	il	
    saldo	di	ognuna.
*/

package es1;

public class BankAccount {
    private float euro;

    public BankAccount (float in_euro){             // Costruttore per conto iniziale con x euro
        this.euro = in_euro;
    }
    public BankAccount (){                          // Costruttore per conto iniziale con 0 euro
        this.euro = 0;
    }

    public void addEuro (float in_euro){            // Add euro
        this.euro += in_euro;
    }

    public void takeEuro (float in_euro){           // Take euro
        this.euro -= in_euro;
    }

    public String toString (){                      // Print euro value
        return "Currently euro: " + this.euro + "€";
    }
    
}

