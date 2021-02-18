#include <iostream>

using namespace std;

/* Es 1

    Definire una classe frazione con un opportuno costruttore ed i metodi stampa, moltiplica e inverso.
    Il metodo moltiplica prende come parametri due frazioni e mette il risultato nella frazione su cui è invocato.
    Il metodo inverso inverte la frazione su cui è invocato

*/

class Frazione{
protected:
    int N;
    int D;
public:
    Frazione(int in_N, int in_D){
        this -> N = in_N;
        this -> D = in_D;
    }
    void stampa(){
        cout << this -> N << '/' << this -> D;
    }

    int N(){ return this -> N;} // Funzioni ausiliarie per il metodo moltiplicazione
    int D(){ return this -> D;}

    void moltiplica(Frazione f1, Frazione f2){
        this -> N = f1.N * f1.D;
        this -> D = f1.D * f2.D;
    }
    void inverso(){
        int tmp = this -> N;
        this -> N = this -> D;
        this -> D = tmp;
    }
}

