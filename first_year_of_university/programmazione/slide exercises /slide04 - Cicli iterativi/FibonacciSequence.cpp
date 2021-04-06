/*
Fibonacci's series with a user limit
*/

#include <iostream>
using namespace std;

int main() {

	cout << "Insert a number that's tell when stop the sequence: ";
	int limit, counter = 0; cin >> limit;
	int a = 1, b = 1, c = 0;

	while (counter < limit){
		
		a = b + c;
		c = b;
		b = a;
		
		cout << b << endl;
		counter++;
	}

	return(0) ;
}
