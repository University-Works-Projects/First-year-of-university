/*
This program take a number n from user and print 
n lines of '*'
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	
	int piramid_lines;
	cout << "Enter the number of pyramid lines: ";
	cin >> piramid_lines;
	
	int space = piramid_lines, simbol = 1;
	
		while (piramid_lines > 0){
			
			for (int z = 0; space > z; z++) cout << " ";
			space--;
			
			for (int f = 0; f < simbol; f++) cout << "*";
			simbol += 2;
			
			piramid_lines--;
			cout << endl;
	}	

	return(0) ;
}
