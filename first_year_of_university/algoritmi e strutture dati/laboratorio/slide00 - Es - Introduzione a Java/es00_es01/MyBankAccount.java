package es00_es01;

public class MyBankAccount implements BankAccount {
    
    private float money;

    public BankAccount (float in_money){             // Costruttore per conto iniziale con x euro
        this.money = in_money;
    }

    public BankAccount (){                          // Costruttore per conto iniziale con 0 euro
        this.money = 0;
    }

    public String toString (){                      // Print euro value
        return "Currently money: " + this.euro);
    }

    @Override
    public void addMonye (float in_money){            // Add euro
        this.money += in_money;
    }

    @Override
    public void takeMoney (float in_money){           // Take euro
        this.money -= in_money;
    }

}

