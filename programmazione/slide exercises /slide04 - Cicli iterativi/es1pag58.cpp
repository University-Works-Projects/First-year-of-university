/*
This program approximates the value of e**x from the addiction 
of: 1 + x + x^2 / 2! + x^3 / 3! + x^4 / 4! + ... + x^n / n!
The program takes the n number from user and print the final
value of e**x

Il programma calcola correttaente il valore della formula 
per ogni x e per ogni n, ma non si approssima al valore 
di e^x, in quanto il valore varia al variare di n.

!!ANZI!! Avendo ad esempio e^5 =(circa) 148,41 per avere
un buon grado di approssimazione bisogna inserire un 
n >= 10, altrimenti vi sono decine di unità di differenza
tra il valore reale e quello approssimato.
In breve aumentando il valore di n si ha un maggiore 
grado di approssimazione, ma ATTENZIONE con valori troppo
grandi di n si hanno overflow
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	
	int x, counter; 
	cout << "Take the formula: e^x = 1 + x + x^2 / 2! + x^3 / 3! + x^4 / 4! + ... + x^n / n!" << endl;
	cout << "Insert x and n values: " << "x = "; cin >> x; 
	cout << "n = "; cin >> counter;
	
	int factorial_counter = 1, factorial_result = 1;
	double n = 1, e = 1;	// non bisogna impostare e=x+1 perchè il programma provvede a calcolare anche il fattoriale per n = 1
	
	if (counter < 0) cout << "ERROR";
	else if (counter == 0) cout << "e^x = 1";
	else {
		for (counter; counter > 0; counter--){
		while (n >= factorial_counter){
			factorial_result *= factorial_counter;
			factorial_counter++;
			//cout << "f_res = " << factorial_result << "   " << "F_count = " << factorial_counter << endl;
		}
		
		e += pow(x,n) / factorial_result;
		n++;
		factorial_result = 1;
		factorial_counter = 1;
		//cout << e << endl;
		}
		cout << "The aproximate value of e^" << x << ": " << e << endl;
		cout << "The librar value of e^" << x << ": " << exp(x);
	}	
	
	return(0) ;
}
