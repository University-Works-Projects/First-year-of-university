package es1;

public class InternationalBankAcocunt extends MyBankAccount {
    
    public final MoneyValue;

    public InternationalBankAcocunt () {                                        // Costruttore per aggiungere solo il tipo di valuta, in questo caso Euro
        super ();
        this.MoneyValue = this.MoneyValue.Euro;
    }

    public InternationalBankAcocunt (float in_money) {                          // COme il caso precedente con l'aggiunta della quantità di denaro
        super (in_money);
        this.MoneyValue = this.MoneyValue.Euro;
    }

    public InternationalBankAcocunt (Value in_moneyValue) {                     // Caso in cui il denaro è già definito, ma il tipo di valuta no
        super ();
        this.value = in_moneyValue;
    }

    public InternationalBankAcocunt (float in_money, Value in_moneyValue) {     // Caso in cui sia la somma di denaro e la valuta sono da definire
        super (in_money);
        this.value = in_moneyValue;
    }

    @Override
    public String toString () {
        return super.toString () + "\nValue: " + this.value;
    }

}