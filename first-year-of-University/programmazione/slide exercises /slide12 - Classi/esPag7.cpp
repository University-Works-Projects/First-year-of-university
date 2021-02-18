#include <iostream>

using namespace std;

/* Es 1

    Definire una classe cerchio con i metodi per calcolare l'area e circonferenza.
    Dopo aver definito la classe, scrivere un programma che crea un cerchio e ne stampa l’area.

*/

    class Cerchio{
    protected:
        const double pi = 3.1415;
        double raggio;
    public:
        Cerchio(double in_raggio){
            this -> raggio = in_raggio;
        }
        double area(){
            return (raggio * raggio * pi);
        }
        double circumference(){
            return (2 * pi * raggio);
        }
        double diameter(){
            return raggio * 2;
        }
    };

    double stampaAreaRaggio(double in_raggio){
        Cerchio c1 = Cerchio(in_raggio);
        return c1.area();
    }

/* Es 2

    Nel definire la classe cerchio avete dovuto scegliere se
    memorizzare in un campo il raggio o il diametro
    modificare la classe cerchio precedentemente definita cambiando questa
    scelta (usare il diametro al posto del raggio o viceversa).

*/

    class Cerchio{
        protected:
            const double pi = 3.1415;
            double diametro;
        public:
            Cerchio(double in_diametro){
                this -> diametro = diametro;
            }
            double area(){
                return ((diametro / 2) * (diametro / 2) * pi);
            }
            double circumference(){
                return (2 * pi * (diametro / 2));
            }
            double raggio(){
                return (diametro / 2);
            }
        };

    double stampaAreaDiametro(double in_diametro){
        Cerchio c1 = Cerchio(in_diametro);
        return c1.area();
    }

int main() {

    cout << stampaAreaDiametro(5);

	return(0) ;
}
