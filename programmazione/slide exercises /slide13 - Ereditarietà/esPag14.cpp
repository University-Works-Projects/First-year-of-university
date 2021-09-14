#include <iostream>
#include <string.h>

using namespace std;

/* Es 1

    Definire una classe contoBanca con un saldo e metodi versa e preleva.
    Definire una sottoclasse contoInteressi con un metodo addizionale che aumenta il saldo del n%.

*/

class ContoBanca{
protected:
    float saldo;
public:
    ContoBanca(float in_saldo){
        this -> saldo = in_saldo;
    }
    float versamento(float in_quota){
        this -> saldo += in_quota;
        return this -> saldo;           // Ritorna il saldo aggiornato
    }
    float prelievo(float in_prelievo){
        this -> saldo += in_prelievo;
        return this -> saldo;           // Ritorna il saldo aggiornato
    }   
};

class ContoInteressi: public ContoBanca(){
protected:
public:
    int incrementoPercentuale(int in_n){
        this -> saldo = this -> saldo + (this -> saldo / 100) * in_n;
        return this -> saldo;           // Ritorna il saldo aggiornato
    }
};

/* Es 2

    Definire una classe persona con campi opportuni, un costruttore e metodo presentati.
    Definire una sottoclasse impiegato con in più campi reparto e stipendio, ed un
    metodo presentati opportunamente modificato e un metodo aumento che aumenta lo stipendio del n%

*/

class Persona{
protected:
    char name[];
    int age;
public:
    Persona(char in_name[], int in_age){
        strcpy(this -> name, in_name);
        this -> age = in_age;
    }
    void presentatiPersona(){
        cout << "My name is: " << this -> name << '.' << endl;
        cout << "Ho " << this -> age << " anni." << endl;
    }
};

class Impegato: public Persona{
protected:
    int reparto;
    float stipendio;
public:
    Impiegato:Persona(int in_reparto, float in_stipendio){      // HELP
        this -> reparto = in_reparto;
        this -> stipendio = in_stipendio;
    }
    void presentatiImpiegato(){
        cout << "Reparto: " << this -> reparto << endl;
        cout << "Stipendio: " << this -> stipendio << endl;
    }
    float aumentoStipendio(int in_aumento){
        this -> stipendio = this -> stipendio + (this -> stipendio / 100) * in_aumento;
        return this -> stipendio;           // Ritorna lo stipendio aggiornato

    }

}
