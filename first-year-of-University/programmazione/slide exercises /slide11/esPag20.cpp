#include <iostream>

using namespace std;

/* Es 1
    Scrivere una funzione ricorsiva che prende n e stampa n asterischi
*/

    void es1 (int n){
        if (n <= 0) cout << 'n';
        else if (n == 1) cout << '*';
        else {
            cout << '*';
            es1(n-1);
        }
    }

/* Es 2
    Scrivere write_vertical in maniera che le cifre sono stampate dalla meno significativa alla più significativa
    Esempio:
        void rcrv_WriteVertical (12342)
        2
        4
        3
        2
        1
*/

    void rcrv_WriteVertical (int n){
        if (n < 10) cout << n;
        else {
            cout << n % 10;
            rcrv_WriteVertical(n / 10);
        }
    }

/* Es 3
    Scrivere una funzione ricorsiva che prende n e stampa un
    numero di asterischi uguale alla somma dei quadrati dei primi n
    numeri naturali
    Esempio: es3(3) = * **** ********* (senza gli spazi)
*/

    void es3 (int n){
        if (n <= 0) cout << 'n';
        else if (n == 1) cout << '*';
        else {
            int pow = n * n;
            es1(m);             // print of n*n --> p.e: 2*2 = 4 -> print: ****
            es3(n - 1);
        }
    }


int main() {

    cout << es1(5);

	cout << "Enter a number: ";
	int n; cin >> n;
	es3(n);

	return(0) ;
}
